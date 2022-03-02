//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Library wrapper for implementing interactions with NI-XNET
//---------------------------------------------------------------------
#ifndef NIXNET_GRPC_LIBRARY_WRAPPER_H
#define NIXNET_GRPC_LIBRARY_WRAPPER_H

#include <grpcpp/grpcpp.h>
#include <nixnet.h>

namespace nixnet_grpc {

class NiXnetLibraryInterface {
 public:
  virtual ~NiXnetLibraryInterface() {}

  virtual nxStatus_t Blink(nxSessionRef_t interfaceRef, u32 modifier) = 0;
  virtual nxStatus_t Clear(nxSessionRef_t sessionRef) = 0;
  virtual nxStatus_t ConnectTerminals(nxSessionRef_t sessionRef, const char source[], const char destination[]) = 0;
  virtual nxStatus_t ConvertTimestamp100nsTo1ns(nxTimestamp100ns_t from, nxTimestamp1ns_t* to) = 0;
  virtual nxStatus_t ConvertTimestamp1nsTo100ns(nxTimestamp1ns_t from, nxTimestamp100ns_t* to) = 0;
  virtual nxStatus_t CreateSession(const char databaseName[], const char clusterName[], const char list[], const char interfaceParameter[], u32 mode, nxSessionRef_t* sessionRef) = 0;
  virtual nxStatus_t CreateSessionByRef(u32 numberOfDatabaseRef, nxDatabaseRef_t arrayOfDatabaseRef[], const char interfaceParameter[], u32 mode, nxSessionRef_t* sessionRef) = 0;
  virtual nxStatus_t DbAddAlias(const char databaseAlias[], const char databaseFilepath[], u32 defaultBaudRate) = 0;
  virtual nxStatus_t DbAddAlias64(const char databaseAlias[], const char databaseFilepath[], u64 defaultBaudRate) = 0;
  virtual nxStatus_t DbCloseDatabase(nxDatabaseRef_t databaseRef, u32 closeAllRefs) = 0;
  virtual nxStatus_t DbDeleteObject(nxDatabaseRef_t dbObjectRef) = 0;
  virtual nxStatus_t DbDeploy(const char ipAddress[], const char databaseAlias[], u32 waitForComplete, u32* percentComplete) = 0;
  virtual nxStatus_t DbGetDatabaseListSizes(const char ipAddress[], u32* sizeofAliasBuffer, u32* sizeofFilepathBuffer) = 0;
  virtual nxStatus_t DbGetPropertySize(nxDatabaseRef_t dbObjectRef, u32 propertyID, u32* propertySize) = 0;
  virtual nxStatus_t DbMerge(nxDatabaseRef_t targetClusterRef, nxDatabaseRef_t sourceObjRef, u32 copyMode, char prefix[], u32 waitForComplete, u32* percentComplete) = 0;
  virtual nxStatus_t DbOpenDatabase(const char databaseName[], nxDatabaseRef_t* databaseRef) = 0;
  virtual nxStatus_t DbRemoveAlias(const char databaseAlias[]) = 0;
  virtual nxStatus_t DbSaveDatabase(nxDatabaseRef_t databaseRef, const char dbFilepath[]) = 0;
  virtual nxStatus_t DbUndeploy(const char ipAddress[], const char databaseAlias[]) = 0;
  virtual nxStatus_t DisconnectTerminals(nxSessionRef_t sessionRef, const char source[], const char destination[]) = 0;
  virtual nxStatus_t Flush(nxSessionRef_t sessionRef) = 0;
  virtual nxStatus_t FutureTimeTrigger(nxSessionRef_t sessionRef, nxTimestamp1ns_t when, u32 timescale) = 0;
  virtual nxStatus_t GetPropertySize(nxSessionRef_t sessionRef, u32 propertyID, u32* propertySize) = 0;
  virtual nxStatus_t GetSubPropertySize(nxSessionRef_t sessionRef, u32 activeIndex, u32 propertyID, u32* propertySize) = 0;
  virtual nxStatus_t ReadSignalSinglePoint(nxSessionRef_t sessionRef, f64 valueBuffer[], u32 sizeOfValueBuffer, nxTimestamp100ns_t timestampBuffer[], u32 sizeOfTimestampBuffer) = 0;
  virtual nxStatus_t ReadSignalWaveform(nxSessionRef_t sessionRef, f64 timeout, nxTimestamp100ns_t* startTime, f64* deltaTime, f64 valueBuffer[], u32 sizeOfValueBuffer, u32* numberOfValuesReturned) = 0;
  virtual nxStatus_t Start(nxSessionRef_t sessionRef, u32 scope) = 0;
  virtual nxStatus_t Stop(nxSessionRef_t sessionRef, u32 scope) = 0;
  virtual nxStatus_t SystemClose(nxSessionRef_t systemRef) = 0;
  virtual nxStatus_t SystemOpen(nxSessionRef_t* systemRef) = 0;
  virtual nxStatus_t Wait(nxSessionRef_t sessionRef, u32 condition, u32 paramIn, f64 timeout, u32* paramOut) = 0;
  virtual nxStatus_t WriteSignalSinglePoint(nxSessionRef_t sessionRef, f64 valueBuffer[], u32 sizeOfValueBuffer) = 0;
  virtual nxStatus_t WriteSignalWaveform(nxSessionRef_t sessionRef, f64 timeout, f64 valueBuffer[], u32 sizeOfValueBuffer) = 0;
  virtual nxStatus_t WriteSignalXY(nxSessionRef_t sessionRef, f64 timeout, f64 valueBuffer[], u32 sizeOfValueBuffer, nxTimestamp100ns_t timestampBuffer[], u32 sizeOfTimestampBuffer, u32 numPairsBuffer[], u32 sizeOfNumPairsBuffer) = 0;
};

}  // namespace nixnet_grpc
#endif  // NIXNET_GRPC_LIBRARY_WRAPPER_H
