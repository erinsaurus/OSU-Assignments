/**************************************************************************************************
** Name: Erin Alltop
** Date: 6/1/16
** Description: Final Project. This program is a text based game. The play is in a street market
** and has to collect certain ingredients on her shopping list. Points can be earned by buying
** or earning rare ingredients, performing small tasks, winning short games, and other
** various ways for bonus points. The final score is displayed at the end.
** This program makes use of polymorphism and containers. The player has a shopping bag that is
** a stack, and each shop is a derived class of the "space" class.
***************************************************************************************************/

#include "space.hpp"
#include "menu.hpp"
#include "player.hpp"
#include "produce.hpp"
#include "chocolate.hpp"
#include "wine.hpp"
#include "spices.hpp"
#include "cheese.hpp"
#include "butcher.hpp"
#include "street.hpp"
#include "bakery.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cctype>

/***************************************************************************************************
 ** Function: verifyNull
 ** Description: This function is a helper function that is used to verify that the direction
 ** the player picks to move to is not NULL. If it is null it returns an error message instead 
 ** of crashing the program.
 ** Parameters: the next location choice and the current location
 ***************************************************************************************************/

bool verifyNull(std::string next, Space* currentLoc)
{
	//test for North
	if (next == "N")
	{
		if (currentLoc->getNorth() != NULL)
		{
			return true;
		}
		else
			return false;
	}

	//test for South
	if (next == "S")
	{
		if (currentLoc->getSouth() != NULL)
		{
			return true;
		}
		else
			return false;
	}

	//test for East
	if (next == "E")
	{
		if (currentLoc->getEast() != NULL)
		{
			return true;
		}
		else
			return false;
	}

	//test for West
	if (next == "W")
	{
		if (currentLoc->getWest() != NULL)
		{
			return true;
		}
		else
			return false;
	}

	//test for NW
	if (next == "NW")
	{
		if (currentLoc->getNW() != NULL)
		{
			return true;
		}
		else
			return false;
	}

	//test for SE
	if (next == "SE")
	{
		if (currentLoc->getSE() != NULL)
		{
			return true;
		}
		else
			return false;
	}

	//test for SW
	if (next == "SW")
	{
		if (currentLoc->getSW() != NULL)
		{
			return true;
		}
		else
			return false;
	}

	//test for NE
	if (next == "NE")
	{
		if (currentLoc->getNE() != NULL)
		{
			return true;
		}
		else
			return false;
	}

	//else return an error message
	else
		std::cout << "Something went wrong in verifyNull() " << std::endl;
	return false;
}

/*************************************************************************************************
 ** Function: gameLoop
 ** Description: This function is the main game loop of the game. It takes the current location
 ** and the player object and moves through the game. If the game is not over, it takes the
 ** next location from the user input and changes the current location pointer to the next 
 ** location. Then it returns the current location pointer.
**************************************************************************************************/

Space* gameLoop(Space* currentLoc, Player* player)
{
	std::string next; //next variable
	std::cout << std::endl;

	currentLoc->stallText(player); //display the stall text for the current stall


	if (player->gameOver() == true) //if game is over, return 
	{
		return NULL;
	}

	else if (player->gameOver() == false) //if game is not over, continue
	{
		std::getline(std::cin, next);

		//input validation
		while (next != "N" && next != "S" && next != "E" && next != "W"
			&& next != "NW" && next != "SE" && next != "C" && next != "R"
			&& next != "NE" && next != "SW")
		{

			std::cout << "Oops! Invalid entry. Please select one of the options available. ";
			std::getline(std::cin, next);
		}

		//loop to allow the user to view the shopping list and shopping bag as many
		//times as they wish
		while (next == "C" || next == "R")
		{
			if (next == "C")
			{
				player->displayBagContents();
				std::cout << "Where would you like to go next? ";
				std::getline(std::cin, next);

			}
			else if (next == "R")
			{
				player->shoppingList();
				std::cout << "Where would you like to go next? ";
				std::getline(std::cin, next);
			}
		}

		verifyNull(next, currentLoc); //verify next location is not NULL

		//while location is null, prompt the user for another location
		//Note: This should not be seen!!
		while (!verifyNull(next, currentLoc)) 
		{
			std::cin.ignore(100, '\n');
			std::cout << "\nSorry! There is no stall in that direction. Please make another selection: ";
			std::getline(std::cin, next);
			verifyNull(next, currentLoc);

		}

		//if the current location is NOT the street, increment time
		if (currentLoc->getStallName() != "Street")
		{
			player->adjustTime();
		}

		//change stalls based on user input
		if (next == "N")
			currentLoc = currentLoc->getNorth();
		if (next == "S")
			currentLoc = currentLoc->getSouth();
		if (next == "E")
			currentLoc = currentLoc->getEast();
		if (next == "W")
			currentLoc = currentLoc->getWest();
		if (next == "NW")
			currentLoc = currentLoc->getNW();
		if (next == "SE")
			currentLoc = currentLoc->getSE();
		if (next == "SW")
			currentLoc = currentLoc->getSW();
		if (next == "NE")
			currentLoc = currentLoc->getNE();

	}

	return currentLoc; 
}

/********************************************************************************************************
 ** Function: main
 ** Description: This is the main function of the game. It gives a breakdown of the points system,
 ** obtains the recipe pick from the user, creates all of the pointers and objects, and loops through
 ** the gameLoop until the game is over.
 ********************************************************************************************************/

int main()
{
	//intro and description of the rules for the user
	std::cout << "Tonight is the night! You have a big dinner party planned and\n"
		<< "only a few hours to gather your ingredients to put on the perfect party.\n"
		<< "\nYou have just arrived at your busy local street market to brave the crowds\n"
		<< "and gather your ingredients within 90 minutes. You know that a visit to each stall\n"
		<< "will cost you 10 minutes of your time, so you have a list prepared and ready to go!" << std::endl;
	std::cout << "\nGather only the ingredients on your list within the alloted time for max points. For\n"
		<< "special bonuses, find or earn deals on your ingredients, find rare ingredients, and\n"
		<< "gather bonus items to wow your guests." << std::endl;
	std::cout << "\nYou have $50.00 in your wallet and a shopping bag that can hold 15 items.\n"
		<< "Spend your time and money wisely to earn the best score possible!" << std::endl;


	srand((unsigned int)time(0)); //random time seed
	
	//pause the game for the user to read the rules
	do
	{
		std::cout << "\nWhen you are ready to continue, press Enter." << std::endl;
	} while (std::cin.get() != '\n');
	

	Menu menus; //menu object
	menus.recipeOptions(); //recipe option list
	char recipe; //recipe variable
	
	//obtain recipe selection from the user
	std::cout << "\nPlease enter your recipe selection of A, B, or C: ";
	std::cin >> recipe;

	recipe = char(toupper(recipe)); //convert to uppercase

	//input validation
	while (recipe != 'A' && recipe != 'B' && recipe != 'C')
	{
		std::cin.ignore(100, '\n');
		std::cout << "Invalid entry! Please enter A, B, or C: ";
		std::cin >> recipe;
	}

	//create player pointer
	Player* player = NULL;
	player = new Player(recipe);
	
	//create Space pointers and assign them to derived class objects
	Space* produce = new Produce;
	Space* butcher = new Butcher;
	Space* chocolate = new Chocolate;
	Space* spices = new Spices;
	Space* street = new Street;
	Space* cheese = new Cheese;
	Space* bakery = new Bakery;
	Space* currentLoc = NULL;
	
	//set the pointers for each object
	cheese->setPtrs(NULL, street, produce, butcher, NULL, NULL, bakery, NULL);
	butcher->setPtrs(cheese, spices, street, NULL, NULL, NULL, NULL, NULL);
	spices->setPtrs(street, NULL, produce, butcher, NULL, NULL, NULL, NULL);
	produce->setPtrs(bakery, spices, NULL, street, NULL, NULL, cheese, NULL);
	chocolate->setPtrs(produce, NULL, NULL, spices, street, NULL, NULL, NULL);
	street->setPtrs(cheese, spices, produce, butcher, NULL, chocolate, bakery, NULL);
	bakery->setPtrs(NULL, produce, NULL, cheese, NULL, NULL, NULL, street);

	currentLoc = street; //current location is the street

	std::cin.ignore(100, '\n'); //clear buffer

	//while the player time is greater than 50 and the game is not over, loop through the game
	do
	{
		currentLoc = gameLoop(currentLoc, player);
		
	} while (player->getTime() > 50 && (player->gameOver() == false));

	//after time has reached 50, removed the chocolate stall and add the wine stall
	//adjust pointers to reflect the new stall
	Space* wine = new Wine;
	wine->setPtrs(NULL, butcher, cheese, NULL, NULL, street, NULL, NULL);
	street->setPtrs(cheese, spices, produce, butcher, wine, NULL, bakery, NULL);
	delete chocolate;
	
	//if the game is not over, loop through the game again until the game is over
	if (player->gameOver() == false)
	{
		do
		{
			currentLoc = gameLoop(currentLoc, player);

		} while (player->gameOver() == false);
	}

	//after the game has concluded, call the endGame function to end the game
	player->endGame();
	delete wine;
	delete cheese;
	delete bakery;
	delete butcher;
	delete produce;
	delete spices;
	delete currentLoc;
//	system("pause");
}


