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

#ifndef grid_hpp
#define grid_hpp
#include "critter.hpp"
#include <iostream>

class Grid
{

private:
char **bugGrid;
int numRows;
int numCols;

public:

    void updateLocation();
    char **createArray(int numRows, int numCols);
    void fillArray(char **&gArray, int numRows, int numCols);
    void printArray(char **bGrid, int numRows, int numCols);
    Grid(int numRows, int numCols);
    void remove(char **&arr, int numCols);
    Grid();

    void setRows(int rows);
    void setCols(int cols);
    int getRows();
    int getCols();

};



#endif
