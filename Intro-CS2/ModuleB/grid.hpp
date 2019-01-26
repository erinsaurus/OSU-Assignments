/****************************************************************************
 ** Author: Erin Alltop
 ** Date: 4/6/16
 ** Description: This program takes user input for the size of the 2D array,
 ** number of critter objects, and number of steps the critters will take.
 ** Input: Row size, Column size, number of critters, number of steps
 ** Output: Critter movement in random directions until number of steps is
 ** reached. Critters do not overlap or fall off grid.
 *****************************************************************************/

#ifndef grid_hpp
#define grid_hpp
#include "critter.hpp"
#include <iostream>

class Grid
{

private:
Critter ***critters;
int numRows;
int numCols;
int numCrit;
int numMoves;


public:

    void updateLocation();
    Critter ***createArray(int numRows, int numCols);
    void fillArray(Critter ***&gArray, int numRows, int numCols);
    void printArray(Critter ***bGrid, int numRows, int numCols);
    Grid(int numRows, int numCols);
    Grid();
   // ~Grid();

    void setRows(int rows);
    void setCols(int cols);
    int getRows();
    int getCols();
    void setNumCrit(int critters);
    int getNumCrit();
    void setNumMoves(int moves);
    int getNumMoves();
    void startPos(Critter ***&gArray, int numRows, int numCols, int numCrit);


};



#endif
