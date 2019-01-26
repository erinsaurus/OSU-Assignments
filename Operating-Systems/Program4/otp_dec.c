/**************************************************
 ** Erin Alltop
 ** CS344 - Winter 2018 - OTP
 ** This program is one of five. It connects to
 ** otp_dec_d.c to request a ciphertext be decrypted
 ** with a given ciphertext and key. It then outputs
 ** the plaintext message to stdout.
 **************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

int main(int argc, char *argv[])
{
	int socketFD, portNumber, charsWritten, charsRead, keyLength, sendLength, messageLength, i;
	struct sockaddr_in serverAddress;
	struct hostent* serverHostInfo;
	char buffer[200000];
    FILE *inputFile; 
    char *message;
    char *key;
    char *newline;
    size_t MAX_LEN = 50000;

	if (argc < 3) { fprintf(stderr,"USAGE: %s hostname port\n", argv[0]); exit(0); } // Check usage & args

	//open key file
	key = (char*)malloc(sizeof(char) * MAX_LEN);
	memset(key, '\0', MAX_LEN);
	inputFile = fopen(argv[2], "r"); // argv[2] is the filename

	// print an error if there is a problem opening file
	if(!inputFile)
	{
		fprintf(stderr, "otp_dec error: unable to open %s file.\n", argv[2]);
		exit(1);
	}

	// print an error if there is a problem reading file
	if(getline(&key, &MAX_LEN, inputFile) == -1)
	{
		fprintf(stderr, "otp_dec error: problem reading file %s\n.", argv[2]);
		exit(1);
	}

	// remove newline and replace it with a null terminator
	if( key[strlen(key) - 1] == '\n')
		key[strlen(key) -1] = '\0';
	
	keyLength = strlen(key); // get key length
	fclose(inputFile); // close key file

	// Open plaintext file
	message = (char*)malloc(sizeof(char) * MAX_LEN);
	memset(message, '\0', MAX_LEN);
	inputFile = fopen(argv[1], "r"); // argv[1] is the plaintext file

	// print an error if there is a problem opening file
	if(!inputFile)
	{
		fprintf(stderr, "otp_dec error: Unable to open %s file\n", argv[1]);
		exit(1);
	}

	// print an error if there is a problem reading file
	if(getline(&message, &MAX_LEN, inputFile) == -1)
	{
		fprintf(stderr, "otp_dec error: Problem reading file %s\n", argv[1]);
		exit(1);
	}

	// remove newline and replace it with a null terminator
	if(message[strlen(message) - 1] == '\n')
		message[strlen(message) -1] = '\0';

	messageLength = strlen(message); // get message length
	fclose(inputFile); // close plaintext file

	// If the message is longer than the key, print an error
	if(messageLength > keyLength)
	{
		fprintf(stderr, "otp_dec error: key '%s' is too short\n", argv[2]);
		exit(1);
	}

	// Check that all characters are valid in key (26 uppercase alphabet and space character only)
	// print an error if not
	for(i = 0; i < keyLength; i++)
	{
		if(!((key[i] >= 'A' && key[i] <= 'Z') || key[i] == ' '))
		{
			fprintf(stderr, "otp_dec error: %s contains bad characters\n", argv[2]);
			exit(1);
		}
	}

	// Check that all characters are valid in message (26 uppercase alphabet and space character only)
	// print an error if not
	for(i = 0; i < messageLength; i++)
	{
		if(!((message[i] >= 'A' && message[i] <= 'Z') || message[i] == ' '))
		{
			fprintf(stderr, "otp_dec error: %s contains bad characters\n", argv[1]);
			exit(1);
		}
	}

	// adding delimiters for concating
	// this will allow us to send both key and message in one message and parse afterwards
	char *token = ","; // delimeter between key and message
	strcat(message, token); // concate the token to message
	strcat(key, token); // concate token to the key
	char *termChar = "@"; // terminating character for message
	strcat(key, termChar); // concate the terminating character to the key

	// concate two strings together for transport
	strcat(message, key);
	sendLength = strlen(message); // get the length of the entire message that will be sent

	// Set up the server address struct
	memset((char*)&serverAddress, '\0', sizeof(serverAddress)); // Clear out the address struct
	portNumber = atoi(argv[3]); // Get the port number, convert to an integer from a string
	serverAddress.sin_family = AF_INET; // Create a network-capable socket
	serverAddress.sin_port = htons(portNumber); // Store the port number
	serverHostInfo = gethostbyname("localhost"); // Convert the machine name into a special form of address
	if (serverHostInfo == NULL) { fprintf(stderr, "CLIENT: ERROR, no such host. Port %d\n", portNumber); exit(2); }
	memcpy((char*)&serverAddress.sin_addr.s_addr, (char*)serverHostInfo->h_addr, serverHostInfo->h_length); // Copy in the address

	// Set up the socket
	socketFD = socket(AF_INET, SOCK_STREAM, 0); // Create the socket
	if (socketFD < 0) { fprintf(stderr, "otp_enc error: problem opening socket\n"); exit(1); }
	
	// Connect to server
	if (connect(socketFD, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) // Connect socket to address
		{
			fprintf(stderr, "otp_dec error: problem connecting\n"); 
			exit(1);
		}

	// send special handshake 'code' to server that this is otp_dec
	char *handshake = "###";
	int codeLength = strlen(handshake);
	charsWritten = send(socketFD, handshake, codeLength, 0); // Write to the server
	if (charsWritten < 0)
		{
			fprintf(stderr, "otp_dec error: problem writing to socket\n");
			exit(1);
		}

	if (charsWritten < strlen(buffer)) printf("WARNING: Not all data written to socket!\n");

	// Get return message from server
	memset(buffer, '\0', sizeof(buffer)); // Clear out the buffer again for reuse
	charsRead = recv(socketFD, buffer, sizeof(buffer) - 1, 0); // Read data from the socket, leaving \0 at end
	if (charsRead < 0)
		{
			fprintf(stderr, "otp_dec error: problem reading from socket\n");
			exit(1);
		}

	if(strcmp(buffer, "ok") == 0)
	{
		// Send message to server
		charsWritten = send(socketFD, message, sendLength, 0); // Write to the server
		if (charsWritten < 0)
		{
			fprintf(stderr, "otp_dec error: problem writing to socket\n");
			exit(1);
		}

		if (charsWritten < strlen(buffer)) printf("WARNING: Not all data written to socket!\n");

		// Get return message from server
		memset(buffer, '\0', 200000); // Clear out the buffer again for reuse
		charsRead = recv(socketFD, buffer, 199999, 0); // Read data from the socket, leaving \0 at end
		if (charsRead < 0) 
		{
			fprintf(stderr, "otp_dec error: problem reading from socket\n");
			exit(1);
		}

		// look for the terminating character to stop reading
		while(!strstr(buffer, "@"))
		{
			charsRead += recv(socketFD, buffer + charsRead, 19999, 0); // keep reading!
			if (charsRead < 0) 
			{
				fprintf(stderr, "otp_dec error: problem reading from socket\n");
				exit(1);
			}
		}

		// erase last character for printing
		if(buffer[strlen(buffer) - 1] == '@')
		buffer[strlen(buffer) -1] = '\0';

		// print to stdout
		fprintf(stdout, buffer);
		fprintf(stdout, "\n"); // add newline character to stdout

		close(socketFD); // Close the socket
	}
	else
	{
		exit(2); // exit if handshake returns negative
	}
	return 0;
}