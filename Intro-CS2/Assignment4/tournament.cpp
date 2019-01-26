/**************************************************************************************************
** Author: Erin Alltop
** Date: 5/19/16
** Description: This program is a fantasy combat game. It allows the user to pick two teams of
** fighters to compete in a tournament. The two teams fight each other until one team has lost.
** The program gives several options for output as well.
** Input: User choices for number of fighters, types of fighters, and names of fighters.
** Output: Step-by-step battle stats until one team loses
**************************************************************************************************/

#include "tournament.hpp"
#include <iomanip>

Tournament::Tournament()
{
	//initialize values of front and rear to NULL
	front1 = NULL;
	rear1 = NULL;
	front2 = NULL;
	rear2 = NULL;
	top = NULL;
}

/************************************************************************************
** Function: addQueue1
** Description: This function adds a new node to the doubly linked struct in the queue.
** This queue represents Team 1's lineup of players.
** Parameters: pointer to a Creature object
** Input/Output: None
*************************************************************************************/

void Tournament::addQueue1(Creature* object)
{
	if (isQueue1Empty()) //if the queue is empty
	{
		front1 = new tourQueue1(object); //assign the front queue location to a new node
		rear1 = front1; //then, assign rear to front
	}
	else
	{ //if the queue is not empty
		rear1->next1 = new tourQueue1(object); //assign the next pointer of rear to a new node
		rear1 = rear1->next1; //then, assign rear to rear's next pointer
	}
}

/**************************************************************************************
Function: removeQueue1
Description: This function checks to see if the queue is empty. If not, then it assigns
** the front value of the queue to a pointer to Creature, and reassigns the front value
** to the next value. There is not an output section of this function purposefully
** as it is not needed. Only a stack displays information in this program.
**************************************************************************************/

void Tournament::removeQueue1()
{
	tourQueue1 *temp; //create a temp pointer node

	if (isQueue1Empty()) //if the queue is empty, indicate there is a problem
	{
		std::cout << "Empty queue!";
		exit(1);
	}
	else
	{ //if queue is not empty..
		temp = front1; //assign temp to equal the front value
		front1 = front1->next1; //reassign front to equal the next location
		delete temp; //delete the temp pointer
	}
}

/****************************************************************************
** Function: isQueue1Empty
** Description: This function is a helper function used to determine if the
** current queue/struct is empty or not. This is used by other functions
** to carry out their functions and prevent an underflow of the queue.
** Input: none
** Output: returns true if queue is empty. returns false if not.
*****************************************************************************/

bool Tournament::isQueue1Empty() const
{
	if (front1 == NULL) //if the front value is null, the queue is empty
		return true;
	else
		return false;
}

/***************************************************************************************
** Function: displayQueue1
** Description: This function prints out the data of the queue to the screen. While
** the queue is not empty, the function continues to call the remove function to find
** the data of the front of the queue and displays it to the screen.
** Parameters: None
** Input: None
** Output: Displays the contents of the queue to the screen in order
** Note: This function is not used in this program as when anything is printed to the
** screen it is only done through the stack. This is being left in to demonstrate
** knowledge of this process.
****************************************************************************************/

void Tournament::displayQueue1()
{
	while (!isQueue1Empty()) //while the queue is not empty
	{
		removeQueue1(); //call the remove function to move through the queue
	}						   //queue and displays the values

	std::cout << std::endl;
}

/************************************************************************************
** Function: add
** Description: This function adds a new node to the singly linked struct on the stack.
** Parameters: pointer to Creature object
** Input/Output: None
*************************************************************************************/

void Tournament::addStack(Creature* object)
{

	top = new tourStack(object, top);
}

/**************************************************************************************
Function: removeStack
Description: This function checks to see if the stack is empty. If not, then it assigns
** the top value of the queue to a char data member, reassigns the top value
to the next value, and the returns the data from the function (the value of the original
** top value.
** Parameter: Value to determine whether the display part of this function executes or not.
** As this function is used multiple times and only needs to display once, this was
** a necessary addition.
**************************************************************************************/

void Tournament::removeStack(int display)
{
	tourStack *temp; //create a temp pointer to a Stacknode

	if (isStackEmpty()) //if the stack is empty, indicate there is a problem
	{
		std::cout << "Empty stack! You should not see this.";
		exit(1);
	}
	else //if the stack is not empty..
	{
		Creature* type = top->object; //assign a new data member to the value of the top location
		temp = top; //assign the temp pointer to top
		top = top->next; //re-assign top to the next pointer in the struct
		delete temp; //delete the temp pointer

		if (display == 2)
		{
			std::cout << type->getType() << " " << type->getName() << " of " << type->getTeam() << std::endl;
		}
		else
		{

		}
	}
}

/****************************************************************************
** Function: isStackEmpty
** Description: This function is a helper function used to determine if the
** current stack/struct is empty or not. This is used by other functions
** to carry out their functions and prevent an underflow of the stack.
** Input: none
** Output: returns true if stack is empty. returns false if not.
*****************************************************************************/

bool Tournament::isStackEmpty() const
{
	if (!top) //if there is not a top value, stack is empty
		return true;
	else
		return false;
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

void Tournament::displayStack()
{
	while (!isStackEmpty()) //while the stack is not empty
	{
		removeStack(2); //continually call the remove function to find the
							   //top value of the stack and display it to the screen
	}
	std::cout << std::endl;
}
/************************************************************************************
** Function: addQueue2
** Description: This function adds a new node to the doubly linked struct in the queue.
** This queue represents Team 2's lineup of players.
** Parameters: pointer to a Creature object
** Input/Output: None
*************************************************************************************/

void Tournament::addQueue2(Creature* object)
{
	if (isQueue2Empty()) //if the queue is empty
	{
		front2 = new tourQueue2(object); //assign the front queue location to a new node
		rear2 = front2; //then, assign rear to front
	}
	else
	{ //if the queue is not empty
		rear2->next2 = new tourQueue2(object); //assign the next pointer of rear to a new node
		rear2 = rear2->next2; //then, assign rear to rear's next pointer
	}
}

/**************************************************************************************
Function: removeQueue2
Description: This function checks to see if the queue is empty. If not, then it assigns
** the front value of the queue to a pointer to Creature, and reassigns the front value
** to the next value. There is not an output section of this function purposefully
** as it is not needed. Only a stack displays information in this program.
**************************************************************************************/

void Tournament::removeQueue2()
{
	tourQueue2 *temp; //create a temp pointer node

	if (isQueue2Empty()) //if the queue is empty, indicate there is a problem
	{
		std::cout << "Empty queue!";
		exit(1);
	}
	else
	{ //if queue is not empty..
		temp = front2; //assign temp to equal the front value
		front2 = front2->next2; //reassign front to equal the next location
		delete temp; //delete the temp pointer
	}
}

/****************************************************************************
** Function: isQueue1Empty
** Description: This function is a helper function used to determine if the
** current queue/struct is empty or not. This is used by other functions
** to carry out their functions and prevent an underflow of the queue.
** Input: none
** Output: returns true if queue is empty. returns false if not.
*****************************************************************************/

bool Tournament::isQueue2Empty() const
{
	if (front2 == NULL) //if the front value is null, the queue is empty
		return true;
	else
		return false;
}

/***************************************************************************************
** Function: displayQueue2
** Description: This function prints out the data of the queue to the screen. While
** the queue is not empty, the function continues to call the remove function to find
** the data of the front of the queue and displays it to the screen.
** Parameters: None
** Input: None
** Output: Displays the contents of the queue to the screen in order
** Note: This function is not used in this program as when anything is printed to the
** screen it is only done through the stack. This is being left in to demonstrate
** knowledge of this process.
****************************************************************************************/

void Tournament::displayQueue2()
{
	while (!isQueue2Empty()) //while the queue is not empty
	{
		removeQueue2(); //call the remove function to move through the queue
	}						   //queue and displays the values

	std::cout << std::endl;
}

/***************************************************************************************
** Function: Battle
** Description: This function performs the tournament. It prompts the user whether they
** wish to see the updated scores after each round, and then carries out the battles.
** The creatures at the head of each queue fight to the death. When a winner is found,
** the loser is removed from the queue and added to the stack (loser pile).
** The winner then regenerates health and is moved to the back of its respective
** queue to fight again.
** Input: User input for the choice to display the updated scores for each round.
****************************************************************************************/

void Tournament::Battle()
{
	//user input and validation for choice to display updated scores in each round
	std::cout << "This simulation will display the winner and loser of each round. ";
	std::cout << "\nWould you also like to see the updated scores for each round? ";
	std::cout << "\nPlease enter a 'Y' or 'N': ";
	char scores;
	std::cin >> scores;

	while (scores != 'Y' && scores != 'N')
	{
		std::cout << "Please enter a 'Y' or 'N' for your choice: ";
		std::cin >> scores;
	}
	
	//variables for team scores and a counter for the rounds
	int team1score = 0;
	int team2score = 0;
	int round = 1;

	/** This is a do-while loop that
	** will continue looping attack/defend
	** for each opponent until one
	** of them has perished
	**/

	do
	{
		Creature *opp1 = front1->object1; //create pointer to object at front of queue 1
		Creature *opp2 = front2->object2; //create pointer to object at front of queue 2

		std::cout << "\nRound " << round << "!" << std::endl; //announce what round it is

		do {
			opp1->attack();   // opponent 1 attack
			opp2->defend(opp1->getAttack());  // opponent 2 defense
			if (opp2->getStrPoints() <= 0) // if opponent 2 has died, exit loop to prevent both players dying at once
			{
				break;
			}
			opp2->attack(); //oponent 2 attack
			opp1->defend(opp2->getAttack()); //opponent 1 defense

		} while (opp1->getStrPoints() > 0 && opp2->getStrPoints() > 0); //while both fighters still alive, continue looping


		//announce winner of the round
		if (opp1->getStrPoints() <= 0) //if opp1 loses, opp2 wins
		{
			std::cout << std::endl;
			std::cout << opp2->getType() << " " << opp2->getName() << " of " << opp2->getTeam() << " wins!\n";

			team2score += 5; //add 5 points to the team of the winner

			if (scores == 'Y') //if user chose yes, list scores for the round
			{
				std::cout << "\n Current Scores: " << std::endl;
				std::cout << std::left << std::setw(0) << " " << "Team 1"
					<< std::left << std::setw(3) << " " << "Team 2" << std::endl;
				std::cout << std::left << std::setw(2) << " " << team1score
					<< std::left << std::setw(8) << " " << team2score << "\n";
			}

			opp2->regen(); //regenerate opp2 winnter
			removeQueue1(); //remove opp1 loser from its queue
			addStack(opp1); //add loser to the loser stack
			removeQueue2(); //remove opp2 winner from its queue
			addQueue2(opp2); //add opp2 winner back to its queue (in the back) 
		}

		else if (opp2->getStrPoints() <= 0) //if opp2 loses, opp1 wins the round
		{
			std::cout << std::endl;
			std::cout << opp1->getType() << " " << opp1->getName() << " of " << opp1->getTeam() << " wins!\n";

			team1score += 5; //add 5 points to team 1 

			if (scores == 'Y') //if the user wishes to see the current scores, display them
			{
				std::cout << "\n Current Scores: " << std::endl;
				std::cout << std::left << std::setw(0) << " " << "Team 1"
					<< std::left << std::setw(3) << " " << "Team 2" << std::endl;
				std::cout << std::left << std::setw(2) << " " << team1score
					<< std::left << std::setw(8) << " " << team2score << "\n";
			}
			opp1->regen(); //regenerate opp1 winner
			removeQueue2(); //remove opp2 loser from its queue
			addStack(opp2); //add opp2 loser to the loser stack
			removeQueue1(); //remove opp1 winner from queue 1
			addQueue1(opp1); //add opp1 back to its queue (in the back)
		}

		round++; //increment counter variable

	} while (!isQueue1Empty() && !isQueue2Empty()); //while both queues remain full or partially full, loop through the rounds

	determineWinners(); //call function to determine the winner
}

/***************************************************************************************
** Function: determineWinners
** Description: This function determines the winner of the tournament. Additionally,
** If there is a tie with multiple fighters in a single queue, then this function
** performs a tie breaker by comparing the damage done by each fighter.
** Parameters: None
** Input: None
** Output: Determines and displays the winners
****************************************************************************************/

void Tournament::determineWinners()
	{
		//if queue 1 is not empty, then team 1 is the winner
		if (!isQueue1Empty())
		{
			std::cout << "\nTeam 1 wins the tournament!\n " << std::endl;

			/*TIE BREAKER ROUND*/
			while (!isQueue1Empty()) //loop while queue 1 remains empty 
			{
				Creature* opp1 = front1->object1; //create a pointer to object at front of queue
				removeQueue1(); //remove object from queue 1
				addQueue2(opp1); //add object to empty queue 2

				if (!isQueue1Empty()) //check to see if queue 1 is empty for comparisons
				{
					Creature* opp1 = front1->object1; //pointer to object at head of queue 1
					Creature* opp2 = front2->object2; //pointer to object at head of queue 2

					if (opp1->getDamageDone() > opp2->getDamageDone()) //if opp1 damage is greater than opp 2 damage
					{
						removeQueue2(); //remove opp2 from queue 2
						addStack(opp2); //add opp2 to the stack (loser pile)
					}
					else if (opp2->getDamageDone() > opp1->getDamageDone()) //if opp2 damage is greater than opp1 damage
					{
						removeQueue1(); //remove opp1 from queue 1
						addStack(opp1); //add opp1 to the stack (loser pile)
					}
				}
				else if (isQueue1Empty()) //if queue 1 is now empty no comparison can be made
				{
					while (!isQueue2Empty())
					{
						opp1 = front2->object2; //reassign pointer to current location of opp1
						removeQueue2(); //remove opp1 from queue 2
						addStack(opp1); //add opp1 to the stack as it is the last remaining fighter
					}
				}
			}
		}
		//if queue 2 is not empty, then team 2 is the winner
		else if (!isQueue2Empty())
		{
			std::cout << "\nTeam 2 wins the tournament!\n " << std::endl;

			/*TIE BREAKER ROUND*/
			while (!isQueue2Empty())
			{
				Creature* opp2 = front2->object2; //create a pointer to object at front of queue
				removeQueue2(); //remove object from queue 2
				addQueue1(opp2); //add object to queue 1 for comparision

				if (!isQueue2Empty()) //if queue is still not empty, then a comparison can be made
				{
					Creature* opp1 = front1->object1; //create pointer to object at front of queue 1
					Creature* opp2 = front2->object2; //create pointer to object at front of queue 2

					if (opp1->getDamageDone() > opp2->getDamageDone()) //if opp1 damage is greater than opp2 damage
					{
						removeQueue2(); //remove object from queue 2
						addStack(opp2); //add opp2 to stack (loser pile)
					}
					else if (opp2->getDamageDone() > opp1->getDamageDone()) //if opp2 damage is greater than opp1 damage
					{
						removeQueue1(); //remove opp1 from queue 1
						addStack(opp1); //add opp1 to the stack (loser pile)
					}
				}
				else if (isQueue2Empty()) //if queue 2 is now empty no comparison can be made
				{
					while (!isQueue1Empty())
					{
						opp2 = front1->object1; //reassign pointer opp2 to front of queue 1
						removeQueue1(); //remove opp2 from queue 1
						addStack(opp2); //reassign opp2 to the stack as it is the last remaining fighter
					}
				}
			}
		}

		//loop three times to remove/display the tope three fighters in the stack
		std::cout << "The top three fighters are: " << std::endl;
		for (int i = 0; i < 3; i++)
		{
			std::cout << "Placed " << (i + 1) << ": ";
			removeStack(2);
		}
	}


