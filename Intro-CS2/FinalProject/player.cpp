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

#include "player.hpp"
#include <string>
#include <iostream>

/**************************************************************************************************
** Function: Non-Default constructor
** Description: This constructor takes the char of the user's choice for what recipe they wish
** to make. It then intializes all of the variables for the program.
***************************************************************************************************/

Player::Player(char choice)
{
	setWallet(50.00); //start with $50
	setRecipe(choice);
	top = NULL;
	Time = 90; //start with 90 minutes
	Location = "Street"; //start in the Street

	//initialize array to "Empty"
	for (int i = 0; i < 15; i++)
	{
		bagContents[i] = "Empty";
	}
}

/**************************************************************************************************
** Function: removeMoney
** Description: This function is used to deincrement the cost of items from the player's wallet.
** It takes as a parameter a double and subtracts it from the wallet contents.
***************************************************************************************************/

void Player::removeMoney(double cost)
{
	setWallet(getWallet() - cost);
}

/**************************************************************************************************
** Function: setWallet
** Description: This function simply sets the wallet variable to a double parameter.
***************************************************************************************************/

void Player::setWallet(double money)
{
	Wallet = money;
}

/**************************************************************************************************
** Function: getWallet
** Description: This function simply returns the Wallet variable
***************************************************************************************************/

double Player::getWallet()
{
	return Wallet;
}

/**************************************************************************************************
** Function: setWallet
** Description: This function simply sets the recipe variable to a char parameter.
***************************************************************************************************/

void Player::setRecipe(char choice)
{
	Recipe = choice;
}

/**************************************************************************************************
** Function: getRecipe
** Description: This function simply returns the Recipe variable
***************************************************************************************************/

char Player::getRecipe()
{
	return Recipe;
}

/**************************************************************************************************
** Function: shoppingList
** Description: This function displays the shopping list to the player depending on what recipe
** they picked. It calls the getRecipe() function and displays the correct recipe.
***************************************************************************************************/

void Player::shoppingList()
{
	Menu list;

	if (getRecipe() == 'A')
	{
		list.displayListA();
	}

	else if (getRecipe() == 'B')
	{
		list.displayListB();
	}

	else if (getRecipe() == 'C')
	{
		list.displayListC();
	}
}

/************************************************************************************
** Function: add
** Description: This function adds a new node to the singly linked struct on the stack.
** Parameters: char value
** Input/Output: None
*************************************************************************************/
void Player::add(Inventory* item)
{
	top = new ShoppingBag(item, top);
	incBagCount();
	std::cout << "Bag count: " << getBagCount() << std::endl;
}

/***************************************************************************************
** Function: displayStack
** Description: This function prints out the data of the stack to the screen. While
** the stack is not empty, the function continues to call the remove function to find
** the data of the top of the queue and displays it to the screen.
** Parameters: None
** Input: None
** Output: Displays the contents of the stack to the screen in "reverse" order
****************************************************************************************/
void Player::displayStack()
{
	while (!isEmpty()) //while the stack is not empty
	{
		std::cout << remove(); //continually call the remove function to find the
							   //top value of the stack and display it to the screen
	}
	std::cout << std::endl;
}

/**************************************************************************************
Function: remove
Description: This function checks to see if the stack is empty. If not, then it assigns
** the top value of the queue to a char data member, reassigns the top value
to the next value, and the returns the data from the function (the value of the original
** top value.
** Input: none
** Output: This function returns a character value from the stack
**************************************************************************************/
Inventory* Player::remove()
{
	ShoppingBag *temp; //create a temp pointer to a Stacknode

	if (isEmpty()) //if the stack is empty, indicate there is a problem
	{
		std::cout << "Empty stack! You should not see this.";
		return NULL;
	}
	else //if the stack is not empty..
	{
		Inventory* data = top->item; //assign a new data member to the value of the top location
		temp = top; //assign the temp pointer to top
		top = top->next; //re-assign top to the next pointer in the struct
		delete temp; //delete the temp pointer
		return data; //return the data that was the original top location value
	}
}

/****************************************************************************
** Function: isEmpty
** Description: This function is a helper function used to determine if the
** current stack/struct is empty or not. This is used by other functions
** to carry out their functions and prevent an underflow of the stack.
** Input: none
** Output: returns true if stack is empty. returns false if not.
*****************************************************************************/
bool Player::isEmpty() const
{
	if (!top) //if there is not a top value, stack is empty
		return true;
	else
		return false;
}

/**************************************************************************************************
** Function: setTime
** Description: This function simply sets the Time variable to an int parameter.
***************************************************************************************************/

void Player::setTime(int time)
{
	Time = time;
}

/**************************************************************************************************
** Function: getTime
** Description: This function simply returns the Time variable
***************************************************************************************************/

int Player::getTime()
{
	return Time;
}

/**************************************************************************************************
** Function: adjustTime
** Description: This function decreases the player time in 10 minute increments
***************************************************************************************************/

void Player::adjustTime()
{
	setTime(getTime() - 10);
}

bool Player::gameOver()
{
	if (getBagCount() <= 15 && getWallet() > 0)
	{
		if (getPuzzlePieces() >= 8)
		{
			char play;
			std::cout << "You have collected all of your items! Would you like to continue playing? Y/N: ";
			std::cin >> play;

			play = char(toupper(play));

			while (play != 'Y' && play != 'N')
			{
				std::cout << "\nPlease enter a Y or N: ";
				std::cin >> play;
				play = char(toupper(play));
			}

			if (play == 'Y')
			{
				return false;
			}
			else if (play == 'N')
			{
				return true;
			}

			return false;
		}
		else
			return false;
	}
	else if (getBagCount() >= 15 || getWallet() <= 0)
	{
		return true;
	}
	return false;
}

/**************************************************************************************************
** Function: getBagCount
** Description: This function simply returns the bagCount variable
***************************************************************************************************/

int Player::getBagCount()
{
	return bagCount;
}

void Player::incBagCount()
{
	bagCount += 1;
}

void Player::displayBagContents()
{
	std::cout << std::endl;
	for (int i = 0; i < 15; i++)
	{
		std::cout << bagContents[i] << std::endl;
	}
	std::cout << std::endl;
}

void Player::changeBagContents(std::string newItem)
{
	if (getRecipe() == 'A')
	{
		if (newItem == "Chicken" || newItem == "Lettuce" || newItem == "Tomato"
			|| newItem == "Carrot" || newItem == "Salad Dressing" || newItem == "Parmesan"
			|| newItem == "Breadsticks" || newItem == "Spice Pack")
		{
			puzzlePiece();
		}
	}

	else if (getRecipe() == 'B')
	{
		if (newItem == "Filet Mignon" || newItem == "Spice Pack" || newItem == "Carrot"
			|| newItem == "Potato" || newItem == "Zucchini" || newItem == "Garlic"
			|| newItem == "Goat" || newItem == "Dinner Rolls")
		{
			puzzlePiece();
		}
	}
	else if (getRecipe() == 'C')
	{
		if (newItem == "Ham" || newItem == "Pineapple" || newItem == "Tomato"
			|| newItem == "Garlic" || newItem == "Pizza Dough" || newItem == "Spice Pack"
			|| newItem == "Mozzarella" || newItem == "Spinach")
		{
			puzzlePiece();
		}
	}

	for (int i = 0; i < 15; i++)
	{
		if (bagContents[i] == "Empty")
		{
			bagContents[i] = newItem;
			return;
		}
	}

	
	return;
}

void Player::puzzlePiece()
{
	puzzlePieces += 1;
}

int Player::getPuzzlePieces()
{
	return puzzlePieces;
}

/**************************************************************************************************
** Function: incBonus
** Description: This function simply increments the Bonus variable by an inc paramter
***************************************************************************************************/

void Player::incBonus(int inc)
{
	Bonus += inc;
}

/**************************************************************************************************
** Function: getBonus
** Description: This function simply returns the Bonus variable
***************************************************************************************************/

int Player::getBonus()
{
	return Bonus;
}

/**************************************************************************************************
** Function: finalScore
** Description: This function calculate the final score minus the bonus.
***************************************************************************************************/

void Player::finalScore()
{
	//if the wallet is exactly 35, add 20 points
	if (getWallet() == 35)
	{
		setScore(20);
		std::cout << "\nYou earned 20 points for meeting your budget of $35 exactly.\n" << std::endl;
	}

	//if the wallet is less than 35, give 2 points for every dollar
	if (getWallet() > 35)
	{
		setScore(30);
		int adjust = getWallet() - 35;
		adjust = adjust * 2;
		setScore(adjust);
		std::cout << "\nYou earned 30 points for coming in under budget. For each dollar under budge you"
			<< "\nalso earned 2 bonus points. You earned " << adjust << " bonus points!\n" << std::endl;
	}

	//if the wallet exceeds the 35 dollar budget, -5 penalty and -2 points for each dollar off
	if (getWallet() < 35)
	{
		setScore(-5);
		int adj = 35 - getWallet();
		adj = adj * 2;
		setScore(-adj);
		std::cout << "\nYou exceeded your budget. You lost 5 points and 2 points for each dollar that"
			<< "\nexceeds your budget. You lost " << adj << " additional points.\n" << std::endl;
	}

	//if time is greater than 90, lose 5 points for each 10 minutes over
	if (getTime() > 90)
	{
		int timeAdj = getTime() / 10;
		setScore(timeAdj * -5);
		std::cout << "\nYou exceeded your time limit and have received a 5 point penalty for each"
			<< "\n10 minutes over time. You have lost " << timeAdj * 5 << " points.\n" << std::endl;
	}
}

/**************************************************************************************************
** Function: getFinalScore
** Description: This function adds the bonus to the score and returns the score.
***************************************************************************************************/

int Player::getFinalScore()
{
	Score += getBonus();
	return Score;
}

/**************************************************************************************************
** Function: setScore
** Description: This function simply sets the Score variable to an int parameter.
***************************************************************************************************/

void Player::setScore(int points)
{
	Score += points;
}

/**************************************************************************************************
** Function: endGame
** Description: This function calculates the final score and displays the result to the player
***************************************************************************************************/

void Player::endGame()
{
	if (getWallet() <= 0)
	{
		std::cout << "\nYou have run out of money!\n" << std::endl;
	}
	else if (getBagCount() >= 15)
	{
		std::cout << "\nYour bag is full!\n" << std::endl;
	}
	
	finalScore();
	std::cout << "\nGame over. Thanks for playing! Your final score is: " << getFinalScore() << " points.\n" << std::endl;

}
