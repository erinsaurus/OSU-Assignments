/********************************************************************
** Author: Erin Alltop
** Date: 4/6/16
** Description: This program moves an ant around a grid. If it
** lands on a white spot, it turns right and makes it black. If it
** lands on a black spot, it turns left and makes it white until
** the program terminates.
*********************************************************************/

#ifndef Ant_hpp
#define Ant_hpp
#include <iostream>
#include <cstring>

class Ant
{
private:

public:
    enum Direction {NORTH, SOUTH, EAST, WEST};
    void playGame(char **&aGrid, int xCoor, int yCoor, int rows, int cols, int numSteps);
    void changeColor(char **&antG, int xCoor, int yCoor, int rows, int cols); //return the color
};
#endif
