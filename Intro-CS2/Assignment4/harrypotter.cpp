/**************************************************************************************************
** Author: Erin Alltop
** Date: 5/19/16
** Description: This program is a fantasy combat game. It allows the user to pick two teams of
** fighters to compete in a tournament. The two teams fight each other until one team has lost.
** The program gives several options for output as well.
** Input: User choices for number of fighters, types of fighters, and names of fighters.
** Output: Step-by-step battle stats until one team loses
**************************************************************************************************/

#include "harrypotter.hpp"
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

void HarryPotter::attack()
{
	// roll 2d6 and calculate total attack amount
	int roll1 = rand() % 6 + 1;
	int roll2 = rand() % 6 + 1;
	int attack = roll1 + roll2;

	std::cout << "\n" << creatureName << " attacks for: " << attack << " points.";
	setDamageDone(attack);
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
	std::cout << "\n" << creatureName << " defends for: " << defend << " points.";
	std::cout << "\n" << creatureName << "'s total damage is: " << damage << " points.";

	// if damage is greater than 0, subtract damage from strength points
	if (damage > 0)
	{
		setStrPoints(getStrPoints() - damage);

		if (getStrPoints() <= 0) // if strength points are 0 or less
		{
			if (getDeath() == 0)  // check to see if Harry has died already. If not (0)..
			{	// announce Harry's death and resurrection

				// display HP's strength points
				std::cout << "\n" << creatureName << "'s Strength Points: " << getStrPoints() << " points." << std::endl;
				std::cout << "\n" << creatureName << " has died and come back from the grave! Their Strength Points are now 10!\n";
				setStrPoints(10); // set strength points to 10
				setDeath(1); // death to 1 (has died already)
			}
			else //Harry dies permanently
			{
				// display HP's strength points
				std::cout << "\n" << creatureName << "'s Strength Points: " << getStrPoints() << " points." << std::endl;
				std::cout << Type << " " << creatureName << " of " << Team << " has died for good. ";
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

/*************************************************************************
** Function: setName
** Description: This function is used to set the name of the fighter.
** This is used for display purposes.
**************************************************************************/

void HarryPotter::setName(std::string name)
{
	creatureName = name;
}

/*************************************************************************
** Function: getName
** Description: This function is and accessor to obtain the name of the
** fighter. This is used for display purposes.
**************************************************************************/

std::string HarryPotter::getName()
{
	return creatureName;
}

/*************************************************************************
** Function: getType
** Description: This function is and accessor to obtain the type of the
** fighter. This is used for display purposes.
**************************************************************************/

std::string HarryPotter::getType()
{
	return Type;
}

/*************************************************************************
** Function: regen
** Description: This function is used to reset the health of the fighter.
** When a fighter wins a match, he is regenerated back to full health
** in order to start fresh for the next round. Harry also refreshes
** his special ability.
**************************************************************************/

void HarryPotter::regen()
{
	setStrPoints(10);
	setDeath(0);
}

/*************************************************************************
** Function: getTeam
** Description: This function is and accessor to obtain the team of the
** fighter. This is used for display purposes.
**************************************************************************/

std::string HarryPotter::getTeam()
{
	return Team;
}

/*************************************************************************
** Function: setTeam
** Description: This function is used to set the team of the fighter.
** This is used for display purposes.
**************************************************************************/

void HarryPotter::setTeam(std::string team)
{
	Team = team;
}
