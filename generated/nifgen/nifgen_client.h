
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// EXPERIMENTAL Client convenience wrapper for NI-FGEN.
//---------------------------------------------------------------------
#ifndef NIFGEN_GRPC_CLIENT_H
#define NIFGEN_GRPC_CLIENT_H

#include <grpcpp/grpcpp.h>

#include <nifgen.grpc.pb.h>
#include <tests/utilities/client_helpers.h>

#include <memory>
#include <vector>

namespace nifgen_grpc::experimental::client {

namespace pb = ::google::protobuf;
using StubPtr = std::unique_ptr<NiFgen::Stub>;
using namespace nidevice_grpc::experimental::client;


AbortGenerationResponse abort_generation(const StubPtr& stub, const nidevice_grpc::Session& vi);
AdjustSampleClockRelativeDelayResponse adjust_sample_clock_relative_delay(const StubPtr& stub, const nidevice_grpc::Session& vi, const double& adjustment_time);
AllocateNamedWaveformResponse allocate_named_waveform(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const pb::string& waveform_name, const pb::int32& waveform_size);
AllocateWaveformResponse allocate_waveform(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const pb::int32& waveform_size);
CheckAttributeViBooleanResponse check_attribute_vi_boolean(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiFgenAttributes& attribute_id, const bool& attribute_value);
CheckAttributeViInt32Response check_attribute_vi_int32(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiFgenAttributes& attribute_id, const simple_variant<NiFgenInt32AttributeValues, pb::int32>& attribute_value);
CheckAttributeViInt64Response check_attribute_vi_int64(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiFgenAttributes& attribute_id, const pb::int64& attribute_value_raw);
CheckAttributeViReal64Response check_attribute_vi_real64(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiFgenAttributes& attribute_id, const simple_variant<NiFgenReal64AttributeValues, double>& attribute_value);
CheckAttributeViSessionResponse check_attribute_vi_session(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiFgenAttributes& attribute_id, const nidevice_grpc::Session& attribute_value);
CheckAttributeViStringResponse check_attribute_vi_string(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiFgenAttributes& attribute_id, const pb::string& attribute_value_raw);
ClearArbMemoryResponse clear_arb_memory(const StubPtr& stub, const nidevice_grpc::Session& vi);
ClearArbSequenceResponse clear_arb_sequence(const StubPtr& stub, const nidevice_grpc::Session& vi, const simple_variant<SequenceHandle, pb::int32>& sequence_handle);
ClearArbWaveformResponse clear_arb_waveform(const StubPtr& stub, const nidevice_grpc::Session& vi, const simple_variant<WaveformHandle, pb::int32>& waveform_handle);
ClearErrorResponse clear_error(const StubPtr& stub, const nidevice_grpc::Session& vi);
ClearFreqListResponse clear_freq_list(const StubPtr& stub, const nidevice_grpc::Session& vi, const simple_variant<FrequencyListOptions, pb::int32>& frequency_list_handle);
ClearInterchangeWarningsResponse clear_interchange_warnings(const StubPtr& stub, const nidevice_grpc::Session& vi);
ClearUserStandardWaveformResponse clear_user_standard_waveform(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name);
CloseResponse close(const StubPtr& stub, const nidevice_grpc::Session& vi);
CommitResponse commit(const StubPtr& stub, const nidevice_grpc::Session& vi);
ConfigureAmplitudeResponse configure_amplitude(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const double& amplitude);
ConfigureArbSequenceResponse configure_arb_sequence(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const pb::int32& sequence_handle, const double& gain, const double& offset);
ConfigureArbWaveformResponse configure_arb_waveform(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const pb::int32& waveform_handle, const double& gain, const double& offset);
ConfigureChannelsResponse configure_channels(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channels);
ConfigureClockModeResponse configure_clock_mode(const StubPtr& stub, const nidevice_grpc::Session& vi, const simple_variant<ClockMode, pb::int32>& clock_mode);
ConfigureCustomFIRFilterCoefficientsResponse configure_custom_fir_filter_coefficients(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const std::vector<double>& coefficients_array);
ConfigureDigitalEdgeScriptTriggerResponse configure_digital_edge_script_trigger(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& trigger_id, const pb::string& source, const pb::int32& edge);
ConfigureDigitalEdgeStartTriggerResponse configure_digital_edge_start_trigger(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& source, const pb::int32& edge);
ConfigureDigitalLevelScriptTriggerResponse configure_digital_level_script_trigger(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& trigger_id, const pb::string& source, const pb::int32& trigger_when);
ConfigureFreqListResponse configure_freq_list(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const pb::int32& frequency_list_handle, const double& amplitude, const double& dc_offset, const double& start_phase);
ConfigureFrequencyResponse configure_frequency(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const double& frequency);
ConfigureOperationModeResponse configure_operation_mode(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const pb::int32& operation_mode);
ConfigureOutputEnabledResponse configure_output_enabled(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const bool& enabled);
ConfigureOutputImpedanceResponse configure_output_impedance(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const double& impedance);
ConfigureOutputModeResponse configure_output_mode(const StubPtr& stub, const nidevice_grpc::Session& vi, const simple_variant<OutputMode, pb::int32>& output_mode);
ConfigureP2PEndpointFullnessStartTriggerResponse configure_p2p_endpoint_fullness_start_trigger(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int32& p2p_endpoint_fullness_level);
ConfigureReferenceClockResponse configure_reference_clock(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& reference_clock_source, const double& reference_clock_frequency);
ConfigureSampleClockSourceResponse configure_sample_clock_source(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& sample_clock_source);
ConfigureSampleRateResponse configure_sample_rate(const StubPtr& stub, const nidevice_grpc::Session& vi, const double& sample_rate);
ConfigureSoftwareEdgeScriptTriggerResponse configure_software_edge_script_trigger(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& trigger_id);
ConfigureSoftwareEdgeStartTriggerResponse configure_software_edge_start_trigger(const StubPtr& stub, const nidevice_grpc::Session& vi);
ConfigureStandardWaveformResponse configure_standard_waveform(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const simple_variant<Waveform, pb::int32>& waveform, const double& amplitude, const double& dc_offset, const double& frequency, const double& start_phase);
ConfigureSynchronizationResponse configure_synchronization(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const pb::int32& synchronization_source);
ConfigureTriggerModeResponse configure_trigger_mode(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const simple_variant<TriggerMode, pb::int32>& trigger_mode);
CreateAdvancedArbSequenceResponse create_advanced_arb_sequence(const StubPtr& stub, const nidevice_grpc::Session& vi, const std::vector<pb::int32>& waveform_handles_array, const std::vector<pb::int32>& loop_counts_array, const std::vector<pb::int32>& sample_counts_array, const std::vector<pb::int32>& marker_location_array);
CreateArbSequenceResponse create_arb_sequence(const StubPtr& stub, const nidevice_grpc::Session& vi, const std::vector<pb::int32>& waveform_handles_array, const std::vector<pb::int32>& loop_counts_array);
CreateFreqListResponse create_freq_list(const StubPtr& stub, const nidevice_grpc::Session& vi, const simple_variant<Waveform, pb::int32>& waveform, const std::vector<double>& frequency_array, const std::vector<double>& duration_array);
CreateWaveformComplexF64Response create_waveform_complex_f64(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const std::vector<nidevice_grpc::NIComplexNumber>& waveform_data_array);
CreateWaveformF64Response create_waveform_f64(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const std::vector<double>& waveform_data_array);
CreateWaveformFromFileF64Response create_waveform_from_file_f64(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const pb::string& file_name, const simple_variant<ByteOrder, pb::int32>& byte_order);
CreateWaveformFromFileHWSResponse create_waveform_from_file_hws(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const pb::string& file_name, const bool& use_rate_from_waveform, const bool& use_gain_and_offset_from_waveform);
CreateWaveformI16Response create_waveform_i16(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const std::vector<pb::int32>& waveform_data_array);
CreateWaveformFromFileI16Response create_waveform_from_file_i16(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const pb::string& file_name, const simple_variant<ByteOrder, pb::int32>& byte_order);
DefineUserStandardWaveformResponse define_user_standard_waveform(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const std::vector<double>& waveform_data_array);
DeleteNamedWaveformResponse delete_named_waveform(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const pb::string& waveform_name);
DeleteScriptResponse delete_script(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const pb::string& script_name);
DisableResponse disable(const StubPtr& stub, const nidevice_grpc::Session& vi);
DisableAnalogFilterResponse disable_analog_filter(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name);
DisableDigitalFilterResponse disable_digital_filter(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name);
DisableDigitalPatterningResponse disable_digital_patterning(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name);
DisableScriptTriggerResponse disable_script_trigger(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& trigger_id);
DisableStartTriggerResponse disable_start_trigger(const StubPtr& stub, const nidevice_grpc::Session& vi);
EnableAnalogFilterResponse enable_analog_filter(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const double& filter_correction_frequency);
EnableDigitalFilterResponse enable_digital_filter(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name);
EnableDigitalPatterningResponse enable_digital_patterning(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name);
ErrorHandlerResponse error_handler(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int32& error_code);
ErrorMessageResponse error_message(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int32& error_code);
ErrorQueryResponse error_query(const StubPtr& stub, const nidevice_grpc::Session& vi);
ExportAttributeConfigurationBufferResponse export_attribute_configuration_buffer(const StubPtr& stub, const nidevice_grpc::Session& vi);
ExportAttributeConfigurationFileResponse export_attribute_configuration_file(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& file_path);
ExportSignalResponse export_signal(const StubPtr& stub, const nidevice_grpc::Session& vi, const simple_variant<Signal, pb::int32>& signal, const pb::string& signal_identifier, const pb::string& output_terminal);
GetAttributeViBooleanResponse get_attribute_vi_boolean(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiFgenAttributes& attribute_id);
GetAttributeViInt32Response get_attribute_vi_int32(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiFgenAttributes& attribute_id);
GetAttributeViInt64Response get_attribute_vi_int64(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiFgenAttributes& attribute_id);
GetAttributeViReal64Response get_attribute_vi_real64(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiFgenAttributes& attribute_id);
GetAttributeViSessionResponse get_attribute_vi_session(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiFgenAttributes& attribute_id);
GetAttributeViStringResponse get_attribute_vi_string(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiFgenAttributes& attribute_id);
GetChannelNameResponse get_channel_name(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int32& index);
GetErrorResponse get_error(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetExtCalLastDateAndTimeResponse get_ext_cal_last_date_and_time(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetExtCalLastTempResponse get_ext_cal_last_temp(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetExtCalRecommendedIntervalResponse get_ext_cal_recommended_interval(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetFIRFilterCoefficientsResponse get_fir_filter_coefficients(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name);
GetHardwareStateResponse get_hardware_state(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetNextCoercionRecordResponse get_next_coercion_record(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetNextInterchangeWarningResponse get_next_interchange_warning(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetSelfCalLastDateAndTimeResponse get_self_cal_last_date_and_time(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetSelfCalLastTempResponse get_self_cal_last_temp(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetSelfCalSupportedResponse get_self_cal_supported(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetStreamEndpointHandleResponse get_stream_endpoint_handle(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& stream_endpoint);
ImportAttributeConfigurationBufferResponse import_attribute_configuration_buffer(const StubPtr& stub, const nidevice_grpc::Session& vi, const std::vector<pb::uint64>& configuration);
ImportAttributeConfigurationFileResponse import_attribute_configuration_file(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& file_path);
InitResponse init(const StubPtr& stub, const pb::string& resource_name, const bool& id_query, const bool& reset_device);
InitWithOptionsResponse init_with_options(const StubPtr& stub, const pb::string& resource_name, const bool& id_query, const bool& reset_device, const pb::string& option_string);
InitializeWithChannelsResponse initialize_with_channels(const StubPtr& stub, const pb::string& resource_name, const pb::string& channel_name, const bool& reset_device, const pb::string& option_string);
InitiateGenerationResponse initiate_generation(const StubPtr& stub, const nidevice_grpc::Session& vi);
InvalidateAllAttributesResponse invalidate_all_attributes(const StubPtr& stub, const nidevice_grpc::Session& vi);
IsDoneResponse is_done(const StubPtr& stub, const nidevice_grpc::Session& vi);
ManualEnableP2PStreamResponse manual_enable_p2p_stream(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& endpoint_name);
QueryArbSeqCapabilitiesResponse query_arb_seq_capabilities(const StubPtr& stub, const nidevice_grpc::Session& vi);
QueryArbWfmCapabilitiesResponse query_arb_wfm_capabilities(const StubPtr& stub, const nidevice_grpc::Session& vi);
QueryFreqListCapabilitiesResponse query_freq_list_capabilities(const StubPtr& stub, const nidevice_grpc::Session& vi);
ReadCurrentTemperatureResponse read_current_temperature(const StubPtr& stub, const nidevice_grpc::Session& vi);
ResetResponse reset(const StubPtr& stub, const nidevice_grpc::Session& vi);
ResetAttributeResponse reset_attribute(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiFgenAttributes& attribute_id);
ResetDeviceResponse reset_device(const StubPtr& stub, const nidevice_grpc::Session& vi);
ResetInterchangeCheckResponse reset_interchange_check(const StubPtr& stub, const nidevice_grpc::Session& vi);
ResetWithDefaultsResponse reset_with_defaults(const StubPtr& stub, const nidevice_grpc::Session& vi);
RevisionQueryResponse revision_query(const StubPtr& stub, const nidevice_grpc::Session& vi);
RouteSignalOutResponse route_signal_out(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const simple_variant<RouteSignalFrom, pb::int32>& route_signal_from, const simple_variant<RouteSignalTo, pb::int32>& route_signal_to);
SelfCalResponse self_cal(const StubPtr& stub, const nidevice_grpc::Session& vi);
SelfTestResponse self_test(const StubPtr& stub, const nidevice_grpc::Session& vi);
SendSoftwareEdgeTriggerResponse send_software_edge_trigger(const StubPtr& stub, const nidevice_grpc::Session& vi, const simple_variant<Trigger, pb::int32>& trigger, const pb::string& trigger_id);
SetAttributeViBooleanResponse set_attribute_vi_boolean(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiFgenAttributes& attribute_id, const bool& attribute_value);
SetAttributeViInt32Response set_attribute_vi_int32(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiFgenAttributes& attribute_id, const simple_variant<NiFgenInt32AttributeValues, pb::int32>& attribute_value);
SetAttributeViInt64Response set_attribute_vi_int64(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiFgenAttributes& attribute_id, const pb::int64& attribute_value_raw);
SetAttributeViReal64Response set_attribute_vi_real64(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiFgenAttributes& attribute_id, const simple_variant<NiFgenReal64AttributeValues, double>& attribute_value);
SetAttributeViSessionResponse set_attribute_vi_session(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiFgenAttributes& attribute_id, const nidevice_grpc::Session& attribute_value);
SetAttributeViStringResponse set_attribute_vi_string(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiFgenAttributes& attribute_id, const pb::string& attribute_value_raw);
SetNamedWaveformNextWritePositionResponse set_named_waveform_next_write_position(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const pb::string& waveform_name, const simple_variant<RelativeTo, pb::int32>& relative_to, const pb::int32& offset);
SetWaveformNextWritePositionResponse set_waveform_next_write_position(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const pb::int32& waveform_handle, const simple_variant<RelativeTo, pb::int32>& relative_to, const pb::int32& offset);
WaitUntilDoneResponse wait_until_done(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int32& max_time);
WriteBinary16WaveformResponse write_binary16_waveform(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const pb::int32& waveform_handle, const std::vector<pb::int32>& data);
WriteComplexBinary16WaveformResponse write_complex_binary16_waveform(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const pb::int32& waveform_handle, const std::vector<nidevice_grpc::NIComplexI16>& data);
WriteNamedWaveformF64Response write_named_waveform_f64(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const pb::string& waveform_name, const std::vector<double>& data);
WriteNamedWaveformI16Response write_named_waveform_i16(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const pb::string& waveform_name, const std::vector<pb::int32>& data);
WriteP2PEndpointI16Response write_p2p_endpoint_i16(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& endpoint_name, const std::vector<pb::int32>& endpoint_data);
WriteScriptResponse write_script(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const pb::string& script);
WriteWaveformResponse write_waveform(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const pb::int32& waveform_handle, const std::vector<double>& data);
WriteWaveformComplexF64Response write_waveform_complex_f64(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const std::vector<nidevice_grpc::NIComplexNumber>& data, const pb::int32& waveform_handle);
WriteNamedWaveformComplexF64Response write_named_waveform_complex_f64(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const pb::string& waveform_name, const std::vector<nidevice_grpc::NIComplexNumber>& data);
WriteNamedWaveformComplexI16Response write_named_waveform_complex_i16(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const pb::string& waveform_name, const std::vector<nidevice_grpc::NIComplexI16>& data);

} // namespace nifgen_grpc::experimental::client

#endif /* NIFGEN_GRPC_CLIENT_H */
