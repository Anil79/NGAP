all:
	gcc -g3 -o NGAP_Server NGAP_Server.c -L. libNGAP_18_5.so libsicore.so -I./ -lpthread -lsctp -DSCTP_SUPPORT -Wl,-rpath .
	gcc -g3 -o NGAP_Client NGAP_Client.c NGAP_test.c -L. libNGAP_18_5.so libsicore.so -I./ -lpthread -lsctp -DSCTP_SUPPORT -Wl,-rpath .
