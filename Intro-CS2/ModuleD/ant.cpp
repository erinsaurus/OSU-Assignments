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
#include "ant.hpp"


/*******************************************************************
** Function: Ant constructor
** Description: This constructor initializes the count of the ant
** object to 0.
********************************************************************/

Ant::Ant()
{
	Count = 0;
	name = "Ant";
}


/********************************************************************************
** Function: setCount
** Description: This function sets the count of the the ant for the number of
** moves the ant makes
*********************************************************************************/

void Ant::setCount(int num)
{
	Count = num;
}

/***************************************************************************
** Fuction: getCount
** Description: This function returns the count of the ant for the number
** of moves it makes
***************************************************************************/

int Ant::getCount()
{
	return Count;
}


/******************************************************************************
** Function: Breed
** Description: This function determines whether the ant breeds. If the number
** of moves the ant has made is 3, a new ant is "born" and returned as a
** pointer to the ant. If the number of moves the ant has made is less than
** 3, then the Breed function returns a null pointer instead.
** Output: Ant pointer that is null or for a new object.
******************************************************************************/

Ant* Ant::Breed()
{

	if (getCount() <= 2)
	{
		setCount(getCount() + 1);
		return NULL;
	}

	else
	{
		setCount(0);
		return new Ant;
	}

}

std::string getClass()
{
	return "Ant";
}

std::string Ant::getClass()
{
	return name;
}
