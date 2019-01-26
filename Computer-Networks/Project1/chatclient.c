/********************************************************************
 ** Erin Alltop
 ** Project 1 - CS372 - Spring 2018
 ** This program is a simple chat client that connects  
 ** to a corresponding server (chatserve.py). 
 ** I referenced Beej's Guide in several areas for assistance in setting up
 ** this client: https://beej.us/guide/bgnet/html/multi/index.html
 *********************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>


// Setup the address information 
struct addrinfo* startUp(char *address, char *port){             
	struct addrinfo hints;
    struct addrinfo *servinfo;
    int status;
	
	memset(&hints, 0, sizeof hints);  // Clear out the struct  
	hints.ai_family = AF_INET;             
	hints.ai_socktype = SOCK_STREAM;  // TCP stream sockets

	// Print an error message if status returns non-zero
	if((status = getaddrinfo(address, port, &hints, &servinfo)) != 0)
	{ 
		fprintf(stderr, "Address error: %s\n", gai_strerror(status));
		exit(1);
	}
	
	return servinfo;
}

// Setup the socket for the connection
int setupSocket(struct addrinfo *servinfo)
{        
	int sockfd, status;                                         
	if ((sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol)) == -1)
	{
		fprintf(stderr, "Error creating socket.\n");
		exit(1);
	}
	
	if ((status = connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen)) == -1)
	{
		fprintf(stderr, "Error connecting.\n");
		exit(1);
	}

	return sockfd;
}

void sendMessage(int sockfd, char *clientMsg, char *clientHandle)
{
	printf("%s> ", clientHandle); 
	int bytes_sent = 0; // error detection  
	
	// Clear out the junk from clientMsg
	memset(clientMsg, 0 ,sizeof(clientMsg)); 
	fgets(clientMsg, 502, stdin);

	// send the message
	bytes_sent = send(sockfd, clientMsg, strlen(clientMsg), 0);  
		
	// Print an error if the number of bytes sent were less than 0
	if(bytes_sent == -1) {fprintf(stderr, "Error sending message.\n"); exit(1);}
}

int receiveMessage(int sockfd, char *serverMsg, char *serverHandle)
{
	int status;
	int terminated = 0;

	// Clear out the junk from the serverMsg
	memset(serverMsg, 0, sizeof(serverMsg));

	// Print an error if status is less than 0
	status = recv(sockfd, serverMsg, 500, 0); 
	
	if (status == -1) {fprintf(stderr, "Error receiving message.\n"); exit(1);}
        
    // if status is 0, the server closed the coonection
	else if (status == 0)
	{                             
		printf("Chat terminated by server.\n");
		terminated = 1; // change to 1 if connection terminated
	}
	else
	{                                                      
		printf("%s> %s\n", serverHandle, serverMsg);
	}

	return terminated; 
}

void chatApp(int sockfd, char *clientHandle, char *serverHandle)
{  

	char clientMsg[501];   // max 500 characters for messages
	char serverMsg[501];
	int terminated;

	// clear stdin
	fgets(clientMsg, 500, stdin);     
    
	while(1)
	{		
		sendMessage(sockfd, clientMsg, clientHandle);
		terminated = receiveMessage(sockfd, serverMsg, serverHandle);

		// if terminated returns 1 we know the connection has been closed
		// and we can close connection from the client end
		if(terminated == 1)
		{
			break;
		}
	}
	
	close(sockfd);                           
	printf("Connection is now closed. Goodbye %s!\n", clientHandle);
}

// This function exchanges erver and client handles
void getServerHandle(int sockfd, char *clientHandle, char *serverHandle)
{
	int cHandle = send(sockfd, clientHandle, strlen(clientHandle), 0);	
	int sHandle = recv(sockfd, serverHandle, 10, 0);
}


// Get user input for handle, setup the connection, and begin the chat
int main(int argc, char *argv[])
{              
	char clientHandle[10];      
    char serverHandle[10];   
	if (argc < 3) { fprintf(stderr,"USAGE: %s hostname port\n", argv[0]); exit(0); } // Check usage & args
	
	// get the client's handle
    printf("Please enter a handle up to 10 characters: ");
	scanf("%s", clientHandle);	
    
	struct addrinfo* servinfo = startUp(argv[1], argv[2]);   
	int sockfd = setupSocket(servinfo);              
	getServerHandle(sockfd, clientHandle, serverHandle); 

	printf("Hi %s! Chat initiated with %s.\n", clientHandle, serverHandle);

	chatApp(sockfd, clientHandle, serverHandle);    
	freeaddrinfo(servinfo); // free the linked list      
}
	





