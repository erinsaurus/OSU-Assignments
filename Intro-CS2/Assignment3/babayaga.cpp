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

#include "babayaga.hpp"
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

void BabaYaga::attack()
{
	// roll 2d6 and calculate total attack amount
	int roll1 = rand() % 6 + 1;
	int roll2 = rand() % 6 + 1;
	int attack = roll1 + roll2;

	//calculate Soul amount. 1/3 of the attack rounded down
	int Soul = (attack / 3);

	std::cout << "\nBaba Yaga attacks for: " << attack << " points.";
	std::cout << "\nBaba Yaga uses Soul! She has gained " << Soul << " Strength Points!";
	setAttack(attack); //set attack amount
	setStrPoints(getStrPoints() + Soul); //recalculate strength points to add soul amount
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

void BabaYaga::defend(int attack)
{
	// roll 1d10 for defense
	int roll1 = rand() % 10 + 1;
	int defend = roll1;
	
	// calculate total damage 
	int damage = (attack - defend) - armor;
	std::cout << "\nBaba Yaga defends for: " << defend << " points.";
	std::cout << "\nBaba Yaga's total damage is: " << damage << " points.";

	//if damage is greater than 0, recalculate strength points minus damage
	if (damage > 0)
	{
		setStrPoints(getStrPoints() - damage);
	}

	std::cout << "\nBaba Yaga Strength Points: " << getStrPoints() << " points." << std::endl;
	
	// announce death if strength points are 0 or less
	if (getStrPoints() <= 0)
	{
		std::cout << "\nBaba Yaga dies! :(";
	}
	else if (getStrPoints() >= 100)
	{	// this is to stop the sometime infinite program that BabaYaga vs BabaYaga does
		std::cout << "Baba Yaga has grown too powerful!";
		setStrPoints(0);
	}
}

/***************************************************************************
** Function: setStrPoints
** Description: This function is used to set the strength points for the
** object in its various functions.
** Parameters: int strength points
***************************************************************************/

void BabaYaga::setStrPoints(int SP)
{
	StrPoints = SP;
}

/*************************************************************************
** Function: getStrPoints
** Description: Accessor for strength points. this function simply
** returns the strength points.
**************************************************************************/

int BabaYaga::getStrPoints()
{
	return StrPoints;
}

/***************************************************************************
** Function: setAttack
** Description: This function is used to set the attack amount for the
** object in its various functions.
** Parameters: int attack amount
***************************************************************************/

void BabaYaga::setAttack(int att)
{
	attackOpp = att;
}

/*************************************************************************
** Function: getAttack
** Description: Accessor for attack points. this function simply
** returns the attack amount.
**************************************************************************/

int BabaYaga::getAttack()
{
	return attackOpp;

}

/***************************************************************************
** Function: setArmor
** Description: This function is used to set the armor amount for the
** object in its various functions.
** Parameters: int armor amount
***************************************************************************/

void BabaYaga::setArmor(int arm)
{
	armor = arm;
}

/*************************************************************************
** Function: getArmor
** Description: Accessor for armor amount. this function simply
** returns the armor amount.
**************************************************************************/

int BabaYaga::getArmor()
{
	return armor;
}
