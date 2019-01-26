/*********************************************************
 ** Erin Alltop
 ** CS344 - Winter 2018
 ** Desc: This program is a basic shell written in C. Like
 ** a bash shell, it has built in commands exit, cd, and
 ** status. It also supports comments starting with #. 
 ** It allows for redirection of standard input and 
 ** standard output and supports both foreground and 
 ** background processes.
 ********************************************************/
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/wait.h> 
#include <string.h> 
#include <sys/types.h> 
#include <fcntl.h> 
#include <unistd.h> 
#include <signal.h> 
#include <sys/stat.h> 
#include <stdbool.h>

#define MAX_ARGS 513
#define MAX_COMMANDS 2048

char* argsArr[MAX_ARGS];
char* inFile = NULL;
char* outFile = NULL;
bool backgroundCommand = false;
int fileIn = -1;
int fileOut = -1;
bool fgMode = false;


void catchSIGINT(int signo)
{       
  char* message;
  char* message2 = "\n: ";

  if(fgMode)
  {
    fgMode = false;
    message = "\nEntering foreground-only mode (& is now ignored)\n";
    write(STDOUT_FILENO, message, 49);
   // printf("\n: ");
    fflush(stdout);
    return;
  }    
  else
    fgMode = true;
    message = "\nExiting foreground-only mode\n";
    write(STDOUT_FILENO, message, 30);
  //  printf(": ");
    fflush(stdout);
    return;

}


void catchSIGTSTP(int signal)
{
  char* message;
  char* message2 = "\n: ";

  if(fgMode)
  {
    fgMode = false;
    message = "\nEntering foreground-only mode (& is now ignored)\n";
    write(STDOUT_FILENO, message, 49);
  //  write(STDOUT_FILENO, message2, 3);
    fflush(stdout);
    return;
  }    
  else
    fgMode = true;
    message = "\nExiting foreground-only mode\n";
    write(STDOUT_FILENO, message, 30);
   // write(STDOUT_FILENO, message2, 3);
    fflush(stdout);
    return;

  //exit(0);
}

/*********************************************************
 * Name: cleanUp
 * Description: This function resets variables and the
 * argsArr to NULL for the next command to use. It also
 * gives the exit status and terminating signal if the
 * background pid is complete.
 * Parameters: int pid, int status
 * Pre-Conditions: none
 * Post-Conditions: variables and array are reset
 ********************************************************/
void cleanUp(int pid)
{
      int i;
     
     // set argsArr to NULL for next command
      for (i = 0; i < MAX_ARGS; i++) 
      {
        argsArr[i] = NULL;
      }

      //Set files to null to be reused for future commands
      inFile = NULL;
      outFile = NULL;
      backgroundCommand = false; // reset to false
      fileIn = -1;
      fileOut = -1;


}

/*********************************************************
 * Name: childProcesses
 * Description: This runs if we are on a child process.
 * It opens / closes correct files as necessary with
 * error handling                                                                     
 * Parameters: none
 * Pre-Conditions: processes are setup
 * Post-Conditions: none
 ********************************************************/
void childProcess()
{
  // If there is a file given for input, open the file
  if (inFile != NULL) 
  { 
      fileIn = open(inFile, O_RDONLY);

      // If there is an issue with the file, output an error
      if (fileIn == -1) 
      {
          fprintf(stderr, "Cannot open %s for input\n", inFile);
          fflush(stdout);
          exit(1);
      } 

      // If there is an issue with redirection, output an error
      else if (dup2(fileIn, 0) == -1) 
      { 
          fprintf(stderr, "dup2 error");
          exit(1);
      }

          close(fileIn); // close the file!
    } 

    // If the process is in the background, redirect to /dev/null, if no input file given
    else if (backgroundCommand) 
    {
       fileIn = open("/dev/null", O_RDONLY);

        // If there is an issue, output an error
       if (fileIn == -1) 
       {
         fprintf(stderr, "open error");
          exit(1);
        } 

        // If there is an issue with redirection, output an error
        else if (dup2(fileIn, 0) == -1) 
        { 
          fprintf(stderr, "dup2 error");
          exit(1);
        }

        close(fileIn); // close the file!
    } 

      // If there is an output file give, open the file
      else if (outFile != NULL) 
      { 
          fileOut = open(outFile, O_WRONLY | O_CREAT | O_TRUNC, 0744);

          // If there is an issue with the file, output error
          if (fileOut == -1) 
          {
            fprintf(stderr, "Unable to open %s\n", outFile);
            fflush(stdout);
            exit(1);
          }

          // If there is an error with the redirection, output error
          if (dup2(fileOut, 1) == -1) 
          { 
             fprintf(stderr, "dup2 error");
             exit(1);
          }

            //close file stream
            close(fileOut);
       }

      // If the command is not recognized, inform user
      if (execvp(argsArr[0], argsArr)) 
      { 
           // Exit command
          fprintf(stderr, "Command %s is not a valid command.\n", argsArr[0]);
          fflush(stdout);
          exit(1);
      }
}

/*********************************************************
 * Name: parentProcess
 * Description: This runs of we are on a parent process.
 * It waits for the foreground process to complete if
 * there is one, otherwise it prints out the 
 * background pid.
 * Parameters: none
 * Pre-Conditions: processes are setup
 * Post-Conditions: none
 ********************************************************/
void parentProcess(int pid, int status)
{

    // If the process is not in the background, wait for foreground to complete
    if (!backgroundCommand) 
    { 
        do 
        {
            waitpid(pid, &status, 0); // waiting....

        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    } 

    // If the process is in the background, print the pid
    else 
    {
        printf("Background pid: %d\n", pid);
    }
}


/*********************************************************
 * Name: runShellLoop
 * Description: This function runs the loop for the shell.
 * Gets and parses user input. Runs background and
 * foreground processes as necessary.
 * Parameters: none
 * Pre-Conditions: signal handlers setup
 * Post-Conditions: none
 ********************************************************/
void runShell() 
  {
    char* userInput = NULL;
    int numArgs;
    char* token;
    int status = 0;
    int pid;
    bool exited = false;
    char* special = "$$";
    char *pos;
    char* foundIt = NULL;

  struct sigaction SIGINT_action = {{0}},
                   SIGTSTP_action = {{0}};

  SIGINT_action.sa_handler = SIG_IGN;

  SIGTSTP_action.sa_handler = catchSIGTSTP;
  sigfillset(&SIGTSTP_action.sa_mask);
  SIGTSTP_action.sa_flags = SA_RESTART;

  sigaction(SIGINT, &SIGINT_action, NULL);
  sigaction(SIGTSTP, &SIGTSTP_action, NULL);

    while (!exited) 
    {
        // The prompt
        printf(": ");
        fflush(stdout);

        //Read in a userInput 
        ssize_t size = 0;

        // Get the user input
        if (!(getline( &userInput, &size, stdin))) 
        {
            exit(0); //end if this is the end of the file
        } 


          // If there is an "$$" substring, replace it with pid
         char pidstr[6];
         snprintf(pidstr, 6, "%d", (int)getpid()); // convert pid to string
         pos = strstr(userInput, special);
         if(pos != NULL)
         {
           strcpy(pos + strlen(pidstr), pos + 2);
           strncpy(pos, pidstr, strlen(pidstr));
         }


        // Getting the first token, initial command
        numArgs = 0;
        token = strtok(userInput, "  \n"); 

        // while there more tokens 
      while (token != NULL) 
      {

        // there is an input file name
        if (strcmp(token, "<") == 0) 
        {
             token = strtok(NULL, " \n");

             // copy the file name to inFile variable
             inFile = strdup(token); 
             
             // get the next argument 
             token = strtok(NULL, " \n");
        } 

        // if there is an output file name
        else if (strcmp(token, ">") == 0) 
        {
          token = strtok(NULL, " \n");

          // copy the file name to outFile variable
          outFile = strdup(token); 

          // get the next argument
          token = strtok(NULL, " \n");
        } 

        // if the command is for a background process
        //Also allows for ignoring extraneous & symbols 
        else if (strcmp(token, "&") == 0) 
        {
            // set backgroundCommand to true
             backgroundCommand = true; 
             break;
        } 

        // otherwise this is an argument or command
        else 
        {
          //store in argsArr*/
          argsArr[numArgs] = strdup(token);

          //get next token
          token = strtok(NULL, " \n");
          numArgs++; 
        }
      }

      // end of array must be NULL
      argsArr[numArgs] = NULL;

 
      if (argsArr[0] == NULL)
      {
        continue; // do nothing if no command is given
      } 

      // Exit if requested
      else if (strcmp(argsArr[0], "exit") == 0) 
      { 
        exit(0);
        exited = true;
      } 

      else if (!(strncmp(argsArr[0], "#", 1)))
      {
        continue; // do nothing if comment
      }

      else if (strcmp(argsArr[0], "status") == 0) 
      { 
        if (WIFEXITED(status)) 
        { 
        //print exit status
          printf("Exit status: %d\n", WEXITSTATUS(status));
        } 

        else 
        { //else print terminating signal
          printf("Terminating signal %d\n", status);
        }
      } 

      else if (strcmp(argsArr[0], "cd") == 0) 
      { 
        // If there is no command with cd, go to home directory
        if (argsArr[1] == NULL) 
        {
          chdir(getenv("HOME"));
        } 
        else 
        { 
          // Otherwise go to specified directory
          chdir(argsArr[1]);
        }
      } 

      else 
      {     // Other commands
        pid = fork();

        switch(pid)
        {
            case 0: // Child process

                SIGTSTP_action.sa_handler = SIG_IGN; // ignore SIGTSTP on child processes
                sigaction(SIGTSTP, &SIGTSTP_action, NULL);

                if(!backgroundCommand) // Foreground process
                {
                    SIGINT_action.sa_handler = SIG_DFL; //set to default is foreground
                      
                }
                else if (backgroundCommand)
                {
                 SIGTSTP_action.sa_handler = SIG_IGN; //set to ignore if background 
                }

                sigaction(SIGINT, &SIGINT_action, NULL);
                childProcess();

            case -1: // Error

                fprintf(stderr, "fork error");
                status = 1;
                break;

            default: // parent process

                parentProcess(pid, status);
        }
      }



      // Check if background processes have completed
      pid = waitpid(-1, &status, WNOHANG);

      while (pid > 0) 
      {
        printf("Background process %d complete\n", pid);

        // If it ended successfully, print the status
        if (WIFEXITED(status)) 
        { 
          printf("Exit status: %d\n", WEXITSTATUS(status));
        } 

        // If it was terminated, print status
        else 
        { 
          printf("Terminating signal: %d\n", status);
        }

        //wait for process to change state
        pid = waitpid(-1, &status, WNOHANG);
      }
        cleanUp(pid);
    }

  }

/*********************************************************
 * Name: main
 * Description: This runs the program!
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 ********************************************************/
int main() 
{
  runShell();
  return 0;
}