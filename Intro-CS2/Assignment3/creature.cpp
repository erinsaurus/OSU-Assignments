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

