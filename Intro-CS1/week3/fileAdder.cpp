/*************************************************************************
 ** Author: Erin Alltop
 ** Date: 1/18/16
 ** Description: A program that opens a file of the user's choosing and
    calculates the sum of the integers in the file.
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main ( )

{

	ifstream inputFile;
	string filename;
	int fileIntegers = 0;
	double numbers;
	double sum;

	//Get the name of the file to open from the user
	cout << "What is the name of the file you would like to use? \n";
	cin >> filename;

	//Open the input file
	inputFile.open(filename.c_str());

	//If the file successfully opened, process it
	
	if (inputFile)
	{
	    //Read the numbers from the file and calculate the sum
	   while (inputFile >> numbers)
		{
		sum += numbers;
		fileIntegers++;
		}

		//Display sum of integers in file
		cout << sum << endl;

		//Close the file
		inputFile.close();

	}
	

	else // The file could not be found and opened

	{  //Display an error message
	   cout << "Could not access file \n";

	}


}

