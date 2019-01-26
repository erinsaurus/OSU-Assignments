/*************************************************************************************
** Author: Erin Alltop
** Date: 5/13/16
** Description: This program demonstrates the use of a stack and a queue. It allows
** the user to decide which concept they wish to execute, then it takes in the
** characters the user would like to display. For the stack, it adds the characters
** to the stack and then displays them in reverse order. For the queue, it adds the
** characters to the queue and then displays them in order.
**************************************************************************************/

#include "stack.hpp"
#include "queue.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

/***************************************************************************************
** Function: Main function
** Description: This function displays a menu, asks the user what they would like to do,
** takes input from the user for either function, and then executes the functions.
** in order to display the output to the screen.
***************************************************************************************/
int main()
{
	int pick = 0; //pick variable

	while(pick != 3)
	{
	std::cout << "\nThis program demonstrates a stack and a queue. Which would you like to try?" << std::endl;
	std::cout << "1) Stack " << std::endl;
	std::cout << "2) Queue " << std::endl;
	std::cout << "3) End Program " << std::endl;
	std::cin >> pick; //take in user pick

		while (pick != 1 && pick != 2 && pick != 3) //input validation if user enters anything other than a 1 or 2
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Please enter either a 1 or a 2 for your pick: " << std::endl;
			std::cin >> pick;
		}

		if (pick == 1) //if the user picks 1, perform stack demonstration
		{
			Stack stack; //create stack object
			std::string userString; //character input variable
			std::cout << "\nPlease enter a sentence to be reversed and press enter: " << std::endl;
			std::cin.ignore(); //clear out the previous input
			std::getline(std::cin, userString); //take in user input

			std::cout << "\nYour reversed string is: " << std::endl;
			//loop through each character in the string to add it to the stack
			for (unsigned int i = 0; i < userString.length(); i++)
			{
				stack.add(userString.at(i));
			}
			//display the stack
			stack.displayStack();
		}

		if (pick == 2)
		{
			Queue queue; //create queue object
			std::string userString; //character input variable
			std::cout << "\nPlease enter a sentence to be reversed and press enter: " << std::endl;
			std::cin.ignore(); //clear out the previous input
			std::getline(std::cin, userString); //take in user input

			std::cout << "\nYour string is: " << std::endl;
			//loop through each character in the string to add it to the queue
			for (unsigned int i = 0; i < userString.length(); i++)
			{
				queue.add(userString.at(i));
			}

			//display the queue
			queue.displayQueue();
		}
	}
	//system("PAUSE");
	return 0;
}
