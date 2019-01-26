/**************************************************************************************************
** Author: Erin Alltop
** Date: 5/19/16
** Description: This program is a fantasy combat game. It allows the user to pick two teams of
** fighters to compete in a tournament. The two teams fight each other until one team has lost.
** The program gives several options for output as well.
** Input: User choices for number of fighters, types of fighters, and names of fighters.
** Output: Step-by-step battle stats until one team loses
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
	virtual void setName(std::string name);
	virtual std::string getName();
	virtual std::string getType();
	virtual void regen();
	virtual std::string getTeam();
	virtual void setTeam(std::string team);
	HarryPotter(std::string name, std::string team) : Creature(0, 10, 0) { 
		Type = "HarryPotter";
		setName(name);
		setTeam(team);
		Death = 0; 
	} //constructor as well as class initialization of Death
	void setDeath(int die);
	int getDeath();
};

#endif