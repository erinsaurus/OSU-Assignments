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

/** This class is the base class for the entire program.
 ** It is used solely as an abstract class and is not a
 ** possibility for an opponent.
 ** Its attack and defend functions are pure virtual 
 ** functions to be used by the derived classes
 **/

#ifndef creature_hpp
#define creature_hpp

class Creature
{
protected:  //protected data members
	int armor;
	int StrPoints;
	int attackOpp;

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

};

#endif