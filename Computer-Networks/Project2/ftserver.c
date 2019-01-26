/*********************************************************************
 ** Erin Alltop
 ** CS372 - Spring 2018
 ** Project 2
 ** This is a simple server to be used in conjunction with ftclient.py.
 ** Together they create a server-client relationship for a file
 ** transfer program. The client can view contents of a directory
 ** and files on the server over a TCP connection. 
 ** NOTE: I used portions of code from a previous class as well as from
 ** Beej's guide to put together this server.
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <dirent.h>
#include <fcntl.h>

/*******************************************************************************
 * Setup the address information for the data connection
 * Arguments: address, port
 * I re-used portions of my last assignment here. 
 ******************************************************************************/
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


/*******************************************************************************
 * Setup a socket for data connection
 * ftserver acting acting as a sort of client for this connection
 * I re-used portions of my last assignment here. 
 ******************************************************************************/
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

/*******************************************************************************
 * This sends a message to the client
 * Arguments: the data port connection, message to send.
 * I re-used portions of my last assignment here. 
 ******************************************************************************/
void sendMessage(int sockfd, char *serverMsg)
{
	int bytes_sent = 0; // error detection  

	// send the message
	bytes_sent = send(sockfd, serverMsg, strlen(serverMsg), 0);  
		
	// Print an error if the number of bytes sent were less than 0
	if(bytes_sent == -1) {fprintf(stderr, "Error sending message.\n"); exit(1);}
}

/*******************************************************************************
 * This receives a message from the client
 * Arguments: the data port connection, message to receive char*
 * I re-used portions of my last assignment here. 
 ******************************************************************************/
void receiveMessage(int sockfd, char *clientMsg)
{
	int status;

	// Clear out the junk from the clientMsg
	memset(clientMsg, 0, sizeof(clientMsg));

	// Print an error if status is less than 0
	status = recv(sockfd, clientMsg, 500, 0); 
	
	if (status == -1) {fprintf(stderr, "Error receiving message.\n"); exit(1);}
                                                         
	printf("%s\n",clientMsg);
}


/*******************************************************************************
 * Creates a string array on the heap used for files in directory
 * Arguments: an integer number of files
 * Reference: https://stackoverflow.com/questions/5935933/dynamically-create-an
 * -array-of-strings-with-malloc
 ******************************************************************************/
char ** createArray(int size)
{
	char ** array = malloc(size*sizeof(char *));
	int i = 0;
	for(; i < size; i++){
		array[i] = malloc(100*sizeof(char));
		memset(array[i],0,sizeof(array[i]));
	}
	return array;
}

/*******************************************************************************
 * Deletes the string array after use. 
 * Arguments: array and number of files
 * Reference: https://stackoverflow.com/questions/4733649/freeing-memory-which-
 * has-been-allocated-to-an-array-of-char-pointers-strings
 ******************************************************************************/
void deleteArray(char ** array, int size)
{
	int i = 0;
	for (; i < size; i++){
		free(array[i]);
	}
	free(array);
}


/*******************************************************************************
 * Retrieves files from the directory to send to client. Copies them 
 * into an array.
 * Arguments: array
 * Reference: https://www.sanfoundry.com/c-program-list-files-directory/
 ******************************************************************************/
int getFiles(char ** files)
{
	DIR * d;
	struct dirent * dir;
	d = opendir(".");
	int i = 0;
	if (d){
		while ((dir = readdir(d)) != NULL){
			if (dir->d_type == DT_REG){
				strcpy(files[i], dir->d_name);
				i++;
			}
		}
		closedir(d);
	}
	return i;
}

/*******************************************************************************
 * Sends the directory to the client.
 * Arguments: The data connection, files, and number of files
 * in the directory
 ******************************************************************************/
void sendDirectory(int sockfd, char ** files, int numFiles){

	// loop through filenames and send to client
	int i;
	for (i = 0; i < numFiles; i++)
	{
		send(sockfd, files[i], 100, 0);
	}

	// send a terminating message to the client
	char * termMsg = "done";
	send(sockfd, termMsg, strlen(termMsg),0);
}

/*******************************************************************************
 * This send the file to the client. It loops through the buffer
 * until no bytes are left, and then sends what was found to the client. 
 * Arguments: the data connection and the fileName
 * Reference: http://stackoverflow.com/questions/2014033/send-and-receive-a-
 * file-in-socket-programming-in-linux-with-c-c-gcc-g
 ******************************************************************************/
void sendFile(int sockfd, char *fileName)
{
	printf("Sending file..\n");
	char buffer[20000];
	memset(buffer, 0, sizeof(buffer));

	// open the file
	int fd = open(fileName, O_RDONLY);

	while (1) 
	{
		// Read data into buffer.
		int bytes_read = read(fd, buffer, sizeof(buffer)-1);

		if (bytes_read == 0) // We're done reading from the file
			break;

		if (bytes_read < 0) 
		{
			fprintf(stderr, "Error reading file.\n");
			return;
		}

		void *p = buffer; // Tracks where in the buffer we are

		while (bytes_read > 0) // loop while there is still more to be read
		{
			int bytes_written = write(sockfd, p, bytes_read);
			if (bytes_written < 0) 
			{
				fprintf(stderr, "Error writing to socket\n");
				return;
			}

			bytes_read -= bytes_written;
			p += bytes_written;
		}
	}

	// clear out the buffer and send the done message
	memset(buffer, 0, sizeof(buffer));
	strcpy(buffer, "__done__");
	send(sockfd, buffer, sizeof(buffer), 0);

}

/*******************************************************************************
 * This function looks through the array of files and looks for one
 * matching the filename given by the client. If it exists, change
 * variable to 1, otherwise it is 0.
 * Arguments: the file array, number of files, and filename we are looking for
 ******************************************************************************/
int findFile(char **files, int numFiles, char *fileName)
{
	int exists = 0;
	int i;
	for (i = 0; i < numFiles; i++)
	{
		if(strcmp(files[i], fileName) == 0)
		{
			exists = 1; // Found it!
		}
	}

	return exists;
}

/*******************************************************************************
 * Handles the data requests from the client. Sends requested information.
 * Arguments: The data connection and the client command
 * Reference: https://www.tutorialspoint.com/c_standard_library/c_function_sprintf.htm
 ******************************************************************************/
void handleRequest(int sockfd, char *command, char *fileName)
{
	// setup an array for the files and get number of files
	char **files = createArray(100);
	int numFiles = getFiles(files);
	char *good = "ok";
	
	if(strcmp(command, "-l") == 0)
	{
		// send the array to the client 
		sendDirectory(sockfd, files, numFiles);
	}
	else
	{	
		printf("Looking for file..\n");
		// look for the requested file
		int foundFile = findFile(files, numFiles, fileName);
		if(foundFile == 1)
		{
			printf("File found on server.\n");
			char newFileName[100];
			memset(newFileName, 0, sizeof(newFileName));
			strcpy(newFileName, "./");
			char *end = newFileName + strlen(newFileName);
			end += sprintf(end, "%s", fileName);
			sendFile(sockfd, newFileName);
		}
		else
		{	// send a message to client if file isn't found
			char *message = "File not found.";
			sendMessage(sockfd, message);
		}
	}

	deleteArray(files, 100);
}

/*******************************************************************************
 * In main, we are setting up the initial TCP control connection and getting
 * the commands from client that we will use over the data connection.
 * There was not an elegent way to parse out the first setup funtions from main.

 * For the initial setup I referenced some previous coursework as well as
 * Beej's guide and Project 1. 
 
 * This program also employs the use of multi-threading and can accept up
 * to 5 child connections.  
 ******************************************************************************/
int main(int argc, char *argv[])
{
	// Setup the main TCP Control connection
	int listenSocketFD, establishedConnectionFD, portNumber, charsRead, status;
	socklen_t sizeOfClientInfo;
	char buffer[200000];
	struct sockaddr_in serverAddress, clientAddress;

	if (argc < 2) { fprintf(stderr,"USAGE: %s port\n", argv[0]); exit(1); } // Check usage & args

	// Set up the address struct for this process (the server)
	memset((char *)&serverAddress, '\0', sizeof(serverAddress));      // Clear out the address struct
	portNumber = atoi(argv[1]);										  // Get the port number, convert to an integer from a string
	serverAddress.sin_family = AF_INET; 							  // Create a network-capable socket
	serverAddress.sin_port = htons(portNumber); 					  // Store the port number
	serverAddress.sin_addr.s_addr = INADDR_ANY; 					  // Any address is allowed for connection to this process

	// Set up the socket
	listenSocketFD = socket(AF_INET, SOCK_STREAM, 0); // Create the socket
	if (listenSocketFD < 0) { fprintf(stderr, "server: problem opening socket\n"); exit(1); }

	// Enable the socket to begin listening
	if (bind(listenSocketFD, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) // Connect socket to port
	{
		fprintf(stderr, "server: problem with binding\n");
		exit(1);
	}	
	listen(listenSocketFD, 5); 											// Flip the socket on - it can now receive up to 5 connections

	printf("Listening on port: %d\n", portNumber);

	while(1) // Loop children until SIGINT ins received
	{
		// Accept a connection, blocking if one is not available until one connects
		sizeOfClientInfo = sizeof(clientAddress); 					// Get the size of the address for the client that will connect
		establishedConnectionFD = accept(listenSocketFD, (struct sockaddr *)&clientAddress, &sizeOfClientInfo); 
		if (establishedConnectionFD < 0)
		{
			fprintf(stderr, "server error: problem with accept\n");
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

				// receive the message from the client
				memset(buffer, '\0', 200000);
				charsRead = recv(establishedConnectionFD, buffer, 199999, 0); 	
				if (charsRead < 0) 
				{
					fprintf(stderr, "server error: problem reading from socket\n");
					exit(1);
				}

				// if ftclient does not sent a valid command, send an error message to ftclient
				if((strncmp(buffer, "-l", 2) != 0) && (strncmp(buffer, "-g", 2) != 0))
				{
					printf("Error: invalid command from client.\n");
					send(establishedConnectionFD, "Server error: Invalid command.", 30, 0); 
				}
				else
				{	// send ok message to client that we are good to go
					send(establishedConnectionFD, "ok", 2, 0); 

					// Parse out command elements
					char *command, *fileName, *serverName, *dataPort;
					command = strtok(buffer, ",");
					fileName = strtok(NULL, ",");
					serverName = strtok(NULL, ",");
					dataPort = strtok(NULL, ",");
					//printf("command: %s\nfileName: %s\nserverName: %s\ndataPort: %s\n", command, fileName, serverName, dataPort);

					// Establish data connection with client
					struct addrinfo* servinfo = startUp(serverName, dataPort);   
					int sockfd = setupSocket(servinfo);  
					handleRequest(sockfd, command, fileName);
					close(sockfd);
					printf("Data connection closed.\n");

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