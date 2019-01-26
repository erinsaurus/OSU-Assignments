/**************************************************************************************************
** Author: Erin Alltop
** Date: 5/19/16
** Description: This program is a fantasy combat game. It allows the user to pick two teams of
** fighters to compete in a tournament. The two teams fight each other until one team has lost.
** The program gives several options for output as well.
** Input: User choices for number of fighters, types of fighters, and names of fighters.
** Output: Step-by-step battle stats until one team loses
**************************************************************************************************/

#include "creature.hpp"

/***************************************************************************
** Function: overloaded constructor
** Description: This function is used by the derived classes to
** initialize the object variables. No objects are ever instantiated
** in the creature class.
** Parameters: armor, strength points, attack amount
***************************************************************************/

Creature::Creature(int arm, int SP, int att)
{
	setArmor(arm);
	setStrPoints(SP);
	setAttack(att);
	damageDone = 0;
}

/*************************************************************************
** Function: getType
** Description: This function is and accessor to obtain the type of the
** fighter. This is used for display purposes.
**************************************************************************/

std::string Creature::getType()
{
	return Type;
}

/*************************************************************************
** Function: getTeam
** Description: This function is and accessor to obtain the team of the
** fighter. This is used for display purposes.
**************************************************************************/

std::string Creature::getTeam()
{
	return Team;
}


/*************************************************************************
** Function: setTeam
** Description: This function is used to set the team of the fighter.
** This is used for display purposes.
**************************************************************************/

void Creature::setTeam(std::string team)
{
	Team = team;
}

/*************************************************************************
** Function: setName
** Description: This function is used to set the name of the fighter.
** This is used for display purposes.
**************************************************************************/

void Creature::setName(std::string name)
{
	creatureName = name;
}

/*************************************************************************
** Function: getName
** Description: This function is and accessor to obtain the name of the
** fighter. This is used for display purposes.
**************************************************************************/

std::string Creature::getName()
{
	return creatureName;
}

/*************************************************************************
** Function: regen
** Description: This function is used to reset the health of the fighter.
** When a fighter wins a match, he is regenerated back to full health
** in order to start fresh for the next round.
**************************************************************************/

void Creature::regen()
{

}

/*************************************************************************
** Function: setDamageDone
** Description: This function adds the damage that a fighter inflicts on
** their opponent to a running total. This information is used in the case
** of a tie breaker.
**************************************************************************/

void Creature::setDamageDone(int damage)
{
	damageDone += damage;
}

/*************************************************************************
** Function: getDamageDone
** Description: This function is an accessor for the amount of damage done
** by a fighter to their opponents. This information is used in the event
** of a tie breaker.
**************************************************************************/

int Creature::getDamageDone()
{
	return damageDone;
}

/***************************************************************************
** Function: setStrPoints
** Description: This function is used to set the strength points for the
** object in its various functions.
** Parameters: int strength points
***************************************************************************/

void Creature::setStrPoints(int SP)
{
	StrPoints = SP;
}

/*************************************************************************
** Function: getStrPoints
** Description: Accessor for strength points. this function simply
** returns the strength points.
**************************************************************************/

int Creature::getStrPoints()
{
	return StrPoints;
}

/***************************************************************************
** Function: setAttack
** Description: This function is used to set the attack amount for the
** object in its various functions.
** Parameters: int attack amount
***************************************************************************/

void Creature::setAttack(int att)
{
	attackOpp = att;
}


/*************************************************************************
** Function: getAttack
** Description: Accessor for attack points. this function simply
** returns the attack amount.
**************************************************************************/


int Creature::getAttack()
{
	return attackOpp;

}

/***************************************************************************
** Function: setArmor
** Description: This function is used to set the armor amount for the
** object in its various functions.
** Parameters: int armor amount
***************************************************************************/

void Creature::setArmor(int arm)
{
	armor = arm;
}

/*************************************************************************
** Function: getArmor
** Description: Accessor for armor amount. this function simply
** returns the armor amount.
**************************************************************************/

int Creature::getArmor()
{
	return armor;
}
