/**************************************************************************************************
** Author: Erin Alltop
** Date: 5/19/16
** Description: This program is a fantasy combat game. It allows the user to pick two teams of
** fighters to compete in a tournament. The two teams fight each other until one team has lost.
** The program gives several options for output as well.
** Input: User choices for number of fighters, types of fighters, and names of fighters.
** Output: Step-by-step battle stats until one team loses
**************************************************************************************************/

#include <iostream>
#include "barbarian.hpp"
#include "medusa.hpp"
#include "babayaga.hpp"
#include "bluemen.hpp"
#include "harrypotter.hpp"
#include "menu.hpp"
#include "tournament.hpp"
#include <ctime>
#include <string>
#include <cstdlib>

int main()
{
	srand(time(0)); // random seed for the program

	 //variables for menu choices
	int amount;
	int type;
	std::string name;
	Menu menu; //menu object to call menu function
	Tournament fight; //Tournament object to run tournament

	//user input for number of fighters and input validation
	std::cout << "This is a fantasy combat tournament game! How many ";
	std::cout << "\nfighters would you like to complete? Please choose a ";
	std::cout << "\nnumber divisble by two to make it fair: ";
	std::cin >> amount;

	while (amount % 2 != 0 || amount <= 0 || amount > 30 || std::cin.fail())
	{
		std::cout << "Please pick a number of fighters divisible by 2 and less than or equal to 30: ";
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cin >> amount;
	}

	std::cout << std::endl;

	int teamNum1 = amount / 2;
	int teamNum2 = amount / 2;
	menu.menu(); //call menu function to display menu

	//loop until all of the fighters have been picked (half of the amount)
	do
	{
		//user input and validation for type of fighter
		std::cout << "Player 1, you have " << teamNum1 << " team members left to pick. ";
		std::cout << "\nWhat fighter would you like to add to your team?: ";
		std::cin >> type;

		while (type < 1 || type > 5 || std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Please enter a choice that is between 1-6: ";
			std::cin >> type;
		}

		//user input and validation for name of fighter
		std::cout << "What should the name of this character be: ";
		do
		{
		 std::getline(std::cin, name);
		} while (name == "");

		std::cout << std::endl;

		//variable for Team number for initialization
		std::string team = "Team 1";

		/** Based on user input, create
		** new objects for each respective
		** class, name, and Team number
		**/

		if (type == 1)
		{
			fight.addQueue1(new Barbarian(name, team));
		}

		else if (type == 2)
		{
			fight.addQueue1(new Medusa(name, team));
		}

		else if (type == 3)
		{
			fight.addQueue1(new BabaYaga(name, team));
		}

		else if (type == 4)
		{
			fight.addQueue1(new BlueMen(name, team));
		}

		else if (type == 5)
		{
			fight.addQueue1(new HarryPotter(name, team));
		}

		teamNum1--; //decrement team number
	} while (teamNum1 > 0);

	menu.menu(); //call menu function to display menu for Player 2

	//loop until number of fighters for Player 2 have been selected (half the amount)
	do
	{
		//user input and input validation for type of fighter
		std::cout << "Player 2, you have " << teamNum2 << " team members left to pick. ";
		std::cout << "\nWhat fighter would you like to add to your team?: ";
		std::cin >> type;

		while (type < 1 || type > 5 || std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << "Please enter a choice that is between 1-6: ";
			std::cin >> type;
		}

		//user input and validation for name of character
		std::cout << "What should the name of this character be: ";
		do
		{
			std::getline(std::cin, name);
		} while (name == "");

		std::cout << std::endl;

		//variable for team number for initialization
		std::string team = "Team 2";

		/** Based on user input, create
		** new objects for each respective
		** class, name, and team number
		**/
		if (type == 1)
		{
			fight.addQueue2(new Barbarian(name, team));
		}

		else if (type == 2)
		{
			fight.addQueue2(new Medusa(name, team));
		}

		else if (type == 3)
		{
			fight.addQueue2(new BabaYaga(name, team));
		}

		else if (type == 4)
		{
			fight.addQueue2(new BlueMen(name, team));
		}

		else if (type == 5)
		{
			fight.addQueue2(new HarryPotter(name, team));
		}

		teamNum2--; //decrement counter
	} while (teamNum2 > 0);

	fight.Battle(); //run the battle

	//provide the option for the user to view the loser pile
	//user input and input validation
	char losers;
	std::cout << "\nWould you like to see the loser pile? ";
	std::cout << "\nPlease enter a 'Y' or 'N': ";
	std::cin >> losers;

	while (losers != 'Y' && losers != 'N')
	{
		std::cout << "Please enter a 'Y' or 'N' for your choice: ";
		std::cin >> losers;
	}

	//if user wishes, display loser pile
	if (losers == 'Y')
	{
		std::cout << "\nLosers from best to worst: " << std::endl;
		fight.displayStack();
	}

	//system("PAUSE");
	return 0;
}
