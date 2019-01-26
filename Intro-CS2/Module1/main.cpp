/************************************************************************
** Author: Erin Alltop
** Date: 4/29/16
** Desciption: This program demonstrates three difference recursive
** functions: recursively reversing a string, adding the sum of
** array elements, and calculating the triangular number of rows.
** Input: User input for string sentence/word, array size and elements
** and rows.
** Output: Reversed string, sum of array elements, and triangular
** number of rows.
************************************************************************/

#include "functions.hpp"
#include <iostream>
#include <string>

int main()
{
	int choice; //choice variable

	do { // menu function
		std::cout << "Please select which function you would like to run: \n";
		std::cout << "1) Recursive String\n";
		std::cout << "2) Recursive Sum of an Array\n";
		std::cout << "3) Recursively Calculate Triangular Number\n";
		std::cout << "4) End Program\n";
		std::cin >> choice;

		while (choice <= 0) //input validation
		{
			std::cout << "Please enter a choice between 1-4: ";
			std::cin >> choice;
		}
		while (choice >= 5)
		{
			std::cout << "Plase enter a choice between 1-4: ";
			std::cin >> choice;

			while (choice <= 0)
			{
				std::cout << "Please enter a choice between 1-4: ";
				std::cin >> choice;
			}
		}

	Functions function; // Functions object

	if (choice == 1) //string
	{
		std::cin.ignore(); // clear out buffer
		std::string sent; //variable for string
		// take in user input and do input validation
		std::cout << "Please enter a word or sentence you would like to reverse: ";
		std::getline(std::cin, sent);
		while (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(100, '\n'); 
			std::cout << "Invalid  input! Please enter how many numbers you would like to sum: ";
			std::cin >> sent;
		}
		std::cout << "Your word or sentence reversed is: " << function.reverseString(sent); //call function
		std::cout << "\n" << std::endl;
	}

	if (choice == 2) //sum of array
	{
		int numArray; //variable for array size

		//take in input and do input validation
		std::cout << "How many numbers would you like to sum? ";
		std::cin >> numArray;
		while (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(100, '\n'); 
			std::cout << "Invalid  input! Please enter how many numbers you would like to sum: ";
			std::cin >> numArray;
		}
		std::cout << "Enter " << numArray << " numbers and press enter when finished: ";
		while (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(100, '\n'); 
			std::cout << "Invalid  input! Please enter " << numArray << " numbers and press enter when finished: ";
			std::cin >> numArray;
		}

		int size = numArray; //variable
		//dynamically allocate array
		int* array = NULL; 
		array = new int[size];
		for (int i = 0; i < size; i++) //take in array elements
		{
			int numbers;
			std::cin >> array[i];
			numbers = array[i];
		}

		std::cout << "Sum is: " << function.sumArray(array, size); //call function
		std::cout << std::endl;
		std::cout << std::endl;
		delete[] array; //delete array
	}

	if (choice == 3) //triangular number
	{
		
		int triangle; // variable

		//take in input and do input validation
		std::cout << "Enter an integer of rows and I will tell you how many";
		std::cout << " integers are in its triangle: ";
		std::cin >> triangle;
		while (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(100, '\n'); // it will ignore 100 characters or get to the end of the line.
			std::cout << "Invalid  input! Please enter an integer for a number of rows: ";
			std::cin >> triangle;
		}
		std::cout << "The triangular number is: " << function.triangleNum(triangle) << "\n" << std::endl; //call function
	}

	} while (choice != 4); // menu function continues until user ends the program

//system("PAUSE");
	return 0;
}
