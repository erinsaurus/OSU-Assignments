/**************************************************
 ** Erin Alltop
 ** CS344 - Winter 2018 - OTP
 ** This program is one of five. It runs in the
 ** background as a daemon. It connects to the other
 ** four programs and generates sockets for 
 ** communication appropriately with child processes.
 ** The child process receives from otp_enc.c a
 ** plaintext and a key via the communication socket.
 ** It then writes back the ciphertext to otp_enc.c
 **************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
	int listenSocketFD, establishedConnectionFD, portNumber, charsRead, status;
	socklen_t sizeOfClientInfo;
	char buffer[200000];
	struct sockaddr_in serverAddress, clientAddress;

	if (argc < 2) { fprintf(stderr,"USAGE: %s port\n", argv[0]); exit(1); } // Check usage & args

	// Set up the address struct for this process (the server)
	memset((char *)&serverAddress, '\0', sizeof(serverAddress)); // Clear out the address struct
	portNumber = atoi(argv[1]); // Get the port number, convert to an integer from a string
	serverAddress.sin_family = AF_INET; // Create a network-capable socket
	serverAddress.sin_port = htons(portNumber); // Store the port number
	serverAddress.sin_addr.s_addr = INADDR_ANY; // Any address is allowed for connection to this process

	// Set up the socket
	listenSocketFD = socket(AF_INET, SOCK_STREAM, 0); // Create the socket
	if (listenSocketFD < 0) { fprintf(stderr, "otp_enc_d error: problem opening socket\n"); exit(1); }

	// Enable the socket to begin listening
	if (bind(listenSocketFD, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) // Connect socket to port
	{
		fprintf(stderr, "otp_enc_d error: problem with binding\n");
		exit(1);
	}	
	listen(listenSocketFD, 5); // Flip the socket on - it can now receive up to 5 connections

	//loop children
	while(1)
	{
		// Accept a connection, blocking if one is not available until one connects
		sizeOfClientInfo = sizeof(clientAddress); // Get the size of the address for the client that will connect
		establishedConnectionFD = accept(listenSocketFD, (struct sockaddr *)&clientAddress, &sizeOfClientInfo); // Accept
		if (establishedConnectionFD < 0)
		{
			fprintf(stderr, "otp_dec_d error: problem with accept\n");
			exit(1);
		}


		/*************** CHILD PROCESS *****************/

		pid_t pid = -5;
		pid = fork();
		switch(pid)
		{
			case -1:
				fprintf(stderr, "fork error!\n");
				break;

			case 0:
				memset(buffer, '\0', 200000); // clear buffer
				charsRead = recv(establishedConnectionFD, buffer, 3, 0); // Read the client's message from the socket
				if (charsRead < 0)
				{
					fprintf(stderr, "otp_enc_d error: problem reading from socket\n");
					exit(1);
				}

				// check for special handshake 'code' for otp_enc. Anything else, exit with error
				if(strcmp(buffer, "@@@") != 0)
				{
					fprintf(stderr, "Error: could not contact otp_enc_d on port %d\n", portNumber);
					send(establishedConnectionFD, "no", 2, 0); // reply that connection can't be made
					exit(2);
				}
				else
				{	// Get the message from the client and display it
					charsRead = send(establishedConnectionFD, "ok", 2, 0);
					memset(buffer, '\0', 200000);
					charsRead = recv(establishedConnectionFD, buffer, 199999, 0); // Read the client's message from the socket
					if (charsRead < 0) 
					{
						fprintf(stderr, "otp_enc_d error: problem reading from socket\n");
						exit(1);
					}

					// Loop to get rest of message until terminating character is found
					while(charsRead != 199999 && !strstr(buffer, "@"))
					{
						charsRead += recv(establishedConnectionFD, buffer + charsRead, 199999, 0); // Read the client's message from the socket
						if (charsRead < 0) 
						{
							fprintf(stderr, "otp_enc_d error: problem reading from socket\n");
							exit(1);
						}
					}

					// Parse the message from the key
					char* message;
					char *key;
					message = strtok(buffer, ",");
					key = strtok(NULL, ",");
					int msgLen = strlen(message);

					// Encrypting the message using ASCII characters
					int i;
					for(i = 0; i < msgLen; i++)
					{
						if(message[i] == 32) message[i] = 91;
						if(key[i] == 32) key [i] = 91;
						message[i] = ((message[i] - 65 + key[i] - 65) % 27) + 65;
						if(message[i] == 91) message[i] = 32;
					}

					// Add a terminating character to the message
					char *termChar = "@";
					strcat(message, termChar);
					msgLen = strlen(message);

					// Send encrypted code back to client
					charsRead = send(establishedConnectionFD, message, msgLen, 0);
					if (charsRead < 0) error("ERROR writing to socket");
					close(establishedConnectionFD); // Close the existing socket which is connected to the client
				}
				
				exit(0);
				break;

				// parent process waits for children to complete
			default:
				do{
					waitpid(pid, &status, 0);
				} while(!WIFEXITED(status) && !WIFSIGNALED(status));
				break;
		}
	}

	return 0; 
}
