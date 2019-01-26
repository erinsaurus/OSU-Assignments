/********************************************************************
** Author: Erin Alltop
** Date: 4/6/16
** Description: This program moves an ant around a grid. If it
** lands on a white spot, it turns right and makes it black. If it
** lands on a black spot, it turns left and makes it white until
** the program terminates.
*********************************************************************/

#include "aGrid.hpp"
#include "Ant.hpp"
#include <iostream>


/****************************************************************
** Function: createArray
** Description: This function creates a temporary array to
** dynamically allocate memory for the array at compile time.
** I used the TA examples as a guide for this function.
** Parameters: number of Rows and Columns for the array
** Pre-Conditions: numRows and numCols declared
** Post-Conditions: new temporary array
*****************************************************************/


char **aGrid::createArray(int numRows, int numCols)
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


void aGrid::fillArray(char **&gArray, int numRows, int numCols)
{
    char dots = '.';
    for (int i = 0; i < numCols; i++){
            for (int j = 0; j < numRows; j++){
                gArray[i][j] = dots;
}
    }

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

void aGrid::printArray(char **bGrid, int numRows, int numCols)
{

    for(int i = 0; i < numCols; i++){
            for (int j = 0; j < numRows; j++){
                std::cout << bGrid[i][j] << " ";
                }
            std::cout << std::endl;
    }

}
