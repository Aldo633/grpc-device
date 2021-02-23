
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service header for the NI-SCOPE Metadata
//---------------------------------------------------------------------
#ifndef NI_SCOPE_GRPC_SERVICE_H
#define NI_SCOPE_GRPC_SERVICE_H

#include <niscope.grpc.pb.h>
#include <condition_variable>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <map>
#include <server/session_repository.h>
#include <server/shared_library.h>

#include "niscope_library_interface.h"

namespace ni {
namespace scope {
namespace grpc {

class NiScopeService final : public NiScope::Service {
public:
  NiScopeService(NiScopeLibraryInterface* library, ni::hardware::grpc::internal::SessionRepository* session_repository);
  virtual ~NiScopeService();
  ::grpc::Status Abort(::grpc::ServerContext* context, const AbortRequest* request, AbortResponse* response) override;
  ::grpc::Status AcquisitionStatus(::grpc::ServerContext* context, const AcquisitionStatusRequest* request, AcquisitionStatusResponse* response) override;
  ::grpc::Status AddWaveformProcessing(::grpc::ServerContext* context, const AddWaveformProcessingRequest* request, AddWaveformProcessingResponse* response) override;
  ::grpc::Status AutoSetup(::grpc::ServerContext* context, const AutoSetupRequest* request, AutoSetupResponse* response) override;
  ::grpc::Status CalSelfCalibrate(::grpc::ServerContext* context, const CalSelfCalibrateRequest* request, CalSelfCalibrateResponse* response) override;
  ::grpc::Status ClearWaveformMeasurementStats(::grpc::ServerContext* context, const ClearWaveformMeasurementStatsRequest* request, ClearWaveformMeasurementStatsResponse* response) override;
  ::grpc::Status ClearWaveformProcessing(::grpc::ServerContext* context, const ClearWaveformProcessingRequest* request, ClearWaveformProcessingResponse* response) override;
  ::grpc::Status Commit(::grpc::ServerContext* context, const CommitRequest* request, CommitResponse* response) override;
  ::grpc::Status ConfigureChanCharacteristics(::grpc::ServerContext* context, const ConfigureChanCharacteristicsRequest* request, ConfigureChanCharacteristicsResponse* response) override;
  ::grpc::Status ConfigureEqualizationFilterCoefficients(::grpc::ServerContext* context, const ConfigureEqualizationFilterCoefficientsRequest* request, ConfigureEqualizationFilterCoefficientsResponse* response) override;
  ::grpc::Status ConfigureHorizontalTiming(::grpc::ServerContext* context, const ConfigureHorizontalTimingRequest* request, ConfigureHorizontalTimingResponse* response) override;
  ::grpc::Status ConfigureTriggerDigital(::grpc::ServerContext* context, const ConfigureTriggerDigitalRequest* request, ConfigureTriggerDigitalResponse* response) override;
  ::grpc::Status ConfigureTriggerEdge(::grpc::ServerContext* context, const ConfigureTriggerEdgeRequest* request, ConfigureTriggerEdgeResponse* response) override;
  ::grpc::Status ConfigureTriggerHysteresis(::grpc::ServerContext* context, const ConfigureTriggerHysteresisRequest* request, ConfigureTriggerHysteresisResponse* response) override;
  ::grpc::Status ConfigureTriggerImmediate(::grpc::ServerContext* context, const ConfigureTriggerImmediateRequest* request, ConfigureTriggerImmediateResponse* response) override;
  ::grpc::Status ConfigureTriggerSoftware(::grpc::ServerContext* context, const ConfigureTriggerSoftwareRequest* request, ConfigureTriggerSoftwareResponse* response) override;
  ::grpc::Status ConfigureTriggerVideo(::grpc::ServerContext* context, const ConfigureTriggerVideoRequest* request, ConfigureTriggerVideoResponse* response) override;
  ::grpc::Status ConfigureTriggerWindow(::grpc::ServerContext* context, const ConfigureTriggerWindowRequest* request, ConfigureTriggerWindowResponse* response) override;
  ::grpc::Status ConfigureVertical(::grpc::ServerContext* context, const ConfigureVerticalRequest* request, ConfigureVerticalResponse* response) override;
  ::grpc::Status Disable(::grpc::ServerContext* context, const DisableRequest* request, DisableResponse* response) override;
  ::grpc::Status ExportAttributeConfigurationBuffer(::grpc::ServerContext* context, const ExportAttributeConfigurationBufferRequest* request, ExportAttributeConfigurationBufferResponse* response) override;
  ::grpc::Status ExportAttributeConfigurationFile(::grpc::ServerContext* context, const ExportAttributeConfigurationFileRequest* request, ExportAttributeConfigurationFileResponse* response) override;
  ::grpc::Status Fetch(::grpc::ServerContext* context, const FetchRequest* request, FetchResponse* response) override;
  ::grpc::Status FetchArrayMeasurement(::grpc::ServerContext* context, const FetchArrayMeasurementRequest* request, FetchArrayMeasurementResponse* response) override;
  ::grpc::Status FetchBinary16(::grpc::ServerContext* context, const FetchBinary16Request* request, FetchBinary16Response* response) override;
  ::grpc::Status FetchBinary32(::grpc::ServerContext* context, const FetchBinary32Request* request, FetchBinary32Response* response) override;
  ::grpc::Status FetchBinary8(::grpc::ServerContext* context, const FetchBinary8Request* request, FetchBinary8Response* response) override;
  ::grpc::Status FetchMeasurementStats(::grpc::ServerContext* context, const FetchMeasurementStatsRequest* request, FetchMeasurementStatsResponse* response) override;
  ::grpc::Status GetAttributeViBoolean(::grpc::ServerContext* context, const GetAttributeViBooleanRequest* request, GetAttributeViBooleanResponse* response) override;
  ::grpc::Status GetAttributeViInt32(::grpc::ServerContext* context, const GetAttributeViInt32Request* request, GetAttributeViInt32Response* response) override;
  ::grpc::Status GetAttributeViInt64(::grpc::ServerContext* context, const GetAttributeViInt64Request* request, GetAttributeViInt64Response* response) override;
  ::grpc::Status GetAttributeViReal64(::grpc::ServerContext* context, const GetAttributeViReal64Request* request, GetAttributeViReal64Response* response) override;
  ::grpc::Status GetAttributeViString(::grpc::ServerContext* context, const GetAttributeViStringRequest* request, GetAttributeViStringResponse* response) override;
  ::grpc::Status GetEqualizationFilterCoefficients(::grpc::ServerContext* context, const GetEqualizationFilterCoefficientsRequest* request, GetEqualizationFilterCoefficientsResponse* response) override;
  ::grpc::Status ImportAttributeConfigurationBuffer(::grpc::ServerContext* context, const ImportAttributeConfigurationBufferRequest* request, ImportAttributeConfigurationBufferResponse* response) override;
  ::grpc::Status ImportAttributeConfigurationFile(::grpc::ServerContext* context, const ImportAttributeConfigurationFileRequest* request, ImportAttributeConfigurationFileResponse* response) override;
  ::grpc::Status InitWithOptions(::grpc::ServerContext* context, const InitWithOptionsRequest* request, InitWithOptionsResponse* response) override;
  ::grpc::Status InitiateAcquisition(::grpc::ServerContext* context, const InitiateAcquisitionRequest* request, InitiateAcquisitionResponse* response) override;
  ::grpc::Status LockSession(::grpc::ServerContext* context, const LockSessionRequest* request, LockSessionResponse* response) override;
  ::grpc::Status ProbeCompensationSignalStart(::grpc::ServerContext* context, const ProbeCompensationSignalStartRequest* request, ProbeCompensationSignalStartResponse* response) override;
  ::grpc::Status ProbeCompensationSignalStop(::grpc::ServerContext* context, const ProbeCompensationSignalStopRequest* request, ProbeCompensationSignalStopResponse* response) override;
  ::grpc::Status Read(::grpc::ServerContext* context, const ReadRequest* request, ReadResponse* response) override;
  ::grpc::Status ResetDevice(::grpc::ServerContext* context, const ResetDeviceRequest* request, ResetDeviceResponse* response) override;
  ::grpc::Status ResetWithDefaults(::grpc::ServerContext* context, const ResetWithDefaultsRequest* request, ResetWithDefaultsResponse* response) override;
  ::grpc::Status SendSoftwareTriggerEdge(::grpc::ServerContext* context, const SendSoftwareTriggerEdgeRequest* request, SendSoftwareTriggerEdgeResponse* response) override;
  ::grpc::Status SetAttributeViBoolean(::grpc::ServerContext* context, const SetAttributeViBooleanRequest* request, SetAttributeViBooleanResponse* response) override;
  ::grpc::Status SetAttributeViInt32(::grpc::ServerContext* context, const SetAttributeViInt32Request* request, SetAttributeViInt32Response* response) override;
  ::grpc::Status SetAttributeViInt64(::grpc::ServerContext* context, const SetAttributeViInt64Request* request, SetAttributeViInt64Response* response) override;
  ::grpc::Status SetAttributeViReal64(::grpc::ServerContext* context, const SetAttributeViReal64Request* request, SetAttributeViReal64Response* response) override;
  ::grpc::Status SetAttributeViString(::grpc::ServerContext* context, const SetAttributeViStringRequest* request, SetAttributeViStringResponse* response) override;
  ::grpc::Status UnlockSession(::grpc::ServerContext* context, const UnlockSessionRequest* request, UnlockSessionResponse* response) override;
  ::grpc::Status Close(::grpc::ServerContext* context, const CloseRequest* request, CloseResponse* response) override;
  ::grpc::Status Reset(::grpc::ServerContext* context, const ResetRequest* request, ResetResponse* response) override;
  ::grpc::Status SelfTest(::grpc::ServerContext* context, const SelfTestRequest* request, SelfTestResponse* response) override;
  private:
  NiScopeLibraryInterface* library_;
  ni::hardware::grpc::internal::SessionRepository* session_repository_;
};

} // namespace grpc
} // namespace scope
} // namespace ni
#endif  // NI_SCOPE_GRPC_SERVICE_H
