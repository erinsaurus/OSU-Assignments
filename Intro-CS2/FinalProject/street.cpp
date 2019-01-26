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

#include "street.hpp"

/**************************************************************************************************
** Function: Class Constructor
** Description: This constructor initializes/sets the name of the class it belongs to. It is a
** string that is called upon later in the program.
***************************************************************************************************/

Street::Street()
{
	setStallName("Street");
}

/**************************************************************************************************
** Function: stallText
** Description: This function displays the stall text for the specific stall. It also lets
** the player know how much time they have left. It calls the shopKeeper function, and after
** exiting this function it exits if the game is over. If not, it displays the locations the
** player can continue onto to further the game.
** Parameters: Player pointer
***************************************************************************************************/

void Street::stallText(Player* player)
{
	std::cout << "\nCurrent Location: Street"
		<< "\nYou are standing in the middle of a bustling street market. There are stalls"
		<< "\nsurrounding you on all sides carrying a variety of different types of foods"
		<< "\nand goods. Friendly shopkeepers wave to entice you into their stall for a closer look."
		<< "\nYou take in the delicious aroma as young, old, families, and pets push past"
		<< "\nyou as you contemplate which stall to peruse next." << std::endl;

	std::cout << "\nAn info booth stands near you with the stock of all the stock."
		<< "\nWould you like to view it? Y/N ";
		char menus;
		std::cin >> menus;
		while (menus != 'Y' && menus != 'N')
		{
			std::cout << "\nPlease enter Y or N: ";
			std::cin >> menus;
		}

		if (menus == 'Y')
		{
			displayMenus();
		}
		else if (menus == 'N')
		{
			//nothing
		}


		std::cin.ignore(10, '\n');

	std::cout << "\nWhat stall will you go enter next? " << std::endl;
	std::cout << "\nN: " << getNorth()->getStallName() << std::endl;
	std::cout << "S: " << getSouth()->getStallName() << std::endl;
	std::cout << "E: " << getEast()->getStallName() << std::endl;
	std::cout << "W: " << getWest()->getStallName() << std::endl;
	std::cout << "NE: " << getNE()->getStallName() << std::endl;


	if (stallSE() == true)
	{
		std::cout << "*SE: " << getSE()->getStallName() << std::endl;
	}
	else if (stallNW() == true)
	{
		std::cout << "*NW: " << getNW()->getStallName() << std::endl;
	}
	else
	{
		std::cout << "Something has gone wrong! No specialty store." << std::endl;
	}

	std::cout << "C: Display Bag Contents" << std::endl;
	std::cout << "R: Display Shopping List" << std::endl;
	std::cout << "\n*Specialty Store! Here for a limited time. ";
	
}

bool Street::stallSE()
{
	if (getSE() == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Street::stallNW()
{
	if (getNW() == NULL)
		return false;
	else
		return true;
}

void Street::displayMenus()
{
	std::cout << std::endl;

	Menu menus;
	menus.displayBakery();
	menus.displayButcher();
	menus.displayCheese();
	menus.displayChocolate();
	menus.displayProduce();
	menus.displaySpices();
	menus.displayWine();

}

/**************************************************************************************************
** Function: createItem
** Description: This function is NULL for this class because it is not used here. But because
** it is a pure virtual function, a function is required for this derived class.
***************************************************************************************************/

Inventory * Street::createItem(char, Player *)
{
	//nothing
	return NULL;
}
