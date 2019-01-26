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

#ifndef babayaga_hpp
#define babayaga_hpp
#include "creature.hpp"

class BabaYaga : public Creature
{

public:
	virtual void setArmor(int arm);
	virtual int getArmor();
	virtual void attack();
	virtual void defend(int attack);
	virtual void setStrPoints(int SP);
	virtual int getStrPoints();
	virtual int getAttack();
	virtual void setAttack(int att);
	BabaYaga() : Creature(3, 12, 0) {}
};

#endif