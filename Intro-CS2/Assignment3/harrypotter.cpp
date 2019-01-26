/**************************************************************************************************
** Author: Erin Alltop
** Date: 5/6/16
** Description: This program is a fantasy combat game. It allows the user to pick two opponents
** to battle to the death. There are 5 different types of opponents that can battle each other or
** themselves. They each have different stats and abilities. Once one of them runs of out Strength
** Points then the game ends and the program terminates.
** Input: User choices for two opponents to battle
** Output: Step-by-step battle stats until one opponent loses
**************************************************************************************************/

#include "harrypotter.hpp"
#include <ctime>
#include <iostream>
#include <cstdlib>

/**********************************************************************************
** Function: attack
** Description: This function attacks the opponent. It rolls the specified number
** of "die" for how many sides the die have, adds them together, at sets the
** attack amount in the setAttack function to be called by the opponent for
** their defense funtion.
** Input/Output: None
**********************************************************************************/

void HarryPotter::attack()
{
	// roll 2d6 and calculate total attack amount
	int roll1 = rand() % 6 + 1;
	int roll2 = rand() % 6 + 1;
	int attack = roll1 + roll2;

	std::cout << "\nHarry Potter attacks for: " << attack << " points.";
	setAttack(attack); //set attack amount
}

/**********************************************************************************
** Function: defend
** Description: This function rolls the specified number of "die" for their
** number of sides. Then it adds them together to determine the amount of defense.
** Next, it calculates the amount of damage that will be taken, which is
** the attack amount minus the defense roll, minus the armor amount.
** The damage is then taken away from the Strength Points
** Parameter: attack amount from opponent
**********************************************************************************/

void HarryPotter::defend(int attack)
{
	// roll 2d6 and calculate total attack amount
	int roll1 = rand() % 6 + 1;
	int roll2 = rand() % 6 + 1;
	int defend = roll1 + roll2;

	// calculate total damage
	int damage = (attack - defend) - armor;

	//display HP's defense and damage
	std::cout << "\nHarry Potter defends for: " << defend << " points.";
	std::cout << "\nHarry Potter's total damage is: " << damage << " points.";

	// if damage is greater than 0, subtract damage from strength points
	if (damage > 0)
	{	
		setStrPoints(getStrPoints() - damage); 

		if (getStrPoints() <= 0) // if strength points are 0 or less
		{
			if (getDeath() == 0)  // check to see if Harry has died already. If not (0)..
			{	// announce Harry's death and resurrection

				// display HP's strength points
				std::cout << "\nHarry Potter's Strength Points: " << getStrPoints() << " points." << std::endl;
				std::cout << "\nHarry Potter has died and come back from the grave! His Strength Points are now 20!";
				setStrPoints(20); // set strength points to 20
				setDeath(1); // death to 1 (has died already)
			}
			else //Harry dies permanently
			{
			// display HP's strength points
			std::cout << "\nHarry Potter's Strength Points: " << getStrPoints() << " points." << std::endl;
			std::cout << "\n Harry Potter has died for good. :(";
			}
		}
	}
}


/***************************************************************************
** Function: setStrPoints
** Description: This function is used to set the strength points for the
** object in its various functions.
** Parameters: int strength points
***************************************************************************/

void HarryPotter::setStrPoints(int SP)
{
	StrPoints = SP;
}

/*************************************************************************
** Function: getStrPoints
** Description: Accessor for strength points. this function simply
** returns the strength points.
**************************************************************************/

int HarryPotter::getStrPoints()
{
	return StrPoints;
}

/***************************************************************************
** Function: setAttack
** Description: This function is used to set the attack amount for the
** object in its various functions.
** Parameters: int attack amount
***************************************************************************/

void HarryPotter::setAttack(int att)
{
	attackOpp = att;
}

/*************************************************************************
** Function: getAttack
** Description: Accessor for attack points. this function simply
** returns the attack amount.
**************************************************************************/

int HarryPotter::getAttack()
{
	return attackOpp;

}

/***************************************************************************
** Function: setArmor
** Description: This function is used to set the armor amount for the
** object in its various functions.
** Parameters: int armor amount
***************************************************************************/

void HarryPotter::setArmor(int arm)
{
	armor = arm;
}

/*************************************************************************
** Function: getArmor
** Description: Accessor for armor amount. this function simply
** returns the armor amount.
**************************************************************************/

int HarryPotter::getArmor()
{
	return armor;
}

/***************************************************************************
** Function: setDeath
** Description: This function is used to set whether or not HP has died
** 0 indicates no, and 1 indicates yes.
** Parameters: int death
***************************************************************************/

void HarryPotter::setDeath(int die)
{
	Death = die;
}

/*************************************************************************
** Function: getDeath
** Description: Accessor for Death. this function simply
** returns whether HP has died or not.
**************************************************************************/

int HarryPotter::getDeath()
{
	return Death;
}
