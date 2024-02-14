
#pragma warning(push)
#pragma warning(disable : 4616)
#pragma warning(disable : 4146)
#pragma warning(disable : 4244)
#include <nifake/nifake_service.h>
#pragma warning(pop)

namespace nifake_grpc {

::grpc::Status NiFakeService::ConvertApiErrorStatusForViSession(::grpc::ServerContextBase* context, int32_t status, ViSession vi)
{
  std::string description(nidevice_grpc::kMaxGrpcErrorDescriptionSize, '\0');
  library_->ErrorMessage(vi, status, &description[0]);
  return nidevice_grpc::ApiErrorAndDescriptionToStatus(context, status, description);
}

}  // namespace nifake_grpc
