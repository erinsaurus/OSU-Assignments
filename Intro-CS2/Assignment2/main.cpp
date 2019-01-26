/**********************************************************************************
** Author: Erin Alltop
** Date: 4/10/16
** Description: This program creates a shopping list for the user. They can add
** or remove items, and display the list. The list contains the name of item
** the type of item, the quantity, cost, extended cost, and total cost of the trip.
***********************************************************************************/


#include <iostream>
#include "list.hpp"
#include "items.hpp"


/*****************************************************************************
** Function: Main
** Description: This main function simply creates a List object and begins
** the program by calling the menu function.
******************************************************************************/

int main()
{

	List shopping;
	shopping.menu();
	return 0;
}
