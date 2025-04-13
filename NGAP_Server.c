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

#include "NGAP_18.5_Stack.h"

void NGAP_ReceiveMessage( uint8_t procedureCode, uint8_t messageType, void * msg, SI_AMFNode * ngNode)
{
	printf("received message procedureCode=%d Type=%d\n", procedureCode, messageType);
	
	if( procedureCode == 21)
	{
		__si_amf_debug_pdu_NGSetupRequest( (SI_AMF_DT_PDU_NGSetupRequest*)msg);
	}
}


int main( int argc, char* argv[])
{
	printf( "E1AP Server\n");
	NGAP__InitStack( "./ngap_s_logs/");
	NGAP__SetHost( "192.160.1.3", NULL, 38412);  //PPID 69
	NGAP__SetOnMessageRecv( NGAP_ReceiveMessage);
	NGAP__StartStack();

	// cat /proc/net/sctp/eps 
	// lsof -R | grep 
		
	__si_core_wait();
}

