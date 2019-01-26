/************************************************************************
 **  Author: Erin Alltop
 **  Class: CS344 - Winter 2018
 **  Program Name: Program 2 - alltope.adventure.c
 **  Description:  This program is the first part of a two part
 **  larger program. This portion takes the directory and files created
 **  by the buildrooms program and opens the most recent directory,
 **  reads the contents and populates a struct with the attributes.
 **  It then plays a simple game, with error validation.
 **  There is also a feature to find the time with threads and mutex.
 **********************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <stdbool.h>

#define MIN_OUT 3
#define MAX_OUT 6
#define NUM_ROOMS 7


enum ROOM_TYPES{
    START_ROOM,
    MID_ROOM,
    END_ROOM
};

/********************************************************
 * Name: struct room
 * Description: This is the struct for
 * the rooms. Contains an ID, array for the name,
 * int for number of connections, and room array
 * for outgoing connections.
 ********************************************************/
struct room 
{
    int numConnections;
    struct room* outboundConnections[MAX_OUT];
    enum ROOM_TYPES roomType;
    char roomName[100];
};

// globals
char dirName[256];
struct room roomList[NUM_ROOMS];
int startRoom;
int steps = 0;
int finalPath[1000];
char *timeFile = "currentTime.txt";

// Mutex and threads
pthread_mutex_t locks[2];
pthread_t threads[2];



/************************************************************
 * Function: writeTime
 * Description: This fuction writes the current time to the 
 * file currentTime.txt
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: currentTime.txt written
 * Source: http://stackoverflow.com/questions/7411301/how-to-introduce-date-and-time-in-log-file
 ************************************************************/
void* writeTime()
{
    pthread_mutex_lock(&locks[0]); //lock thread

    FILE *fp;
    fp = fopen("currentTime.txt", "w+");
    char buff[50];
    struct tm *timeInfo;

    //time structs
    time_t now = time (0);
    timeInfo = localtime (&now);

    // format date and time. Was unable to get PM to be lowercase
    strftime (buff, sizeof(buff), "%I:%M%p, %A, %B %d, %Y\n", timeInfo);

    fputs(buff, fp);
    fclose(fp);

    pthread_mutex_unlock(&locks[0]); //unlock thread
    usleep(50);
}

 /************************************************************
  * Function: printTime()
  * Description: Prints contents of currentTime.txt file
  * Parameters: None
  * Pre-Conditions: Valid time.txt file
  * Post-Conditions: time.txt contents printed to screen
*************************************************************/
void* printTime() {

    pthread_mutex_lock(&locks[1]); // lock thread
    char buffer[50];
    FILE *fp;
    fp = fopen("currentTime.txt", "r");
    if(fp == NULL) {
        perror("Error\n");
    }
    else {
        //print buffer line
        fgets(buffer, 50, fp);
        printf("\n%s\n", buffer);
        fclose(fp);
    }
    pthread_mutex_unlock(&locks[1]); // unlcok thread
    usleep(50);
}


 /************************************************************
  * Function: InitializeThreads
  * Description: This function initializes the mutex threads
  * Parameters: None
  * Pre-Conditions: none
  * Post-Conditions: threads initialized
*************************************************************/
void InitializeThreads()
{
    int i;
    int close = 0;

    // Initialize both mutexes 
    for (i = 0; i < 2; i++) 
    {
        if(pthread_mutex_init(&locks[i], NULL) != 0)
        {
            printf("Failed to initialize mutex %d\n", i+1);
    }
    pthread_mutex_lock(&locks[i]); // lock for threads
  }

   pthread_create(&(threads[0]), NULL, &writeTime, NULL);
   pthread_create(&(threads[1]), NULL, &printTime, NULL);
}

/*********************************************************
 * Name: SelectFolder
 * Description: This function selects the newest directory
 * for use in the rest of the program.
 * NOTE: I used the code from reading 2.4 for this part.
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 ********************************************************/
void SelectFolder()
{
  int newestDirTime = -1; // Modified timestamp of newest subdir examined
  char targetDirPrefix[32] = "alltope.rooms."; // Prefix we're looking for
  char newestDirName[256]; // Holds the name of the newest dir that contains prefix
  memset(newestDirName, '\0', sizeof(newestDirName));

  DIR* dirToCheck; // Holds the directory we're starting in
  struct dirent *fileInDir; // Holds the current subdir of the starting dir
  struct stat dirAttributes; // Holds information we've gained about subdir

  dirToCheck = opendir("."); // Open up the directory this program was run in

  if (dirToCheck > 0) // Make sure the current directory could be opened
  {
    while ((fileInDir = readdir(dirToCheck)) != NULL) // Check each entry in dir
    {
      if (strstr(fileInDir->d_name, targetDirPrefix) != NULL) // If entry has prefix
      {
        stat(fileInDir->d_name, &dirAttributes); // Get attributes of the entry

        if ((int)dirAttributes.st_mtime > newestDirTime) // If this time is bigger
        {
          newestDirTime = (int)dirAttributes.st_mtime;
          memset(newestDirName, '\0', sizeof(newestDirName));
          strcpy(newestDirName, fileInDir->d_name);
        }
      }
    }
  }

  closedir(dirToCheck); // Close the directory we opened
  strcpy(dirName, newestDirName);
}


/*********************************************************
 * Name: InitializeGraph
 * Description: This function sets up the graph before
 * connections are made. It initializes the 
 * numConnections to 0 and adds NULL values
 * to outboundConnections for each room
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: rooms are initialized
 ********************************************************/
void InitializeGraph(){
    int i, j;

    // set number of connections to 0
    for(i = 0; i < NUM_ROOMS; i++)
    {
        roomList[i].numConnections = 0; 

        // set all outbound connections to NULL
         for(j = 0; j < MAX_OUT; j++)
         {
            roomList[i].outboundConnections[j] = NULL;
         } 
    }
}

/*********************************************************
 * Name: addRoomNames
 * Description: This function loops through the file
 * and adds room names to provide something to iterate
 * through more easily for adding the rest of the struct
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 ********************************************************/
void addRoomNames()
{
    DIR *dir;
    struct dirent *ent;
    int FileCount = 0;//iterates through the room structs

    InitializeGraph();//initalize the roomlist.

    /*Filling struct Names*/
    if ((dir = opendir (dirName)) != NULL) 
    {
    /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL) 
        {
            //printf ("%s\n", ent->d_name);
            if(strlen(ent->d_name) > 2)
            { // copy file name to struct.
                strcpy(roomList[FileCount].roomName,ent->d_name);
                FileCount++;
            }
        }
    }
}


/********************************************************
 * Name: getRoomPosition
 * Description: This functions returns the position of 
 * a room in roomList via the name. 
 * Parameters: char* name
 * Pre-Conditions: graph fully created
 * Post-Conditions: returns room position in roomList
 ********************************************************/
int getRoomPosition(char *name)
{
    int position = -1; // will return -1 if not found
    int i;

    for(i = 0; i < NUM_ROOMS; i++)
    {
        if( strcmp(roomList[i].roomName, name) == 0 )
        {
            position = i; // if found, set to i
        }
    }
    return position; 
}

/*********************************************************
 * Name: ConnectRoom
 * Description: This function connects rooms x and y together.
 * It does not check if this connection is valid.
 * Parameters: struct room* x, struct room* y
 * Pre-Conditions: rooms x and y created
 * Post-Conditions: rooms x and y are connected (one way)
 ********************************************************/
void ConnectRoom(int x,int y)
{
    // set int to reflect last position of outboundConnections array
    int xOut = roomList[x].numConnections;

    // set x and y to be last connection of array
    roomList[x].outboundConnections[xOut] = &roomList[y]; 

    // increment x number of connections
    roomList[x].numConnections++; 
}

/*********************************************************
 * Name: FillRoomList
 * Description: This function fills the roomList struct
 * with information from the files in the directory of the
 * rooms. room name, type, and connections are filled
 * Parameters: none
 * Pre-Conditions: struct is setup and initialized
 * Post-Conditions: struct setup complete
 ********************************************************/
void FillRoomList()
{
    char fileLine[256];
    char fileVal[256];

    FILE *fp; // file pointer
    int i, j;

    // add the room names and change directory
    addRoomNames(); 
    chdir(dirName); 

    // loop through the rooms to add room type and connections
    for(i = 0; i < NUM_ROOMS; i++)
    {
        // open room file for reading
        fp = fopen(roomList[i].roomName, "r");

        // error checking
        if(fp == NULL)
        { 
            printf("%s file unable to be opened\n", roomList[i].roomName);
            return;
        }

        // initialize to prevent undefined behavior 
        memset(fileLine, '\0', sizeof(fileLine));
        memset(fileVal, '\0', sizeof(fileVal));

        // loop through each line in the file
        while(fgets(fileLine, sizeof(fileLine), fp) != NULL)
        {
            // parse token at ":"
            strtok(fileLine, ":");
            strcpy(fileVal, strtok(NULL,""));

            // append end of line
            fileVal[strlen(fileVal) - 1] = '\0';
            fileLine[strlen(fileLine) - 1] = '\0';

            // this removes spaces from the string
            for(j = 0; j < strlen(fileVal); j++)
            { 
                fileVal[j] = fileVal[j + 1];
            }

            // if we find ROOM TYPE match from the token, assign room type
            if(strcmp(fileLine,"ROOM TYP") == 0)
            { 
                if(strcmp(fileVal,"START_ROOM") == 0)
                {
                    roomList[i].roomType = START_ROOM;
                    startRoom = i;          // assign these two to their
                    finalPath[steps] = i;   // global variables
                }
                else if(strcmp(fileVal,"END_ROOM") == 0)
                {
                    roomList[i].roomType = END_ROOM;
                }
                else
                {
                    roomList[i].roomType = MID_ROOM;
                }
            }           // add connections for the room
            else if(strcmp(fileLine,"CONNECTION ") == 0)
            { 
                int connectMe = getRoomPosition(fileVal);
                ConnectRoom(i, connectMe);
            }
        }

        // close the file!
        fclose(fp); 
    }

    // go back to main directory
    chdir(".."); 
}

/*********************************************************
 * Name: PrintFinal
 * Description: This function prints out the final message
 * to the user, along with the step count and the
 * path to victory.
 * Parameters: none
 * Pre-Conditions: game is over!
 * Post-Conditions: none
 ********************************************************/
void PrintFinal()
{

    printf("YOU HAVE FOUND THE END ROOM. CONGRATULATIONS!\n");
    printf("YOU TOOK %d STEPS. YOUR PATH TO VICTORY WAS:\n", steps);

    int i;

    // loop through steps to print out final victory path
    for(i = 0; i < steps + 1; i++)
    { 
        printf("%s\n", roomList[finalPath[i]].roomName);
    }
}

/*********************************************************
 * Name: PlayGame
 * Description: This function plays the game! It runs until
 * the game is over. It uses the inputbuffer from the user
 * input to determine which room to go, as well as performs
 * input validation for user input. It also records the
 * path taken and the number of steps it took to get there.
 * Parameters: none
 * Pre-Conditions: struct is setup completely
 * Post-Conditions: none
 ********************************************************/
void PlayGame()
{
    int currRoomPos, i;
    bool roomMatches = false;
    struct room currRoom;
    char InputBuffer[256];
    bool gameOver = false; 

    // this loops until the game is over
    do{
        //record step to room.
        currRoomPos = finalPath[steps];
        currRoom = roomList[currRoomPos];

        // print out current location
        printf("CURRENT LOCATION: %s\n",currRoom.roomName);
        printf("POSSIBLE CONNECTIONS:");

        // print out the possible connections
        for(i = 0; i < currRoom.numConnections - 1; i++)
        {
            printf(" %s,", currRoom.outboundConnections[i]->roomName);
        }
        // last one to include the '.' at the end
        printf(" %s.\n", currRoom.outboundConnections[i]->roomName);

        // get user input
        memset(InputBuffer, '\0', sizeof(InputBuffer));
        printf("WHERE TO? >");
        scanf("%255s", InputBuffer);
        printf("\n");

        // reset roomMatches to false for next iteration
        roomMatches = false;

       // iterate through the connections of the room and look for a match
        for(i = 0; i < currRoom.numConnections; i++)
        {
            // if a match is found, increment steps and move to selected room
            if(strcmp(InputBuffer, currRoom.outboundConnections[i]->roomName) == 0)
            { 
                ++steps; 
                finalPath[steps] = getRoomPosition(InputBuffer); // find the room in roomList

                // move to the next room
                currRoomPos = finalPath[steps]; 
                currRoom = roomList[currRoomPos];
                roomMatches = true; // match found!

                // if the end room is found, game over!
                if(currRoom.roomType == END_ROOM)
                { 
                   gameOver = true;
                }
            }
        }

        // if user input is equal to time, print it out
        if(strcmp(InputBuffer,"time") == 0 && roomMatches == false)
        {
            // unlock write thread
            pthread_mutex_unlock(&locks[0]);
            usleep(50);

            //lock write thread
            pthread_mutex_lock(&locks[0]);

            //unlock read thread
            pthread_mutex_unlock(&locks[1]);
            usleep(50);

            //lock read thread
            pthread_mutex_lock(&locks[1]);
            
        }
        // If no matches are found, print an error
        else if(roomMatches == false)
        {
            printf("HUH? I DON’T UNDERSTAND THAT ROOM. TRY AGAIN.\n\n");
        }
    }
    while(gameOver == false);

    // print the final output to the user
    PrintFinal();

    //destroy threads
    pthread_mutex_destroy(&locks[0]);
    pthread_mutex_destroy(&locks[1]);
    
}

/*********************************************************
 * Name: main
 * Description: Runs the program
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 ********************************************************/
int main(void)
{
    InitializeThreads();
    SelectFolder();
    FillRoomList();   
    PlayGame();
    return 0;
}
