/**************************************************************************************************
** Author: Erin Alltop
** Date: 5/19/16
** Description: This program is a fantasy combat game. It allows the user to pick two teams of
** fighters to compete in a tournament. The two teams fight each other until one team has lost.
** The program gives several options for output as well.
** Input: User choices for number of fighters, types of fighters, and names of fighters.
** Output: Step-by-step battle stats until one team loses
**************************************************************************************************/

#ifndef barbarian_hpp
#define barbarian_hpp
#include "creature.hpp"

class Barbarian : public Creature
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
	virtual void setName(std::string name);
	virtual std::string getName();
	virtual std::string getType();
	virtual void regen();
	virtual void setTeam(std::string team);
	virtual std::string getTeam();
	Barbarian(std::string name, std::string team) : Creature(0, 12, 0) {
		Type = "Barbarian";
		setName(name);
		setTeam(team);
	}
};

#endif