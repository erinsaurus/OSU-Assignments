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
#include "doodlebug.hpp"


/****************************************************************************
** Function: Doodlebug constructor
** Description: This constructor initializes the count of the doodlebug
** object to 0.
*****************************************************************************/

Doodlebug::Doodlebug()
{
	Count = 0;
	name = "Doodlebug";
	noEat = 0;
}

/********************************************************************************
** Function: setCount
** Description: This function sets the count of the the doodlebug for the number of
** moves the ant makes
*********************************************************************************/

void Doodlebug::setCount(int num)
{
	Count = num;
}

/*******************************************************************************
** Fuction: getCount
** Description: This function returns the count of the doodlebug for the number
** of moves it makes
********************************************************************************/

int Doodlebug::getCount()
{
	return Count;
}


/******************************************************************************
** Function: Breed
** Description: This function determines whether the ant breeds. If the number
** of moves the doodlebug has made is 8, a new doodlebug is "born" and returned 
** as a pointer to the doodlebug. If the number of moves the doodlebug has made 
** is less than 8, then the Breed function returns a null pointer instead.
** Output: Doodlebug pointer that is null or for a new object.
******************************************************************************/

Doodlebug* Doodlebug::Breed()
{
	if (Count <= 8)
	{
		setCount(getCount() + 1);
		return NULL;
	}
	else
	{
		setCount(0);
		return new Doodlebug;
	}
}

/******************************************************************************
** Function: getClass 
** Description: This function returns the name of the class of the object
** Input: None
** Output: Class name
*******************************************************************************/


std::string Doodlebug::getClass()
{
	return name;
}

/******************************************************************************
** Function: Starve
** Description: This function sets the count for the number of moves and move
** attempts the doodlebug has gone without eating.
** Input: None
** Output: None
*******************************************************************************/

void Doodlebug::Starve()
{
	setNoEat(getNoEat() + 1);
}

/***********************************************************************************
** Function: Eat
** Description: This function resets the noEat variable for the object to 0 after 
** it has eaten.
** Input: None
** Output: None
************************************************************************************/

void Doodlebug::Eat()
{
	setNoEat(0);
}

/************************************************************************************
** Function: setNoEat
** Description: This function sets the count of the the doodlebug for the number of
** moves the doodlebug goes without eating
************************************************************************************/

void Doodlebug::setNoEat(int eat)
{
	noEat = eat;
}

/*********************************************************************************
** Fuction: getNoEat
** Description: This function returns the count of the doodlebug for the number
** of moves it goes without eating
*********************************************************************************/

int Doodlebug::getNoEat()
{
	return noEat;
}

