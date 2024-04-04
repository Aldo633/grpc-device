cmake_minimum_required(VERSION 3.12.0)

project(ni_grpc_device_server C CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(CreateVirtualEnvironment)

# Workaround for: https://bugs.chromium.org/p/boringssl/issues/detail?id=423
if (CMAKE_SYSTEM_PROCESSOR STREQUAL "AMD64")
  set(CMAKE_SYSTEM_PROCESSOR "amd64")
endif()

#----------------------------------------------------------------------
# Use the grpc targets directly from this build, only when not cross-compiling.
#----------------------------------------------------------------------
if(CMAKE_CROSSCOMPILING)
  find_program(_PROTOBUF_PROTOC protoc)
  find_program(_GRPC_CPP_PLUGIN_EXECUTABLE grpc_cpp_plugin)

  if(NOT _GRPC_DEVICE_NILRT_LEGACY_TOOLCHAIN)
    find_package(gRPC REQUIRED)
    find_library(_REFLECTION grpc++_reflection)
    find_library(_GRPC_GRPCPP grpc++)
    find_library(_PROTOBUF_LIBPROTOBUF protobuf)
      else()
    add_subdirectory(third_party/grpc ${CMAKE_CURRENT_BINARY_DIR}/grpc EXCLUDE_FROM_ALL)
    set(_REFLECTION grpc++_reflection)
    set(_GRPC_GRPCPP grpc++)
    set(_PROTOBUF_LIBPROTOBUF libprotobuf)
    add_subdirectory(third_party/grpc-sideband ${CMAKE_CURRENT_BINARY_DIR}/grpc-sideband)
  endif()

else()
  add_subdirectory(third_party/grpc ${CMAKE_CURRENT_BINARY_DIR}/grpc EXCLUDE_FROM_ALL)
  set(_PROTOBUF_PROTOC $<TARGET_FILE:protobuf::protoc>)
  set(_REFLECTION grpc++_reflection)
  set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:grpc_cpp_plugin>)
  set(_GRPC_GRPCPP grpc++)
  set(_PROTOBUF_LIBPROTOBUF libprotobuf)
  add_subdirectory(third_party/grpc-sideband ${CMAKE_CURRENT_BINARY_DIR}/grpc-sideband)
endif()

CreateVirtualEnvironment(virtual_environment
  REQUIREMENTS_TXT 
    ${CMAKE_SOURCE_DIR}/python_build_requirements.txt
  ENV_NAME
    venv
  OUT_PYTHON_EXE 
    PYTHON_EXE
)

#----------------------------------------------------------------------
# Use C++17 (needed for shared_mutex support on Linux)
#----------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#----------------------------------------------------------------------
# Include generated *.pb.h files
#----------------------------------------------------------------------
set(proto_srcs_dir "${CMAKE_CURRENT_BINARY_DIR}/proto")
file(MAKE_DIRECTORY ${proto_srcs_dir})
include_directories(
  "${proto_srcs_dir}"
  "./generated"
  "./imports/include"
  "./source"
  "./third_party/grpc-sideband/src"
)

#----------------------------------------------------------------------
# Define libraries to link
#----------------------------------------------------------------------
if(WIN32)
  link_directories("./imports/lib/win64")
else()
  # Add grpc-sideband deps here
  link_directories("./imports/lib/linux")
endif()

if(NOT MSVC)
  set(RDMA_LIB "libnirdma.so")
else()
  set(RDMA_LIB "rdma.lib")
endif()

#----------------------------------------------------------------------
# Get list of NI Driver APIs and directories to generate from
#----------------------------------------------------------------------
set(metadata_dir ${CMAKE_SOURCE_DIR}/source/codegen/metadata)
set(service_output_dir ${CMAKE_SOURCE_DIR}/generated)
set(codegen_dir ${CMAKE_SOURCE_DIR}/source/codegen)
set(custom_dir ${CMAKE_SOURCE_DIR}/source/custom)
set(nidrivers "nidaqmx" "nidcpower" "nidigitalpattern" "nidmm" "nifake" "nifake_extension" "nifake_non_ivi" "nifgen" "nifpga" "nirfmxbluetooth" "nirfmxinstr" "nirfmxlte" "nirfmxnr" "nirfmxspecan" "nirfmxwlan" "nirfsa" "nirfsg" "niscope" "niswitch" "nisync" "nitclk" "nixnet" "nixnetsocket")

#----------------------------------------------------------------------
# Create NI Driver APIs proto and server files
#----------------------------------------------------------------------
set(codegen_scripts
  "${codegen_dir}/client_helpers.py"
  "${codegen_dir}/common_helpers.py"
  "${codegen_dir}/generate_service.py"
  "${codegen_dir}/generate_shared_service_files.py"
  "${codegen_dir}/service_helpers.py"
  "${codegen_dir}/proto_helpers.py"
  "${codegen_dir}/metadata_mutation.py"
  "${codegen_dir}/metadata_validation.py"
  "${codegen_dir}/template_helpers.py"
  "${codegen_dir}/templates/client.cpp.mako"
  "${codegen_dir}/templates/client.h.mako"
  "${codegen_dir}/templates/client_helpers.mako"
  "${codegen_dir}/templates/library_interface.h.mako"
  "${codegen_dir}/templates/library.cpp.mako"
  "${codegen_dir}/templates/library.h.mako"
  "${codegen_dir}/templates/mock_library.h.mako"
  "${codegen_dir}/templates/proto.mako"
  "${codegen_dir}/templates/proto_helpers.mako"
  "${codegen_dir}/templates/register_all_services.h.mako"
  "${codegen_dir}/templates/register_all_services.cpp.mako"  
  "${codegen_dir}/templates/service.cpp.mako"
  "${codegen_dir}/templates/service_helpers.mako"
  "${codegen_dir}/templates/service.h.mako"
  "${codegen_dir}/templates/service_registrar.h.mako"
  "${codegen_dir}/templates/service_registrar.cpp.mako"  
  )

# Populated in the api loop below.
set(nidriver_service_srcs "")
set(nidriver_client_srcs "")

# We'll codegen all drivers, but some are not included in the server build.
set(nidrivers_to_build ${nidrivers})
# Fake drivers are not in the server and are added manually to the UnitTestRunner build.
list(FILTER nidrivers_to_build EXCLUDE REGEX "^nifake.*")
if (NOT WIN32)
  # None of the RFmx drivers support Linux and building against the headers fails.
  # Exclude them on Linux.
  list(FILTER nidrivers_to_build EXCLUDE REGEX "^nirfmx.*")
endif()

set(all_codegen_dependencies "")

foreach(api ${nidrivers})
  set(codegen_dependencies
    "${metadata_dir}/${api}/attributes.py"
    "${metadata_dir}/${api}/attributes_addon.py"
    "${metadata_dir}/${api}/config.py"
    "${metadata_dir}/${api}/config_addon.py"
    "${metadata_dir}/${api}/enums.py"
    "${metadata_dir}/${api}/enums_addon.py"
    "${metadata_dir}/${api}/functions.py"
    "${metadata_dir}/${api}/functions_addon.py"
    "${metadata_dir}/${api}/__init__.py")
  if (EXISTS "${metadata_dir}/${api}/custom_proto.mako")
    set(codegen_dependencies ${codegen_dependencies} "${metadata_dir}/${api}/custom_proto.mako")
  endif()
  set(all_codegen_dependencies
    ${all_codegen_dependencies}
    ${codegen_dependencies}
  )

  set(output_files
    ${service_output_dir}/${api}/${api}_client.cpp
    ${service_output_dir}/${api}/${api}_client.h
    ${service_output_dir}/${api}/${api}_library_interface.h
    ${service_output_dir}/${api}/${api}_library.cpp
    ${service_output_dir}/${api}/${api}_library.h
    ${service_output_dir}/${api}/${api}_mock_library.h
    ${service_output_dir}/${api}/${api}.proto
    ${service_output_dir}/${api}/${api}_service.cpp
    ${service_output_dir}/${api}/${api}_service.h
    ${service_output_dir}/${api}/${api}_service_registrar.cpp
    ${service_output_dir}/${api}/${api}_service_registrar.h
  )
  set(gen_command COMMAND ${PYTHON_EXE} ${codegen_dir}/generate_service.py ${metadata_dir}/${api}/ -o ${service_output_dir}/)
  if (api IN_LIST nidrivers_to_build)
    set(nidriver_service_srcs
      ${nidriver_service_srcs}
      "${service_output_dir}/${api}/${api}_service.cpp"
      "${service_output_dir}/${api}/${api}_service_registrar.cpp"
      "${service_output_dir}/${api}/${api}_library.cpp"
      "${custom_dir}/${api}_service.custom.cpp")
    set(nidriver_client_srcs
      ${nidriver_client_srcs}
      "${service_output_dir}/${api}/${api}_client.cpp")
  endif()
  set(proto_dependencies ${codegen_dependencies} ${codegen_scripts} virtual_environment)
  add_custom_command(OUTPUT ${output_files}
    ${gen_command}
    COMMENT "Generating proto file and service for ${api}"
    DEPENDS ${proto_dependencies})
endforeach()

add_custom_command(
  OUTPUT 
    ${service_output_dir}/register_all_services.cpp
    ${service_output_dir}/register_all_services.h
  COMMAND 
    ${PYTHON_EXE} ${codegen_dir}/generate_shared_service_files.py ${metadata_dir}/ -o ${service_output_dir}/
  COMMENT 
    "Generating shared service files"
  DEPENDS
    ${all_codegen_dependencies}
    ${codegen_scripts} 
    virtual_environment
)

set(nidriver_service_srcs
    ${nidriver_service_srcs}
    ${service_output_dir}/register_all_services.cpp
)

#----------------------------------------------------------------------
# Proto file
#----------------------------------------------------------------------
get_filename_component(session_proto "source/protobuf/session.proto" ABSOLUTE)
get_filename_component(nidevice_proto "source/protobuf/nidevice.proto" ABSOLUTE)
get_filename_component(data_moniker_proto "source/protobuf/data_moniker.proto" ABSOLUTE)
get_filename_component(session_proto_path "${session_proto}" PATH)

#----------------------------------------------------------------------
# Generate sources from proto files
# Usage: GenerateGrpcSources(PROTO <path> OUTPUT <path>...)
#----------------------------------------------------------------------
function(GenerateGrpcSources)
  set(oneValueArgs PROTO)
  set(multiValueArgs OUTPUT)
  cmake_parse_arguments(GENERATE_ARGS "" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})
  set(output_files "${GENERATE_ARGS_OUTPUT}")
  set(proto_file "${GENERATE_ARGS_PROTO}")
  get_filename_component(proto_path "${proto_file}" PATH)
  # Asssumption: all outputs are in the same directory: use the zero-th.
  list(GET output_files 0 proto_srcs)
  get_filename_component(proto_out_path "${proto_srcs}" PATH)
  add_custom_command(
    OUTPUT ${output_files}
    COMMAND ${_PROTOBUF_PROTOC}
    ARGS --grpc_out "${proto_out_path}"
      --cpp_out "${proto_out_path}"
      -I "${proto_path}"
      -I ${CMAKE_SOURCE_DIR}/third_party/grpc/third_party/protobuf/src/
      -I ${CMAKE_SOURCE_DIR}/source/protobuf
      --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
      "${proto_file}"
    DEPENDS "${proto_file}" "${session_proto}")
endfunction()

set(session_proto_srcs "${proto_srcs_dir}/session.pb.cc")
set(session_proto_hdrs "${proto_srcs_dir}/session.pb.h")
set(session_grpc_srcs "${proto_srcs_dir}/session.grpc.pb.cc")
set(session_grpc_hdrs "${proto_srcs_dir}/session.grpc.pb.h")
set(nidevice_proto_srcs "${proto_srcs_dir}/nidevice.pb.cc")
set(nidevice_proto_hdrs "${proto_srcs_dir}/nidevice.pb.h")
set(data_moniker_proto_srcs "${proto_srcs_dir}/data_moniker.pb.cc")
set(data_moniker_proto_hdrs "${proto_srcs_dir}/data_moniker.pb.h")
set(data_moniker_grpc_srcs "${proto_srcs_dir}/data_moniker.grpc.pb.cc")
set(data_moniker_grpc_hdrs "${proto_srcs_dir}/data_moniker.grpc.pb.h")

GenerateGrpcSources(
  PROTO
    ${session_proto}
  OUTPUT
    "${session_proto_srcs}" 
    "${session_proto_hdrs}" 
    "${session_grpc_srcs}" 
    "${session_grpc_hdrs}"
)

GenerateGrpcSources(
  PROTO
    ${nidevice_proto}
  OUTPUT
    "${nidevice_proto_srcs}"
    "${nidevice_proto_hdrs}"
)

GenerateGrpcSources(
  PROTO
    ${data_moniker_proto}
  OUTPUT
    "${data_moniker_proto_srcs}"
    "${data_moniker_proto_hdrs}"
    "${data_moniker_grpc_srcs}"
    "${data_moniker_grpc_hdrs}"
)

foreach(api ${nidrivers})
  GenerateGrpcSources(
    PROTO
      ${service_output_dir}/${api}/${api}.proto
    OUTPUT
      "${proto_srcs_dir}/${api}.pb.cc"
      "${proto_srcs_dir}/${api}.pb.h"
      "${proto_srcs_dir}/${api}.grpc.pb.cc"
      "${proto_srcs_dir}/${api}.grpc.pb.h"
  )
  if(api IN_LIST nidrivers_to_build)
    set(nidriver_service_srcs
      ${nidriver_service_srcs}
      "${proto_srcs_dir}/${api}.pb.cc"
      "${proto_srcs_dir}/${api}.grpc.pb.cc")
  endif()
endforeach()

add_executable(ni_grpc_device_server
  "source/server/core_server.cpp"
  "source/server/core_service_registrar.cpp"
  "source/server/device_enumerator.cpp"
  "source/server/feature_toggles.cpp"
  "source/server/logging.cpp"
  "source/server/semaphore.cpp"
  "source/server/server_configuration_parser.cpp"
  "source/server/server_security_configuration.cpp"
  "source/server/session_repository.cpp"
  "source/server/session_utilities_service.cpp"
  "source/server/shared_library.cpp"
  "source/server/syscfg_library.cpp"
  "source/server/data_moniker_service.cpp"
  ${data_moniker_proto_srcs}
  ${data_moniker_grpc_srcs}
  ${nidevice_proto_srcs}
  ${session_proto_srcs}
  ${session_grpc_srcs}
  ${nidriver_service_srcs})

if(CMAKE_SYSTEM_NAME STREQUAL Linux)
  target_sources(ni_grpc_device_server
    PRIVATE "source/server/linux/syslog_logging.cpp"
    PRIVATE "source/server/linux/daemonize.cpp")
endif()

target_link_libraries(ni_grpc_device_server
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF}
  ${CMAKE_DL_LIBS}
  nlohmann_json::nlohmann_json
)

target_link_libraries(ni_grpc_device_server
  ni_grpc_sideband
  ${RDMA_LIB}
)

set_target_properties(ni_grpc_device_server PROPERTIES BUILD_WITH_INSTALL_RPATH TRUE)

if(WIN32)
  target_link_libraries(ni_grpc_device_server Delayimp nidaqmx nidcpower niDigital nidmm niFgen niScope niRFmxBT niRFmxInstr niRFmxLTE niRFmxNR niRFmxSpecAn niRFmxWLAN niRFSA niRFSG niswitch nisync niTClk nixnet nixntipstack)
  set_target_properties(ni_grpc_device_server PROPERTIES LINK_FLAGS "/DELAYLOAD:nicaiu.dll /DELAYLOAD:nidcpower.dll /DELAYLOAD:niDigital_64.dll /DELAYLOAD:nidmm_64.dll /DELAYLOAD:niFgen_64.dll /DELAYLOAD:niRFmxBT.dll /DELAYLOAD:niRFmxInstr.dll /DELAYLOAD:niRFmxLTE.dll /DELAYLOAD:niRFmxNR.dll /DELAYLOAD:niRFmxSpecAn.dll /DELAYLOAD:niRFmxWLAN.dll /DELAYLOAD:niRFSA_64.dll /DELAYLOAD:niRFSG_64.dll /DELAYLOAD:niScope.dll /DELAYLOAD:niswitch.dll /DELAYLOAD:nisync.dll /DELAYLOAD:niTClk_64.dll /DELAYLOAD:nixnet.dll /DELAYLOAD:nixntipstack.dll")
  set(ni_grpc_device_server CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /DELAYLOAD:nicaiu.dll /DELAYLOAD:nidcpower.dll /DELAYLOAD:niDigital_64.dll /DELAYLOAD:nidmm_64.dll /DELAYLOAD:niFgen_64.dll /DELAYLOAD:niScope.dll /DELAYLOAD:niRFmxBT.dll /DELAYLOAD:niRFmxInstr.dll /DELAYLOAD:niRFmxLTE.dll /DELAYLOAD:niRFmxNR.dll /DELAYLOAD:niRFmxSpecAn.dll /DELAYLOAD:niRFmxWLAN.dll /DELAYLOAD:niRFSA_64.dll /DELAYLOAD:niRFSG_64.dll /DELAYLOAD:niswitch.dll /DELAYLOAD:nisync.dll /DELAYLOAD:niTClk_64.dll /DELAYLOAD:nixnet.dll /DELAYLOAD:nixntipstack.dll")
endif()

#----------------------------------------------------------------------
# Copy server_config.json to binary output directory
#----------------------------------------------------------------------
add_custom_command(
   TARGET ni_grpc_device_server POST_BUILD
   COMMAND  ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_SOURCE_DIR}/source/config/insecure_config.json
            $<TARGET_FILE_DIR:ni_grpc_device_server>/server_config.json)

#----------------------------------------------------------------------
# Add JSON parser and configure google tests
#----------------------------------------------------------------------
if(CMAKE_CROSSCOMPILING AND NOT _GRPC_DEVICE_NILRT_LEGACY_TOOLCHAIN)
  find_package(nlohmann_json REQUIRED)
  find_library(gtest REQUIRED)
else()
  add_subdirectory(third_party/json ${CMAKE_CURRENT_BINARY_DIR}/json EXCLUDE_FROM_ALL)
  enable_testing()
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  add_subdirectory(third_party/gtest ${CMAKE_CURRENT_BINARY_DIR}/gtest EXCLUDE_FROM_ALL)
endif()

# Link test executable against gtest
add_executable(IntegrationTestsRunner
    "source/tests/utilities/run_all_tests.cpp"
    "source/tests/integration/ni_fake_service_tests_endtoend.cpp"
    "source/tests/integration/ni_fake_non_ivi_service_tests_endtoend.cpp"
    "source/tests/integration/session_utilities_service_tests.cpp"
    "source/tests/integration/session_utilities_service_tests_endtoend.cpp"
    "source/server/device_enumerator.cpp"
    "source/server/feature_toggles.cpp"
    "source/server/semaphore.cpp"
    "source/server/session_repository.cpp"
    "source/server/session_utilities_service.cpp"
    "source/server/shared_library.cpp"
    ${data_moniker_proto_srcs}
    ${nidevice_proto_srcs}
    ${session_proto_srcs}
    ${session_grpc_srcs}
    "${proto_srcs_dir}/nifake.pb.cc"
    "${proto_srcs_dir}/nifake.grpc.pb.cc"
    "${proto_srcs_dir}/nifake_non_ivi.pb.cc"
    "${proto_srcs_dir}/nifake_non_ivi.grpc.pb.cc"
    "${service_output_dir}/nifake/nifake_client.cpp"
    "${service_output_dir}/nifake/nifake_service.cpp"
    "${service_output_dir}/nifake_non_ivi/nifake_non_ivi_client.cpp"
    "${service_output_dir}/nifake_non_ivi/nifake_non_ivi_service.cpp"
    "${custom_dir}/nifake_non_ivi_service.custom.cpp"
)

    set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
    set(THREADS_PREFER_PTHREAD_FLAG TRUE)
    find_package(Threads REQUIRED)

target_link_libraries(IntegrationTestsRunner
    gtest
    gmock
    ${_GRPC_GRPCPP}
    ${CMAKE_DL_LIBS}
    Threads::Threads)

add_library(TestApi SHARED
    "source/tests/utilities/test_api.cpp")
add_compile_definitions(TestApi TEST_API_BUILDING)

add_executable(UnitTestsRunner
    "source/tests/utilities/run_all_tests.cpp"
    "source/tests/unit/callback_router_tests.cpp"
    "source/tests/unit/converters_tests.cpp"
    "source/tests/unit/session_resource_repository_tests.cpp"
    "source/tests/unit/session_repository_tests.cpp"
    "source/tests/unit/device_enumerator_tests.cpp"
    "source/tests/unit/server_configuration_parser_tests.cpp"
    "source/tests/unit/server_security_configuration_tests.cpp"
    "source/tests/unit/ni_fake_non_ivi_service_tests.cpp"
    "source/tests/unit/ni_fake_service_tests.cpp"
    "source/tests/unit/shared_library_tests.cpp"
    "source/tests/unit/syscfg_library_tests.cpp"
    "source/tests/unit/xnet_converters_tests.cpp"
    "source/server/device_enumerator.cpp"
    "source/server/feature_toggles.cpp"
    "source/server/semaphore.cpp"
    "source/server/server_configuration_parser.cpp"
    "source/server/server_security_configuration.cpp"
    "source/server/session_repository.cpp"
    "source/server/shared_library.cpp"
    "source/server/syscfg_library.cpp"
    ${data_moniker_proto_srcs}
    ${nidevice_proto_srcs}
    ${session_proto_srcs}
    ${session_grpc_srcs}
    "${proto_srcs_dir}/nifake.pb.cc"
    "${proto_srcs_dir}/nifake.grpc.pb.cc"
    "${proto_srcs_dir}/nifake_extension.pb.cc"
    "${proto_srcs_dir}/nifake_extension.grpc.pb.cc"
    "${proto_srcs_dir}/nifake_non_ivi.pb.cc"
    "${proto_srcs_dir}/nifake_non_ivi.grpc.pb.cc"
    "${proto_srcs_dir}/nixnetsocket.pb.cc"
    "${service_output_dir}/nifake/nifake_service.cpp"
    "${service_output_dir}/nifake_extension/nifake_extension_service.cpp"
    "${service_output_dir}/nifake_non_ivi/nifake_non_ivi_service.cpp"
    "${custom_dir}/nifake_service.custom.cpp"
    "${custom_dir}/nifake_extension_service.custom.cpp"
    "${custom_dir}/nifake_non_ivi_service.custom.cpp"
)

# ni_fake_service_tests.cpp and several DAQ cpp files exceed the MSVC limit for the number of sections 
# in an obj file defined by PE-COFF. This line disables the limit.
if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj /D_SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING")
else()
  # On Linux, nirdma has weak symbol linkage to lvrt. So ignore errors related to undefined symbols from shared libs.
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wl,--allow-shlib-undefined")
endif()

target_include_directories(UnitTestsRunner
    PRIVATE "${service_output_dir}/nifake"
    PRIVATE "${service_output_dir}/nifake_extension"
    PRIVATE "${service_output_dir}/nifake_non_ivi")

target_link_libraries(UnitTestsRunner
    gtest
    gmock
    ${_GRPC_GRPCPP}
    ${CMAKE_DL_LIBS}
    Threads::Threads
    nlohmann_json::nlohmann_json)

#----------------------------------------------------------------------
# Copy test asset certificates to binary output certs sub-directory
#----------------------------------------------------------------------
add_custom_command(
  TARGET UnitTestsRunner POST_BUILD
  COMMAND  ${CMAKE_COMMAND} -E copy_directory
           ${CMAKE_SOURCE_DIR}/source/tests/assets/
           $<TARGET_FILE_DIR:UnitTestsRunner>/)

set(system_test_runner_sources
  "source/tests/utilities/run_all_tests.cpp"
  "source/server/core_service_registrar.cpp"
  "source/tests/system/device_server.cpp"
  "source/tests/system/enumerate_devices.cpp"
  "source/tests/system/session_utilities_service_tests.cpp"
  "source/tests/system/nidaqmx_driver_api_tests.cpp"
  "source/tests/system/nidaqmx_session_tests.cpp"
  "source/tests/system/nidcpower_driver_api_tests.cpp"
  "source/tests/system/nidcpower_session_tests.cpp"
  "source/tests/system/nidigital_driver_api_tests.cpp"
  "source/tests/system/nidigital_session_tests.cpp"
  "source/tests/system/nidmm_driver_api_tests.cpp"
  "source/tests/system/nidmm_session_tests.cpp"
  "source/tests/system/nifgen_driver_api_tests.cpp"
  "source/tests/system/nifgen_session_tests.cpp"
  "source/tests/system/nirfsa_driver_api_tests.cpp"
  "source/tests/system/nirfsg_driver_api_tests.cpp"
  "source/tests/system/nirfsg_session_tests.cpp"
  "source/tests/system/niscope_driver_api_tests.cpp"
  "source/tests/system/niscope_session_tests.cpp"
  "source/tests/system/niswitch_driver_api_tests.cpp"
  "source/tests/system/niswitch_session_tests.cpp"
  "source/tests/system/nisync_driver_api_tests.cpp"
  "source/tests/system/nisync_session_tests.cpp"
  "source/tests/system/nitclk_driver_api_tests.cpp"
  "source/tests/system/nixnetsocket_driver_api_tests.cpp"
  "source/server/device_enumerator.cpp"
  "source/server/feature_toggles.cpp"
  "source/server/session_repository.cpp"
  "source/server/semaphore.cpp"
  "source/server/session_utilities_service.cpp"
  "source/server/shared_library.cpp"
  "source/server/syscfg_library.cpp"
  "source/server/data_moniker_service.cpp"
  ${data_moniker_proto_srcs}
  ${data_moniker_grpc_srcs}
  ${nidevice_proto_srcs}
  ${session_proto_srcs}
  ${session_grpc_srcs}
  ${nidriver_service_srcs}
  ${nidriver_client_srcs}
)

if(WIN32)
  list(
    APPEND 
      system_test_runner_sources
        "source/tests/system/nirfmxbluetooth_driver_api_tests.cpp"
        "source/tests/system/nirfmxbluetooth_session_tests.cpp"
        "source/tests/system/nirfmxinstr_driver_api_tests.cpp"
        "source/tests/system/nirfmxlte_driver_api_tests.cpp"
        "source/tests/system/nirfmxlte_session_tests.cpp"
        "source/tests/system/nirfmxnr_driver_api_tests.cpp"
        "source/tests/system/nirfmxnr_session_tests.cpp"
        "source/tests/system/nirfmxspecan_driver_api_tests.cpp"
        "source/tests/system/nirfmxspecan_session_tests.cpp"
        "source/tests/system/nirfmxwlan_driver_api_tests.cpp"
        "source/tests/system/nirfmxwlan_session_tests.cpp"
  )
endif()

add_executable(SystemTestsRunner ${system_test_runner_sources})

target_link_libraries(SystemTestsRunner
    gtest
    gmock
    ${_GRPC_GRPCPP}
    ${CMAKE_DL_LIBS}
    nlohmann_json::nlohmann_json
)

target_link_libraries(SystemTestsRunner
  ni_grpc_sideband
  ${RDMA_LIB}
)

add_custom_command(
  TARGET SystemTestsRunner POST_BUILD
  COMMAND  ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/source/tests/assets/data/
            $<TARGET_FILE_DIR:SystemTestsRunner>/)

if(WIN32)
    target_link_libraries(SystemTestsRunner Delayimp nidaqmx nidcpower niDigital nidmm niFgen niRFmxBT niRFmxInstr niRFmxLTE niRFmxNR niRFmxSpecAn niRFmxWLAN niRFSA niRFSG niScope niswitch nisync niTClk nixnet nixntipstack)
    set_target_properties(SystemTestsRunner PROPERTIES LINK_FLAGS "/DELAYLOAD:nicaiu.dll /DELAYLOAD:nidcpower.dll /DELAYLOAD:niDigital_64.dll /DELAYLOAD:nidmm_64.dll /DELAYLOAD:niFgen_64.dll /DELAYLOAD:niRFmxBT.dll /DELAYLOAD:niRFmxInstr.dll /DELAYLOAD:niRFmxLTE.dll /DELAYLOAD:niRFmxNR.dll /DELAYLOAD:niRFmxSpecAn.dll /DELAYLOAD:niRFmxWLAN.dll /DELAYLOAD:niRFSA_64.dll /DELAYLOAD:niRFSG_64.dll /DELAYLOAD:niScope.dll /DELAYLOAD:niswitch.dll /DELAYLOAD:nisync.dll /DELAYLOAD:niTClk_64.dll /DELAYLOAD:nixnet.dll /DELAYLOAD:nixntipstack.dll")
    set(SystemTestsRunner CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /DELAYLOAD:nicaiu.dll /DELAYLOAD:nidcpower.dll /DELAYLOAD:niDigital_64.dll /DELAYLOAD:nidmm_64.dll /DELAYLOAD:niFgen_64.dll /DELAYLOAD:niRFmxBT.dll /DELAYLOAD:niRFmxInstr.dll /DELAYLOAD:niRFmxLTE.dll /DELAYLOAD:niRFmxNR.dll /DELAYLOAD:niRFmxSpecAn.dll /DELAYLOAD:niRFmxWLAN.dll /DELAYLOAD:niRFSA_64.dll /DELAYLOAD:niRFSG_64.dll /DELAYLOAD:niScope.dll /DELAYLOAD:niswitch.dll /DELAYLOAD:nisync.dll /DELAYLOAD:niTClk_64.dll /DELAYLOAD:nixnet.dll /DELAYLOAD:nixntipstack.dll")
endif()

# Hook up different google test runners to CTest
# add_test( NAME UnitTests COMMAND UnitTestsRunner )
add_test( NAME UnitTests COMMAND UnitTestsRunner )
add_test( NAME IntegrationTests COMMAND IntegrationTestsRunner )
add_test( NAME SystemTests COMMAND SystemTestsRunner )
