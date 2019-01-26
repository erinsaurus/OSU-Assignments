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

#ifndef grid_hpp
#define grid_hpp
#include "ant.hpp"
#include <iostream>

class Grid
{

private:
	Ant ***critters;
	int numRows;
	int numCols;
	int numCrit;
	int numMoves;


public:

	void updateLocation();
	Ant ***createArray(int numRows, int numCols);
	void fillArray(Ant ***&gArray, int numRows, int numCols);
	void printArray(Ant ***bGrid, int numRows, int numCols);
	void remove(Ant ***&bGrid, int numRows, int numCols);
	Grid(int numRows, int numCols);
	Grid();
	//~Grid();

	void setRows(int rows);
	void setCols(int cols);
	int getRows();
	int getCols();
	void setNumCrit(int critters);
	int getNumCrit();
	void setNumMoves(int moves);
	int getNumMoves();
	void startPos(Ant ***&gArray, int numRows, int numCols, int numCrit);



};



#endif
