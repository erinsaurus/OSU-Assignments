/****************************************************************************
** Author: Erin Alltop
** Date: 4/15/16
** Description: This program takes user input for the size of the 2D array,
** number of ant objects, and number of steps the ant will take. If the
** ant moves 3 times, it breeds and leaves a new ant in its spot when it moves.
** Input: Row size, Column size, number of ants, number of steps
** Output: ant movement in random directions until number of steps is
** reached. Ants do not overlap or fall off grid.
*****************************************************************************/


#include "critter.hpp"

class Ant : public Critter
{
public:
	Ant* Breed();
	void setCount(int num);
	int getCount();
	Ant();
	void killAnt();
private:
	int Count;

};
