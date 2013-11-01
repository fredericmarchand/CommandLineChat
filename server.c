/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *  server.c
 *  Frederic Marchand
 *
 *  This server source file contains the function to
 *  setup a connection as a server.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "types.h"

//this function is used to setup the server
void setupConnection(int *myListenSocket, int *clientSocket, int myPort){
    
    struct sockaddr_in  myAddr, clientAddr;
    int i, addrSize;
    
    /* create socket */
    *myListenSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (*myListenSocket < 0) {
        printf("Couldn't open socket\n");
        exit(-1);
    }
    
    /* setup my server address */
    memset(&myAddr, 0, sizeof(myAddr));
    myAddr.sin_family = AF_INET;
    myAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    myAddr.sin_port = htons((unsigned short) myPort);
    
    /* bind my listen socket */
    i = bind(*myListenSocket, 
             (struct sockaddr *) &myAddr,
             sizeof(myAddr));
    if (i < 0) {
        printf("Couldn't bind socket\n");
        exit(-1);
    }
    
    /* listen */
    i = listen(*myListenSocket, 5);
    if (i < 0) {
        printf("Couldn't listen\n");
        exit(-1);
    }
    
    /* wait for connection request */
    
    addrSize = sizeof(clientAddr);
    
    *clientSocket = accept(*myListenSocket,
                          (struct sockaddr *) &clientAddr,
                          &addrSize);
    if (*clientSocket < 0) {
        printf("Couldn't accept the connection\n");
        exit(-1);
    }
}


