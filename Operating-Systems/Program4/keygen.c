/**************************************************
 ** Erin Alltop
 ** CS344 - Winter 2018 - OTP
 ** This program is one of five. It creates a key 
 ** file of specified length. The characters in
 ** the file generated are any of 27 characters
 ** (26 uppercase alphabet and space character).
 ** These are generated randomly.
 ** This key is for use in the other five programs
 ** to encrypt and decrypt a plaintext message.
 **************************************************/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <time.h>

int main(int argc, char **argv)
{
	int i, keyLength;
	srand(time(0)); // random seed
	int randomNum = -1;

	// if arguments are less than 2, print an error
	if(argc != 2)
	{
		fprintf(stderr, "Error: problem with arguments.\n");
		exit(1);
	}

	// get and store specified length, converted to int
	keyLength = atoi(argv[1]);

	// randomly generate a character string of specified length
	// characters are 26 uppercase alphabet and space
	for(i = 0; i < keyLength; i++)
	{
		randomNum = rand() % 27 + 'A';

		if(randomNum == -1)
			{
				fprintf(stderr, "Something went wrong with random generation.\n");
				exit(1);
			}

		else
		{
			if(randomNum == 26 + 'A')
			{
				randomNum = 32; // convert to space char
			}

			// print to stdout
			fprintf(stdout, "%c", randomNum);
		}

		randomNum = -1; //reset to -1 for error checking
	}

	// add newline as the last character
	fprintf(stdout, "\n");

	return 0;
}
