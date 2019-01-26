/**************************************************************************************************
** Author: Erin Alltop
** Date: 5/19/16
** Description: This program is a fantasy combat game. It allows the user to pick two teams of
** fighters to compete in a tournament. The two teams fight each other until one team has lost.
** The program gives several options for output as well.
** Input: User choices for number of fighters, types of fighters, and names of fighters.
** Output: Step-by-step battle stats until one team loses
**************************************************************************************************/

/** This class is the base class for the entire program.
** It is used solely as an abstract class and is not a
** possibility for an opponent.
** Its attack and defend functions are pure virtual
** functions to be used by the derived classes
**/

#ifndef creature_hpp
#define creature_hpp
#include <string>

class Creature
{
protected:  //protected data members
	int armor;
	int StrPoints;
	int attackOpp;
	std::string creatureName;
	std::string Type;
	std::string Team;
	int damageDone;

public:
	virtual void attack() = 0;   //pure virtual function
	virtual void defend(int attack) = 0; //pure virtual function
	virtual void setArmor(int arm);
	virtual int getArmor();
	virtual void setStrPoints(int SP);
	virtual int getStrPoints();
	virtual ~Creature() {} //destructor
	virtual int getAttack();
	virtual void setAttack(int att);
	Creature() {} //constructor
	Creature(int arm, int SP, int att);  //constructor with parameters for initialization
	virtual void setName(std::string name);
	virtual std::string getName();
	virtual std::string getType();
	virtual std::string getTeam();
	virtual void setTeam(std::string team);
	virtual void regen();
	virtual void setDamageDone(int damage);
	virtual int getDamageDone();

};

#endif