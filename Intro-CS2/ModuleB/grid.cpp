/****************************************************************************
 ** Author: Erin Alltop
 ** Date: 4/6/16
 ** Description: This program takes user input for the size of the 2D array,
 ** number of critter objects, and number of steps the critters will take.
 ** Input: Row size, Column size, number of critters, number of steps
 ** Output: Critter movement in random directions until number of steps is
 ** reached. Critters do not overlap or fall off grid.
 *****************************************************************************/

#include "grid.hpp"
#include "critter.hpp"
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <unistd.h>

/*********************************************************************
 ** Function: Constructor
 ** Description: This is the constructor for the Grid class
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 ************************************************************************/
//constructor
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


Critter ***Grid::createArray(int numRows, int numCols)

{
    Critter ***tArray;

    tArray = new Critter**[numCols];
    for(int i = 0; i < numCols; i++){
        tArray[i] = new Critter*[numRows];
    }
    return tArray;
}


/****************************************************************
 ** Function: fillArray
 ** Description: This function initializes the new array with
 ** dots before it can be used in other functions. I used the TA
 ** Example as a guide to create this function.
 ** Parameters: Array by reference, number of rows and columns
 ** number of critters by user input
 ** Pre-Conditions: array dynamically allocated
 ** Post-Conditions: initialized array
 *****************************************************************/


void Grid::fillArray(Critter ***&gArray, int numRows, int numCols)

{
    //initialize all locations to NULL
      for(int i = 0; i < numCols; i++){
        for(int j = 0; j < numRows; j++){
                gArray[i][j] = NULL;
        }
    }

}

/*********************************************************************
 ** Function: startPos
 ** Description: This functions starts the critters in random positions
 ** on the grid
 ** Parameters: grid by reference, number of rows, number of columns,
 ** number of critters
 ** Pre-Conditions: User input for all values
 ** Post-Conditions: sets the critters in random starting positions
 ************************************************************************/
void Grid::startPos(Critter ***&gArray, int numRows, int numCols, int numCrit)
{



    //for each critter, search through the array and insert critter objects in unoccupied cells
    for(int i = 0; i < numCrit; i++){
        int xCoor = rand() % numRows;
        int yCoor = rand() % numCols;
            if(gArray[xCoor][yCoor] == NULL)
                {gArray[xCoor][yCoor] = new Critter;
            gArray[xCoor][yCoor]->setXcoor(xCoor);
            gArray[xCoor][yCoor]->setYcoor(yCoor);
            } //if the cell is already occupied, set the counter back by one
            else if (gArray[xCoor][yCoor] != NULL)
                --i;
            }
    }

/****************************************************************
 ** Function: remove Array
 ** Description: This function deallocates the array at the end
 ** of the program.
 ** Parameters: Array by reference, number of columns
 ** Pre-Conditions: array dynamically allocated, program complete
 ** Post-Conditions: initialized array
 *****************************************************************/
/*
void Grid::remove(Critter ***&arr, int numCols)
{
    for(int i = 0; i < numCols; i++)
        delete(arr[i]);
    delete(arr);
}
*/

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

void Grid::printArray(Critter ***bGrid, int numRows, int numCols)

{

    for(int i = 0; i < numCols; i++){
        for(int j = 0; j <numRows; j++){
            if(!bGrid[i][j])
                std::cout << " " << '.';
            else
                std::cout << " " << 'C';

        }
    std::cout << std::endl;
    }

    }

/*********************************************************************
 ** Function: setRows
 ** Description: This function sets the number of rows from main
 ** Parameters: int number of rows
 ** Pre-Conditions: User input from main for number of rows
 ** Post-Conditions: number of rows
 ************************************************************************/
void Grid::setRows(int rows)
{
    numRows = rows;
}


/*********************************************************************
 ** Function: setCols
 ** Description: This function sets the number of columns from main
 ** Parameters: int number of columns
 ** Pre-Conditions: User input from main for number of columns
 ** Post-Conditions: number of columns
 ************************************************************************/
void Grid::setCols(int cols)
{
    numCols = cols;
}

/*********************************************************************
 ** Function: getRows
 ** Description: This function returns the number of set rows
 ** Parameters: None
 ** Pre-Conditions: setRows function
 ** Post-Conditions: returns rows
 ************************************************************************/
int Grid::getRows()
{
    return numRows;
}


/*********************************************************************
 ** Function: getCols
 ** Description: This function returns the number of set columns
 ** Parameters: None
 ** Pre-Conditions: User input from main for number of columns
 ** Post-Conditions: returns columns
 ************************************************************************/
int Grid::getCols()
{
    return numCols;
}


/*********************************************************************
 ** Function: setNumCrit
 ** Description: This function sets the number of critters from main
 ** Parameters: int number of critters
 ** Pre-Conditions: User input from main for number of critters
 ** Post-Conditions: number of critters
 ************************************************************************/
void Grid::setNumCrit(int critters)
{
    numCrit = critters;
}


/*********************************************************************
 ** Function: getNumCrit
 ** Description: This function returns the number of critters
 ** Parameters: None
 ** Pre-Conditions: number of critters set in setNumCrit
 ** Post-Conditions: returns number of critters
 ************************************************************************/
int Grid::getNumCrit()
{
    return numCrit;
}

/*********************************************************************
 ** Function: setNumMoves
 ** Description: This function sets the number of moves from main
 ** Parameters: int number of moves
 ** Pre-Conditions: User input from main for number of moves
 ** Post-Conditions: sets the number of moves
 ************************************************************************/
void Grid::setNumMoves(int moves)
{
    numMoves = moves;
}

/*********************************************************************
 ** Function: getNumMoves
 ** Description: This function gets the number of moves
 ** Parameters: None
 ** Pre-Conditions: Number of moves set in setNumMoves()
 ** Post-Conditions: returns the number of moves
 ************************************************************************/

int Grid::getNumMoves()
{
    return numMoves;
}
/*********************************************************************
 ** Function: updateLocation
 ** Description: This function updates the location of the critter.
 ** It calls the moveCritter location from the Critter class to
 ** find the direction that the critter has moved, and then prints
 ** The program terminates after the number of steps is complete.
 ** Parameters: Array by reference, beginning x and y coordinates,
 ** and number of rows and columns.
 ** Pre-Conditions: all parameters declared and initialized
 ** Post-Conditions: Critter has exited the grid, and numSteps outputted.
 ************************************************************************/

 void Grid::updateLocation()
 {

 Critter ***bGrid;
 Critter bug; //Critter object

 //create, fill, and print array with starting locations of critters
bGrid = createArray(getRows(), getCols());
fillArray(bGrid, getRows(), getCols());
startPos(bGrid, getRows(), getCols(), getNumCrit());
printArray(bGrid, getRows(), getCols());

std::cout << std::endl;


int numMoves = 0; //counter

bug.setMoveCheck(2);
//continue looping until number of steps is complete
 do{ //searching array
 for(int i = 0; i < getCols(); i++){
    for(int j = 0; j < getRows(); j++){
        if(bGrid[i][j] != NULL)
          {
            if(bGrid[i][j]->getMoveCheck() != 1){ //check if critter has moved
             bGrid[i][j]->moveCritter(bGrid, numCols, numRows); //call move function
            // std::cout << "Coordinates after move function: " << bGrid[i][j]->getXcoor() << " " << bGrid[i][j]->getYcoor() << std::endl;
                if(bGrid[bGrid[i][j]->getXcoor()][bGrid[i][j]->getYcoor()] == bGrid[i][j])
                { /* Do not set location to NULL if critter has not moved!*/
                  //  std::cout << "I didn't move. Don't delete me bro!" << std::endl;
                }
                else if(bGrid[bGrid[i][j]->getXcoor()][bGrid[i][j]->getYcoor()] != bGrid[i][j])
                {   //if critter has moved, set old pointer to NULL after assigning critter to new pointer
                    bGrid[bGrid[i][j]->getXcoor()][bGrid[i][j]->getYcoor()] = bGrid[i][j];
                    bGrid[i][j] = NULL;
                }
        //     system("cls");
         }

             //reset the move check variable to not moved
             else if(bGrid[i][j]->getMoveCheck() == 1)
             {
                 bGrid[i][j]->setMoveCheck(2);
             }
          }
        else if(bGrid[i][j] == NULL)
            {/*do nothing*/}


    }
 }

printArray(bGrid, getRows(), getCols()); //print the array
std::cout << std::endl;
  numMoves++; //move counter

 }while(numMoves < getNumMoves()); //loop while move counter is less than or equal to number of moves requested

 std::cout << std::endl;
//remove(bGrid, getCols());
 }

 /*********************************************************************
 ** Function: Deconstructor
 ** Description: This function is the deconstructor from the Grid class.
 ** It deallocates the array
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 ************************************************************************/
/*

Grid::~Grid()
 {
    for(int i = 0; i < getCols(); i++)
        delete(critters[i]);
    delete(critters);
 }
*/



