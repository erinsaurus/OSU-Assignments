
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

#include "barbarian.hpp"
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

void Barbarian::attack()
{
	// 2d6 random rolls
	int roll1 = rand() % 6 + 1;
	int roll2 = rand() % 6 + 1;
	int attack = roll1 + roll2; //calculate total attack

	std::cout << "\nBarbarian attacks for: " << attack << " points.";
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

void Barbarian::defend(int attack)
{
	// 2d6 ranom rolls
	int roll1 = rand() % 6 + 1;
	int roll2 = rand() % 6 + 1;
	int defend = roll1 + roll2; // calculate total defense rolls

	int damage = (attack - defend) - armor; //calculate total damage
	std::cout << "\nBarbarian defends for: " << defend << " points.";
	std::cout << "\nBarbarian's total damage is: " << damage << " points.";

	// if damage is greater that 0, recalculate strength points
	if (damage > 0)
	{
		setStrPoints(getStrPoints() - damage); 
	}

	std::cout << "\nBarbarian Strength Points: " << getStrPoints() << " points." << std::endl;
	if (getStrPoints() <= 0) // announce death if strength points go to 0 or below
		std::cout << "\nBarbarian dies! :(";
}


/***************************************************************************
** Function: setStrPoints
** Description: This function is used to set the strength points for the 
** object in its various functions.
** Parameters: int strength points
***************************************************************************/

void Barbarian::setStrPoints(int SP)
{
	StrPoints = SP;
}

/*************************************************************************
** Function: getStrPoints
** Description: Accessor for strength points. this function simply
** returns the strength points.
**************************************************************************/

int Barbarian::getStrPoints()
{
	return StrPoints;
}


/***************************************************************************
** Function: setAttack
** Description: This function is used to set the attack amount for the
** object in its various functions.
** Parameters: int attack amount
***************************************************************************/

void Barbarian::setAttack(int att)
{
	attackOpp = att;
}

/*************************************************************************
** Function: getAttack
** Description: Accessor for attack points. this function simply
** returns the attack amount.
**************************************************************************/

int Barbarian::getAttack()
{
	return attackOpp;

}

/***************************************************************************
** Function: setArmor
** Description: This function is used to set the armor amount for the
** object in its various functions.
** Parameters: int armor amount
***************************************************************************/

void Barbarian::setArmor(int arm)
{
	armor = arm;
}

/*************************************************************************
** Function: getArmor
** Description: Accessor for armor amount. this function simply
** returns the armor amount.
**************************************************************************/

int Barbarian::getArmor()
{
	return armor;
}
