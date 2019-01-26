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


#include "grid.hpp"
#include "critter.hpp"
#include <iostream>
#include <cstdlib>

Grid::Grid()
{

}

/****************************************************************
** Function: createArray
** Description: This function creates a temporary array to
** dynamically allocate memory for the array at compile time.
** I used the TA examples as a guide for this function.
** Parameters: number of Rows and Columns for the array
** Pre-Conditions: numRows and numCols declared
** Post-Conditions: new temporary array
*****************************************************************/



char **Grid::createArray(int numRows, int numCols)
{
    char **tArray;

    tArray = new char*[numCols];
    for(int i = 0; i < numCols; i++)
        tArray[i] = new char[numRows];
        return tArray;


}

/****************************************************************
** Function: fillArray
** Description: This function initializes the new array with
** dots before it can be used in other functions. I used the TA
** Example as a guide to create this function.
** Parameters: Array by reference, number of rows and columns
** Pre-Conditions: array dynamically allocated
** Post-Conditions: initialized array
*****************************************************************/


void Grid::fillArray(char **&gArray, int numRows, int numCols)
{
    char dots = '.';
    for (int i = 0; i < numCols; i++){
            for (int j = 0; j < numRows; j++){
                gArray[i][j] = dots;
}
    }

}

void Grid::remove(char **&arr, int numCols)
{
    for(int i = 0; i < numCols; i++)
        delete(arr[i]);
    delete(arr);
}

/****************************************************************
** Function: printArray
** Description: This function simply prints out the array. It
** uses two for loops to print out each element of the array.
** I used the TA examples as a guide for this function.
** Parameters: pointer to array, number of rows and columns
** Pre-Conditions: numRows and numCols declared, array dynamically
** allocated and initialized
** Post-Conditions: array printed out
*****************************************************************/

void Grid::printArray(char **bGrid, int numRows, int numCols)
{

    for(int i = 0; i < numCols; i++){
            for (int j = 0; j < numRows; j++){
                std::cout << bGrid[i][j] << " ";
                }
            std::cout << std::endl;
    }

}

void Grid::setRows(int rows)
{
     numRows = rows;
}

void Grid::setCols(int cols)
{
     numCols = cols;
}

int Grid::getRows()
{
    return numRows;
}

int Grid::getCols()
{
    return numCols;
}

/*********************************************************************
** Function: updateLocation
** Description: This function updates the location of the critter.
** It calls the moveCritter location from the Critter class to
** find the direction that the critter has moved, and then prints
** the array with the new location of the critter.
** Once the critter has gone off the grid, the critter is squashed
** and the program outputs the number of steps it took.
** Parameters: Array by reference, beginning x and y coordinates,
** and number of rows and columns.
** Pre-Conditions: all parameters declared and initialized
** Post-Conditions: Critter has exited the grid, and numSteps outputted.
************************************************************************/

void Grid::updateLocation()
{
    char **bGrid;
    Critter bug; //Critter object
    bug.startXcoor(getRows());
    bug.startYcoor(getCols());
    bug.getXcoor();
    bug.getYcoor();
    char critter = 'C';


    //create, fill, and print blank array
    bGrid = createArray(getRows(), getCols());
    fillArray(bGrid, getRows(), getCols());
    printArray(bGrid, getRows(), getCols());
    std::cout << std::endl;

    //set starting position
    bGrid[bug.getXcoor()][bug.getYcoor()] = critter;
    printArray(bGrid, getRows(), getCols());
    std::cout << std::endl;

    //setting currX and currY to the beginning coordinates
    int currX = bug.getXcoor();
    int currY = bug.getYcoor();
    int direction; //variable for the new direction

    bug.setNumMoves(0);

//This function moves the critter in random directions until it falls off the grid
while(currX >= 0 && currX <= getRows()-1 && currY >= 0 && currY <= getCols()-1) {
    bGrid[currX][currY] = '.'; //resetting the grid to empty before next iteration

    direction = bug.moveCritter(); //obtaining the new direction from the moveCritter function
      if (direction == 1) //North
        currX -= 1;
      else if (direction == 2) //East
        currY += 1;
      else if (direction == 3) //South
        currX += 1;
      else if (direction == 4) //West
        currY -= 1;


if(currX >= 0 && currX <= getRows()-1 && currY >=0 && currY <= getCols()-1)
{bGrid[currX][currY] = critter;

    //print out new array with the critter on the grid
    printArray(bGrid, getRows(), getCols()); }


    bug.moveCounter(bug.getNumMoves()); //counts the number of steps
    std::cout << std::endl;

}
    std::cout << "The critter is squashed! :( " << std::endl;
    std::cout << "The critter took " << bug.getNumMoves() << " steps before its untimely death." << std::endl;
    remove(bGrid, getCols());
}



