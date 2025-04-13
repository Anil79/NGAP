#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <semaphore.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <unistd.h>
#include <signal.h>
#include <limits.h>
#include <poll.h>
#include <sys/epoll.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <error.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <net/if.h> 

#include "sirik_core.h"
#include "libAsn.h"
#include "NGAP_18.5.h"
//#include "lib_node.h"

#ifndef SIRIK_AMF_V2_H
#define SIRIK_AMF_V2_H


#pragma pack(4)
typedef struct __si_ngap_node
{
	SI_Socket * siSocket;
	//SI_RAN_Client * RANClient;
	int NodeType;
	uint8_t * transportEng;
	
} SI_AMFNode;


typedef struct SI_AMFNode SI_NGAPNode;



typedef void (*fp_ngap_on_message)( uint8_t procedureCode, uint8_t messageType, void * msg, SI_AMFNode * ngNode);
void __si_ngap_set_message_handler( fp_ngap_on_message handler);

void __si_amf_handle_message( SI_AMFNode * s1apNode, SI_SocketSCTPBuffer * sctpBuffer);

int __si_amf_sendmsg( uint8_t * buffer, uint32_t len, SI_AMFNode * ngNode);
void __si_amf_app_message_handler( uint8_t procedureCode, uint8_t messageType, void * msg, SI_AMFNode * ngNode);




int __si_amf_send_AMFConfigurationUpdate( SI_AMF_DT_PDU_AMFConfigurationUpdate * objAMFConfigurationUpdate, SI_AMFNode * amfNode);
int __si_amf_send_AMFConfigurationUpdateAcknowledge( SI_AMF_DT_PDU_AMFConfigurationUpdateAcknowledge * objAMFConfigurationUpdateAcknowledge, SI_AMFNode * amfNode);
int __si_amf_send_AMFConfigurationUpdateFailure( SI_AMF_DT_PDU_AMFConfigurationUpdateFailure * objAMFConfigurationUpdateFailure, SI_AMFNode * amfNode);
int __si_amf_send_AMFCPRelocationIndication( SI_AMF_DT_PDU_AMFCPRelocationIndication * objAMFCPRelocationIndication, SI_AMFNode * amfNode);
int __si_amf_send_AMFStatusIndication( SI_AMF_DT_PDU_AMFStatusIndication * objAMFStatusIndication, SI_AMFNode * amfNode);
int __si_amf_send_BroadcastSessionModificationRequest( SI_AMF_DT_PDU_BroadcastSessionModificationRequest * objBroadcastSessionModificationRequest, SI_AMFNode * amfNode);
int __si_amf_send_BroadcastSessionModificationResponse( SI_AMF_DT_PDU_BroadcastSessionModificationResponse * objBroadcastSessionModificationResponse, SI_AMFNode * amfNode);
int __si_amf_send_BroadcastSessionModificationFailure( SI_AMF_DT_PDU_BroadcastSessionModificationFailure * objBroadcastSessionModificationFailure, SI_AMFNode * amfNode);
int __si_amf_send_BroadcastSessionReleaseRequest( SI_AMF_DT_PDU_BroadcastSessionReleaseRequest * objBroadcastSessionReleaseRequest, SI_AMFNode * amfNode);
int __si_amf_send_BroadcastSessionReleaseResponse( SI_AMF_DT_PDU_BroadcastSessionReleaseResponse * objBroadcastSessionReleaseResponse, SI_AMFNode * amfNode);
int __si_amf_send_BroadcastSessionReleaseRequired( SI_AMF_DT_PDU_BroadcastSessionReleaseRequired * objBroadcastSessionReleaseRequired, SI_AMFNode * amfNode);
int __si_amf_send_BroadcastSessionSetupRequest( SI_AMF_DT_PDU_BroadcastSessionSetupRequest * objBroadcastSessionSetupRequest, SI_AMFNode * amfNode);
int __si_amf_send_BroadcastSessionSetupResponse( SI_AMF_DT_PDU_BroadcastSessionSetupResponse * objBroadcastSessionSetupResponse, SI_AMFNode * amfNode);
int __si_amf_send_BroadcastSessionSetupFailure( SI_AMF_DT_PDU_BroadcastSessionSetupFailure * objBroadcastSessionSetupFailure, SI_AMFNode * amfNode);
int __si_amf_send_BroadcastSessionTransportRequest( SI_AMF_DT_PDU_BroadcastSessionTransportRequest * objBroadcastSessionTransportRequest, SI_AMFNode * amfNode);
int __si_amf_send_BroadcastSessionTransportResponse( SI_AMF_DT_PDU_BroadcastSessionTransportResponse * objBroadcastSessionTransportResponse, SI_AMFNode * amfNode);
int __si_amf_send_BroadcastSessionTransportFailure( SI_AMF_DT_PDU_BroadcastSessionTransportFailure * objBroadcastSessionTransportFailure, SI_AMFNode * amfNode);
int __si_amf_send_CellTrafficTrace( SI_AMF_DT_PDU_CellTrafficTrace * objCellTrafficTrace, SI_AMFNode * amfNode);
int __si_amf_send_ConnectionEstablishmentIndication( SI_AMF_DT_PDU_ConnectionEstablishmentIndication * objConnectionEstablishmentIndication, SI_AMFNode * amfNode);
int __si_amf_send_DeactivateTrace( SI_AMF_DT_PDU_DeactivateTrace * objDeactivateTrace, SI_AMFNode * amfNode);
int __si_amf_send_DistributionSetupRequest( SI_AMF_DT_PDU_DistributionSetupRequest * objDistributionSetupRequest, SI_AMFNode * amfNode);
int __si_amf_send_DistributionSetupResponse( SI_AMF_DT_PDU_DistributionSetupResponse * objDistributionSetupResponse, SI_AMFNode * amfNode);
int __si_amf_send_DistributionSetupFailure( SI_AMF_DT_PDU_DistributionSetupFailure * objDistributionSetupFailure, SI_AMFNode * amfNode);
int __si_amf_send_DistributionReleaseRequest( SI_AMF_DT_PDU_DistributionReleaseRequest * objDistributionReleaseRequest, SI_AMFNode * amfNode);
int __si_amf_send_DistributionReleaseResponse( SI_AMF_DT_PDU_DistributionReleaseResponse * objDistributionReleaseResponse, SI_AMFNode * amfNode);
int __si_amf_send_DownlinkNASTransport( SI_AMF_DT_PDU_DownlinkNASTransport * objDownlinkNASTransport, SI_AMFNode * amfNode);
int __si_amf_send_DownlinkNonUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_DownlinkNonUEAssociatedNRPPaTransport * objDownlinkNonUEAssociatedNRPPaTransport, SI_AMFNode * amfNode);
int __si_amf_send_DownlinkRANConfigurationTransfer( SI_AMF_DT_PDU_DownlinkRANConfigurationTransfer * objDownlinkRANConfigurationTransfer, SI_AMFNode * amfNode);
int __si_amf_send_DownlinkRANEarlyStatusTransfer( SI_AMF_DT_PDU_DownlinkRANEarlyStatusTransfer * objDownlinkRANEarlyStatusTransfer, SI_AMFNode * amfNode);
int __si_amf_send_DownlinkRANStatusTransfer( SI_AMF_DT_PDU_DownlinkRANStatusTransfer * objDownlinkRANStatusTransfer, SI_AMFNode * amfNode);
int __si_amf_send_DownlinkUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_DownlinkUEAssociatedNRPPaTransport * objDownlinkUEAssociatedNRPPaTransport, SI_AMFNode * amfNode);
int __si_amf_send_ErrorIndication( SI_AMF_DT_PDU_ErrorIndication * objErrorIndication, SI_AMFNode * amfNode);
int __si_amf_send_HandoverCancel( SI_AMF_DT_PDU_HandoverCancel * objHandoverCancel, SI_AMFNode * amfNode);
int __si_amf_send_HandoverCancelAcknowledge( SI_AMF_DT_PDU_HandoverCancelAcknowledge * objHandoverCancelAcknowledge, SI_AMFNode * amfNode);
int __si_amf_send_HandoverNotify( SI_AMF_DT_PDU_HandoverNotify * objHandoverNotify, SI_AMFNode * amfNode);
int __si_amf_send_HandoverRequired( SI_AMF_DT_PDU_HandoverRequired * objHandoverRequired, SI_AMFNode * amfNode);
int __si_amf_send_HandoverCommand( SI_AMF_DT_PDU_HandoverCommand * objHandoverCommand, SI_AMFNode * amfNode);
int __si_amf_send_HandoverPreparationFailure( SI_AMF_DT_PDU_HandoverPreparationFailure * objHandoverPreparationFailure, SI_AMFNode * amfNode);
int __si_amf_send_HandoverRequest( SI_AMF_DT_PDU_HandoverRequest * objHandoverRequest, SI_AMFNode * amfNode);
int __si_amf_send_HandoverRequestAcknowledge( SI_AMF_DT_PDU_HandoverRequestAcknowledge * objHandoverRequestAcknowledge, SI_AMFNode * amfNode);
int __si_amf_send_HandoverFailure( SI_AMF_DT_PDU_HandoverFailure * objHandoverFailure, SI_AMFNode * amfNode);
int __si_amf_send_HandoverSuccess( SI_AMF_DT_PDU_HandoverSuccess * objHandoverSuccess, SI_AMFNode * amfNode);
int __si_amf_send_InitialContextSetupRequest( SI_AMF_DT_PDU_InitialContextSetupRequest * objInitialContextSetupRequest, SI_AMFNode * amfNode);
int __si_amf_send_InitialContextSetupResponse( SI_AMF_DT_PDU_InitialContextSetupResponse * objInitialContextSetupResponse, SI_AMFNode * amfNode);
int __si_amf_send_InitialContextSetupFailure( SI_AMF_DT_PDU_InitialContextSetupFailure * objInitialContextSetupFailure, SI_AMFNode * amfNode);
int __si_amf_send_InitialUEMessage( SI_AMF_DT_PDU_InitialUEMessage * objInitialUEMessage, SI_AMFNode * amfNode);
int __si_amf_send_LocationReport( SI_AMF_DT_PDU_LocationReport * objLocationReport, SI_AMFNode * amfNode);
int __si_amf_send_LocationReportingControl( SI_AMF_DT_PDU_LocationReportingControl * objLocationReportingControl, SI_AMFNode * amfNode);
int __si_amf_send_LocationReportingFailureIndication( SI_AMF_DT_PDU_LocationReportingFailureIndication * objLocationReportingFailureIndication, SI_AMFNode * amfNode);
int __si_amf_send_MTCommunicationHandlingRequest( SI_AMF_DT_PDU_MTCommunicationHandlingRequest * objMTCommunicationHandlingRequest, SI_AMFNode * amfNode);
int __si_amf_send_MTCommunicationHandlingResponse( SI_AMF_DT_PDU_MTCommunicationHandlingResponse * objMTCommunicationHandlingResponse, SI_AMFNode * amfNode);
int __si_amf_send_MTCommunicationHandlingFailure( SI_AMF_DT_PDU_MTCommunicationHandlingFailure * objMTCommunicationHandlingFailure, SI_AMFNode * amfNode);
int __si_amf_send_MulticastSessionActivationRequest( SI_AMF_DT_PDU_MulticastSessionActivationRequest * objMulticastSessionActivationRequest, SI_AMFNode * amfNode);
int __si_amf_send_MulticastSessionActivationResponse( SI_AMF_DT_PDU_MulticastSessionActivationResponse * objMulticastSessionActivationResponse, SI_AMFNode * amfNode);
int __si_amf_send_MulticastSessionActivationFailure( SI_AMF_DT_PDU_MulticastSessionActivationFailure * objMulticastSessionActivationFailure, SI_AMFNode * amfNode);
int __si_amf_send_MulticastSessionDeactivationRequest( SI_AMF_DT_PDU_MulticastSessionDeactivationRequest * objMulticastSessionDeactivationRequest, SI_AMFNode * amfNode);
int __si_amf_send_MulticastSessionDeactivationResponse( SI_AMF_DT_PDU_MulticastSessionDeactivationResponse * objMulticastSessionDeactivationResponse, SI_AMFNode * amfNode);
int __si_amf_send_MulticastSessionUpdateRequest( SI_AMF_DT_PDU_MulticastSessionUpdateRequest * objMulticastSessionUpdateRequest, SI_AMFNode * amfNode);
int __si_amf_send_MulticastSessionUpdateResponse( SI_AMF_DT_PDU_MulticastSessionUpdateResponse * objMulticastSessionUpdateResponse, SI_AMFNode * amfNode);
int __si_amf_send_MulticastSessionUpdateFailure( SI_AMF_DT_PDU_MulticastSessionUpdateFailure * objMulticastSessionUpdateFailure, SI_AMFNode * amfNode);
int __si_amf_send_MulticastGroupPaging( SI_AMF_DT_PDU_MulticastGroupPaging * objMulticastGroupPaging, SI_AMFNode * amfNode);
int __si_amf_send_NASNonDeliveryIndication( SI_AMF_DT_PDU_NASNonDeliveryIndication * objNASNonDeliveryIndication, SI_AMFNode * amfNode);
int __si_amf_send_NGReset( SI_AMF_DT_PDU_NGReset * objNGReset, SI_AMFNode * amfNode);
int __si_amf_send_NGResetAcknowledge( SI_AMF_DT_PDU_NGResetAcknowledge * objNGResetAcknowledge, SI_AMFNode * amfNode);
int __si_amf_send_NGSetupRequest( SI_AMF_DT_PDU_NGSetupRequest * objNGSetupRequest, SI_AMFNode * amfNode);
int __si_amf_send_NGSetupResponse( SI_AMF_DT_PDU_NGSetupResponse * objNGSetupResponse, SI_AMFNode * amfNode);
int __si_amf_send_NGSetupFailure( SI_AMF_DT_PDU_NGSetupFailure * objNGSetupFailure, SI_AMFNode * amfNode);
int __si_amf_send_OverloadStart( SI_AMF_DT_PDU_OverloadStart * objOverloadStart, SI_AMFNode * amfNode);
int __si_amf_send_OverloadStop( SI_AMF_DT_PDU_OverloadStop * objOverloadStop, SI_AMFNode * amfNode);
int __si_amf_send_Paging( SI_AMF_DT_PDU_Paging * objPaging, SI_AMFNode * amfNode);
int __si_amf_send_PathSwitchRequest( SI_AMF_DT_PDU_PathSwitchRequest * objPathSwitchRequest, SI_AMFNode * amfNode);
int __si_amf_send_PathSwitchRequestAcknowledge( SI_AMF_DT_PDU_PathSwitchRequestAcknowledge * objPathSwitchRequestAcknowledge, SI_AMFNode * amfNode);
int __si_amf_send_PathSwitchRequestFailure( SI_AMF_DT_PDU_PathSwitchRequestFailure * objPathSwitchRequestFailure, SI_AMFNode * amfNode);
int __si_amf_send_PDUSessionResourceModifyRequest( SI_AMF_DT_PDU_PDUSessionResourceModifyRequest * objPDUSessionResourceModifyRequest, SI_AMFNode * amfNode);
int __si_amf_send_PDUSessionResourceModifyResponse( SI_AMF_DT_PDU_PDUSessionResourceModifyResponse * objPDUSessionResourceModifyResponse, SI_AMFNode * amfNode);
int __si_amf_send_PDUSessionResourceModifyIndication( SI_AMF_DT_PDU_PDUSessionResourceModifyIndication * objPDUSessionResourceModifyIndication, SI_AMFNode * amfNode);
int __si_amf_send_PDUSessionResourceModifyConfirm( SI_AMF_DT_PDU_PDUSessionResourceModifyConfirm * objPDUSessionResourceModifyConfirm, SI_AMFNode * amfNode);
int __si_amf_send_PDUSessionResourceNotify( SI_AMF_DT_PDU_PDUSessionResourceNotify * objPDUSessionResourceNotify, SI_AMFNode * amfNode);
int __si_amf_send_PDUSessionResourceReleaseCommand( SI_AMF_DT_PDU_PDUSessionResourceReleaseCommand * objPDUSessionResourceReleaseCommand, SI_AMFNode * amfNode);
int __si_amf_send_PDUSessionResourceReleaseResponse( SI_AMF_DT_PDU_PDUSessionResourceReleaseResponse * objPDUSessionResourceReleaseResponse, SI_AMFNode * amfNode);
int __si_amf_send_PDUSessionResourceSetupRequest( SI_AMF_DT_PDU_PDUSessionResourceSetupRequest * objPDUSessionResourceSetupRequest, SI_AMFNode * amfNode);
int __si_amf_send_PDUSessionResourceSetupResponse( SI_AMF_DT_PDU_PDUSessionResourceSetupResponse * objPDUSessionResourceSetupResponse, SI_AMFNode * amfNode);
int __si_amf_send_PrivateMessage( SI_AMF_DT_PDU_PrivateMessage * objPrivateMessage, SI_AMFNode * amfNode);
int __si_amf_send_PWSCancelRequest( SI_AMF_DT_PDU_PWSCancelRequest * objPWSCancelRequest, SI_AMFNode * amfNode);
int __si_amf_send_PWSCancelResponse( SI_AMF_DT_PDU_PWSCancelResponse * objPWSCancelResponse, SI_AMFNode * amfNode);
int __si_amf_send_PWSFailureIndication( SI_AMF_DT_PDU_PWSFailureIndication * objPWSFailureIndication, SI_AMFNode * amfNode);
int __si_amf_send_PWSRestartIndication( SI_AMF_DT_PDU_PWSRestartIndication * objPWSRestartIndication, SI_AMFNode * amfNode);
int __si_amf_send_RANConfigurationUpdate( SI_AMF_DT_PDU_RANConfigurationUpdate * objRANConfigurationUpdate, SI_AMFNode * amfNode);
int __si_amf_send_RANConfigurationUpdateAcknowledge( SI_AMF_DT_PDU_RANConfigurationUpdateAcknowledge * objRANConfigurationUpdateAcknowledge, SI_AMFNode * amfNode);
int __si_amf_send_RANConfigurationUpdateFailure( SI_AMF_DT_PDU_RANConfigurationUpdateFailure * objRANConfigurationUpdateFailure, SI_AMFNode * amfNode);
int __si_amf_send_RANCPRelocationIndication( SI_AMF_DT_PDU_RANCPRelocationIndication * objRANCPRelocationIndication, SI_AMFNode * amfNode);
int __si_amf_send_RANPagingRequest( SI_AMF_DT_PDU_RANPagingRequest * objRANPagingRequest, SI_AMFNode * amfNode);
int __si_amf_send_RerouteNASRequest( SI_AMF_DT_PDU_RerouteNASRequest * objRerouteNASRequest, SI_AMFNode * amfNode);
int __si_amf_send_RetrieveUEInformation( SI_AMF_DT_PDU_RetrieveUEInformation * objRetrieveUEInformation, SI_AMFNode * amfNode);
int __si_amf_send_RRCInactiveTransitionReport( SI_AMF_DT_PDU_RRCInactiveTransitionReport * objRRCInactiveTransitionReport, SI_AMFNode * amfNode);
int __si_amf_send_SecondaryRATDataUsageReport( SI_AMF_DT_PDU_SecondaryRATDataUsageReport * objSecondaryRATDataUsageReport, SI_AMFNode * amfNode);
int __si_amf_send_TimingSynchronisationStatusRequest( SI_AMF_DT_PDU_TimingSynchronisationStatusRequest * objTimingSynchronisationStatusRequest, SI_AMFNode * amfNode);
int __si_amf_send_TimingSynchronisationStatusResponse( SI_AMF_DT_PDU_TimingSynchronisationStatusResponse * objTimingSynchronisationStatusResponse, SI_AMFNode * amfNode);
int __si_amf_send_TimingSynchronisationStatusFailure( SI_AMF_DT_PDU_TimingSynchronisationStatusFailure * objTimingSynchronisationStatusFailure, SI_AMFNode * amfNode);
int __si_amf_send_TimingSynchronisationStatusReport( SI_AMF_DT_PDU_TimingSynchronisationStatusReport * objTimingSynchronisationStatusReport, SI_AMFNode * amfNode);
int __si_amf_send_TraceFailureIndication( SI_AMF_DT_PDU_TraceFailureIndication * objTraceFailureIndication, SI_AMFNode * amfNode);
int __si_amf_send_TraceStart( SI_AMF_DT_PDU_TraceStart * objTraceStart, SI_AMFNode * amfNode);
int __si_amf_send_UEContextModificationRequest( SI_AMF_DT_PDU_UEContextModificationRequest * objUEContextModificationRequest, SI_AMFNode * amfNode);
int __si_amf_send_UEContextModificationResponse( SI_AMF_DT_PDU_UEContextModificationResponse * objUEContextModificationResponse, SI_AMFNode * amfNode);
int __si_amf_send_UEContextModificationFailure( SI_AMF_DT_PDU_UEContextModificationFailure * objUEContextModificationFailure, SI_AMFNode * amfNode);
int __si_amf_send_UEContextReleaseCommand( SI_AMF_DT_PDU_UEContextReleaseCommand * objUEContextReleaseCommand, SI_AMFNode * amfNode);
int __si_amf_send_UEContextReleaseComplete( SI_AMF_DT_PDU_UEContextReleaseComplete * objUEContextReleaseComplete, SI_AMFNode * amfNode);
int __si_amf_send_UEContextReleaseRequest( SI_AMF_DT_PDU_UEContextReleaseRequest * objUEContextReleaseRequest, SI_AMFNode * amfNode);
int __si_amf_send_UEContextResumeRequest( SI_AMF_DT_PDU_UEContextResumeRequest * objUEContextResumeRequest, SI_AMFNode * amfNode);
int __si_amf_send_UEContextResumeResponse( SI_AMF_DT_PDU_UEContextResumeResponse * objUEContextResumeResponse, SI_AMFNode * amfNode);
int __si_amf_send_UEContextResumeFailure( SI_AMF_DT_PDU_UEContextResumeFailure * objUEContextResumeFailure, SI_AMFNode * amfNode);
int __si_amf_send_UEContextSuspendRequest( SI_AMF_DT_PDU_UEContextSuspendRequest * objUEContextSuspendRequest, SI_AMFNode * amfNode);
int __si_amf_send_UEContextSuspendResponse( SI_AMF_DT_PDU_UEContextSuspendResponse * objUEContextSuspendResponse, SI_AMFNode * amfNode);
int __si_amf_send_UEContextSuspendFailure( SI_AMF_DT_PDU_UEContextSuspendFailure * objUEContextSuspendFailure, SI_AMFNode * amfNode);
int __si_amf_send_UEInformationTransfer( SI_AMF_DT_PDU_UEInformationTransfer * objUEInformationTransfer, SI_AMFNode * amfNode);
int __si_amf_send_UERadioCapabilityCheckRequest( SI_AMF_DT_PDU_UERadioCapabilityCheckRequest * objUERadioCapabilityCheckRequest, SI_AMFNode * amfNode);
int __si_amf_send_UERadioCapabilityCheckResponse( SI_AMF_DT_PDU_UERadioCapabilityCheckResponse * objUERadioCapabilityCheckResponse, SI_AMFNode * amfNode);
int __si_amf_send_UERadioCapabilityIDMappingRequest( SI_AMF_DT_PDU_UERadioCapabilityIDMappingRequest * objUERadioCapabilityIDMappingRequest, SI_AMFNode * amfNode);
int __si_amf_send_UERadioCapabilityIDMappingResponse( SI_AMF_DT_PDU_UERadioCapabilityIDMappingResponse * objUERadioCapabilityIDMappingResponse, SI_AMFNode * amfNode);
int __si_amf_send_UERadioCapabilityInfoIndication( SI_AMF_DT_PDU_UERadioCapabilityInfoIndication * objUERadioCapabilityInfoIndication, SI_AMFNode * amfNode);
int __si_amf_send_UETNLABindingReleaseRequest( SI_AMF_DT_PDU_UETNLABindingReleaseRequest * objUETNLABindingReleaseRequest, SI_AMFNode * amfNode);
int __si_amf_send_UplinkNASTransport( SI_AMF_DT_PDU_UplinkNASTransport * objUplinkNASTransport, SI_AMFNode * amfNode);
int __si_amf_send_UplinkNonUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_UplinkNonUEAssociatedNRPPaTransport * objUplinkNonUEAssociatedNRPPaTransport, SI_AMFNode * amfNode);
int __si_amf_send_UplinkRANConfigurationTransfer( SI_AMF_DT_PDU_UplinkRANConfigurationTransfer * objUplinkRANConfigurationTransfer, SI_AMFNode * amfNode);
int __si_amf_send_UplinkRANEarlyStatusTransfer( SI_AMF_DT_PDU_UplinkRANEarlyStatusTransfer * objUplinkRANEarlyStatusTransfer, SI_AMFNode * amfNode);
int __si_amf_send_UplinkRANStatusTransfer( SI_AMF_DT_PDU_UplinkRANStatusTransfer * objUplinkRANStatusTransfer, SI_AMFNode * amfNode);
int __si_amf_send_UplinkUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_UplinkUEAssociatedNRPPaTransport * objUplinkUEAssociatedNRPPaTransport, SI_AMFNode * amfNode);
int __si_amf_send_WriteReplaceWarningRequest( SI_AMF_DT_PDU_WriteReplaceWarningRequest * objWriteReplaceWarningRequest, SI_AMFNode * amfNode);
int __si_amf_send_WriteReplaceWarningResponse( SI_AMF_DT_PDU_WriteReplaceWarningResponse * objWriteReplaceWarningResponse, SI_AMFNode * amfNode);
int __si_amf_send_UplinkRIMInformationTransfer( SI_AMF_DT_PDU_UplinkRIMInformationTransfer * objUplinkRIMInformationTransfer, SI_AMFNode * amfNode);
int __si_amf_send_DownlinkRIMInformationTransfer( SI_AMF_DT_PDU_DownlinkRIMInformationTransfer * objDownlinkRIMInformationTransfer, SI_AMFNode * amfNode);



#endif

