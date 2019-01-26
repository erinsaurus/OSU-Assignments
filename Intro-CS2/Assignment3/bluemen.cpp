
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

#include "bluemen.hpp"
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

void BlueMen::attack()
{
	// roll 2d10 and caculate total for attack amount
	int roll1 = rand() % 10 + 1;
	int roll2 = rand() % 10 + 1;
	int attack = roll1 + roll2;

	std::cout << "\nBlue Men attack for: " << attack << " points.";
	setAttack(attack); // set attack amount
}

/**********************************************************************************
** Function: defend
** Description: This function rolls the specified number of "die" for their
** number of sides. Then it adds them together to determine the amount of defense.
** Next, it calculates the amount of damage that will be taken, which is
** the attack amount minus the defense roll, minus the armor amount.
** The damage is then taken away from the Strength Points
** Additionally, this function tests to see if the Strength Points meet certain 
** conditions. If SP are 9-12, the blue men roll 3 die. If SP are 5-8, the blue
** men roll 2 die, and if SP are 4 or less, the blue men roll 1 die.
** Parameter: attack amount from opponent
**********************************************************************************/

void BlueMen::defend(int attack)
{
	// roll 3d6 random rolls
	int roll1 = rand() % 6 + 1;
	int roll2 = rand() % 6 + 1;
	int roll3 = rand() % 6 + 1;
	
	int defend; // defend declaration
	
	if (getStrPoints() >= 9)
	{ // if SP greater than or equal to 9, add all 3 dice rolls
		defend = roll1 + roll2 + roll3;
	}
	else if (getStrPoints() < 9 && getStrPoints() >= 5)
	{ // if SP between 5-8, add only 2 dice rolls
		std::cout << "\nThe Blue Men have only 2 die left!";
		defend = roll1 + roll2;
	}
	else if (getStrPoints() <= 4)
	{  // if less than 5, add only 1 dice roll
		std::cout << "\nThe Blue Men have only 1 dice left!";
		defend = roll1;
	}

	//calcualte total damage 
	int damage = (attack - defend) - armor;

	std::cout << "\nBlue Men defend for: " << defend << " points.";
	std::cout << "\nBlue Men total damage is: " << damage << " points.";

	//if damage greater than 0, subtract it from Strength Points
	if (damage > 0)
	{
		setStrPoints(getStrPoints() - damage);
	}

	std::cout << "\nBlue Men Strength Points: " << getStrPoints() << " points." << std::endl;

	//if strength points <= 0 , announce death
	if (getStrPoints() <= 0)
	{
		std::cout << "\nThe Blue Men have died!";
	}
}

/***************************************************************************
** Function: setStrPoints
** Description: This function is used to set the strength points for the
** object in its various functions.
** Parameters: int strength points
***************************************************************************/

void BlueMen::setStrPoints(int SP)
{
	StrPoints = SP;
}

/*************************************************************************
** Function: getStrPoints
** Description: Accessor for strength points. this function simply
** returns the strength points.
**************************************************************************/

int BlueMen::getStrPoints()
{
	return StrPoints;
}

/***************************************************************************
** Function: setAttack
** Description: This function is used to set the attack amount for the
** object in its various functions.
** Parameters: int attack amount
***************************************************************************/

void BlueMen::setAttack(int att)
{
	attackOpp = att;
}


/*************************************************************************
** Function: getAttack
** Description: Accessor for attack points. this function simply
** returns the attack amount.
**************************************************************************/

int BlueMen::getAttack()
{
	return attackOpp;

}

/***************************************************************************
** Function: setArmor
** Description: This function is used to set the armor amount for the
** object in its various functions.
** Parameters: int armor amount
***************************************************************************/

void BlueMen::setArmor(int arm)
{
	armor = arm;
}

/*************************************************************************
** Function: getArmor
** Description: Accessor for armor amount. this function simply
** returns the armor amount.
**************************************************************************/

int BlueMen::getArmor()
{
	return armor;
}
