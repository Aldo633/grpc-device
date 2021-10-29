
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service header for the NI-SCOPE Metadata
//---------------------------------------------------------------------
#ifndef NISCOPE_GRPC_SERVICE_H
#define NISCOPE_GRPC_SERVICE_H

#include <niscope.grpc.pb.h>
#include <condition_variable>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <map>
#include <server/converters.h>
#include <server/feature_toggles.h>
#include <server/session_resource_repository.h>
#include <server/shared_library.h>
#include <server/exceptions.h>

#include "niscope_library_interface.h"

namespace niscope_grpc {

class NiScopeService final : public NiScope::Service {
public:
  using ResourceRepositorySharedPtr = std::shared_ptr<nidevice_grpc::SessionResourceRepository<ViSession>>;

  NiScopeService(
    NiScopeLibraryInterface* library,
    ResourceRepositorySharedPtr session_repository,
    const nidevice_grpc::FeatureToggles& feature_toggles = {});
  virtual ~NiScopeService();
  
  ::grpc::Status Abort(::grpc::ServerContext* context, const AbortRequest* request, AbortResponse* response) override;
  ::grpc::Status AcquisitionStatus(::grpc::ServerContext* context, const AcquisitionStatusRequest* request, AcquisitionStatusResponse* response) override;
  ::grpc::Status ActualMeasWfmSize(::grpc::ServerContext* context, const ActualMeasWfmSizeRequest* request, ActualMeasWfmSizeResponse* response) override;
  ::grpc::Status ActualNumWfms(::grpc::ServerContext* context, const ActualNumWfmsRequest* request, ActualNumWfmsResponse* response) override;
  ::grpc::Status ActualRecordLength(::grpc::ServerContext* context, const ActualRecordLengthRequest* request, ActualRecordLengthResponse* response) override;
  ::grpc::Status AddWaveformProcessing(::grpc::ServerContext* context, const AddWaveformProcessingRequest* request, AddWaveformProcessingResponse* response) override;
  ::grpc::Status AdjustSampleClockRelativeDelay(::grpc::ServerContext* context, const AdjustSampleClockRelativeDelayRequest* request, AdjustSampleClockRelativeDelayResponse* response) override;
  ::grpc::Status AutoSetup(::grpc::ServerContext* context, const AutoSetupRequest* request, AutoSetupResponse* response) override;
  ::grpc::Status CableSenseSignalStart(::grpc::ServerContext* context, const CableSenseSignalStartRequest* request, CableSenseSignalStartResponse* response) override;
  ::grpc::Status CableSenseSignalStop(::grpc::ServerContext* context, const CableSenseSignalStopRequest* request, CableSenseSignalStopResponse* response) override;
  ::grpc::Status CalSelfCalibrate(::grpc::ServerContext* context, const CalSelfCalibrateRequest* request, CalSelfCalibrateResponse* response) override;
  ::grpc::Status CheckAttributeViBoolean(::grpc::ServerContext* context, const CheckAttributeViBooleanRequest* request, CheckAttributeViBooleanResponse* response) override;
  ::grpc::Status CheckAttributeViInt32(::grpc::ServerContext* context, const CheckAttributeViInt32Request* request, CheckAttributeViInt32Response* response) override;
  ::grpc::Status CheckAttributeViInt64(::grpc::ServerContext* context, const CheckAttributeViInt64Request* request, CheckAttributeViInt64Response* response) override;
  ::grpc::Status CheckAttributeViReal64(::grpc::ServerContext* context, const CheckAttributeViReal64Request* request, CheckAttributeViReal64Response* response) override;
  ::grpc::Status CheckAttributeViSession(::grpc::ServerContext* context, const CheckAttributeViSessionRequest* request, CheckAttributeViSessionResponse* response) override;
  ::grpc::Status CheckAttributeViString(::grpc::ServerContext* context, const CheckAttributeViStringRequest* request, CheckAttributeViStringResponse* response) override;
  ::grpc::Status ClearWaveformMeasurementStats(::grpc::ServerContext* context, const ClearWaveformMeasurementStatsRequest* request, ClearWaveformMeasurementStatsResponse* response) override;
  ::grpc::Status ClearWaveformProcessing(::grpc::ServerContext* context, const ClearWaveformProcessingRequest* request, ClearWaveformProcessingResponse* response) override;
  ::grpc::Status Close(::grpc::ServerContext* context, const CloseRequest* request, CloseResponse* response) override;
  ::grpc::Status Commit(::grpc::ServerContext* context, const CommitRequest* request, CommitResponse* response) override;
  ::grpc::Status ConfigureAcquisition(::grpc::ServerContext* context, const ConfigureAcquisitionRequest* request, ConfigureAcquisitionResponse* response) override;
  ::grpc::Status ConfigureChanCharacteristics(::grpc::ServerContext* context, const ConfigureChanCharacteristicsRequest* request, ConfigureChanCharacteristicsResponse* response) override;
  ::grpc::Status ConfigureClock(::grpc::ServerContext* context, const ConfigureClockRequest* request, ConfigureClockResponse* response) override;
  ::grpc::Status ConfigureEqualizationFilterCoefficients(::grpc::ServerContext* context, const ConfigureEqualizationFilterCoefficientsRequest* request, ConfigureEqualizationFilterCoefficientsResponse* response) override;
  ::grpc::Status ConfigureHorizontalTiming(::grpc::ServerContext* context, const ConfigureHorizontalTimingRequest* request, ConfigureHorizontalTimingResponse* response) override;
  ::grpc::Status ConfigureTriggerDigital(::grpc::ServerContext* context, const ConfigureTriggerDigitalRequest* request, ConfigureTriggerDigitalResponse* response) override;
  ::grpc::Status ConfigureTriggerEdge(::grpc::ServerContext* context, const ConfigureTriggerEdgeRequest* request, ConfigureTriggerEdgeResponse* response) override;
  ::grpc::Status ConfigureTriggerGlitch(::grpc::ServerContext* context, const ConfigureTriggerGlitchRequest* request, ConfigureTriggerGlitchResponse* response) override;
  ::grpc::Status ConfigureTriggerHysteresis(::grpc::ServerContext* context, const ConfigureTriggerHysteresisRequest* request, ConfigureTriggerHysteresisResponse* response) override;
  ::grpc::Status ConfigureTriggerImmediate(::grpc::ServerContext* context, const ConfigureTriggerImmediateRequest* request, ConfigureTriggerImmediateResponse* response) override;
  ::grpc::Status ConfigureTriggerRunt(::grpc::ServerContext* context, const ConfigureTriggerRuntRequest* request, ConfigureTriggerRuntResponse* response) override;
  ::grpc::Status ConfigureTriggerSoftware(::grpc::ServerContext* context, const ConfigureTriggerSoftwareRequest* request, ConfigureTriggerSoftwareResponse* response) override;
  ::grpc::Status ConfigureTriggerVideo(::grpc::ServerContext* context, const ConfigureTriggerVideoRequest* request, ConfigureTriggerVideoResponse* response) override;
  ::grpc::Status ConfigureTriggerWidth(::grpc::ServerContext* context, const ConfigureTriggerWidthRequest* request, ConfigureTriggerWidthResponse* response) override;
  ::grpc::Status ConfigureTriggerWindow(::grpc::ServerContext* context, const ConfigureTriggerWindowRequest* request, ConfigureTriggerWindowResponse* response) override;
  ::grpc::Status ConfigureVertical(::grpc::ServerContext* context, const ConfigureVerticalRequest* request, ConfigureVerticalResponse* response) override;
  ::grpc::Status Disable(::grpc::ServerContext* context, const DisableRequest* request, DisableResponse* response) override;
  ::grpc::Status ErrorHandler(::grpc::ServerContext* context, const ErrorHandlerRequest* request, ErrorHandlerResponse* response) override;
  ::grpc::Status ExportAttributeConfigurationBuffer(::grpc::ServerContext* context, const ExportAttributeConfigurationBufferRequest* request, ExportAttributeConfigurationBufferResponse* response) override;
  ::grpc::Status ExportAttributeConfigurationFile(::grpc::ServerContext* context, const ExportAttributeConfigurationFileRequest* request, ExportAttributeConfigurationFileResponse* response) override;
  ::grpc::Status ExportSignal(::grpc::ServerContext* context, const ExportSignalRequest* request, ExportSignalResponse* response) override;
  ::grpc::Status Fetch(::grpc::ServerContext* context, const FetchRequest* request, FetchResponse* response) override;
  ::grpc::Status FetchArrayMeasurement(::grpc::ServerContext* context, const FetchArrayMeasurementRequest* request, FetchArrayMeasurementResponse* response) override;
  ::grpc::Status FetchBinary16(::grpc::ServerContext* context, const FetchBinary16Request* request, FetchBinary16Response* response) override;
  ::grpc::Status FetchBinary32(::grpc::ServerContext* context, const FetchBinary32Request* request, FetchBinary32Response* response) override;
  ::grpc::Status FetchBinary8(::grpc::ServerContext* context, const FetchBinary8Request* request, FetchBinary8Response* response) override;
  ::grpc::Status FetchComplex(::grpc::ServerContext* context, const FetchComplexRequest* request, FetchComplexResponse* response) override;
  ::grpc::Status FetchComplexBinary16(::grpc::ServerContext* context, const FetchComplexBinary16Request* request, FetchComplexBinary16Response* response) override;
  ::grpc::Status FetchMeasurement(::grpc::ServerContext* context, const FetchMeasurementRequest* request, FetchMeasurementResponse* response) override;
  ::grpc::Status FetchMeasurementStats(::grpc::ServerContext* context, const FetchMeasurementStatsRequest* request, FetchMeasurementStatsResponse* response) override;
  ::grpc::Status GetAttributeViBoolean(::grpc::ServerContext* context, const GetAttributeViBooleanRequest* request, GetAttributeViBooleanResponse* response) override;
  ::grpc::Status GetAttributeViInt32(::grpc::ServerContext* context, const GetAttributeViInt32Request* request, GetAttributeViInt32Response* response) override;
  ::grpc::Status GetAttributeViInt64(::grpc::ServerContext* context, const GetAttributeViInt64Request* request, GetAttributeViInt64Response* response) override;
  ::grpc::Status GetAttributeViReal64(::grpc::ServerContext* context, const GetAttributeViReal64Request* request, GetAttributeViReal64Response* response) override;
  ::grpc::Status GetAttributeViSession(::grpc::ServerContext* context, const GetAttributeViSessionRequest* request, GetAttributeViSessionResponse* response) override;
  ::grpc::Status GetAttributeViString(::grpc::ServerContext* context, const GetAttributeViStringRequest* request, GetAttributeViStringResponse* response) override;
  ::grpc::Status GetChannelName(::grpc::ServerContext* context, const GetChannelNameRequest* request, GetChannelNameResponse* response) override;
  ::grpc::Status GetChannelNameFromString(::grpc::ServerContext* context, const GetChannelNameFromStringRequest* request, GetChannelNameFromStringResponse* response) override;
  ::grpc::Status GetEqualizationFilterCoefficients(::grpc::ServerContext* context, const GetEqualizationFilterCoefficientsRequest* request, GetEqualizationFilterCoefficientsResponse* response) override;
  ::grpc::Status GetError(::grpc::ServerContext* context, const GetErrorRequest* request, GetErrorResponse* response) override;
  ::grpc::Status GetErrorMessage(::grpc::ServerContext* context, const GetErrorMessageRequest* request, GetErrorMessageResponse* response) override;
  ::grpc::Status GetFrequencyResponse(::grpc::ServerContext* context, const GetFrequencyResponseRequest* request, GetFrequencyResponseResponse* response) override;
  ::grpc::Status GetNormalizationCoefficients(::grpc::ServerContext* context, const GetNormalizationCoefficientsRequest* request, GetNormalizationCoefficientsResponse* response) override;
  ::grpc::Status GetScalingCoefficients(::grpc::ServerContext* context, const GetScalingCoefficientsRequest* request, GetScalingCoefficientsResponse* response) override;
  ::grpc::Status GetStreamEndpointHandle(::grpc::ServerContext* context, const GetStreamEndpointHandleRequest* request, GetStreamEndpointHandleResponse* response) override;
  ::grpc::Status ImportAttributeConfigurationBuffer(::grpc::ServerContext* context, const ImportAttributeConfigurationBufferRequest* request, ImportAttributeConfigurationBufferResponse* response) override;
  ::grpc::Status ImportAttributeConfigurationFile(::grpc::ServerContext* context, const ImportAttributeConfigurationFileRequest* request, ImportAttributeConfigurationFileResponse* response) override;
  ::grpc::Status Init(::grpc::ServerContext* context, const InitRequest* request, InitResponse* response) override;
  ::grpc::Status InitWithOptions(::grpc::ServerContext* context, const InitWithOptionsRequest* request, InitWithOptionsResponse* response) override;
  ::grpc::Status InitiateAcquisition(::grpc::ServerContext* context, const InitiateAcquisitionRequest* request, InitiateAcquisitionResponse* response) override;
  ::grpc::Status ProbeCompensationSignalStart(::grpc::ServerContext* context, const ProbeCompensationSignalStartRequest* request, ProbeCompensationSignalStartResponse* response) override;
  ::grpc::Status ProbeCompensationSignalStop(::grpc::ServerContext* context, const ProbeCompensationSignalStopRequest* request, ProbeCompensationSignalStopResponse* response) override;
  ::grpc::Status Read(::grpc::ServerContext* context, const ReadRequest* request, ReadResponse* response) override;
  ::grpc::Status ReadMeasurement(::grpc::ServerContext* context, const ReadMeasurementRequest* request, ReadMeasurementResponse* response) override;
  ::grpc::Status Reset(::grpc::ServerContext* context, const ResetRequest* request, ResetResponse* response) override;
  ::grpc::Status ResetDevice(::grpc::ServerContext* context, const ResetDeviceRequest* request, ResetDeviceResponse* response) override;
  ::grpc::Status RevisionQuery(::grpc::ServerContext* context, const RevisionQueryRequest* request, RevisionQueryResponse* response) override;
  ::grpc::Status SampleMode(::grpc::ServerContext* context, const SampleModeRequest* request, SampleModeResponse* response) override;
  ::grpc::Status SampleRate(::grpc::ServerContext* context, const SampleRateRequest* request, SampleRateResponse* response) override;
  ::grpc::Status SelfTest(::grpc::ServerContext* context, const SelfTestRequest* request, SelfTestResponse* response) override;
  ::grpc::Status SendSoftwareTriggerEdge(::grpc::ServerContext* context, const SendSoftwareTriggerEdgeRequest* request, SendSoftwareTriggerEdgeResponse* response) override;
  ::grpc::Status SetAttributeViBoolean(::grpc::ServerContext* context, const SetAttributeViBooleanRequest* request, SetAttributeViBooleanResponse* response) override;
  ::grpc::Status SetAttributeViInt32(::grpc::ServerContext* context, const SetAttributeViInt32Request* request, SetAttributeViInt32Response* response) override;
  ::grpc::Status SetAttributeViInt64(::grpc::ServerContext* context, const SetAttributeViInt64Request* request, SetAttributeViInt64Response* response) override;
  ::grpc::Status SetAttributeViReal64(::grpc::ServerContext* context, const SetAttributeViReal64Request* request, SetAttributeViReal64Response* response) override;
  ::grpc::Status SetAttributeViSession(::grpc::ServerContext* context, const SetAttributeViSessionRequest* request, SetAttributeViSessionResponse* response) override;
  ::grpc::Status SetAttributeViString(::grpc::ServerContext* context, const SetAttributeViStringRequest* request, SetAttributeViStringResponse* response) override;

  bool is_enabled();
private:
  NiScopeLibraryInterface* library_;
  ResourceRepositorySharedPtr session_repository_;

  struct NiScopeFeatureToggles
  {
    using CodeReadiness = nidevice_grpc::FeatureToggles::CodeReadiness;
    NiScopeFeatureToggles(const nidevice_grpc::FeatureToggles& feature_toggles);

    bool is_enabled;
  };

  NiScopeFeatureToggles feature_toggles_;
};

} // namespace niscope_grpc

namespace nidevice_grpc {
namespace converters {
template <>
void convert_to_grpc(const niScope_wfmInfo& input, niscope_grpc::WaveformInfo* output);
template <>
void convert_to_grpc(const niScope_coefficientInfo& input, niscope_grpc::CoefficientInfo* output);
} // namespace converters
} // namespace nidevice_grpc

#endif  // NISCOPE_GRPC_SERVICE_H
