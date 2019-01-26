/********************************************************************
** Author: Erin Alltop
** Date: 4/6/16
** Description: This program moves an ant around a grid. If it
** lands on a white spot, it turns right and makes it black. If it
** lands on a black spot, it turns left and makes it white until
** the program terminates.
*********************************************************************/

#ifndef aGrid_hpp
#define aGrid_hpp
#include <iostream>

class aGrid
{
private:
    char *antGrid;
public:
    enum Direction {NORTH, SOUTH, EAST, WEST};
    char **createArray(int numRows, int numCols);
    void fillArray(char **&gArray, int numRows, int numCols);
    void printArray(char **bGrid, int numRows, int numCols);


};

#endif
