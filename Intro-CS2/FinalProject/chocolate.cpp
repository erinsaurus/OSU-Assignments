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

#include "chocolate.hpp"

/**************************************************************************************************
** Function: displayInventory
** Description: This function displays the inventory of the stall. It creates a menu object
** and calls the display function for the specific stall. This is used by shopkeeper
** function in order to display the goods available for purchase to the player.
***************************************************************************************************/

void Chocolate::displayInventory()
{
	Menu display;
	display.displayChocolate();
}

/**************************************************************************************************
** Function: Class Constructor
** Description: This constructor initializes/sets the name of the class it belongs to. It is a
** string that is called upon later in the program.
***************************************************************************************************/

Chocolate::Chocolate()
{
	setStallName("Chocolate");
}

/**************************************************************************************************
** Function: setDieCheck
** Description: This is a helper function that sets the variable for whether the special function
** has been used or not. 0 = not used. 1 = used. Each special function is only used once so this
** function helps to be sure that functions are not repeated during the program.
***************************************************************************************************/

void Chocolate::setDieCheck(int done)
{
	dieCheck = done;
}

/**************************************************************************************************
** Function: getDieCheck
** Description: This is a helper function that returns the check for whether the special function
** of this class/stall has been used yet. Each function is only used one so this is to be sure
** that the game is not repeating special functions.
***************************************************************************************************/

int Chocolate::getDieCheck()
{
	return dieCheck;
}

void Chocolate::dieGuessing(Player* player, double price)
{
	std::cout << "\nAfter finally pulling yourself away from the delicious temptations of the chocolate stall,"
		<< "\nyou hand your selection to the shopkeeper for purchase. The shopkeeper is a small, plump woman with a kind"
		<< "\nface that looks like it has had the privilege of eating chocolate everyday."
		<< "\n\nHello my dear! I see you have a keen eye for chocolate. You seem like the type of person who would"
		<< "\nbe interested in some rare imported chocolate. It is of the same type you have in your hand right now,"
		<< "\nbut very exotic. Since it is so rare and desired, I have a little game I like to play to earn the chocolate."
		<< "\nRoll three five-sided die and guess a number. If the die is within 5 of your guess, you can buy the chocolate"
		<< "\nfor the same price of what you have in your hand. If you guess right it's free!"
		<< "\n\nDo you wish to play? Y/N: ";
	
	char choc;
	std::cin >> choc;
	while (choc != 'Y' && choc != 'N')
	{
		std::cout << "Sorry, I am a bit hard of hearing. Would you like to play? Please enter Y or N: ";
		std::cin >> choc;
	}

	if (choc == 'Y')
	{
		std::cout << "\nWhat number would you like to guess? It should be less than 15: ";
		int guess;
		std::cin >> guess;
		while (guess > 15 || guess <= 0)
		{
			std::cout << "\nPlease choose a number between 1 and 15: ";
			std::cin >> guess;
		}

		int roll1 = rand() % 5 + 1;
		int roll2 = rand() % 5 + 1;
		int roll3 = rand() % 5 + 1;
		int totalRoll = roll1 + roll2 + roll3;

		std::cout << "\nYou pick up three die that seem to have magically appeared before you and toss them."
			<< "\nYou rolled: " << totalRoll << std::endl;

		if (guess <= totalRoll + 5 && guess >= totalRoll - 5)
		{
			std::cout << "\nGreat guess! You are within 5 of the roll so you get to take this home with you." << std::endl;
			player->removeMoney(price);
			player->incBonus(15);
		}
		else if (guess == totalRoll)
		{
			std::cout << "Fantastic guess! You got it right on the money! You definitely deserve to have"
				<< "\nthis for free. Enjoy the chocolate!" << std::endl;
			player->removeMoney(0);
			player->incBonus(15);
		}
		else
		{
			std::cout << "\nClose! Sorry, you didn't guess close enough. Maybe next time." << std::endl;
		}
	}
	else if (choc == 'N')
	{
		player->removeMoney(price);
	}

	setDieCheck(1);
}

/**************************************************************************************************
** Function: stallText
** Description: This function displays the stall text for the specific stall. It also lets
** the player know how much time they have left. It calls the shopKeeper function, and after
** exiting this function it exits if the game is over. If not, it displays the locations the
** player can continue onto to further the game.
** Parameters: Player pointer
***************************************************************************************************/

void Chocolate::stallText(Player* player)
{
	std::cout << "\nCurrent Location: Chocolate" << std::endl;
	std::cout << "\nYou have " << player->getTime() << " minutes left before you are late!" << std::endl;
	std::cout << "Welcome to The Three Chocolatiers! We have an amazing selection of chocolates"
		<< "\nfor all of your chocolate needs. Please let us know if there is anything we can help you with!" << std::endl;

	shopKeeper(player);

	if (player->gameOver() == true) //if game is over, return 
	{
		std::cin.ignore(100, '\n'); //clear buffer for next input
		return;
	}

	else if (player->gameOver() == false) //if game is not over, continue
	{
		std::cout << "\nFrom here you can go: "
			<< "\nN: " << getNorth()->getStallName() << std::endl;
		std::cout << "W: " << getWest()->getStallName() << std::endl;
		std::cout << "NW: " << getNW()->getStallName() << std::endl;
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

Inventory * Chocolate::createItem(char purchase, Player* player)
{
	Inventory* item = NULL; //create pointer to Inventory object

	//Selection = A
	if (purchase == 'A')
	{
		item = new Inventory("Milk", 5.00); //create pointer to new Inventory item and initialize with name and price

		//if player doesn't have enough money, inform them and return
		if (player->getWallet() <= 4.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}

		//add selection to shopping bag. If special function has not been done
		//yet, call the special function. Otherwise, remove the money
		//from the player's wallet. Add bonus for bonus item to score
		else
		{
			player->changeBagContents("Milk");
			if (getDieCheck() == 0)
			{
				dieGuessing(player, 5.00);
			}

			else
			{
				player->removeMoney(5.00);
			}

			std::cout << "\nYou collected a bonus item! You have received 10 bonus points." << std::endl;
			player->incBonus(15);
		}
	}

	//Selection = B
	if (purchase == 'B')
	{
		item = new Inventory("Dark", 5.00); //create pointer to new Inventory item and initialize with name and price

		//if player doesn't have enough money, inform them and return
		if (player->getWallet() <= 4.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}

		//add selection to shopping bag. If special function has not been done
		//yet, call the special function. Otherwise, remove the money
		//from the player's wallet. Add bonus for bonus item to score
		else
		{
			player->changeBagContents("Dark");
			if (getDieCheck() == 0)
			{
				dieGuessing(player, 5.00);
			}

			else
			{
				player->removeMoney(5.00);
			}

			std::cout << "\nYou collected a bonus item! You have received 10 bonus points." << std::endl;
			player->incBonus(15);
		}
	}

	//Selection = C
	if (purchase == 'C')
	{
		item = new Inventory("White", 5.00); //create pointer to new Inventory item and initialize with name and price

		//if player doesn't have enough money, inform them and return
		if (player->getWallet() <= 4.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}

		//add selection to shopping bag. If special function has not been done
		//yet, call the special function. Otherwise, remove the money
		//from the player's wallet. Add bonus for bonus item to score
		else
		{
			player->changeBagContents("White");
			if (getDieCheck() == 0)
			{
				dieGuessing(player, 5.00);
			}

			else
			{
				player->removeMoney(5.00);
			}

			std::cout << "\nYou collected a bonus item! You have received 10 bonus points." << std::endl;
			player->incBonus(15);
		}
	}

	//Selection = D
	if (purchase == 'D')
	{
		item = new Inventory("Bittersweet", 5.00); //create pointer to new Inventory item and initialize with name and price

		//if player doesn't have enough money, inform them and return
		if (player->getWallet() <= 4.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}

		//add selection to shopping bag. If special function has not been done
		//yet, call the special function. Otherwise, remove the money
		//from the player's wallet. Add bonus for bonus item to score
		else
		{
			player->changeBagContents("Bittersweet");
			if (getDieCheck() == 0)
			{
				dieGuessing(player, 5.00);
			}

			else
			{
				player->removeMoney(5.00);
			}

			std::cout << "\nYou collected a bonus item! You have received 10 bonus points." << std::endl;
			player->incBonus(15);
		}
	}

	//Selection = E
	if (purchase == 'E')
	{
		item = new Inventory("Baking", 5.00); //create pointer to new Inventory item and initialize with name and price

		//if player doesn't have enough money, inform them and return
		if (player->getWallet() <= 4.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}

		//add selection to shopping bag. If special function has not been done
		//yet, call the special function. Otherwise, remove the money
		//from the player's wallet. Add bonus for bonus item to score
		else
		{
			player->changeBagContents("Baking");
			if (getDieCheck() == 0)
			{
				dieGuessing(player, 5.00);
			}

			else
			{
				player->removeMoney(5.00);
			}

			std::cout << "\nYou collected a bonus item! You have received 10 bonus points." << std::endl;
			player->incBonus(15);
		}
	}

	//Selection = F
	if (purchase == 'F')
	{
		item = new Inventory("Chocolate Oil", 5.00); //create pointer to new Inventory item and initialize with name and price

		//if player doesn't have enough money, inform them and return
		if (player->getWallet() <= 4.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}

		//add selection to shopping bag. If special function has not been done
		//yet, call the special function. Otherwise, remove the money
		//from the player's wallet. Add bonus for bonus item to score
		else
		{
			player->changeBagContents("Chocolate Oil");
			if (getDieCheck() == 0)
			{
				dieGuessing(player, 5.00);
			}

			else
			{
				player->removeMoney(5.00);
			}

			std::cout << "\nYou collected a bonus item! You have received 10 bonus points." << std::endl;
			player->incBonus(15);
		}
	}

	//Seleection = G
	if (purchase == 'G')
	{
		item = new Inventory("Unsweetened", 5.00); //create pointer to new Inventory item and initialize with name and price


		//if player doesn't have enough money, inform them and return
		if (player->getWallet() <= 4.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}

		//add selection to shopping bag. If special function has not been done
		//yet, call the special function. Otherwise, remove the money
		//from the player's wallet. Add bonus for bonus item to score
		else
		{
			player->changeBagContents("Unsweetened");
			if (getDieCheck() == 0)
			{
				dieGuessing(player, 5.00);
			}

			else
			{
				player->removeMoney(5.00);
			}

			std::cout << "\nYou collected a bonus item! You have received 10 bonus points." << std::endl;
			player->incBonus(15);
		}
	}

	//Selection = H
	if (purchase == 'H')
	{
		item = new Inventory("Chocolate Liquer", 5.00); //create pointer to new Inventory item and initialize with name and price

		//if player doesn't have enough money, inform them and return
		if (player->getWallet() <= 4.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}

		//add selection to shopping bag. If special function has not been done
		//yet, call the special function. Otherwise, remove the money
		//from the player's wallet. Add bonus for bonus item to score
		else
		{
			player->changeBagContents("Chocolate Liquer");
			if (getDieCheck() == 0)
			{
				dieGuessing(player, 5.00);
			}

			else
			{
				player->removeMoney(5.00);
			}

			std::cout << "\nYou collected a bonus item! You have received 10 bonus points." << std::endl;
			player->incBonus(15);
		}
	}

	//Selection = I
	if (purchase == 'I')
	{
		item = new Inventory("Cacao", 5.00); //create pointer to new Inventory item and initialize with name and price

		//if player doesn't have enough money, inform them and return
		if (player->getWallet() <= 4.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}

		//add selection to shopping bag. If special function has not been done
		//yet, call the special function. Otherwise, remove the money
		//from the player's wallet. Add bonus for bonus item to score
		else
		{
			player->changeBagContents("Cacao");
			if (getDieCheck() == 0)
			{
				dieGuessing(player, 5.00);
			}

			else
			{
				player->removeMoney(5.00);
			}

			std::cout << "\nYou collected a bonus item! You have received 10 bonus points." << std::endl;
			player->incBonus(15);
		}
	}

	//Selection = J
	if (purchase == 'J')
	{
		item = new Inventory("Ground", 5.00); //create pointer to new Inventory item and initialize with name and price

		//if player doesn't have enough money, inform them and return
		if (player->getWallet() <= 4.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}

		//add selection to shopping bag. If special function has not been done
		//yet, call the special function. Otherwise, remove the money
		//from the player's wallet. Add bonus for bonus item to score
		else
		{
			player->changeBagContents("Ground");
			if (getDieCheck() == 0)
			{
				dieGuessing(player, 5.00);
			}

			else
			{
				player->removeMoney(5.00);
			}

			std::cout << "\nYou collected a bonus item! You have received 10 bonus points." << std::endl;
			player->incBonus(15);
		}
	}

	return item; //return new inventory item
}
