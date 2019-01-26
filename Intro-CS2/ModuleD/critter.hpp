/****************************************************************************
** Author: Erin Alltop
** Date: 4/29/16
** Description: This program takes user input for the size of the 2D array,
** number of ant objects, nomber of doodlebug objects, and number of steps
** the critters will take. If the ant moves 3 times, it breeds and leaves a
** new ant in its spot when it moves. It does not eat or starve. If the
** doodlebug moves 8 times, it breeds and leaves a new doodlebug in its
** spot when it moves. If it doesn't eat in 3 moves/move attempts it starves
** and dies.
** Input: Row size, Column size, number of ants, number of doodlebugs
** number of steps
** Output: ant/doodlebug movement in random directions until number of steps is
** reached. Doodlebugs eat ants but not doodlebugs. Critters do not fall
** of the grid.
*****************************************************************************/


#ifndef critter_hpp
#define critter_hpp
#include <iostream>

class Critter
{
private:
	int xCoor;
	int yCoor;
	int direction;
	int moveCheck;
	std::string name;


public:
	void setXcoor(int x);
	void setYcoor(int y);
	int getXcoor();
	int getYcoor();
	Critter();
	void setMoveCheck(int check);
	int getMoveCheck();
	void setDirection(int dir);
	int getDirection();
	void moveCritter(int numCols, int numRows);
	void randomDirection();
	virtual Critter* Breed();
	virtual std::string getClass();
	virtual void setClass(std::string cname);
	virtual void Eat();
	virtual ~Critter() {};	

};


#endif
