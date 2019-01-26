/****************************************************************************
 ** Author: Erin Alltop
 ** Date: 4/6/16
 ** Description: This program takes user input for the size of the 2D array,
 ** number of critter objects, and number of steps the critters will take.
 ** Input: Row size, Column size, number of critters, number of steps
 ** Output: Critter movement in random directions until number of steps is
 ** reached. Critters do not overlap or fall off grid.
 *****************************************************************************/
#include <iostream>
#include "grid.hpp"
#include "critter.hpp"
#include <cstdlib>
#include <cmath>


/*********************************************************************
 ** Function: setXcoor
 ** Description: This function sets the x coordinate for the critter
 ** Parameters: int x coordinate
 ** Pre-Conditions: None
 ** Post-Conditions: sets the x coordinate
 ************************************************************************/
void Critter::setXcoor(int x)
{
    xCoor = x;
}


/*********************************************************************
 ** Function: setYcoor
 ** Description: This function sets the y coordinate for the critter
 ** Parameters: int y coordinate
 ** Pre-Conditions: None
 ** Post-Conditions: sets the y coordinate
 ************************************************************************/
void Critter::setYcoor(int y)
{
    yCoor = y;
}


/*********************************************************************
 ** Function: getXcoor
 ** Description: This function gets the x coordinate for the critter
 ** Parameters: None
 ** Pre-Conditions: x coordinate set by the setXcoor() function
 ** Post-Conditions: returns the x coordinate
 ************************************************************************/
int Critter::getXcoor()
{
    return xCoor;
}

/*********************************************************************
 ** Function: getYcoor
 ** Description: This function gets the y coordinate for the critter
 ** Parameters: None
 ** Pre-Conditions: y coordinate set by the setYcoor() function
 ** Post-Conditions: returns the y coordinate
 ************************************************************************/
int Critter::getYcoor()
{
    return yCoor;
}

/*********************************************************************
 ** Function: Critter class constructor
 ** Description: This function is the constructor for the critter class
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 ************************************************************************/
Critter::Critter()
{

}

/*********************************************************************
 ** Function: setMoveCheck
 ** Description: This function set the move check for whether the critter
 ** has move or not this generation
 ** Parameters: int check. 1=moved
 ** Pre-Conditions: None
 ** Post-Conditions: sets the move check
 ************************************************************************/
void Critter::setMoveCheck(int check)
{
    moveCheck = check;
}

/*********************************************************************
 ** Function: getMoveCheck
 ** Description: This function gets the move check from the setMoveCheck()
 ** function
 ** Parameters: None
 ** Pre-Conditions: move check set in setMoveCheck() function
 ** Post-Conditions: returns the move check
 ************************************************************************/
int Critter::getMoveCheck()
{
    return moveCheck;
}


/**************************************************************
** Function: int moveCritter();
** Description: This is called by the updateLocation function
** to move the critter in one of four random direction.
** If the critter would go off the grid or onto another
** critter it does not move. This function sets the new x and y
** coordinates of the critters.
** Parameters: Array, number of rows and columns
** Pre-Conditions: None
** Post-Conditions: None
***************************************************************/

void Critter::moveCritter(Critter ***bGrid, int numCols, int numRows)
{

       //picking a random direction
        int randomNum;
        randomNum = rand() % 4 + 1;
        setMoveCheck(2); //set moves to "not moved" 1 = moved

        /* Matching random number to possible directions
         * If the critter would go off the grid or onto a
         * critter, it does not move. If it not, adjust
         * x or y coordinates and set the critter as
         * having moved.
         */

        if (randomNum == 1){ //North
            if(getXcoor() > 0 && (bGrid[(getXcoor()-1)][getYcoor()] == NULL))
                setXcoor(getXcoor() - 1);
                setMoveCheck(1);
            //    std::cout << "Move North! " << std::endl;
        }
        else if (randomNum == 2){ //East
            if(getYcoor() < (numCols-1) && (bGrid[getXcoor()][(getYcoor()+1)] == NULL))
                setYcoor(getYcoor() + 1);
                setMoveCheck(1);
             //   std::cout << "Move East! " << std::endl;
        }
        else if (randomNum == 3){ //South
            if(getXcoor() < (numRows-1) && (bGrid[(getXcoor()+1)][getYcoor()] == NULL))
                setXcoor(getXcoor() + 1);
                setMoveCheck(1);
              //  std::cout << "Move South! " << std::endl;
        }
        else if (randomNum == 4){ //West
            if(getYcoor() > 0 && (bGrid[getXcoor()][(getYcoor()-1)] == NULL))
                setYcoor(getYcoor() - 1);
                setMoveCheck(1);
              //  std::cout << "Move West! " << std::endl;
        }
}


