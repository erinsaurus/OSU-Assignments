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

#ifndef harrypotter_hpp
#define harrypotter_hpp
#include "creature.hpp"

class HarryPotter : public Creature
{

private:
	int Death; //class private data member for Death

public:
	virtual void setArmor(int arm);
	virtual int getArmor();
	virtual void attack();
	virtual void defend(int attack);
	virtual void setStrPoints(int SP);
	virtual int getStrPoints();
	virtual int getAttack();
	virtual void setAttack(int att);
	HarryPotter() : Creature(0, 10, 0) { Death = 0; } //constructor as well as class initialization of Death
	void setDeath(int die);
	int getDeath();
};

#endif