/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *  Frederic Marchand
 *
 *  contains the main function which calls the functions
 *  in server.c, client.c and util.c.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <unistd.h>
#include "types.h"

void emptyString(char*);

int main(int argc, char *argv[]){
    
    char SERVER_IP[14];
    if(argc>1)
        strcpy(SERVER_IP, argv[1]);
    
    int myPort = 62210;
    int cors;//this variable tells us if the user is the client or server (1 for server and 0 for client)
    int myListenSocket, clientSocket;//sockets
    int bytesRcv;//received bytes
    
    char *inStr;  //input string
    int p = 120;
    char buffer[120];  //buffer for sending
    
    
    if(argc > 1){  //checks if the user is going to be a client
        printf("\n\nWelcome!\nYou are a Client.\nWaiting for connection...\n\n");
        establishConnection(&clientSocket, SERVER_IP, myPort);
        cors = 0;
    }
    else{ //checks if the user is going to be a server
        printf("\n\nWelcome!\nYou are a Server.\nWaiting for connection...\n\n");
        setupConnection(&myListenSocket, &clientSocket, myPort);
        cors = 1;
    }
    
         int i;
         i = fork();
         if(i == 0){
             while(1){
                 memset(buffer, '\0', sizeof(buffer));
                bytesRcv = recv(clientSocket, buffer, sizeof(buffer), 0);
                if(strcmp(buffer, "exit")==0){
                    printf("\nYour chat partner has exited the conversation\n");
                    break;
                }
                printf("\nReceived: %s\n", buffer);
                 emptyString(buffer);
             }
         }
         else{
            while(1){
                memset(buffer, '\0', sizeof(buffer));
                inStr = (char*)malloc(sizeof(p));
                getline(&inStr, &p, stdin);
                strcpy(buffer, inStr);
                send(clientSocket, buffer, strlen(buffer), 0);
                emptyString(buffer);
                emptyString(inStr);
                free(inStr);
            }
        }
}

void emptyString(char *string){
    int i;
    for(i=0; i<strlen(string); i++){
        string[0] = 0;
    }
    return;
}
