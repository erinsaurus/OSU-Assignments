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

#include "spices.hpp"

/**************************************************************************************************
** Function: displayInventory
** Description: This function displays the inventory of the stall. It creates a menu object
** and calls the display function for the specific stall. This is used by shopkeeper
** function in order to display the goods available for purchase to the player.
***************************************************************************************************/

void Spices::displayInventory()
{
	Menu display;
	display.displaySpices();
}

/**************************************************************************************************
** Function: Class Constructor
** Description: This constructor initializes/sets the name of the class it belongs to. It is a
** string that is called upon later in the program.
***************************************************************************************************/

Spices::Spices()
{
	setStallName("Spices");
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

Inventory * Spices::createItem(char purchase, Player* player)
{
	Inventory* item = NULL;

	if (purchase == 'A')
	{
		item = new Inventory("Pepper", 3.00);

		if (player->getWallet() <= 2.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			player->changeBagContents("Pepper");
			if (getGuessCheck() == 0)
			{
				guessThePrice(player, 3.00);
			}
			else
			{
				player->removeMoney(3.00);
			}
		}
	}
	if (purchase == 'B')
	{
		item = new Inventory("Salt", 2.00);

		if (player->getWallet() <= 1.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			player->changeBagContents("Salt");
			if (getGuessCheck() == 0)
			{
				guessThePrice(player, 2.00);
			}
			else
			{
				player->removeMoney(2.00);
			}
		}
	}
	if (purchase == 'C')
	{
		item = new Inventory("Rosemary", 3.00);

		if (player->getWallet() <= 2.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			player->changeBagContents("Rosemary");
			if (getGuessCheck() == 0)
			{
				guessThePrice(player, 3.00);
			}
			else
			{
				player->removeMoney(3.00);
			}
		}
	}
	if (purchase == 'D')
	{
		item = new Inventory("Cayenne", 2.00);

		if (player->getWallet() <= 1.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			player->changeBagContents("Cayenne");
			if (getGuessCheck() == 0)
			{
				guessThePrice(player, 2.00);
			}
			else
			{
				player->removeMoney(2.00);
			}
		}
	}
	if (purchase == 'E')
	{
		item = new Inventory("Parsley", 3.00);

		if (player->getWallet() <= 2.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			player->changeBagContents("Parsley");
			if (getGuessCheck() == 0)
			{
				guessThePrice(player, 3.00);
			}
			else
			{
				player->removeMoney(3.00);
			}
		}
	}
	if (purchase == 'F')
	{
		item = new Inventory("Cumin", 4.00);

		if (player->getWallet() <= 3.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			player->changeBagContents("Cumin");
			if (getGuessCheck() == 0)
			{
				guessThePrice(player, 4.00);
			}
			else
			{
				player->removeMoney(4.00);
			}
		}
	}
	if (purchase == 'G')
	{
		item = new Inventory("Cinnamon", 3.00);

		if (player->getWallet() <= 2.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			player->changeBagContents("Cinnamon");
			if (getGuessCheck() == 0)
			{
				guessThePrice(player, 3.00);
			}
			else
			{
				player->removeMoney(3.00);
			}
		}
	}
	if (purchase == 'H')
	{
		item = new Inventory("Nutmeg", 2.00);

		if (player->getWallet() <= 1.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			player->changeBagContents("Nutmeg");
			if (getGuessCheck() == 0)
			{
				guessThePrice(player, 2.00);
			}
			else
			{
				player->removeMoney(2.00);
			}
		}
	}
	if (purchase == 'I')
	{
		item = new Inventory("Paprika", 5.00);

		if (player->getWallet() <= 4.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			player->changeBagContents("Paprika");
			if (getGuessCheck() == 0)
			{
				guessThePrice(player, 5.00);
			}
			else
			{
				player->removeMoney(5.00);
			}
		}
	}
	if (purchase == 'J')
	{
		item = new Inventory("Spice Pack", 2.00);

		if (player->getWallet() <= 1.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			player->changeBagContents("Spice Pack");
			if (getGuessCheck() == 0)
			{
				guessThePrice(player, 2.00);
			}
			else
			{
				player->removeMoney(2.00);
			}
		}
	}

	return item;
}

void Spices::guessThePrice(Player * player, double price)
{
	std::cout << "\nJust as you begin to hand your money over to the shopkeeper he"
		<< "\nputs his hand out in a gesture to stop you in your tracks. Confused, you look"
		<< "\nup at him and see a jolly beared man who looks suspiciously like Santa Claus."
		<< "\nHe grins down at you as if he has a secret he is bursting to share."
		<< "\n\n'Before you do that, there is one more thing. I happen to have a very rare"
		<< "\ncompletely organic, pesticide-free, home-grown, free-range spice of the exact"
		<< "\nvariety you are purchasing! I am willing to let this go to the right person. To"
		<< "\nto make it a little more interesting.. if you guess the price within 15 guesses"
		<< "\nI will give it to you for free! If you don't guess within 15 tries, then you"
		<< "\n aren't the rightful owner I fear! This is a one-time offer, today only."
		<< "\n\n Would you like to play? Win to earn 15 bonus points! Y/N ";

	char play;
	std::cin >> play;
	while (play != 'Y' && play != 'N')
	{
		std::cout << "I didn't catch that. Please enter a Y or N: ";
		std::cin >> play;
	}

	int cost = 15;

	if (play == 'Y')
	{
		std::cout << "\n\nExcellent! You won't be disappointed. To make it a little"
			<< "\nsimpler, guess only in whole numbers. No tax on this baby!"
			<< "\nWhat is your first guess? ";
			int guess; 
			std::cin >> guess;

			int numGuesses = 0;
			while (numGuesses <= 15)
			{
				if (guess < cost)
				{
					std::cout << "\nToo low! Think higher. ";
					std::cout << "\nRemaining guesses: " << 16 - numGuesses << " ";
					std::cout << "\nGuess again: ";
					std::cin >> guess;
				}
				else if (guess > cost)
				{
					std::cout << "\nToo high! Think lower. ";
					std::cout << "\nRemaining guesses: " << 16 - numGuesses << " ";
					std::cout << "\nGuess again: ";
					std::cin >> guess;
				}
				else if (guess == cost)
				{
					std::cout << "\nYou nailed it! Here is your prize - for free!" << std::endl;
					std::cout << "\nYou have received a 15 point bonus for your stunning cleverness!" << std::endl;
					player->incBonus(15);
					player->removeMoney(0);
					return;
				}

				numGuesses++;

			}

			std::cout << "\nOh dear. Looks like this spice is looking for another home."
				<< "\nThe correct price is $" << 15.00 << " Better luck next time!" << std::endl;

			player->removeMoney(price);
	}
	else if (play == 'N')
	{
		player->removeMoney(price);
	}

	setGuessCheck(1);
}

/**************************************************************************************************
** Function: setGuessCheck
** Description: This is a helper function that sets the variable for whether the special function
** has been used or not. 0 = not used. 1 = used. Each special function is only used once so this
** function helps to be sure that functions are not repeated during the program.
***************************************************************************************************/

void Spices::setGuessCheck(int done)
{
	guessCheck = done;
}

/**************************************************************************************************
** Function: getGuessCheck
** Description: This is a helper function that returns the check for whether the special function
** of this class/stall has been used yet. Each function is only used one so this is to be sure
** that the game is not repeating special functions.
***************************************************************************************************/

int Spices::getGuessCheck()
{
	return guessCheck;
}

/**************************************************************************************************
** Function: stallText
** Description: This function displays the stall text for the specific stall. It also lets
** the player know how much time they have left. It calls the shopKeeper function, and after
** exiting this function it exits if the game is over. If not, it displays the locations the
** player can continue onto to further the game.
** Parameters: Player pointer
***************************************************************************************************/

void Spices::stallText(Player* player)
{
	std::cout << "\nCurrent Location: Spices" << std::endl;
	std::cout << "\nYou have " << player->getTime() << " minutes left before you are late!" << std::endl;
	std::cout << "Welcome to Good Thymes! Whether you need salt, pepper, or a more exotic spice,"
		<< "\nwe have what you are looking for here. Browse the selection at your leisure!" << std::endl;

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
		std::cout << "E: " << getEast()->getStallName() << std::endl;
		std::cout << "W: " << getWest()->getStallName() << std::endl;
		std::cout << "C: Display Bag Contents" << std::endl;
		std::cout << "R: Display Shopping List" << std::endl;
		std::cout << "Where would you like to go next? ";
	}
}