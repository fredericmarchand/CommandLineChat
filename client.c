/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *  client.c
 *  Frederic Marchand
 *
 *  This client source file contains the function to 
 *  establish a connection as a client.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */



#include "types.h"

//This function establishes a connection to the server
void establishConnection(int *mySocket, char* SERVER_IP, int myPort){
    
    struct sockaddr_in  addr;
    int i;
    
    /* create socket */
    *mySocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (*mySocket < 0) {
        printf("Couldn't open socket\n");
        exit(-1);
    }
    
    /* setup address */
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    addr.sin_port = htons((unsigned short) myPort);
    
    /* connect to server */
    i = connect(*mySocket, 
                (struct sockaddr *) &addr,
                sizeof(addr));
    if (i<0) {
        printf("Client could not connect!\n");
        exit(-1);
    }
}

//this function performs a series of checks 
int checkLetter(char *letter, char *checkedLetters, int position){
    int r=0;
    if(strlen(letter)==1){
        int i;
        for (i=0; i<strlen(checkedLetters); i++){
            if(letter[0] == checkedLetters[i]){
                printf("This letter has already been checked\n");
                r = (-1);//function will return -1 if the letter has already been checked
                break;
            }
        }
    }
    else if(strlen(letter)>1){
        r=1;//function will return 1 if the letter is actually a word that the player wanted to check
    }
    else{
        checkedLetters[position] = letter[0];//add the letter to the list
    }
    return(r);//the letter is added to the list of checked letters
}

