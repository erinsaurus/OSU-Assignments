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

#include <iostream>
#include "grid.hpp"
#include "critter.hpp"
#include <cstdlib>
#include <cmath>


/**************************************************************
** Function: int moveCritter();
** Description: This is called by the updateLocation function
** to move the critter in one of four random direction.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
***************************************************************/

void Critter::setXcoor(int x)
{
    xCoor = x;
}

void Critter::setYcoor(int y)
{
    yCoor = y;
}

int Critter::getXcoor()
{
    return xCoor;
}

int Critter::getYcoor()
{
    return yCoor;
}

void Critter::setNumMoves(int moves)
{
    numMoves = moves;
}

int Critter::getNumMoves()
{
    return numMoves;
}

int Critter::moveCritter()
{
        int direction;

       //picking a random direction
        int randomNum;
        randomNum = rand() % 4 + 1;

        //Matching the random number to four possible directions
        if (randomNum == 1)
        direction = 1; //North
        else if (randomNum == 2)
        direction = 2; //East
        else if (randomNum == 3)
        direction = 3; //South
        else if (randomNum == 4)
        direction = 4; //West

        return direction;

}

int Critter::startXcoor(int numRows)
{
    int startX;
    startX = rand() % numRows;
    setXcoor(startX);
    getXcoor();
    return xCoor;
}

int Critter::startYcoor(int numCols)
{
    int startY;
    startY = rand() % numCols;
    setYcoor(startY);
    getYcoor();
    return yCoor;
}

int Critter::moveCounter(int numMoves)
{
    setNumMoves(numMoves+1);
    getNumMoves();
    return numMoves;
}
