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
#include <resolv.h>

#include "sirik_socket.h"
#include "NGAP_18.5.h"
#include "NGAP_18.5_Stack.h"
#include "NGAP_test.h"


int ngap_server_onconnect( SI_Socket * siSocket)
{
	printf("Connected\n");

	SI_AMFNode * f1Node = (SI_AMFNode *) siSocket->transportEng;

	if(!f1Node)
	{
		__si_malloc2( sizeof( SI_AMFNode), (uint8_t **)&f1Node);
		siSocket->transportEng 	= (uint8_t *) f1Node;
		f1Node->transportEng 	= (uint8_t *) siSocket;
	}
	f1Node->siSocket = siSocket;

	SI_AMF_DT_PDU_UEContextReleaseRequest * oUEContextReleaseRequest = (SI_AMF_DT_PDU_UEContextReleaseRequest *)__si_allocM(sizeof(SI_AMF_DT_PDU_UEContextReleaseRequest));
	memset( oUEContextReleaseRequest, 0, sizeof(SI_AMF_DT_PDU_UEContextReleaseRequest));
	
	oUEContextReleaseRequest->aMFUENGAPID = 6;
	oUEContextReleaseRequest->aMFUENGAPID_isset = 1;

	oUEContextReleaseRequest->rANUENGAPID = 7;
	oUEContextReleaseRequest->rANUENGAPID_isset = 1;
	
	__si_amf_send_UEContextReleaseRequest( oUEContextReleaseRequest, f1Node);



	// SI_AMF_DT_PDU_NGSetupRequest * oNGSetupRequest = (SI_AMF_DT_PDU_NGSetupRequest *)__si_allocM(sizeof(SI_AMF_DT_PDU_NGSetupRequest));
	// memset( oNGSetupRequest, 0, sizeof(SI_AMF_DT_PDU_NGSetupRequest));


	// // // ID = id-GlobalRANNodeID, PRESENCE = mandatory L:9858
	// //SI_AMF_DT_GlobalRANNodeID * globalRANNodeID;
	// __si_amf_init_GlobalRANNodeID( &oNGSetupRequest->globalRANNodeID);
	
		// // oNGSetupRequest->globalRANNodeID->SelectedChoice = 0;
		// // __si_amf_init_GlobalGNB_ID( &oNGSetupRequest->globalRANNodeID->u.globalGNB_ID);
		// // // SI_AMF_DT_PLMNIdentity * pLMNIdentity;
		// // __si_amf_init_PLMNIdentity2( &oNGSetupRequest->globalRANNodeID->u.globalGNB_ID->pLMNIdentity, "\x03\x01\x02", 3);
		// // //SI_AMF_DT_GNB_ID * gNB_ID;
		// // __si_amf_init_GNB_ID( &oNGSetupRequest->globalRANNodeID->u.globalGNB_ID->gNB_ID);
		// // oNGSetupRequest->globalRANNodeID->u.globalGNB_ID->gNB_ID->SelectedChoice = 0;
		// // //SI_AMF_DT_GNBID_gNB_ID * gNB_ID;
		// // __si_amf_init_GNBID_gNB_ID2( &oNGSetupRequest->globalRANNodeID->u.globalGNB_ID->gNB_ID->u.gNB_ID, "\x11\x11\x11", 3, 22);
		
		
		// oNGSetupRequest->globalRANNodeID->SelectedChoice = 3;
		// //SI_AMF_DT_PDU_GlobalRANNodeID_ExtIEs * choice_Extensions_ext 
		// oNGSetupRequest->globalRANNodeID->u.choice_Extensions =  (SI_AMF_DT_PDU_GlobalRANNodeID_ExtIEs*)__si_allocM(sizeof(SI_AMF_DT_PDU_GlobalRANNodeID_ExtIEs));
		// memset( oNGSetupRequest->globalRANNodeID->u.choice_Extensions, 0, sizeof(SI_AMF_DT_PDU_GlobalRANNodeID_ExtIEs));
		
		// __si_amf_init_GlobalW_AGF_ID( &oNGSetupRequest->globalRANNodeID->u.choice_Extensions->globalWAGFID);
		// __si_amf_init_PLMNIdentity2( &oNGSetupRequest->globalRANNodeID->u.choice_Extensions->globalWAGFID->pLMNIdentity, "\x03\x01\x02", 3);
		
		// //SI_AMF_DT_W_AGF_ID * w_AGF_ID;
		// __si_amf_init_W_AGF_ID( &oNGSetupRequest->globalRANNodeID->u.choice_Extensions->globalWAGFID->w_AGF_ID);
		// oNGSetupRequest->globalRANNodeID->u.choice_Extensions->globalWAGFID->w_AGF_ID->SelectedChoice = 0;
		// // SI_AMF_DT_WAGFID_w_AGF_ID * w_AGF_ID;
		// __si_amf_init_WAGFID_w_AGF_ID2( &oNGSetupRequest->globalRANNodeID->u.choice_Extensions->globalWAGFID->w_AGF_ID->u.w_AGF_ID, 
			// "\x33\x33", 2, 16);
		
		// oNGSetupRequest->globalRANNodeID->u.choice_Extensions->globalWAGFID_isset = 1;
	
		// // choice_Extensions_ext
			// // Requires 1 more byte for padding.
	
		
		// oNGSetupRequest->globalRANNodeID_isset = 1;












	// // SI_AMF_DT_SupportedTAList * supportedTAList;
	// __si_amf_init_SupportedTAList( &oNGSetupRequest->supportedTAList);
	
	// SI_AMF_DT_SupportedTAItem * oSupportedTAItem = (SI_AMF_DT_SupportedTAItem *)__si_allocM(sizeof(SI_AMF_DT_SupportedTAItem));
	// memset( oSupportedTAItem, 0, sizeof(SI_AMF_DT_SupportedTAItem));
	
	// // SI_AMF_DT_TAC * tAC;
	// __si_amf_init_TAC2( &oSupportedTAItem->tAC, "\x01\0x2\x03", 3);
	
	
	
	// // SI_AMF_DT_BroadcastPLMNList * broadcastPLMNList;
	// __si_amf_init_BroadcastPLMNList( &oSupportedTAItem->broadcastPLMNList);
	
	// SI_AMF_DT_BroadcastPLMNItem * oBroadcastPLMNItem = (SI_AMF_DT_BroadcastPLMNItem *)__si_allocM(sizeof(SI_AMF_DT_BroadcastPLMNItem));
	// memset( oBroadcastPLMNItem, 0, sizeof(SI_AMF_DT_BroadcastPLMNItem));
	
	// //SI_AMF_DT_PLMNIdentity * pLMNIdentity;
	// __si_amf_init_PLMNIdentity2( &oBroadcastPLMNItem->pLMNIdentity, "\x03\x01\x02", 3);
		
	// //SI_AMF_DT_SliceSupportList * tAISliceSupportList;
	// __si_amf_init_SliceSupportList( &oBroadcastPLMNItem->tAISliceSupportList);
	
	
	// SI_AMF_DT_SliceSupportItem * oSliceSupportItem = (SI_AMF_DT_SliceSupportItem *)__si_allocM(sizeof(SI_AMF_DT_SliceSupportItem));
	// memset( oSliceSupportItem, 0, sizeof(SI_AMF_DT_SliceSupportItem));
	
	// // SI_AMF_DT_S_NSSAI * s_NSSAI;
	// __si_amf_init_S_NSSAI( &oSliceSupportItem->s_NSSAI);
	// __si_amf_init_SST2( &oSliceSupportItem->s_NSSAI->sST, "\x11", 1);
	// oSliceSupportItem->s_NSSAI->isPresent_sD = 0;
	
	// __si_linked_list_add( oBroadcastPLMNItem->tAISliceSupportList->SliceSupportItem, (uint8_t*)oSliceSupportItem);
	
	
	// __si_linked_list_add( oSupportedTAItem->broadcastPLMNList->BroadcastPLMNItem, (uint8_t*)oBroadcastPLMNItem);
	
	
	// __si_linked_list_add( oNGSetupRequest->supportedTAList->SupportedTAItem, (uint8_t*)oSupportedTAItem);
	// oNGSetupRequest->supportedTAList_isset = 1;

	// oNGSetupRequest->defaultPagingDRX = __si_amf__PagingDRX_v32_val;
	// oNGSetupRequest->defaultPagingDRX_isset = 1;

	// oNGSetupRequest->uERetentionInformation = 0;
	// oNGSetupRequest->uERetentionInformation_isset = 1;

	// oNGSetupRequest->nBIoTDefaultPagingDRX = __si_amf__NB_IoT_DefaultPagingDRX_rf128_val;
	// oNGSetupRequest->nBIoTDefaultPagingDRX_isset = 1;
	
	
	// __si_amf_send_NGSetupRequest( oNGSetupRequest, f1Node);
	
	
	__si_amf__Send_DownlinkRIMInformationTransfer_Prototype( f1Node);
	__si_amf__Send_PDUSessionResourceSetupResponse_Prototype( f1Node);
	
	
	return 0;
}	

void NGAP_ReceiveMessage( uint8_t procedureCode, uint8_t messageType, void * msg, SI_AMFNode * ngNode)
{
	printf("Received Message With procedureCode=%u\n", procedureCode);
}

int main( int argc, char* argv[])
{
	printf( "E1AP Server\n");
	NGAP__InitStack( "./ngap_c_logs/");
	NGAP__SetHost( "192.160.1.4", NULL, 0);
	NGAP__AddServer( "192.160.1.3", NULL, 38412);
	NGAP__SetOnConnect( ngap_server_onconnect);
	NGAP__SetOnMessageRecv( NGAP_ReceiveMessage);
	NGAP__StartStack();

	// cat /proc/net/sctp/eps 
	// lsof -R | grep 
		
	__si_core_wait();
}

