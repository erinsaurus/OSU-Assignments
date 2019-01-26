/**************************************************************************************************
** Author: Erin Alltop
** Date: 5/19/16
** Description: This program is a fantasy combat game. It allows the user to pick two teams of 
** fighters to compete in a tournament. The two teams fight each other until one team has lost.
** The program gives several options for output as well.
** Input: User choices for number of fighters, types of fighters, and names of fighters.
** Output: Step-by-step battle stats until one team loses
**************************************************************************************************/

#include "babayaga.hpp"
#include <ctime>
#include <iostream>

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

//	std::cout << "\nBaba Yaga attacks for: " << attack << " points.";
	std::cout << creatureName << " uses Soul! She has gained " << Soul << " Strength Points!\n";
	setAttack(attack); //set attack amount
	setDamageDone(attack);
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
	std::cout << "\n" << creatureName << " defends for: " << defend << " points.";
	std::cout << "\n" << creatureName << "'s total damage is: " << damage << " points.";

	//if damage is greater than 0, recalculate strength points minus damage
	if (damage > 0)
	{
		setStrPoints(getStrPoints() - damage);
	}

	std::cout << "\n" << creatureName << "'s Strength Points: " << getStrPoints() << " points." << std::endl;

	// announce death if strength points are 0 or less
	if (getStrPoints() <= 0)
	{
		std::cout << Type << " " << creatureName << " of " << Team << " has died.";
	}
	else if (getStrPoints() >= 100)
	{	// this is to stop the sometime infinite program that BabaYaga vs BabaYaga does
		std::cout << Type << " " << creatureName << " has grown too powerful and dies!";
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

/*************************************************************************
** Function: setName
** Description: This function is used to set the name of the fighter.
** This is used for display purposes.
**************************************************************************/

void BabaYaga::setName(std::string name)
{
	creatureName = name;
}

/*************************************************************************
** Function: getName
** Description: This function is and accessor to obtain the name of the
** fighter. This is used for display purposes.
**************************************************************************/

std::string BabaYaga::getName()
{
	return creatureName;
}

/*************************************************************************
** Function: getType
** Description: This function is and accessor to obtain the type of the
** fighter. This is used for display purposes.
**************************************************************************/

std::string BabaYaga::getType()
{
	return Type;
}

/*************************************************************************
** Function: regen
** Description: This function is used to reset the health of the fighter.
** When a fighter wins a match, he is regenerated back to full health
** in order to start fresh for the next round.
**************************************************************************/

void BabaYaga::regen()
{
	setStrPoints(12);
}

/*************************************************************************
** Function: getTeam
** Description: This function is and accessor to obtain the team of the
** fighter. This is used for display purposes.
**************************************************************************/

std::string BabaYaga::getTeam()
{
	return Team;
}

/*************************************************************************
** Function: setTeam
** Description: This function is used to set the team of the fighter.
** This is used for display purposes.
**************************************************************************/

void BabaYaga::setTeam(std::string team)
{
	Team = team;
}
