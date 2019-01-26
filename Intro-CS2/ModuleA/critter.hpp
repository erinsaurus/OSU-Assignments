/****************************************************************************
** Author: Erin Alltop
** Date: 3/29/16
** Description: This program takes user input for the size of a 2D array
** and also for the beginning location of a critter. The critter then takes
** steps in random directions until it goes off the grid, in which case
** it is squashed.
** Input: Row size, Column size, Beginning x and and y coordinates
** Output: Critter movement in random directions and number of steps
** it took until the critter got squashed (moved off grid).
*****************************************************************************/


#ifndef critter_hpp
#define critter_hpp
#include "grid.hpp"
#include <iostream>

class Critter
{
private:
    int numMoves;
    int xCoor;
    int yCoor;

public:
    int moveCritter();
    void setXcoor(int x);
    void setYcoor(int y);
    int getXcoor();
    int getYcoor();
    void setNumMoves(int moves);
    int getNumMoves();
    int startXcoor(int numRows);
    int startYcoor(int numCols);
    int moveCounter(int numMoves);

};


#endif
