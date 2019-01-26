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

#include "bakery.hpp"

/**************************************************************************************************
 ** Function: displayInventory
 ** Description: This function displays the inventory of the stall. It creates a menu object
 ** and calls the display function for the specific stall. This is used by shopkeeper
 ** function in order to display the goods available for purchase to the player.
***************************************************************************************************/

void Bakery::displayInventory()
{
	Menu display;
	display.displayBakery();
}

/**************************************************************************************************
** Function: setOvenCheck
** Description: This is a helper function that sets the variable for whether the special function
** has been used or not. 0 = not used. 1 = used. Each special function is only used once so this
** function helps to be sure that functions are not repeated during the program.
***************************************************************************************************/

void Bakery::setOvenCheck(int done)
{
	ovenCheck = done;
}

/**************************************************************************************************
** Function: getOvenCheck
** Description: This is a helper function that returns the check for whether the special function
** of this class/stall has been used yet. Each function is only used one so this is to be sure
** that the game is not repeating special functions.
***************************************************************************************************/

int Bakery::getOvenCheck()
{
	return ovenCheck;
}

/**************************************************************************************************
** Function: ovenHelp
** Description: This function is the special function for this class. It is only done once.
** It prompts the user for help. If the user helps the shopKeeper, he/she gets 5 bonus points
** on his/her final score. If not, there is no penalty.
***************************************************************************************************/

void Bakery::ovenHelp(Player * player)
{
	//flavor text and description of the problem to the user
	std::cout << "\nYou know that dinner party is complete without a delicious side of bread."
		<< "\nThere's nothing that gets those good feelings flowing like some carbs!"
		<< "\nAfter picking out your side, you approach the shopkeeper - a young man with"
		<< "\na beard, tattoos, and Pink Floyd t-shirt who is busy kneading some dough."
		<< "\nYou tell him what you would like to purchase and his eyes brighten."
		<< "\n\n'It's your lucky day! I happen to have exactly that ready to come out of the"
		<< "\noven hot and fresh right now. I'm a bit of a mess, but if you grab it for me"
		<< "\nI'll give you first pick and I'll be forever grateful for your help!' He beams at you."
		<< "\n\nDo you take the bread from the oven? Y/N: ";

	//user input and validation
	char yn;
	std::cin >> yn;
	while (yn != 'Y' && yn != 'N')
	{
		std::cout << "Please enter Y or N: ";
		std::cin >> yn;
	}

	//if yes, the player helps the shopKeeper
	if (yn == 'Y')
	{
		std::cout << "\n\n'Right on! There are some oven mitts right next to the oven. Be careful!'"
			<< "\n\nYou grab the oven mitts, open the door to the brick oven behind the shopkeeper"
			<< "\nand pull out perfectly formed bread that tantalizes your senses."
			<< "\nNext dinner party, you promise yourself, you will make homemade bread. But this"
			<< "\nis too good to pass up just the same."
			<< "\nThe shopkeeper thanks you kindly, you pay for your bread, and you are on your way." << std::endl;

		player->incBonus(5); //player earns 5 bonus points
		std::cout << "\n\nYou have earned 5 bonus points for helping the shopkeeper. Good job!" << std::endl;
	}

	//if no, the player faces no penalty
	if (yn == 'N')
	{
		std::cout << "\n\n'Well that's okay! I am sure you have a lot of things to buy"
			<< "\nand do today. Thanks anyway and peace to you and yours!' The shopkeeper"
			<< "\nsmiles and says to you as he hands you an already packaged bread and takes"
			<< "\nyour money." << std::endl;
	}

	setOvenCheck(1); //set the special function variable to indicate it is completed
}

/**************************************************************************************************
** Function: Class Constructor
** Description: This constructor initializes/sets the name of the class it belongs to. It is a 
** string that is called upon later in the program.
***************************************************************************************************/

Bakery::Bakery()
{
	setStallName("Bakery");
}

/**************************************************************************************************
** Function: stallText
** Description: This function displays the stall text for the specific stall. It also lets
** the player know how much time they have left. It calls the shopKeeper function, and after
** exiting this function it exits if the game is over. If not, it displays the locations the
** player can continue onto to further the game.
** Parameters: Player pointer
***************************************************************************************************/

void Bakery::stallText(Player* player)
{
	//flavor text/intro
	std::cout << "\nCurrent Location: Bakery" << std::endl;
	std::cout << "\nYou have " << player->getTime() << " minutes left before you are late!" << std::endl;
	std::cout << "Welcome to Freds's Breads! Whether you need white bread, wheat bread, or a joke or two,"
		<< "\nwe have it all! Bread and jokes baked fresh daily. Buy something or dont, but please enjoy"
		<< "\nthe smells either way." << std::endl;
	

	shopKeeper(player); //call shopKeeper function

	if (player->gameOver() == true) //if game is over, return 
	{
		std::cin.ignore(100, '\n'); //clear buffer for next input
		return;
	}

	else if (player->gameOver() == false) //if game is not over, continue
	{
		//display directions player can go
		std::cout << "\nFrom here you can go: "
			<< "\nS: " << getSouth()->getStallName() << std::endl;
		std::cout << "W: " << getWest()->getStallName() << std::endl;
		std::cout << "SW: " << getSW()->getStallName() << std::endl;
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

Inventory* Bakery::createItem(char purchase, Player* player)
{
	Inventory* item = NULL; //create a NULL pointer to an Inventory item

	//Selection = A
	if (purchase == 'A')
	{
		item = new Inventory("White", 2.00); //create new item. Initialize with name and price.

		//if player doesn't have enough money, inform them
		//and return from the function
		if (player->getWallet() <= 1.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{		
			if (getOvenCheck() == 0) //if the special function has not been used yet, call the function
			{
				ovenHelp(player);
			}

			//add the item to the shopping bag list and remove money from player wallet
			player->changeBagContents("White");
			player->removeMoney(2.00);
		}
	}

	//Selection = B
	if (purchase == 'B')
	{
		item = new Inventory("French Bread", 2.00); //create new item. Initialize with name and price.

		//if player doesn't have enough money, inform them
		//and return from the function
		if (player->getWallet() <= 1.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			if (getOvenCheck() == 0) //if the special function has not been used yet, call the function
			{
				ovenHelp(player);
			}

			//add the item to the shopping bag list and remove money from player wallet
			player->changeBagContents("French Bread");
			player->removeMoney(2.00);
		}
	}

	//Selection = C
	if (purchase == 'C')
	{
		item = new Inventory("Breadsticks", 4.00); //create new item. Initialize with name and price.

		//if player doesn't have enough money, inform them and return										
		if (player->getWallet() <= 3.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			if (getOvenCheck() == 0) //if the special function has not been used yet, call the function
			{
				ovenHelp(player);
			}

			//add the item to the shopping bag list and remove money from player wallet
			player->changeBagContents("Breadsticks");
			player->removeMoney(4.00);
		}
	}

	//Selection = D
	if (purchase == 'D')
	{
		item = new Inventory("Hotdog Buns", 1.00); //create new item. Initialize with name and price.

		//if player doesn't have enough money, inform them and return	
		if (player->getWallet() <= 0.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			if (getOvenCheck() == 0) //if the special function has not been used yet, call the function
			{
				ovenHelp(player);
			}

			//add the item to the shopping bag list and remove money from player wallet
			player->changeBagContents("Hotdog Buns");
			player->removeMoney(1.00);
		}
	}

	//Selection = E
	if (purchase == 'E')
	{
		item = new Inventory("Dinner Rolls", 4.00); //create new item. Initialize with name and price.

		//if player doesn't have enough money, inform them and return
		if (player->getWallet() <= 3.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			if (getOvenCheck() == 0) //if the special function has not been used yet, call the function
			{
				ovenHelp(player);
			}

			//add the item to the shopping bag list and remove money from player wallet
			player->changeBagContents("Dinner Rolls");
			player->removeMoney(4.00);
		}
	}

	//Selection = F
	if (purchase == 'F')
	{
		item = new Inventory("Pizza Dough", 5.00); //create new item. Initialize with name and price.

		//if player doesn't have enough money, inform them and return	
		if (player->getWallet() <= 4.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			if (getOvenCheck() == 0) //if the special function has not been used yet, call the function
			{
				ovenHelp(player);
			}

			//add the item to the shopping bag list and remove money from player wallet
			player->changeBagContents("Pizza Dough");
			player->removeMoney(5.00);
		}
	}

	//Selection = G
	if (purchase == 'G')
	{
		item = new Inventory("Wheat", 4.00); //create new item. Initialize with name and price.

		//if player doesn't have enough money, inform them and return	
		if (player->getWallet() <= 3.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			if (getOvenCheck() == 0) //if the special function has not been used yet, call the function
			{
				ovenHelp(player);
			}

			//add the item to the shopping bag list and remove money from player wallet
			player->changeBagContents("Wheat");
			player->removeMoney(4.00);
		}
	}

	//Selection = H
	if (purchase == 'H')
	{
		item = new Inventory("Multigrain", 3.00); //create new item. Initialize with name and price.

		//if player doesn't have enough money, inform them and return	
		if (player->getWallet() <= 3.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			if (getOvenCheck() == 0) //if the special function has not been used yet, call the function
			{
				ovenHelp(player);
			}

			//add the item to the shopping bag list and remove money from player wallet
			player->changeBagContents("Multigrain");
			player->removeMoney(3.00);
		}
	}

	//Selection = I
	if (purchase == 'I')
	{
		item = new Inventory("Garlic Bread", 1.00); //create new item. Initialize with name and price.

		//if player doesn't have enough money, inform them and return		
		if (player->getWallet() <= 0.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			if (getOvenCheck() == 0) //if the special function has not been used yet, call the function
			{
				ovenHelp(player);
			}

			//add the item to the shopping bag list and remove money from player wallet
			player->changeBagContents("Garlic Bread");
			player->removeMoney(1.00);
		}
	}

	//Selection = J
	if (purchase == 'J')
	{
		item = new Inventory("Pastry", 1.00); //create new item. Initialize with name and price.

		//if player doesn't have enough money, inform them and return	
		if (player->getWallet() <= 0.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			if (getOvenCheck() == 0) //if the special function has not been used yet, call the function
			{
				ovenHelp(player);
			}

			//add the item to the shopping bag list and remove money from player wallet
			player->changeBagContents("Pastry");
			player->removeMoney(1.00);
		}
	}

	return item; //return a pointer to the new item to be added to the stack
}

