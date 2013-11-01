/* * * * * * * * * * * * * * * * * * * * * *
 *
 *  types.h
 *  Frederic Marchand
 *  #100817579
 *  Comp2401 Assignment 4
 *
 *
 *  Types.h is a header file which contains
 *  the function prototypes of the funcions 
 *  assignment 4
 *
 *
 * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>

#define MY_PORT 63720




//Function prototypes 
void  funMessage(int);
void  setupConnection(int *myListenSocket, int *clientSocket, int myPort);
char* toLowerCase(char *word);
void  askedLetter(char *letter, char *word, int letterSpots[]);
void  establishConnection(int *mySocket, char* SERVER_IP, int myPort);
int   wordOrLetter(char *letter);
int   winOrLose(int *letterSpots, char *word);
void  empty(char *string);

