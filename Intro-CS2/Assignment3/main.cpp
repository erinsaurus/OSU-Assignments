/**************************************************************************************************
** Author: Erin Alltop
** Date: 5/6/16
** Description: This program is a fantasy combat game. It allows the user to pick two opponents
** to battle to the death. There are 5 different types of opponents that can battle each other or
** themselves. They each have different stats and abilities. Once one of them runs of out Strength
** Points then the game ends and the program terminates.
** Input: User choices for two opponents to battle
** Output: Step-by-step battle stats until one opponent loses
**************************************************************************************************/


#include <iostream>
#include "barbarian.hpp"
#include "medusa.hpp"
#include "babayaga.hpp"
#include "bluemen.hpp"
#include "harrypotter.hpp"
#include "menu.hpp"
#include <ctime>
#include <cstdlib>

int main()
{

	Menu menu; //menu object to call menu function
	menu.menu(); //call menu function to display menu
	srand(time(0)); // random seed for the program

	//variables for menu choices
	int choice1; 
	int choice2;
	std::cin >> choice1 >> choice2; //take in user input for choices
	
	// user input validation
	while (choice1 <= 0 || choice2 >= 6 || choice2 <= 0 || choice2 >= 6)
	{
		std::cout << "Please enter two choices that are between 1-6: ";
		std::cin >> choice1 >> choice2;
	}
	std::cout << std::endl;

	//create null Creature pointers to objects ONLY
	Creature* opp1 = NULL;
	Creature* opp2 = NULL;


	/** Based on user input, create
	 ** new objects for each respective
	 ** class and choice
	 **/

	// choice 1
	if (choice1 == 1)
	{opp1 = new Barbarian;}

	else if (choice1 == 2)
	{opp1 = new Medusa;}

	else if (choice1 == 3)
	{opp1 = new BabaYaga;}

	else if (choice1 == 4)
	{opp1 = new BlueMen;}

	else if (choice1 == 5)
	{opp1 = new HarryPotter;}

	//choice 2
	if (choice2 == 1)
	{opp2 = new Barbarian;}

	else if (choice2 == 2)
	{opp2 = new Medusa;}

	else if (choice2 == 3)
	{opp2 = new BabaYaga;}

	else if (choice2 == 4)
	{opp2 = new BlueMen;}

	else if (choice2 == 5)
	{opp2 = new HarryPotter;}

	int round = 1; // counter variabe

	/** This is a do-while loop that 
	 ** will continue looping attack/defend
	 ** for each opponent until one
	 ** of them has perished
	 **/

	do {

		std::cout << "\nRound " << round << "!" << std::endl;
		opp1->attack();   // opponent 1 attack 
		opp2->defend(opp1->getAttack());  // opponent 2 defense
		if (opp2->getStrPoints() <= 0) // if opponent 2 has died, exit loop to prevent both players dying at once
		{
			break;
		}
		opp2->attack(); //oponent 2 attack
		opp1->defend(opp2->getAttack()); //opponent 1 defense
		round++; //increment counter variable

	} while (opp1->getStrPoints() > 0 && opp2->getStrPoints() > 0); //while both fighters still alive, continue looping


	//announce winner!
	if (opp1->getStrPoints() <= 0)
	{
		std::cout << std::endl;
		std::cout << "\nOpponent 2 wins!\n";
	}
	else if (opp2->getStrPoints() <= 0)
	{
		std::cout << std::endl;
		std::cout << "\nOpponent 1 wins!\n";
	}

	//delete objects
	delete opp1;
	delete opp2;
		
//	system("PAUSE");
	return 0;
}
