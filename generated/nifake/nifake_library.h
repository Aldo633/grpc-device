//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Real implementation of LibraryInterface for NI-FAKE
//---------------------------------------------------------------------
#ifndef NI_FAKE_GRPC_LIBRARY_H
#define NI_FAKE_GRPC_LIBRARY_H

#include "nifake_library_interface.h"

#include <server/shared_library.h>

namespace ni {
namespace fake {
namespace grpc {

class NiFakeLibrary : public ni::fake::grpc::NiFakeLibraryInterface {
 public:
  NiFakeLibrary();
  virtual ~NiFakeLibrary();

  ::grpc::Status check_function_exists(std::string functionName);
  ViStatus Abort(ViSession vi);
  ViStatus AcceptListOfDurationsInSeconds(ViSession vi, ViInt32 count, ViReal64 delays[]);
  ViStatus BoolArrayOutputFunction(ViSession vi, ViInt32 numberOfElements, ViBoolean anArray[]);
  ViStatus DoubleAllTheNums(ViSession vi, ViInt32 numberCount, ViReal64 numbers[]);
  ViStatus EnumArrayOutputFunction(ViSession vi, ViInt32 numberOfElements, ViInt16 anArray[]);
  ViStatus EnumInputFunctionWithDefaults(ViSession vi, ViInt16 aTurtle);
  ViStatus ExportAttributeConfigurationBuffer(ViSession vi, ViInt32 sizeInBytes, ViInt8 configuration[]);
  ViStatus FetchWaveform(ViSession vi, ViInt32 numberOfSamples, ViReal64 waveformData[], ViInt32* actualNumberOfSamples);
  ViStatus GetABoolean(ViSession vi, ViBoolean* aBoolean);
  ViStatus GetANumber(ViSession vi, ViInt16* aNumber);
  ViStatus GetAStringOfFixedMaximumSize(ViSession vi, ViChar aString[256]);
  ViStatus GetAStringUsingPythonCode(ViSession vi, ViInt16 aNumber, ViChar aString[]);
  ViStatus GetAnIviDanceString(ViSession vi, ViInt32 bufferSize, ViChar aString[]);
  ViStatus GetAnIviDanceWithATwistString(ViSession vi, ViInt32 bufferSize, ViChar aString[], ViInt32* actualSize);
  ViStatus GetArrayForPythonCodeCustomType(ViSession vi, ViInt32 numberOfElements, struct CustomStruct arrayOut[]);
  ViStatus GetArrayForPythonCodeDouble(ViSession vi, ViInt32 numberOfElements, ViReal64 arrayOut[]);
  ViStatus GetArraySizeForPythonCode(ViSession vi, ViInt32* sizeOut);
  ViStatus GetArrayUsingIviDance(ViSession vi, ViInt32 arraySize, ViReal64 arrayOut[]);
  ViStatus GetAttributeViBoolean(ViSession vi, ViConstString channelName, ViAttr attributeId, ViBoolean* attributeValue);
  ViStatus GetAttributeViInt32(ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32* attributeValue);
  ViStatus GetAttributeViInt64(ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt64* attributeValue);
  ViStatus GetAttributeViReal64(ViSession vi, ViConstString channelName, ViAttr attributeId, ViReal64* attributeValue);
  ViStatus GetAttributeViString(ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32 bufferSize, ViChar attributeValue[]);
  ViStatus GetCalDateAndTime(ViSession vi, ViInt32 calType, ViInt32* month, ViInt32* day, ViInt32* year, ViInt32* hour, ViInt32* minute);
  ViStatus GetCalInterval(ViSession vi, ViInt32* months);
  ViStatus GetCustomType(ViSession vi, struct CustomStruct* cs);
  ViStatus GetCustomTypeArray(ViSession vi, ViInt32 numberOfElements, struct CustomStruct cs[]);
  ViStatus GetEnumValue(ViSession vi, ViInt32* aQuantity, ViInt16* aTurtle);
  ViStatus GetError(ViSession vi, ViStatus* errorCode, ViInt32 bufferSize, ViChar description[]);
  ViStatus ImportAttributeConfigurationBuffer(ViSession vi, ViInt32 sizeInBytes, ViInt8 configuration[]);
  ViStatus InitWithOptions(ViString resourceName, ViBoolean idQuery, ViBoolean resetDevice, ViConstString optionString, ViSession* vi);
  ViStatus Initiate(ViSession vi);
  ViStatus MultipleArrayTypes(ViSession vi, ViInt32 outputArraySize, ViReal64 outputArray[], ViReal64 outputArrayOfFixedLength[3], ViInt32 inputArraySizes, ViReal64 inputArrayOfFloats[], ViInt16 inputArrayOfIntegers[]);
  ViStatus MultipleArraysSameSize(ViSession vi, ViReal64 values1[], ViReal64 values2[], ViReal64 values3[], ViReal64 values4[], ViInt32 size);
  ViStatus OneInputFunction(ViSession vi, ViInt32 aNumber);
  ViStatus ParametersAreMultipleTypes(ViSession vi, ViBoolean aBoolean, ViInt32 anInt32, ViInt64 anInt64, ViInt16 anIntEnum, ViReal64 aFloat, ViReal64 aFloatEnum, ViInt32 stringSize, ViConstString aString);
  ViStatus PoorlyNamedSimpleFunction(ViSession vi);
  ViStatus Read(ViSession vi, ViReal64 maximumTime, ViReal64* reading);
  ViStatus ReadFromChannel(ViSession vi, ViConstString channelName, ViInt32 maximumTime, ViReal64* reading);
  ViStatus ReturnANumberAndAString(ViSession vi, ViInt16* aNumber, ViChar aString[256]);
  ViStatus ReturnDurationInSeconds(ViSession vi, ViReal64* timedelta);
  ViStatus ReturnListOfDurationsInSeconds(ViSession vi, ViInt32 numberOfElements, ViReal64 timedeltas[]);
  ViStatus ReturnMultipleTypes(ViSession vi, ViBoolean* aBoolean, ViInt32* anInt32, ViInt64* anInt64, ViInt16* anIntEnum, ViReal64* aFloat, ViReal64* aFloatEnum, ViInt32 arraySize, ViReal64 anArray[], ViInt32 stringSize, ViChar aString[]);
  ViStatus SetAttributeViBoolean(ViSession vi, ViConstString channelName, ViAttr attributeId, ViBoolean attributeValue);
  ViStatus SetAttributeViInt32(ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32 attributeValue);
  ViStatus SetAttributeViInt64(ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt64 attributeValue);
  ViStatus SetAttributeViReal64(ViSession vi, ViConstString channelName, ViAttr attributeId, ViReal64 attributeValue);
  ViStatus SetAttributeViString(ViSession vi, ViConstString channelName, ViAttr attributeId, ViConstString attributeValue);
  ViStatus SetCustomType(ViSession vi, struct CustomStruct cs);
  ViStatus SetCustomTypeArray(ViSession vi, ViInt32 numberOfElements, struct CustomStruct cs[]);
  ViStatus StringValuedEnumInputFunctionWithDefaults(ViSession vi, ViConstString aMobileOSName);
  ViStatus TwoInputFunction(ViSession vi, ViReal64 aNumber, ViString aString);
  ViStatus Use64BitNumber(ViSession vi, ViInt64 input, ViInt64* output);
  ViStatus WriteWaveform(ViSession vi, ViInt32 numberOfSamples, ViReal64 waveform[]);
  ViStatus close(ViSession vi);
  ViStatus error_message(ViSession vi, ViStatus errorCode, ViChar errorMessage[256]);
  ViStatus self_test(ViSession vi, ViInt16* selfTestResult, ViChar selfTestMessage[256]);

 private:
  using AbortPtr = ViStatus (*)(ViSession vi);
  using AcceptListOfDurationsInSecondsPtr = ViStatus (*)(ViSession vi, ViInt32 count, ViReal64 delays[]);
  using BoolArrayOutputFunctionPtr = ViStatus (*)(ViSession vi, ViInt32 numberOfElements, ViBoolean anArray[]);
  using DoubleAllTheNumsPtr = ViStatus (*)(ViSession vi, ViInt32 numberCount, ViReal64 numbers[]);
  using EnumArrayOutputFunctionPtr = ViStatus (*)(ViSession vi, ViInt32 numberOfElements, ViInt16 anArray[]);
  using EnumInputFunctionWithDefaultsPtr = ViStatus (*)(ViSession vi, ViInt16 aTurtle);
  using ExportAttributeConfigurationBufferPtr = ViStatus (*)(ViSession vi, ViInt32 sizeInBytes, ViInt8 configuration[]);
  using FetchWaveformPtr = ViStatus (*)(ViSession vi, ViInt32 numberOfSamples, ViReal64 waveformData[], ViInt32* actualNumberOfSamples);
  using GetABooleanPtr = ViStatus (*)(ViSession vi, ViBoolean* aBoolean);
  using GetANumberPtr = ViStatus (*)(ViSession vi, ViInt16* aNumber);
  using GetAStringOfFixedMaximumSizePtr = ViStatus (*)(ViSession vi, ViChar aString[256]);
  using GetAStringUsingPythonCodePtr = ViStatus (*)(ViSession vi, ViInt16 aNumber, ViChar aString[]);
  using GetAnIviDanceStringPtr = ViStatus (*)(ViSession vi, ViInt32 bufferSize, ViChar aString[]);
  using GetAnIviDanceWithATwistStringPtr = ViStatus (*)(ViSession vi, ViInt32 bufferSize, ViChar aString[], ViInt32* actualSize);
  using GetArrayForPythonCodeCustomTypePtr = ViStatus (*)(ViSession vi, ViInt32 numberOfElements, struct CustomStruct arrayOut[]);
  using GetArrayForPythonCodeDoublePtr = ViStatus (*)(ViSession vi, ViInt32 numberOfElements, ViReal64 arrayOut[]);
  using GetArraySizeForPythonCodePtr = ViStatus (*)(ViSession vi, ViInt32* sizeOut);
  using GetArrayUsingIviDancePtr = ViStatus (*)(ViSession vi, ViInt32 arraySize, ViReal64 arrayOut[]);
  using GetAttributeViBooleanPtr = ViStatus (*)(ViSession vi, ViConstString channelName, ViAttr attributeId, ViBoolean* attributeValue);
  using GetAttributeViInt32Ptr = ViStatus (*)(ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32* attributeValue);
  using GetAttributeViInt64Ptr = ViStatus (*)(ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt64* attributeValue);
  using GetAttributeViReal64Ptr = ViStatus (*)(ViSession vi, ViConstString channelName, ViAttr attributeId, ViReal64* attributeValue);
  using GetAttributeViStringPtr = ViStatus (*)(ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32 bufferSize, ViChar attributeValue[]);
  using GetCalDateAndTimePtr = ViStatus (*)(ViSession vi, ViInt32 calType, ViInt32* month, ViInt32* day, ViInt32* year, ViInt32* hour, ViInt32* minute);
  using GetCalIntervalPtr = ViStatus (*)(ViSession vi, ViInt32* months);
  using GetCustomTypePtr = ViStatus (*)(ViSession vi, struct CustomStruct* cs);
  using GetCustomTypeArrayPtr = ViStatus (*)(ViSession vi, ViInt32 numberOfElements, struct CustomStruct cs[]);
  using GetEnumValuePtr = ViStatus (*)(ViSession vi, ViInt32* aQuantity, ViInt16* aTurtle);
  using GetErrorPtr = ViStatus (*)(ViSession vi, ViStatus* errorCode, ViInt32 bufferSize, ViChar description[]);
  using ImportAttributeConfigurationBufferPtr = ViStatus (*)(ViSession vi, ViInt32 sizeInBytes, ViInt8 configuration[]);
  using InitWithOptionsPtr = ViStatus (*)(ViString resourceName, ViBoolean idQuery, ViBoolean resetDevice, ViConstString optionString, ViSession* vi);
  using InitiatePtr = ViStatus (*)(ViSession vi);
  using MultipleArrayTypesPtr = ViStatus (*)(ViSession vi, ViInt32 outputArraySize, ViReal64 outputArray[], ViReal64 outputArrayOfFixedLength[3], ViInt32 inputArraySizes, ViReal64 inputArrayOfFloats[], ViInt16 inputArrayOfIntegers[]);
  using MultipleArraysSameSizePtr = ViStatus (*)(ViSession vi, ViReal64 values1[], ViReal64 values2[], ViReal64 values3[], ViReal64 values4[], ViInt32 size);
  using OneInputFunctionPtr = ViStatus (*)(ViSession vi, ViInt32 aNumber);
  using ParametersAreMultipleTypesPtr = ViStatus (*)(ViSession vi, ViBoolean aBoolean, ViInt32 anInt32, ViInt64 anInt64, ViInt16 anIntEnum, ViReal64 aFloat, ViReal64 aFloatEnum, ViInt32 stringSize, ViConstString aString);
  using PoorlyNamedSimpleFunctionPtr = ViStatus (*)(ViSession vi);
  using ReadPtr = ViStatus (*)(ViSession vi, ViReal64 maximumTime, ViReal64* reading);
  using ReadFromChannelPtr = ViStatus (*)(ViSession vi, ViConstString channelName, ViInt32 maximumTime, ViReal64* reading);
  using ReturnANumberAndAStringPtr = ViStatus (*)(ViSession vi, ViInt16* aNumber, ViChar aString[256]);
  using ReturnDurationInSecondsPtr = ViStatus (*)(ViSession vi, ViReal64* timedelta);
  using ReturnListOfDurationsInSecondsPtr = ViStatus (*)(ViSession vi, ViInt32 numberOfElements, ViReal64 timedeltas[]);
  using ReturnMultipleTypesPtr = ViStatus (*)(ViSession vi, ViBoolean* aBoolean, ViInt32* anInt32, ViInt64* anInt64, ViInt16* anIntEnum, ViReal64* aFloat, ViReal64* aFloatEnum, ViInt32 arraySize, ViReal64 anArray[], ViInt32 stringSize, ViChar aString[]);
  using SetAttributeViBooleanPtr = ViStatus (*)(ViSession vi, ViConstString channelName, ViAttr attributeId, ViBoolean attributeValue);
  using SetAttributeViInt32Ptr = ViStatus (*)(ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32 attributeValue);
  using SetAttributeViInt64Ptr = ViStatus (*)(ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt64 attributeValue);
  using SetAttributeViReal64Ptr = ViStatus (*)(ViSession vi, ViConstString channelName, ViAttr attributeId, ViReal64 attributeValue);
  using SetAttributeViStringPtr = ViStatus (*)(ViSession vi, ViConstString channelName, ViAttr attributeId, ViConstString attributeValue);
  using SetCustomTypePtr = ViStatus (*)(ViSession vi, struct CustomStruct cs);
  using SetCustomTypeArrayPtr = ViStatus (*)(ViSession vi, ViInt32 numberOfElements, struct CustomStruct cs[]);
  using StringValuedEnumInputFunctionWithDefaultsPtr = ViStatus (*)(ViSession vi, ViConstString aMobileOSName);
  using TwoInputFunctionPtr = ViStatus (*)(ViSession vi, ViReal64 aNumber, ViString aString);
  using Use64BitNumberPtr = ViStatus (*)(ViSession vi, ViInt64 input, ViInt64* output);
  using WriteWaveformPtr = ViStatus (*)(ViSession vi, ViInt32 numberOfSamples, ViReal64 waveform[]);
  using closePtr = ViStatus (*)(ViSession vi);
  using error_messagePtr = ViStatus (*)(ViSession vi, ViStatus errorCode, ViChar errorMessage[256]);
  using self_testPtr = ViStatus (*)(ViSession vi, ViInt16* selfTestResult, ViChar selfTestMessage[256]);

  typedef struct FunctionPointers {
    AbortPtr Abort;
    AcceptListOfDurationsInSecondsPtr AcceptListOfDurationsInSeconds;
    BoolArrayOutputFunctionPtr BoolArrayOutputFunction;
    DoubleAllTheNumsPtr DoubleAllTheNums;
    EnumArrayOutputFunctionPtr EnumArrayOutputFunction;
    EnumInputFunctionWithDefaultsPtr EnumInputFunctionWithDefaults;
    ExportAttributeConfigurationBufferPtr ExportAttributeConfigurationBuffer;
    FetchWaveformPtr FetchWaveform;
    GetABooleanPtr GetABoolean;
    GetANumberPtr GetANumber;
    GetAStringOfFixedMaximumSizePtr GetAStringOfFixedMaximumSize;
    GetAStringUsingPythonCodePtr GetAStringUsingPythonCode;
    GetAnIviDanceStringPtr GetAnIviDanceString;
    GetAnIviDanceWithATwistStringPtr GetAnIviDanceWithATwistString;
    GetArrayForPythonCodeCustomTypePtr GetArrayForPythonCodeCustomType;
    GetArrayForPythonCodeDoublePtr GetArrayForPythonCodeDouble;
    GetArraySizeForPythonCodePtr GetArraySizeForPythonCode;
    GetArrayUsingIviDancePtr GetArrayUsingIviDance;
    GetAttributeViBooleanPtr GetAttributeViBoolean;
    GetAttributeViInt32Ptr GetAttributeViInt32;
    GetAttributeViInt64Ptr GetAttributeViInt64;
    GetAttributeViReal64Ptr GetAttributeViReal64;
    GetAttributeViStringPtr GetAttributeViString;
    GetCalDateAndTimePtr GetCalDateAndTime;
    GetCalIntervalPtr GetCalInterval;
    GetCustomTypePtr GetCustomType;
    GetCustomTypeArrayPtr GetCustomTypeArray;
    GetEnumValuePtr GetEnumValue;
    GetErrorPtr GetError;
    ImportAttributeConfigurationBufferPtr ImportAttributeConfigurationBuffer;
    InitWithOptionsPtr InitWithOptions;
    InitiatePtr Initiate;
    MultipleArrayTypesPtr MultipleArrayTypes;
    MultipleArraysSameSizePtr MultipleArraysSameSize;
    OneInputFunctionPtr OneInputFunction;
    ParametersAreMultipleTypesPtr ParametersAreMultipleTypes;
    PoorlyNamedSimpleFunctionPtr PoorlyNamedSimpleFunction;
    ReadPtr Read;
    ReadFromChannelPtr ReadFromChannel;
    ReturnANumberAndAStringPtr ReturnANumberAndAString;
    ReturnDurationInSecondsPtr ReturnDurationInSeconds;
    ReturnListOfDurationsInSecondsPtr ReturnListOfDurationsInSeconds;
    ReturnMultipleTypesPtr ReturnMultipleTypes;
    SetAttributeViBooleanPtr SetAttributeViBoolean;
    SetAttributeViInt32Ptr SetAttributeViInt32;
    SetAttributeViInt64Ptr SetAttributeViInt64;
    SetAttributeViReal64Ptr SetAttributeViReal64;
    SetAttributeViStringPtr SetAttributeViString;
    SetCustomTypePtr SetCustomType;
    SetCustomTypeArrayPtr SetCustomTypeArray;
    StringValuedEnumInputFunctionWithDefaultsPtr StringValuedEnumInputFunctionWithDefaults;
    TwoInputFunctionPtr TwoInputFunction;
    Use64BitNumberPtr Use64BitNumber;
    WriteWaveformPtr WriteWaveform;
    closePtr close;
    error_messagePtr error_message;
    self_testPtr self_test;
  } FunctionLoadStatus;

  ni::hardware::grpc::internal::SharedLibrary shared_library_;
  FunctionPointers function_pointers_;
};

}  // namespace grpc
}  // namespace fake
}  // namespace ni

#endif  // NI_FAKE_GRPC_LIBRARY_H
