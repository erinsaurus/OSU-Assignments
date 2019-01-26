/**************************************************************************************************
** Author: Erin Alltop
** Date: 5/19/16
** Description: This program is a fantasy combat game. It allows the user to pick two teams of
** fighters to compete in a tournament. The two teams fight each other until one team has lost.
** The program gives several options for output as well.
** Input: User choices for number of fighters, types of fighters, and names of fighters.
** Output: Step-by-step battle stats until one team loses
**************************************************************************************************/

#include "bluemen.hpp"
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

void BlueMen::attack()
{
	// roll 2d10 and caculate total for attack amount
	int roll1 = rand() % 10 + 1;
	int roll2 = rand() % 10 + 1;
	int attack = roll1 + roll2;

	std::cout << "\n" << creatureName << " attacks for: " << attack << " points.";
	setDamageDone(attack);
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

	std::cout << "\n" << creatureName << " Blue Men defend for: " << defend << " points.";
	std::cout << "\n" << creatureName << "'s total damage is: " << damage << " points.";

	//if damage greater than 0, subtract it from Strength Points
	if (damage > 0)
	{
		setStrPoints(getStrPoints() - damage);
	}

	std::cout << "\n" << creatureName << " Strength Points: " << getStrPoints() << " points." << std::endl;

	//if strength points <= 0 , announce death
	if (getStrPoints() <= 0)
	{
		std::cout << Type << " " << creatureName << " of " << Team << " have died.";
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
** Function: getType
** Description: This function is and accessor to obtain the type of the
** fighter. This is used for display purposes.
**************************************************************************/

std::string BlueMen::getType()
{
	return Type;
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

/*************************************************************************
** Function: setName
** Description: This function is used to set the name of the fighter.
** This is used for display purposes.
**************************************************************************/

void BlueMen::setName(std::string name)
{
	creatureName = name;
}

/*************************************************************************
** Function: getName
** Description: This function is and accessor to obtain the name of the
** fighter. This is used for display purposes.
**************************************************************************/

std::string BlueMen::getName()
{
	return creatureName;
}

/*************************************************************************
** Function: regen
** Description: This function is used to reset the health of the fighter.
** When a fighter wins a match, he is regenerated back to full health
** in order to start fresh for the next round.
**************************************************************************/

void BlueMen::regen()
{
	setStrPoints(12);
}

/*************************************************************************
** Function: getTeam
** Description: This function is and accessor to obtain the team of the
** fighter. This is used for display purposes.
**************************************************************************/

std::string BlueMen::getTeam()
{
	return Team;
}

/*************************************************************************
** Function: setTeam
** Description: This function is used to set the team of the fighter.
** This is used for display purposes.
**************************************************************************/

void BlueMen::setTeam(std::string team)
{
	Team = team;
}
