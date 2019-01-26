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

#include "wine.hpp"

/**************************************************************************************************
** Function: displayInventory
** Description: This function displays the inventory of the stall. It creates a menu object
** and calls the display function for the specific stall. This is used by shopkeeper
** function in order to display the goods available for purchase to the player.
***************************************************************************************************/

void Wine::displayInventory()
{
	Menu display;
	display.displayWine();
}

/**************************************************************************************************
** Function: stallText
** Description: This function displays the stall text for the specific stall. It also lets
** the player know how much time they have left. It calls the shopKeeper function, and after
** exiting this function it exits if the game is over. If not, it displays the locations the
** player can continue onto to further the game.
** Parameters: Player pointer
***************************************************************************************************/

void Wine::stallText(Player* player)
{
	std::cout << "\nCurrent Location: Wine" << std::endl;
	std::cout << "\nYou have " << player->getTime() << " minutes left before you are late!" << std::endl;
	std::cout << "Welcome to the Chianti Shanty! We have all of your needs for a good time here."
		<< "\nPlease browse our wares and let me know if you have any questions." << std::endl;

	if (getTestCheck() == 0)
	{
		wineTasting();
	}


	shopKeeper(player);
	
	if (player->gameOver() == true) //if game is over, return 
	{
		std::cin.ignore(100, '\n'); //clear buffer for next input
		return;
	}

	else if (player->gameOver() == false) //if game is not over, continue
	{
		std::cout << "\nFrom here you can go: "
			<< "\nS: " << getSouth()->getStallName() << std::endl;
		std::cout << "E: " << getEast()->getStallName() << std::endl;
		std::cout << "SE: " << getSE()->getStallName() << std::endl;
		std::cout << "C: Display Bag Contents" << std::endl;
		std::cout << "R: Display Shopping List" << std::endl;
		std::cout << "Where would you like to go next? ";
	}
}

/**************************************************************************************************
** Function: createItem
** Description: This function is used by the shopKeeper to create Inventory objects for the
** player stack. Depending on the user selection, an inventory item is created and initialized
** with the name of the object based on what the player purchased. This information is used
** also to populate the shopping list for the user to see what they have bought already.
** In this function, if the price of the object might be manipulated by the class special function,
** those functions are located here.
***************************************************************************************************/

Inventory * Wine::createItem(char purchase, Player* player)
{
	Inventory* item = NULL;

	if (purchase == 'A')
	{
		item = new Inventory("Bordeaux", 5.00);

		if (player->getWallet() <= 4.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			player->changeBagContents("Bordeaux");
			player->removeMoney(5);
			player->incBonus(15);
			std::cout << "\nYou collected a bonus item! You have received 10 bonus points." << std::endl;
		}
	}
	if (purchase == 'B')
	{
		item = new Inventory("Merlot", 5.00);

		if (player->getWallet() <= 4.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			player->changeBagContents("Merlot");
			player->removeMoney(5.00);
			player->incBonus(15);
			std::cout << "\nYou collected a bonus item! You have received 10 bonus points." << std::endl;
		}
	}
	if (purchase == 'C')
	{
		item = new Inventory("Pinot Noir", 5.00);

		if (player->getWallet() <= 4.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			player->changeBagContents("Pinot Noir");
			player->removeMoney(5.00);
			player->incBonus(15);
			std::cout << "\nYou collected a bonus item! You have received 10 bonus points." << std::endl;
		}
	}
	if (purchase == 'D')
	{
		item = new Inventory("Pinot Grigio", 5.00);

		if (player->getWallet() <= 4.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			player->changeBagContents("Pinot Grigio");
			player->removeMoney(5.00);
			player->incBonus(15);
			std::cout << "\nYou collected a bonus item! You have received 10 bonus points." << std::endl;
		}
	}
	if (purchase == 'E')
	{
		item = new Inventory("Chardonnay", 5.00);

		if (player->getWallet() <= 4.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			player->changeBagContents("Chardonnay");
			player->removeMoney(5.00);
			player->incBonus(15);
			std::cout << "\nYou collected a bonus item! You have received 10 bonus points." << std::endl;
		}
	}
	if (purchase == 'F')
	{
		item = new Inventory("Champagne", 5.00);

		if (player->getWallet() <= 4.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			player->changeBagContents("Champagne");
			player->removeMoney(5.00);
			player->incBonus(15);
			std::cout << "\nYou collected a bonus item! You have received 10 bonus points." << std::endl;
		}
	}
	if (purchase == 'G')
	{
		item = new Inventory("Prosecco", 5.00);

		if (player->getWallet() <= 4.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			player->changeBagContents("Prosecco");
			player->removeMoney(5.00);
			player->incBonus(15);
			std::cout << "\nYou collected a bonus item! You have received 10 bonus points." << std::endl;
		}
	}
	if (purchase == 'H')
	{
		item = new Inventory("Port", 5.00);

		if (player->getWallet() <= 4.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			player->changeBagContents("Port");
			player->removeMoney(5.00);
			player->incBonus(15);
			std::cout << "\nYou collected a bonus item! You have received 10 bonus points." << std::endl;
		}
	}
	if (purchase == 'I')
	{
		item = new Inventory("Marsala", 5.00);

		if (player->getWallet() <= 4.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			player->changeBagContents("Marsala");
			player->removeMoney(5.00);
			player->incBonus(15);
			std::cout << "\nYou collected a bonus item! You have received 10 bonus points." << std::endl;
		}
	}
	if (purchase == 'J')
	{
		item = new Inventory("Cava", 5.00);

		if (player->getWallet() <= 4.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			player->changeBagContents("Cava");
			player->removeMoney(5.00);
			player->incBonus(15);
			std::cout << "\nYou collected a bonus item! You have received 10 bonus points." << std::endl;
		}
	}

	return item;
}

/**************************************************************************************************
** Function: Class Constructor
** Description: This constructor initializes/sets the name of the class it belongs to. It is a
** string that is called upon later in the program.
***************************************************************************************************/

Wine::Wine()
{
	setStallName("Wine");
}

/**************************************************************************************************
** Function: wineTasting
** Description: This special function only occurs once. If the user chooses, they can do a short
** taste test to see what they prefer. The ratings are random numbers.
***************************************************************************************************/

void Wine::wineTasting()
{
	std::cout << "\nYou aren't much of a wine drinker, though you like to cook with it."
		<< "\nSo selecting a wine for your guests is a daunting experience."
		<< "\nThe shopkeeper sees your hesitancy and offers a few samples for you to"
		<< "\ntaste test. Would you like to try? Y/N ";
	char yn;
	std::cin >> yn;

	if (yn != 'Y' && yn != 'N')
	{
		std::cout << "Please enter a Y or N: ";
		std::cin >> yn;
	}

	if (yn == 'Y')
	{
		int taste1 = rand() % 10 + 1;
		std::cout << "\nThis is a blind taste test. It will be three different"
			<< "\ntypes of wine: Sparkling, White, and Red to see which you prefer!";
		std::cout << "\n\nFirst up is a Sparkling wine. You swish the wine around and ponder"
			<< "\nbefore you give your final assessment: " << taste1 << " out of 10." << std::endl;
		
		int taste2 = rand() % 10 + 1;
		std::cout << "\nNext up is a White wine. You take a big gulp and think about how you"
			<< "\n like it. After some thought, you give it a " << taste2 << " out of 10." << std::endl;

		int taste3 = rand() % 10 + 1;
		std::cout << "\nLastly is the Red wine. You try this one on for size and do some"
			<< "\nthinking on the flavors. You decide that it is a " << taste3 << " out of 10." << std::endl;

		std::cout << "\nYou thank the shopkeeper for her hospitality and go back to your shopping"
			<< "\nknowing at least now a little more about your wine preferences!\n" << std::endl;

		setTestCheck(1);
		
	}

}

/**************************************************************************************************
** Function: setTestCheck
** Description: This is a helper function that sets the variable for whether the special function
** has been used or not. 0 = not used. 1 = used. Each special function is only used once so this
** function helps to be sure that functions are not repeated during the program.
***************************************************************************************************/

void Wine::setTestCheck(int done)
{
	testCheck = done;
}

/**************************************************************************************************
** Function: getTestCheck
** Description: This is a helper function that returns the check for whether the special function
** of this class/stall has been used yet. Each function is only used one so this is to be sure
** that the game is not repeating special functions.
***************************************************************************************************/

int Wine::getTestCheck()
{
	return testCheck;
}
