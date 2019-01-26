/****************************************************************************
 ** Author: Erin Alltop
 ** Date: 4/6/16
 ** Description: This program takes user input for the size of the 2D array,
 ** number of critter objects, and number of steps the critters will take.
 ** Input: Row size, Column size, number of critters, number of steps
 ** Output: Critter movement in random directions until number of steps is
 ** reached. Critters do not overlap or fall off grid.
 *****************************************************************************/

#ifndef critter_hpp
#define critter_hpp
//#include "grid.hpp"
#include <iostream>

class Critter
{
private:
    int xCoor;
    int yCoor;
    int direction;
    int moveCheck;



public:
    void moveCritter(Critter ***bGrid, int numCols, int numRows);
    void setXcoor(int x);
    void setYcoor(int y);
    int getXcoor();
    int getYcoor();
    int moveCounter(int numMoves);
    Critter();
    void setMoveCheck(int check);
    int getMoveCheck();

};

#endif



