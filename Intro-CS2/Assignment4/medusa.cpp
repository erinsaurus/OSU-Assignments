/**************************************************************************************************
** Author: Erin Alltop
** Date: 5/19/16
** Description: This program is a fantasy combat game. It allows the user to pick two teams of
** fighters to compete in a tournament. The two teams fight each other until one team has lost.
** The program gives several options for output as well.
** Input: User choices for number of fighters, types of fighters, and names of fighters.
** Output: Step-by-step battle stats until one team loses
**************************************************************************************************/

#include "medusa.hpp"
#include <ctime>
#include <iostream>

/**********************************************************************************
** Function: attack
** Description: This function attacks the opponent. It rolls the specified number
** of "die" for how many sides the die have, adds them together, at sets the
** attack amount in the setAttack function to be called by the opponent for
** their defense funtion.
** Additionally, if the roll is 12, the opponent dies. To ensure this, the attack
** amount is set to 100.
** Input/Output: None
**********************************************************************************/

void Medusa::attack()
{
	// rill 2d6 and add them together for total attack amount
	int roll1 = rand() % 6 + 1;
	int roll2 = rand() % 6 + 1;
	int attack = roll1 + roll2;

	std::cout << "\n" << creatureName << " attacks for: " << attack << " points.";

	// if attack roll equals 12, set attack to 100 to instantly kill opponent
	if (attack == 12)
	{
		std::cout << "\nMedusa uses Glare! Her opponent is turned to stone!\n";
		setAttack(100);
	}
	else //otherwise, set attack amount normally
	{
		setDamageDone(attack);
		setAttack(attack);
	}
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

void Medusa::defend(int attack)
{
	// roll for 1d6 and set defense amount to roll
	int roll1 = rand() % 6 + 1;
	int defend = roll1;

	// calculate amount of total damage
	int damage = (attack - defend) - armor;

	// if damage is greater than 0, recalculate strength points minus damage
	if (damage > 0)
	{
		setStrPoints(getStrPoints() - damage);
	}

	// cout statements to display
	std::cout << "\n" << creatureName << " defends for: " << defend << " points.";
	std::cout << "\n" << creatureName << "'s total damage is: " << damage << " points.";
	std::cout << "\n" << creatureName << "'s Strength Points: " << getStrPoints() << " points." << std::endl;

	//if strength points are <= 0, announce medusa's death
	if (getStrPoints() <= 0)
		std::cout << Type << " " << creatureName << " of " << Team << " has died.";
}

/***************************************************************************
** Function: setStrPoints
** Description: This function is used to set the strength points for the
** object in its various functions.
** Parameters: int strength points
***************************************************************************/

void Medusa::setStrPoints(int SP)
{
	StrPoints = SP;
}

/*************************************************************************
** Function: getStrPoints
** Description: Accessor for strength points. this function simply
** returns the strength points.
**************************************************************************/

int Medusa::getStrPoints()
{
	return StrPoints;
}

/***************************************************************************
** Function: setAttack
** Description: This function is used to set the attack amount for the
** object in its various functions.
** Parameters: int attack amount
***************************************************************************/

void Medusa::setAttack(int att)
{
	attackOpp = att;
}


/*************************************************************************
** Function: getAttack
** Description: Accessor for attack points. this function simply
** returns the attack amount.
**************************************************************************/

int Medusa::getAttack()
{
	return attackOpp;

}

/***************************************************************************
** Function: setArmor
** Description: This function is used to set the armor amount for the
** object in its various functions.
** Parameters: int armor amount
***************************************************************************/

void Medusa::setArmor(int arm)
{
	armor = arm;
}

/*************************************************************************
** Function: getArmor
** Description: Accessor for armor amount. this function simply
** returns the armor amount.
**************************************************************************/

int Medusa::getArmor()
{
	return armor;
}

/*************************************************************************
** Function: setName
** Description: This function is used to set the name of the fighter.
** This is used for display purposes.
**************************************************************************/

void Medusa::setName(std::string name)
{
	creatureName = name;
}

/*************************************************************************
** Function: getName
** Description: This function is and accessor to obtain the name of the
** fighter. This is used for display purposes.
**************************************************************************/

std::string Medusa::getName()
{
	return creatureName;
}

/*************************************************************************
** Function: getType
** Description: This function is and accessor to obtain the type of the
** fighter. This is used for display purposes.
**************************************************************************/

std::string Medusa::getType()
{
	return Type;
}

/*************************************************************************
** Function: regen
** Description: This function is used to reset the health of the fighter.
** When a fighter wins a match, he is regenerated back to full health
** in order to start fresh for the next round. 
**************************************************************************/

void Medusa::regen()
{
	setStrPoints(8);
}

/*************************************************************************
** Function: getTeam
** Description: This function is and accessor to obtain the team of the
** fighter. This is used for display purposes.
**************************************************************************/

std::string Medusa::getTeam()
{
	return Team;
}

/*************************************************************************
** Function: setTeam
** Description: This function is used to set the team of the fighter.
** This is used for display purposes.
**************************************************************************/

void Medusa::setTeam(std::string team)
{
	Team = team;
}
