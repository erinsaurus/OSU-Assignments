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


#ifndef grid_hpp
#define grid_hpp
#include "ant.hpp"
#include <iostream>

class Grid
{

private:
	Critter ***critters;
	int numRows;
	int numCols;
	int numCrit;
	int numMoves;
	int numAnts;
	int numDoodles;


public:

	void updateLocation();
	Grid(int rows, int cols, int ant, int doo);
	void fillArray();
	void printArray();
	Grid();
	virtual ~Grid();
	void startPos();
	void moveAnt(int xCoor, int yCoor);
	void moveDoodlebug(int xCoor, int yCoor);
	bool isFull();

};



#endif
