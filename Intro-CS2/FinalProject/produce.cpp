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

#include "produce.hpp"
#include "wine.hpp"

/**************************************************************************************************
** Function: Class Constructor
** Description: This constructor initializes/sets the name of the class it belongs to. It is a
** string that is called upon later in the program.
***************************************************************************************************/

Produce::Produce()
{
	
	setStallName("Produce");
}

/**************************************************************************************************
** Function: displayInventory
** Description: This function displays the inventory of the stall. It creates a menu object
** and calls the display function for the specific stall. This is used by shopkeeper
** function in order to display the goods available for purchase to the player.
***************************************************************************************************/

void Produce::displayInventory()
{
	Menu display;
	display.displayProduce();
}

/**************************************************************************************************
** Function: stallText
** Description: This function displays the stall text for the specific stall. It also lets
** the player know how much time they have left. It calls the shopKeeper function, and after
** exiting this function it exits if the game is over. If not, it displays the locations the
** player can continue onto to further the game.
** Parameters: Player pointer
***************************************************************************************************/

void Produce::stallText(Player* player)
{
	std::cout << "\nCurrent Location: Produce" << std::endl;
	std::cout << "\nYou have " << player->getTime() << " minutes left before you are late!" << std::endl;
	std::cout << "Welcome to Seed and Trowel! As you can see, all of our produce is top quality"
		<< "\nand locally grown. Only the best of the best is selected for this stall. Enjoy!" << std::endl;

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
		std::cout << "S: " << getSouth()->getStallName() << std::endl;
		std::cout << "W: " << getWest()->getStallName() << std::endl;
		std::cout << "NE: " << getNE()->getStallName() << std::endl;
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

Inventory * Produce::createItem(char purchase, Player* player)
{
	Inventory* item = NULL;

	//Selection = A
	if (purchase == 'A')
	{
		item = new Inventory("Carrot", 2.00);

		if (player->getWallet() <= 1.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			player->changeBagContents("Carrot");
			if (getRPSCheck() == 0)
			{
				rpsGame(player, 2.00);
			}
			else
			{
				player->removeMoney(2.00);
			}
		}
	}
	if (purchase == 'B')
	{
		item = new Inventory("Lettuce", 2.00);

		if (player->getWallet() <= 1.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			player->changeBagContents("Lettuce");
			if (getRPSCheck() == 0)
			{
				rpsGame(player, 2.00);
			}
			else
			{
				player->removeMoney(2.00);
			}
		}
	}
	if (purchase == 'C')
	{
		item = new Inventory("Salad Dressing", 5.00);

		if (player->getWallet() <= 4.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			player->changeBagContents("Salad Dressing");
			if (getRPSCheck() == 0)
			{
				rpsGame(player, 5.00);
			}
			else
			{
				player->removeMoney(5.00);
			}
		}
	}
	if (purchase == 'D')
	{
		item = new Inventory("Potato", 1.00);

		if (player->getWallet() <= 0.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			player->changeBagContents("Potato");
			if (getRPSCheck() == 0)
			{
				rpsGame(player, 1.00);
			}
			else
			{
				player->removeMoney(1.00);
			}
		}
	}
	if (purchase == 'E')
	{
		item = new Inventory("Zucchini", 2.00);

		if (player->getWallet() <= 1.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			player->changeBagContents("Zucchini");
			if (getRPSCheck() == 0)
			{
				rpsGame(player, 2.00);
			}
			else
			{
				player->removeMoney(2.00);
			}
		}
	}
	if (purchase == 'F')
	{
		item = new Inventory("Garlic", 1.00);

		if (player->getWallet() <= 0.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			player->changeBagContents("Garlic");
			if (getRPSCheck() == 0)
			{
				rpsGame(player, 1.00);
			}
			else
			{
				player->removeMoney(1.00);
			}
		}
	}
	if (purchase == 'G')
	{
		item = new Inventory("Pineapple", 4.00);

		if (player->getWallet() <= 3.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			player->changeBagContents("Pineapple");
			if (getRPSCheck() == 0)
			{
				rpsGame(player, 4.00);
			}
			else
			{
				player->removeMoney(4.00);
			}
		}
	}
	if (purchase == 'H')
	{
		item = new Inventory("Asparagus", 3.00);

		if (player->getWallet() <= 2.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			player->changeBagContents("Asparagus");
			if (getRPSCheck() == 0)
			{
				rpsGame(player, 3.00);
			}
			else
			{
				player->removeMoney(3.00);
			}
		}
	}
	if (purchase == 'I')
	{
		item = new Inventory("Spinach", 2.00);

		if (player->getWallet() <= 1.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			player->changeBagContents("Spinach");
			if (getRPSCheck() == 0)
			{
				rpsGame(player, 2.00);
			}
			else
			{
				player->removeMoney(2.00);
			}
		}
	}
	if (purchase == 'J')
	{
		item = new Inventory("Tomato", 1.00);

		if (player->getWallet() <= 0.00)
		{
			std::cout << "Uh oh! You don't have enough money for this purchase." << std::endl;
			return NULL;
		}
		else
		{
			player->changeBagContents("Tomato");
			if (getRPSCheck() == 0)
			{
				rpsGame(player, 1.00);
			}
			else
			{
				player->removeMoney(1.00);
			}
		}
	}

	return item;
}


/**************************************************************************************************
** Function: setRPSCheck
** Description: This is a helper function that sets the variable for whether the special function
** has been used or not. 0 = not used. 1 = used. Each special function is only used once so this
** function helps to be sure that functions are not repeated during the program.
***************************************************************************************************/

void Produce::setRPSCheck(int rps)
{
	rpsCheck = rps;
}

/**************************************************************************************************
** Function: getRPSCheck
** Description: This is a helper function that returns the check for whether the special function
** of this class/stall has been used yet. Each function is only used one so this is to be sure
** that the game is not repeating special functions.
***************************************************************************************************/

int Produce::getRPSCheck()
{
	return rpsCheck;
}

void Produce::rpsGame(Player * player, double price)
{
	std::cout << "\nBeing an excellent cook (if you-do-say-so-yourself), you are aware"
		<< "\nof the pitfalls of bad ingredients. The ingredients make the dish, and you"
		<< "\nare always sure to gather on the best of the bunch (so to speak). After spending"
		<< "\nsome time carefully browsing the produce stall, you finally spot the perfect ingredient"
		<< "\n for your dish. It is perfectly shaped, perfectly colored, and calling your name."
		<< "\nEagerly, you reach down to grab your beautiful prize of years of knowledge"
		<< "\n and dedication to your craft.."
		<< "\n\nBut alas! Just as your hand brushes your delectable selection, another hand"
		<< "\nswoops in and grabs it. The thief is a hurried-looking middle-aged woman who is"
		<< "\nchatting to a friend and not paying attention. Clearly she did not realize"
		<< "\nthe gravity of the situation."
		<< "\n\n'Excuse me ma'am,' you pipe up over her conversation, 'I was just grabbing for that.'"
		<< "\nShe scoffs and brushes you off, continuing her conversation. But you are not to be"
		<< "\nput off. 'Sorry, but I need that for my dinner party tonight.'"
		<< "\nShe stops her conversation to look at you and says, 'there must be a hundred here,"
		<< "\ncan't you grab another?'"
		<< "\n'Actually I can't. It's hard to explain.' (she wouldn't understand) 'I'll play you"
		<< "\nyou Rock / Paper / Scissors for it!'"
		<< "\n\nThe woman sighs but seems a little intrigued. What makes this one so special?"
		<< "\n'Fine.' She says. 'But if I win you have to leave me alone.'"
		<< "\n'Are you sure you want to do this? Y/N' ";

	char play;
	std::cin >> play;
	while (play != 'Y' && play != 'N')
	{
		std::cout << "Sorry, I didn't catch that. Do you want to play or not? Enter Y or N: ";
		std::cin >> play;
	}

	if (play == 'Y')
	{
		std::cout << "\n'Okay let's play. 1.. 2... 3... shoot!' ";

		//1 = Rock
		//2 = Paper
		//3 = Scissors
		//rock beats scissors
		//paper beats rock
		//scissors beats paper


		
		
		int oppWin = 0;
		int youWin = 0;

		while (oppWin <=2 && youWin <=2 && oppWin == youWin)
		{
			//opponent guess
			int opp = rand() % 3 + 1;
			std::cout << "\nChoose Rock, Paper, or Scissors (R, P, or S): ";
			char rps;
			std::cin >> rps;
			while (rps != 'R' && rps != 'P' && rps != 'S')
			{
				std::cout << "\nPlease choose R, P or S: ";
				std::cin >> rps;
			}

			if (opp == 1 && rps == 'R') //Rock vs Rock
			{
				std::cout << "\nYou: Rock"
				<< "\nOpponent: Rock"
				<< "\nIt's a tie! Go again.";
				
			}
			else if (opp == 1 && rps == 'P') //Rock vs Paper
			{
				std::cout << "\nYou: Paper"
					<< "\nOpponent: Rock"
					<< "\nYou win! Go again.";
				youWin++;
			}
			else if (opp == 1 && rps == 'S') //Rock vs Scissors
			{
				std::cout << "\nYou: Scissors"
					<< "\nOpponent: Rock"
					<< "\nOpponent wins! Go again.";

				oppWin++;
			}
			else if (opp == 2 && rps == 'R') //Paper vs Rock
			{
				std::cout << "\nYou: Rock"
					<< "\nOpponent: Paper"
					<< "\nOpponent wins! Go again.";

				oppWin++;
			}
			else if (opp == 2 && rps == 'P') //Paper vs Paper
			{
				std::cout << "\nYou: Paper"
					<< "\nOpponent: Paper"
					<< "\nIt's a tie! Go again.";

				
			}
			else if (opp == 2 && rps == 'S') //Paper vs Scissors
			{
				std::cout << "\nYou: Scissors"
					<< "\nOpponent: Paper"
					<< "\nYou win! Go again.";
		
				youWin++;
			}
			else if (opp == 3 && rps == 'R') //Scissors vs Rock
			{
				std::cout << "\nYou: Rock"
					<< "\nOpponent: Scissors"
					<< "\nYou win! Go again.";
		
				youWin++;
			}
			else if (opp == 3 && rps == 'P') //Scissors vs Paper
			{
				std::cout << "\nYou: Paper"
					<< "\nOpponent: Scissors"
					<< "\nOpponent wins! Go again.";
			
				oppWin++;
			}
			else if (opp == 3 && rps == 'S') //Scissors vs Scissors
			{
				std::cout << "\nYou: Scissors"
					<< "\nOpponent: Scissors"
					<< "\nIt's a tie! Go again.";
			}
		}

		if (oppWin > youWin)
		{
			std::cout << "\n\nThe woman wins and hurriedly shuffles away before"
				<< "\nyou can stop her. You dejectedly, but fairly, take the next best"
				<< "\nselection to make your purchase. Maybe your guests won't notice." << std::endl;

			player->removeMoney(price);
		}
		else if (youWin > oppWin)
		{
			std::cout << "\n\nYou are victorious! You grab your prize from the woman before"
				<< "\nshe can change her mind. You clearly are the superior being and the"
				<< "\nsuperior chef. Your dinner will be all the more tantalizing due to this"
				<< "\nbeatiful specimen of an ingredient."
				<< "\n\nThe shopkeeper who watched this all unfold, was keenly impressed with your"
				<< "\ndedication to his product and your obvious skill at Rock / Paper / Scissors."
				<< "\nAs an additional bonus he offers you your purchase, free of charge. What a day!" << std::endl;

			player->removeMoney(0);
		}
		else if (youWin == oppWin)
		{
			std::cout << "Tie. You shouldnt see this." << std::endl;
		}

	}
	if (play == 'N')
	{
		player->removeMoney(price);
	}

	setRPSCheck(1);
}
