/****************************************************************************
** Author: Erin Alltop
** Date: 4/29/16
** Description: This program takes user input for the size of the 2D array,
** number of ant objects, nomber of doodlebug objects, and number of steps
** the critters will take. If the ant moves 3 times, it breeds and leaves a
** new ant in its spot when it moves. It does not eat or starve. If the
** doodlebug moves 8 times, it breeds and leaves a new doodlebug in its
** spot when it moves. If it doesn't eat in 3 moves/move attempts it starves
** and dies.
** Input: Row size, Column size, number of ants, number of doodlebugs
** number of steps
** Output: ant/doodlebug movement in random directions until number of steps is
** reached. Doodlebugs eat ants but not doodlebugs. Critters do not fall
** of the grid.
*****************************************************************************/

#include <iostream>
#include "critter.hpp"
#include <cstdlib>
#include <cmath>
#include <cstring>


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
	setMoveCheck(0);
	setXcoor(0);
	setYcoor(0);
	setDirection(0);
	setClass("");
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

void Critter::setDirection(int dir)
{
	direction = dir;
}

int Critter::getDirection()
{
	return direction;
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

void Critter::moveCritter(int numCols, int numRows)
{


	setMoveCheck(2); //set moves to "not moved" 1 = moved

					 /* Matching random number to possible directions
					 * If the critter would go off the grid or onto a
					 * critter, it does not move. If it not, adjust
					 * x or y coordinates and set the critter as
					 * having moved.
					 */

	if (getDirection() == 1) { //North
		setXcoor(getXcoor() - 1);
		setMoveCheck(1);
		//    std::cout << "Move North! " << std::endl;
	}
	else if (getDirection() == 2) { //East
		setYcoor(getYcoor() + 1);
		setMoveCheck(1);
		//   std::cout << "Move East! " << std::endl;
	}
	else if (getDirection() == 3) { //South
		setXcoor(getXcoor() + 1);
		setMoveCheck(1);
		//  std::cout << "Move South! " << std::endl;
	}
	else if (getDirection() == 4) { //West
		setYcoor(getYcoor() - 1);
		setMoveCheck(1);
		//  std::cout << "Move West! " << std::endl;
	}
}

void Critter::randomDirection()
{
	//picking a random direction
	int dir;
	dir = rand() % 4 + 1;

	setDirection(dir);
}

Critter* Critter::Breed()
{
	return NULL;
}

std::string Critter::getClass()
{
	return name;
}

void Critter::setClass(std::string cname)
{
	name = cname;
}

void Critter::Eat()
{
	
}