/************************************************************************
 **  Author: Erin Alltop
 **  Class: CS344 - Winter 2018
 **  Program Name: Program 2 - alltope.buildrooms.c
 **  Description:  This program is the first part of a two part
 **  larger program. This portion creates files that contain 
 **  descriptions of a certain number of "rooms" and how they are
 **  connected to the other rooms in the game. This file also 
 **  contains a portion to report the current time through the use of
 **  mutexes and multithreading to the user. 
 **  This is used in conjunction with alltope.adventure.c to create
 **  a simple adventure game.
 **  NOTE: Pseudocode used was provided from additional reading 2.2
 **********************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// Constants to allow the game to be easily altered
#define MAX_OUT 6
#define MIN_OUT 3
#define NUM_ROOMS 7


/********************************************************
 * Name: struct room
 * Description: This is the struct for
 * the rooms. Contains an ID, array for the name,
 * int for number of connections, and room array
 * for outgoing connections.
 ********************************************************/
struct room {
	int id;
	int initCheck;
	char roomName[50];
	int numConnections;
	struct room* outboundConnections[NUM_ROOMS];
	char roomType[50];
};

// Using global arrays for room names, final room list, and room types
char* roomNames[10] = {"Icecrown", "Nagrand", "Westfall", "Outland", "Draenor", "Azshara", "Tanaris", "Pandaria", "Durator", "Uldum"};
struct room roomList[NUM_ROOMS];
char* roomTypes[3] = {"START_ROOM", "END_ROOM", "MID_ROOM"};


/*********************************************************
 * Name: IsGraphFull
 * Description: This function returns true if
 * all rooms have 3 to 6 outbound connections,
 * and false otherwise.
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 ********************************************************/
bool IsGraphFull()
{
	bool result = true; //start true
	int i = 0;

	// Loop through all rooms. If any room has less than
	// 3 connections, then the room graph is not full
	for(i = 0; i < NUM_ROOMS; i++)
	{
		if(roomList[i].numConnections < MIN_OUT)
		{
			result = false; // Change to false if connections < 3
		}
	}
	
	return result;

}

/*********************************************************
 * Name: IsSameRoom
 * Description: This function returns true if room x
 * and y are the same room, and false otherwise.
 * Parameters: rooms x and y for comparison
 * Pre-Conditions: rooms x and y are created
 * Post-Conditions: none
 ********************************************************/
bool IsSameRoom(struct room* x, struct room* y)
{
	bool result = false; // start false

	// if the rooms have the same name, change to true
	if(!strcmp(x->roomName, y->roomName)) 
		result = true;

	return result;
}

/*********************************************************
 * Name: CanAddConnectionFrom
 * Description: This function returns true if a connection
 * can be added from room x, and false otherwise.
 * Parameters: struct room* x to be checked
 * Pre-Conditions: room x created
 * Post-Conditions: none
 ********************************************************/
bool CanAddConnectionFrom(struct room* x)
{
	bool result = true; // start true

	// if number of connections is greater than 5,
	// connection cannot be made (maxed out)
	if(x->numConnections > (MAX_OUT - 1))
		result = false; // change to false

	return result;
}

/*********************************************************
 * Name: ConnectionAlreadyExists
 * Description: This function returns true if a connection
 * from room x to room y already exists, and false otherwise.
 * Parameters: struct room* x, struct room* y
 * Pre-Conditions: rooms x and y created
 * Post-Conditions: none
 ********************************************************/
bool ConnectionAlreadyExists(struct room* x, struct room* y)
{
	bool result = false; // start false
	int i;

	// Loop through all connections of x 
	for(i = 0; i < x->numConnections; i++)
	{
		// if connection has the same name as y, a connection already exists
		if(!strcmp(x->outboundConnections[i]->roomName, y->roomName))
			result = true; // change to true
	}

	return result;	
}

/*********************************************************
 * Name: GetRandomRoom
 * Description: This function returns a random room.
 * It does not validate if a connection can be added.
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: random room is returned from function
 ********************************************************/
struct room* GetRandomRoom()
{
	int randomRoom;
	randomRoom = rand() % NUM_ROOMS; // random number from NUM_ROOMS
	return &roomList[randomRoom]; // return roomList @ random number
}

/*********************************************************
 * Name: ConnectRoom
 * Description: This function connects rooms x and y together.
 * It does not check if this connection is valid.
 * Parameters: struct room* x, struct room* y
 * Pre-Conditions: rooms x and y created
 * Post-Conditions: rooms x and y are connected (one way)
 ********************************************************/
void ConnectRoom(struct room* x, struct room* y)
{
	// set ints to reflect last position of outboundConnections array
	int xOut = x->numConnections;
	int yOut = y->numConnections;

	// set x and y to be last connection of array
	x->outboundConnections[xOut] = y;
	y->outboundConnections[yOut] = x;

	// increment x number of connections
	x->numConnections++;
}

/*********************************************************
 * Name: AddRandomConnection
 * Description: This function adds a random, valid 
 * outbound connection from a room to another room
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: rooms a and b are connected (both ways)
 ********************************************************/
void AddRandomConnection()
{
	struct room* A; // pointers to rooms A and B
	struct room* B;
	
	while(true)
	{
		A = GetRandomRoom();
		
		// if a connection can be added, we are done!
		if (CanAddConnectionFrom(A) == true)
			break;
	}

	do
	{
		B = GetRandomRoom();

	} // loop until both A and be can be connected, are not the same room, and don't already have a connection
	while(CanAddConnectionFrom(B) == false || IsSameRoom(A, B) == true || ConnectionAlreadyExists(A, B) == true);

	// add connections (both ways!)
	ConnectRoom(A, B); 
	ConnectRoom(B, A); 
}

/*********************************************************
 * Name: PrintRoomOutboundConnection
 * Description: This function is used for printing various
 * testing statements. Not to be turned in.
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 ********************************************************/
/*void PrintRoomOutboundConnections(struct room* input)
{
	printf("%s has %d connections.\n",
		input->roomName, input->numConnections);
	printf("The rooms connected to (%s/%d) are:\n",
		input->roomName, input->id);
	fflush(stdout);

	int i;
	for(i = 0; i < input->numConnections; i++)
	{	printf("Loop # %d", i);
		fflush(stdout);
		printf(" (%s/%d)\n", input->outboundConnections[i]->roomName,
			input->outboundConnections[i]->id);
		fflush(stdout);
	}
	return;
}*/

/*********************************************************
 * Name: InitializeGraph
 * Description: This function sets up the graph before
 * connections are made. It initializes the id,
 * numConnections, and randomly assigns room names and
 * room types for each room.
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 ********************************************************/
void InitializeGraph()
{
	int i, randomType;
	struct room* randomRoom;
	bool result = true;

	// initial initialization
	for(i = 0; i < NUM_ROOMS; i++)
	{
		roomList[i].id = i;
		roomList[i].initCheck = 0; // this is going to be used to indicate if room has been added
		roomList[i].numConnections = 0;
	}

	for(i = 0; i < NUM_ROOMS; i++)
	{
		randomRoom = GetRandomRoom(); // get first random room

		// while room has been added to list (initCheck = 1)
		while(randomRoom->initCheck == 1)
		{
			// get another random room
			randomRoom = GetRandomRoom();
		}

		// once room has been found, add name, change initCheck, and give room type
		strcpy(randomRoom->roomName, roomNames[i]); 
		randomRoom->initCheck = 1;
		strcpy(roomList[i].roomType, roomTypes[2]); // MID_ROOM
	}

	// Assign start and end rooms for first and last of random list
	strcpy(roomList[0].roomType, roomTypes[0]); // START_ROOM
	strcpy(roomList[NUM_ROOMS-1].roomType, roomTypes[1]); // END_ROOM
}

/*********************************************************
 * Name: createDir
 * Description: This function sets up the the directory
 * for the files to be inserted.
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: directory is setup and returned
 ********************************************************/
char* createDir()
{
	int pid = getpid(); 
	char* dirAddress = "alltope.rooms.";
	char* directory = malloc(30); //allocate memory for directory

	sprintf(directory, "%s%d", dirAddress, pid); //add string together with pid

	mkdir(directory, 0700); //make directory with permissions

	return directory;
}

/*********************************************************
 * Name: writeFiles
 * Description: This function writes the required information
 * to the file -> room name, connections, and type
 * Parameters: struct room* input, char* directory
 * Pre-Conditions: graph is done and connected, 
 * directory is created
 * Post-Conditions: files are written and closed
 ********************************************************/
void writeFiles(struct room* input, char* directory)
{
	chdir(directory); // change directory
	int i, j;

	 // Open the file to write 
    for(i = 0; i < NUM_ROOMS; i++) {

    	// room names
        FILE *fp = fopen(input[i].roomName, "w");
        fprintf(fp, "ROOM NAME: %s\n", input[i].roomName);

        // connections
        for(j = 0; j < input[i].numConnections; j++) {
            fprintf(fp, "CONNECTION %d: %s\n", j+1, input[i].outboundConnections[j]->roomName);
        }

        // room type
        fprintf(fp, "ROOM TYPE: %s\n", input[i].roomType);

        // close file
        fclose(fp);
    }
}

/*********************************************************
 * Name: createFiles
 * Description: This function creates the room directory
 * files, calls the AddRandomConnection() function until
 * connections are complete, and calls the writeFiles()
 * function to write the roomList to the files
 * Parameters: none
 * Pre-Conditions: graph initialized, directory is created
 * Post-Conditions: rooms are connected, files written
 ********************************************************/
void createFiles()
{
	int i, j;
	int pid = getpid();
	char *roomDir = createDir(); // get room directory

	// while graph not full, keep adding connections
	while(IsGraphFull() == false)
	{
		AddRandomConnection();
	}
	
	// Write files to directory
	writeFiles(roomList, roomDir);
}

/*********************************************************
 * Name: main
 * Description: Runs the program
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 ********************************************************/
int main()
{
	srand(time(NULL)); //random seed
	InitializeGraph(); 
	createFiles();
	return 0;
}

	
