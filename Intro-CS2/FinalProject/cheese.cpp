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

#include "cheese.hpp"

/**************************************************************************************************
** Function: displayInventory
** Description: This function displays the inventory of the stall. It creates a menu object
** and calls the display function for the specific stall. This is used by shopkeeper
** function in order to display the goods available for purchase to the player.
***************************************************************************************************/

void Cheese::displayInventory()
{
	Menu display;
	display.displayCheese();
}

/**************************************************************************************************
** Function: stallText
** Description: This function displays the stall text for the specific stall. It also lets
** the player know how much time they have left. It calls the shopKeeper function, and after
** exiting this function it exits if the game is over. If not, it displays the locations the
** player can continue onto to further the game.
** Parameters: Player pointer
***************************************************************************************************/

void Cheese::stallText(Player* player)
{
	//flavor text and intro
	std::cout << "\nCurrent Location: Cheese" << std::endl;
	std::cout << "\nYou have " << player->getTime() << " minutes left before you are late!" << std::endl;
	std::cout << "Welcome to Better Cheddar! Please enjoy our wide selection of local and"
		<< "\nimported cheeses. Everything is made with a labor of love, and our prices are low!" << std::endl;

	shopKeeper(player); //call shopKeeper function

	if (player->gameOver() == true) //if game is over, return 
	{
		std::cin.ignore(100, '\n'); //clear buffer for next input
		return;
	}

	else if (player->gameOver() == false) //if game is not over, continue
	{
		//display where the user can go
		std::cout << "\nFrom here you can go: "
			<< "\nS: " << getSouth()->getStallName() << std::endl;
		std::cout << "E: " << getEast()->getStallName() << std::endl;
		std::cout << "W: " << getWest()->getStallName() << std::endl;
		std::cout << "NE: " << getNE()->getStallName() << std::endl;
		std::cout << "C: Display Bag Contents" << std::endl;
		std::cout << "R: Display Shopping List" << std::endl;
		std::cout << "Where would you like to go next? ";
	}
}

/**************************************************************************************************
** Function: Class Constructor
** Description: This constructor initializes/sets the name of the class it belongs to. It is a
** string that is called upon later in the program.
***************************************************************************************************/

Cheese::Cheese()
{
	setStallName("Cheese");
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

Inventory* Cheese::createItem(char purchase, Player* player)
{
	Inventory* item = NULL; //create pointer to Inventory object

	//Selection = A
	if (purchase == 'A')
	{
		item = new Inventory("Cheddar", 3.00); //create new object and initialize it with name and price of selection

		 //if player doesn't have enough money, inform them and return
		if (player->getWallet() <= 2.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}

		//otherwise, add item to bag. If the special function has not been
		//used yet, call the function. Otherwise, remove the money from the player's wallet.
		else
		{
			player->changeBagContents("Cheddar");
		
			if (getSLCheck() == 0)
			{
				shopLifter(player, 3.00);
			}
			else
			{
				player->removeMoney(3.00);
			}
		}
	}
	
	//Selection = B
	if (purchase == 'B')
	{
		item = new Inventory("Colby Jack", 5.00); //create new object and initialize it with name and price of selection

		//if player doesn't have enough money, inform them and return
		if (player->getWallet() <= 4.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}

		//otherwise, add item to bag. If the special function has not been
		//used yet, call the function. Otherwise, remove the money from the player's wallet.
		else
		{
			player->changeBagContents("Colby Jack");
			
			if (getSLCheck() == 0)
			{
				shopLifter(player, 5.00);
			}
			else
			{
				player->removeMoney(5.00);
			}
		}
	}

	//Selection = C
	if (purchase == 'C')
	{
		item = new Inventory("Mozzarella", 3.00); //create new object and initialize it with name and price of selection

		//if player doesn't have enough money, inform them and return
		if (player->getWallet() <= 2.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}

		//otherwise, add item to bag. If the special function has not been
		//used yet, call the function. Otherwise, remove the money from the player's wallet.
		else
		{
			player->changeBagContents("Mozzarella");

			if (getSLCheck() == 0)
			{
				shopLifter(player, 3.00);
			}
			else
			{
				player->removeMoney(3.00);
			}
		}
	}

	//Selection = D
	if (purchase == 'D')
	{
		item = new Inventory("American", 2.00); //create new object and initialize it with name and price of selection

		//if player doesn't have enough money, inform them and return
		if (player->getWallet() <= 1.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}

		//otherwise, add item to bag. If the special function has not been
		//used yet, call the function. Otherwise, remove the money from the player's wallet.
		else
		{
			player->changeBagContents("American");

			if (getSLCheck() == 0)
			{
				shopLifter(player, 2.00);
			}
			else
			{
				player->removeMoney(2.00);
			}
		}
	}

	//Selection = E
	if (purchase == 'E')
	{
		item = new Inventory("Goat", 3.00); //create new object and initialize it with name and price of selection

		//if player doesn't have enough money, inform them and return
		if (player->getWallet() <= 2.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}

		//otherwise, add item to bag. If the special function has not been
		//used yet, call the function. Otherwise, remove the money from the player's wallet.
		else
		{
			player->changeBagContents("Goat");

			if (getSLCheck() == 0)
			{
				shopLifter(player, 3.00);
			}
			else
			{
				player->removeMoney(3.00);
			}
		}
	}

	//Selection = F
	if (purchase == 'F')
	{
		item = new Inventory("Bleu", 4.00); //create new object and initialize it with name and price of selection

		//if player doesn't have enough money, inform them and return
		if (player->getWallet() <= 2.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}

		//otherwise, add item to bag. If the special function has not been
		//used yet, call the function. Otherwise, remove the money from the player's wallet.
		else
		{
			player->changeBagContents("Bleu");
			if (getSLCheck() == 0)
			{
				shopLifter(player, 4.00);
			}
			else
			{
				player->removeMoney(4.00);
			}
		}
	}

	//Selection = G
	if (purchase == 'G')
	{
		item = new Inventory("Parmesan", 3.00); //create new object and initialize it with name and price of selection

		//if player doesn't have enough money, inform them and return
		if (player->getWallet() <= 2.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}

		//otherwise, add item to bag. If the special function has not been
		//used yet, call the function. Otherwise, remove the money from the player's wallet.
		else
		{
			player->changeBagContents("Parmesan");
			if (getSLCheck() == 0)
			{
				shopLifter(player, 3.00);
			}
			else
			{
				player->removeMoney(3.00);
			}
		}
	}

	//Selection = H
	if (purchase == 'H')
	{
		item = new Inventory("Feta", 2.00); //create new object and initialize it with name and price of selection

		//if player doesn't have enough money, inform them and return
		if (player->getWallet() <= 1.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}

		//otherwise, add item to bag. If the special function has not been
		//used yet, call the function. Otherwise, remove the money from the player's wallet.
		else
		{
			player->changeBagContents("Feta");
			if (getSLCheck() == 0)
			{
				shopLifter(player, 2.00);
			}
			else
			{
				player->removeMoney(2.00);
			}
		}
	}

	//Selection = I
	if (purchase == 'I')
	{
		item = new Inventory("Meunster", 5.00); //create new object and initialize it with name and price of selection
		
		//if player doesn't have enough money, inform them and return
		if (player->getWallet() <= 4.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}

		//otherwise, add item to bag. If the special function has not been
		//used yet, call the function. Otherwise, remove the money from the player's wallet.
		else
		{
			player->changeBagContents("Meunster");
			if (getSLCheck() == 0)
			{
				shopLifter(player, 5.00);
			}
			else
			{
				player->removeMoney(5.00);
			}
		}
	}

	//Selection = J
	if (purchase == 'J')
	{
		item = new Inventory("Pepper Jack", 4.00); //create new object and initialize it with name and price of selection

		//if player doesn't have enough money, inform them and return
		if (player->getWallet() <= 3.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}

		//otherwise, add item to bag. If the special function has not been
		//used yet, call the function. Otherwise, remove the money from the player's wallet.
		else
		{
			player->changeBagContents("Pepper Jack");
			if (getSLCheck() == 0)
			{
				shopLifter(player, 4.00);
			}
			else
			{
				player->removeMoney(4.00);
			}
		}
	}

	return item; //return pointer to new Inventory object
}

/*******************************************************************************************************
 ** Function: shopLifter
 ** Description: This is the special function of the Cheese class. It is only used once. The player
 ** faces a moral dillema. They have spotted a shoplifter who offers to give them free cheese if they
 ** don't turn them in. What will the player decide?
 ** If the user turns in the shop lifter they get a 50 percent discount and a hefty bonus. If they don't
 ** turn in the shoplifter they get the cheese for free and no penalty (but no bonus).
********************************************************************************************************/

void Cheese::shopLifter(Player* player, double price)
{
	//flavor text and explanation
	char moralD;
	std::cout << "\nAs you look through the goods of the cheese stall"
		<< "\nyou spot a shifty looking fellow out of the corner of your eye."
		<< "\nYou turn your gaze to get a better look and spot him stuffing some"
		<< "\nof the cheese you were about to purchase into his backpack!"
		<< "\n\nHe sees you eyeing him and smiles at you broadly, glancing"
		<< "\nquickly at the shopkeeper before pulling you aside and speaking quietly."
		<< "\n\n'Hello friend! Lovely day isn't it? What you saw there.. I am running"
		<< "\nlow on funds this month and my kids are hungry. Could I tempt you with some"
		<< "\nof the wares in exchange for your.. discretion?'"
		<< "\n\nHe looks at you hopefully. What do you do? "
		<< "\n\nA) Tell the shopkeeper about the thief"
		<< "\nB) Keep quiet and accept the cheese ";
	std::cin >> moralD;

	moralD = char(toupper(moralD)); //convert to uppercase

	//input validation
	while (moralD != 'A' && moralD != 'B')
	{
		std::cout << "Please enter A or B";
		std::cin >> moralD;
	}

	//if you turn in the shoplifter
	if (moralD == 'A')
	{
		std::cout << "\n'There is no reason to shoplift, my friend,' you say to the man"
			<< "\nbefore waving to the shopkeeper to get his attention."
			<< "\n'You again!' the shopkeeper bellows before swiftly grabbing up the shoplifter."
			<< "\n'I thought I told you to stay away from here?'"
			<< "\n\nAfter dealing with the shoplifter, the man turns to you. 'Thank you for your help!"
			<< "\nI nearly missed him this time.' Please, let me give you a 50% discount on your purchase today!"
			<< "\n\nYou gratefully accept his offer and feel a little better about yourself to boot!" << std::endl;

		player->removeMoney(price / 2); //receive 50% discount
		player->incBonus(10); //receive 10 points bonus

		std::cout << "\n\nGreat choice! You have received a 10 point bonus for your moral fortitude." << std::endl;
	

	}
	else if(moralD == 'B')
	{
		std::cout << "\nYou glance around at the shopkeeper and see that he is"
			<< "\nengrossed in a conversation with another customer. He would not"
			<< "\nnotice a cheese or two missing, would he? There are so many!"
			<< "\nYou are already on a tight budget and a little guiltily accept"
			<< "\nthe man's offer. He does have kids to feed after all.." << std::endl;

		player->removeMoney(0); //free cheese.. but at what cost?
		
	}

	setSLCheck(1); //mark task as completed
}


/**************************************************************************************************
** Function: setSLCheck
** Description: This is a helper function that sets the variable for whether the special function
** has been used or not. 0 = not used. 1 = used. Each special function is only used once so this
** function helps to be sure that functions are not repeated during the program.
***************************************************************************************************/

void Cheese::setSLCheck(int check)
{
	slCheck = check;
}

/**************************************************************************************************
** Function: getSLCheck
** Description: This is a helper function that returns the check for whether the special function
** of this class/stall has been used yet. Each function is only used one so this is to be sure
** that the game is not repeating special functions.
***************************************************************************************************/

int Cheese::getSLCheck()
{
	return  slCheck;
}
