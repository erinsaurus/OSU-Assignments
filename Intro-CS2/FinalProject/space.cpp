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
#include <iostream>
#include <cstdlib>


/*******************************************************************************************************
** Function: shopKeeper
** Description: This function acts as the shopkeeper. It tells the player how much money they have
** for reference, asks if they would like to purchase something, and calls the function to make the
** purchase and add the object to the player bag (stack).
** Input: User input for whether they want to make a purchase, what they want to purchase, and
** whether they would like to make another purchase.
** Output: Adds player purchase to the stack.
*******************************************************************************************************/

void Space::shopKeeper(Player* player)
{
	//tell the user their wallet contents and ask if they would like to make a purchase
	char initYN;
	std::cout << "\nYou have: $" << player->getWallet() << " Would you like to make a purchase Y/N? ";
	std::cin >> initYN;

	initYN = char(toupper(initYN)); //convert to uppercase

	if (initYN == 'N') //if no, clear buffer and return from function
	{
		std::cin.ignore(10, '\n');
		return;
	}

	//variables
	char purchase;
	char yn = 'Y';

	//while user wishes to make a purchase, continue loops
	while (yn == 'Y')
	{
		displayInventory(); //display shop inventory

		std::cout << "Please select one item to purchase: ";
		std::cin >> purchase;

		purchase = char(toupper(purchase)); //convert to uppercase

											//user input for user selection
		while (purchase != 'A' && purchase != 'B' && purchase != 'C' && purchase != 'D' && purchase != 'E'
			&& purchase != 'F' && purchase != 'G' && purchase != 'H' && purchase != 'I' && purchase != 'J')
		{
			std::cin.ignore(100, '\n'); //clear buffer
			std::cout << "\nPlease make a selection of A-J: ";
			std::cin >> purchase;
			purchase = char(toupper(purchase)); //convert to uppercase
		}

		/* Add item user picks to the player stack. This also
		* creates the item in the createItem function which returns
		* a pointer to the new item - adding it to the stack.
		*/
		player->add(createItem(purchase, player));

		if (player->gameOver() == true) //if game is over, return 
		{
			std::cin.ignore(100, '\n'); //clear buffer for next input
			return;
		}

		else if (player->gameOver() == false) //if game is not over, continue
		{
			//ask user if they would like to make another purchase
			std::cout << "\nWould you like to purchase another item? Y/N: ";
			std::cin >> yn;

			yn = char(toupper(yn)); //convert to uppercase
		}
	}

	std::cin.ignore(100, '\n'); //clear buffer for next input
}

/*************************************************************************************************
 ** Function: getNorth
 ** Description: This function simply returns the pointer to North of the Space.
*************************************************************************************************/

Space* Space::getNorth()
{
	return North;
}

/*************************************************************************************************
** Function: getWest
** Description: This function simply returns the pointer to West of the Space.
*************************************************************************************************/

Space* Space::getWest()
{
	return West;
}

/*************************************************************************************************
** Function: getSouth
** Description: This function simply returns the pointer to South of the Space.
*************************************************************************************************/

Space* Space::getSouth()
{
	return South;
}

/*************************************************************************************************
** Function: getEast
** Description: This function simply returns the pointer to East of the Space.
*************************************************************************************************/

Space* Space::getEast()
{
	return East;
}

/*************************************************************************************************
** Function: getNW
** Description: This function simply returns the pointer to NW of the Space.
*************************************************************************************************/

Space * Space::getNW()
{
	return NorthWest;
}

/*************************************************************************************************
** Function: getSE
** Description: This function simply returns the pointer to SE of the Space.
*************************************************************************************************/

Space * Space::getSE()
{
	return SouthEast;
}

/*************************************************************************************************
** Function: getNE
** Description: This function simply returns the pointer to NE of the Space.
*************************************************************************************************/

Space * Space::getNE()
{
	return NorthEast;
}

/*************************************************************************************************
** Function: getSW
** Description: This function simply returns the pointer to SW of the Space.
*************************************************************************************************/

Space* Space::getSW()
{
	return SouthWest;
}

/*************************************************************************************************
** Function: setNorth
** Description: This function simply sets the North pointer of the Space.
*************************************************************************************************/

void Space::setNorth(Space* n)
{
	North = n;
}

/*************************************************************************************************
** Function: setWest
** Description: This function simply sets the West pointer of the Space.
*************************************************************************************************/

void Space::setWest(Space* w)
{
	West = w;
}

/*************************************************************************************************
** Function: setSouth
** Description: This function simply sets the South pointer of the Space.
*************************************************************************************************/

void Space::setSouth(Space* s)
{
	South = s;
}

/*************************************************************************************************
** Function: setEast
** Description: This function simply sets the East pointer of the Space.
*************************************************************************************************/

void Space::setEast(Space* e)
{
	East = e;
}


/*************************************************************************************************
** Function: setNW
** Description: This function simply sets the NW pointer of the Space.
*************************************************************************************************/

void Space::setNW(Space * nw)
{
	NorthWest = nw;
}

/*************************************************************************************************
** Function: setSE
** Description: This function simply sets the SE pointer of the Space.
*************************************************************************************************/

void Space::setSE(Space * se)
{
	SouthEast = se;
}

/*************************************************************************************************
** Function: setNE
** Description: This function simply sets the NE pointer of the Space.
*************************************************************************************************/

void Space::setNE(Space * ne)
{
	NorthEast = ne;
}

/*************************************************************************************************
** Function: setSW
** Description: This function simply sets the SW pointer of the Space.
*************************************************************************************************/

void Space::setSW(Space * sw)
{
	SouthWest = sw;
}

/*************************************************************************************************
** Function: Destructor
** Description: This is the destructor of the Space class
*************************************************************************************************/

Space::~Space()
{

}

/*************************************************************************************************
** Function: getStallName
** Description: This function simply returns the stall name (string).
*************************************************************************************************/

std::string Space::getStallName()
{
	return stallName;
}

/*************************************************************************************************
** Function: setStallName
** Description: This function sets the stall name (string).
*************************************************************************************************/

void Space::setStallName(std::string name)
{
	stallName = name;
}

void Space::stallText(Player* player)
{
}

/*************************************************************************************************
** Function: Default Constructor
** Description: This is the default constructor of the Space class. 
*************************************************************************************************/

Space::Space()
{

}

/*************************************************************************************************
** Function: displayInventory
** Description: For each class, they have a different displayInventory function.
** The function is blank here.
*************************************************************************************************/

void Space::displayInventory()
{
	
}

/*************************************************************************************************
** Function: setPtrs
** Description: This function is used to set all of the pointers for each space.
*************************************************************************************************/

void Space::setPtrs(Space * n, Space * s, Space * e, Space * w, Space * nw, Space * se, Space* ne, Space* sw)
{
	setNorth(n);
	setSouth(s);
	setEast(e);
	setWest(w);
	setNW(nw);
	setSE(se);
	setNE(ne);
	setSW(sw);
}



