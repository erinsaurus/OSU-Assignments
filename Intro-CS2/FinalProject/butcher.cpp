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

#include "butcher.hpp"

/**************************************************************************************************
** Function: displayInventory
** Description: This function displays the inventory of the stall. It creates a menu object
** and calls the display function for the specific stall. This is used by shopkeeper
** function in order to display the goods available for purchase to the player.
***************************************************************************************************/

void Butcher::displayInventory()
{
	Menu display;
	display.displayButcher();
}

/**************************************************************************************************
** Function: Class Constructor
** Description: This constructor initializes/sets the name of the class it belongs to. It is a
** string that is called upon later in the program.
***************************************************************************************************/

Butcher::Butcher()
{
	setStallName("Butcher");
}

/**************************************************************************************************
** Function: stallText
** Description: This function displays the stall text for the specific stall. It also lets
** the player know how much time they have left. It calls the shopKeeper function, and after
** exiting this function it exits if the game is over. If not, it displays the locations the
** player can continue onto to further the game.
** Parameters: Player pointer
***************************************************************************************************/

void Butcher::stallText(Player* player)
{
	//flavor text and intro
	std::cout << "\nCurrent Location: Butcher" << std::endl;
	std::cout << "\nYou have " << player->getTime() << " minutes left before you are late!" << std::endl;
	std::cout << "Welcome to Smokey Woods Pastures! All our meats are free-rage and antibiotic free."
		<< "\nThank you for visiting and please stop back by any time." << std::endl;

	//if special function hasn't been used yet, call the function
	if (getLostCheck() == 0) 
	{
		lostBoy(player);
	}

	//call the shopKeeper function
	shopKeeper(player);

	if (player->gameOver() == true) //if game is over, return 
	{
		std::cin.ignore(100, '\n'); //clear buffer for next input
		return;
	}

	else if (player->gameOver() == false) //if game is not over, continue
	{
		//display where the player can go next
		std::cout << "\nFrom here you can go: "
			<< "\nN: " << getNorth()->getStallName() << std::endl;
		std::cout << "S: " << getSouth()->getStallName() << std::endl;
		std::cout << "E: " << getEast()->getStallName() << std::endl;
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

Inventory* Butcher::createItem(char purchase, Player* player)
{
	Inventory* item = NULL; //create pointer to a new inventory item

	//Selection = A
	if (purchase == 'A')
	{
		item = new Inventory("Chicken", 5.00); //create new object and initialize with name and price of selection

		//if the player doesn't have enough money, inform them and return
		if (player->getWallet() <= 4.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}

		//add the item to the shopping bag and remove money from player's wallet
		else
		{
			player->changeBagContents("Chicken");
			player->removeMoney(5.00);
		}
	}

	//Selection = B
	if (purchase == 'B')
	{
		item = new Inventory("Salmon", 6.00); //create new object and initialize with name and price of selection
		 
		//if the player doesn't have enough money, inform them and return
		if (player->getWallet() <= 5.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}

		//add the item to the shopping bag and remove money from player's wallet
		else
		{
			player->changeBagContents("Salmon");
			player->removeMoney(6.00);
		}
	}

	//Selection = C
	if (purchase == 'C')
	{
		item = new Inventory("Rib Eye", 10.00); //create new object and initialize with name and price of selection

		//if the player doesn't have enough money, inform them and returns
		if (player->getWallet() <= 9.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}

		//add the item to the shopping bag and remove money from player's wallet
		else
		{
			player->changeBagContents("Rib Eye");
			player->removeMoney(10.00);
		}
	}

	//Selection = D
	if (purchase == 'D')
	{
		item = new Inventory("Turkey", 7.00); //create new object and initialize with name and price of selection
		
		//if the player doesn't have enough money, inform them and return
		if (player->getWallet() <= 6.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}

		//add the item to the shopping bag and remove money from player's wallet
		else
		{
			player->changeBagContents("Turkey");
			player->removeMoney(7.00);
		}
	}

	//Selection = E
	if (purchase == 'E')
	{
		item = new Inventory("Veal", 20.00); //create new object and initialize with name and price of selection

		//if the player doesn't have enough money, inform them and return
		if (player->getWallet() <= 19.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}

		//add the item to the shopping bag and remove money from player's wallet
		else
		{
			player->changeBagContents("Veal");
			player->removeMoney(20.00);
		}
	}

	//Selection = F
	if (purchase == 'F')
	{
		item = new Inventory("Filet Mignon", 10.00);

		//if the player doesn't have enough money, inform them and return
		if (player->getWallet() <= 9.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}

		//add the item to the shopping bag and remove money from player's wallet
		else
		{
			player->changeBagContents("Filet Mignon");
			player->removeMoney(10.00);
		}
	}		

	//Selection = G
	if (purchase == 'G')
	{
		item = new Inventory("Pepperoni", 4.00); //create new object and initialize with name and price of selection

		//if the player doesn't have enough money, inform them and return
		if (player->getWallet() <= 3.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}

		//add the item to the shopping bag and remove money from player's wallet
		else
		{
			player->changeBagContents("Pepperoni");
			player->removeMoney(4.00);
		}
	}

	//Selection = H
	if (purchase == 'H')
	{
		item = new Inventory("Ham", 6.00); //create new object and initialize with name and price of selection

		//if the player doesn't have enough money, inform them and return
		if (player->getWallet() <= 5.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}

		//add the item to the shopping bag and remove money from player's wallet
		else
		{
			player->changeBagContents("Ham");
			player->removeMoney(6.00);
		}
	}

	//Selection = I
	if (purchase == 'I')
	{
		item = new Inventory("Bison", 15.00); //create new object and initialize with name and price of selection

		//if the player doesn't have enough money, inform them and return
		if (player->getWallet() <= 14.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}

		//add the item to the shopping bag and remove money from player's wallet
		else
		{
			player->changeBagContents("Bison");
			player->removeMoney(15.00);
		}
	}

	//Selection = J
	if (purchase == 'J')
	{
		item = new Inventory("Shrimp", 5.00); //create new object and initialize with name and price of selection

		//if the player doesn't have enough money, inform them and return
		if (player->getWallet() <= 4.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}

		//add the item to the shopping bag and remove money from player's wallet
		else
		{
			player->changeBagContents("Shrimp");
			player->removeMoney(5.00);
		}
	}

	return item; //return the pointer to the new item
}

/*****************************************************************************************************
 ** Function: lostBoy
 ** Description: Special function for the Butcher class. This function prompts the user to help
 ** a young lost boy or not. If the user accepts, they get 5 points bonus. Otherwise, they
 ** have no penalty.
 *****************************************************************************************************/

void Butcher::lostBoy(Player* player)
{
	//flavor text and user prompt
	std::cout << "\nAs you walk into the the butcher stall you notice a little boy about 5 or 6"
		<< "\ncrying near the entrance. You look around and don't see any adults in sight that"
		<< "\nmight belong to him. Do you stop and see if you can help him find his parents? Y/N: ";
	
	//user input and validation
	char yn;
	std::cin >> yn;

	yn = char(toupper(yn)); //convert to uppercase

	while (yn != 'Y' && yn != 'N')
	{
		std::cout << "\nPlease enter Y or N: ";
		std::cin >> yn;
	}

	//if yes, flavor text and increment bonus points by 5
	if (yn == 'Y')
	{
		std::cout << "\n\nYou crouch down to the boy and ask him if he is lost. He nods his"
			<< "\nhead mournfully at you. Taking his hand, you tell him you will help find"
			<< "\nhis parents and he smiles at you. You walk out of the stall and take"
			<< "\nonly a few steps before the boy runs to a neighboring stall where his"
			<< "\nparents are browsing some wares, oblivious to his absence."
			<< "\n\nWell, it was a short deed, but a good deed nonetheless. You feel"
			<< "\nproud of yourself and return to the butcher stall.\n" << std::endl;

		player->incBonus(5); //+5 bonus points
		std::cout << "\n\nYou have earned 5 bonus points for your kindness!" << std::endl;
	}

	//if no, there is no penalty
	if (yn == 'N')
	{
		std::cout << "\n\nYou've never particularly liked children and this one"
			<< "\nseems particularly.. snotty. You assure yourself that someone"
			<< "\nwill find or help him soon enough and you continue into the butcher"
			<< "\nshop. Kids should learn to stop running off from their parents.\n" << std::endl;
	}

	setLostCheck(1); //set variable to have special function completed
}


/**************************************************************************************************
** Function: setLostCheck
** Description: This is a helper function that sets the variable for whether the special function
** has been used or not. 0 = not used. 1 = used. Each special function is only used once so this
** function helps to be sure that functions are not repeated during the program.
***************************************************************************************************/

void Butcher::setLostCheck(int done)
{
	lostCheck = done;
}

/**************************************************************************************************
** Function: getLostCheck
** Description: This is a helper function that returns the check for whether the special function
** of this class/stall has been used yet. Each function is only used one so this is to be sure
** that the game is not repeating special functions.
***************************************************************************************************/

int Butcher::getLostCheck()
{
	return lostCheck;
}
