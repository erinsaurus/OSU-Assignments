/**********************************************************************************
** Author: Erin Alltop
** Date: 4/10/16
** Description: This program creates a shopping list for the user. They can add
** or remove items, and display the list. The list contains the name of item
** the type of item, the quantity, cost, extended cost, and total cost of the trip.
***********************************************************************************/


#include "list.hpp"
#include <iostream>
#include <iomanip>
#include <cstring>


/*********************************************************************************
** Function: List constructor
** Description: This function initializes the data members of the List class
** as well as allocates the array of Item objects
**********************************************************************************/

List::List()
{
	maxSize = 4;
	currentSize = 0;
	totalCost = 0;

	shoppingList = new Items[maxSize];
}


/*********************************************************************************
** Function: addItem
** Description: This function adds a new item to the shopping list. It determines
** if the array has room to take on another object. If not, it calls the resize()
** function to expand the array. If not, it assigned a new object to the array
** and calls the Enter() function for user input of information.
** Output: Adds a new object to the Items array
**********************************************************************************/

void List::addItem()
{

	std::cout << "Add an item to the shopping list. \n" << std::endl;

	if (currentSize == maxSize)
		resize();
	shoppingList[currentSize++].Enter();
	
}


/*********************************************************************************
** Function: removeItem
** Description: This function removes an item from the array. It asks the user for
** what they would like to remove from the list, searches the array for a matching
** name, and then removes it from the array if found. It also decreases the
** currentSize by one and adjusts the total cost of the trip to remove the 
** extended cost of the item.
** Input: User input for name of object
** Output: Adjusts array to remove indicated object
**********************************************************************************/

void List::removeItem()
{
	std::cin.ignore(); //erase buffer
	std::string name;
	std::cout << "Remove an item from the shopping list. \n" << std::endl;
	std::cout << "What would you like to remove from the list? "; //input desired name
	std::getline(std::cin, name);

	//call helper function to locate the name
	int findName = lookFor(name);

	if (findName == -1) //if the name is not found, inform the user
		std::cout << name << " not found on list!";
	else
	{		//adjust total cost
		for (int j = findName + 1; j < currentSize; j++)
			totalCost -= shoppingList[j - 1].getExtendedCost();

		//remove object from array
		for (int j = findName + 1; j < currentSize; j++)
			shoppingList[j - 1] = shoppingList[j];

		currentSize--; //decrease size of the array in the variable
		std::cout << "Item removed from list.\n";
	}

}


/*********************************************************************************
** Function: lookFor
** Description: This function is a helper function of the removeItem() function.
** This function searches the array and determines if the item name inputted
** from the user matches any names in the array.
** Parameters: a string name
** Output: Returnes where the found name is on the array.
**********************************************************************************/

int List::lookFor(std::string name)
{
	for (int i = 0; i < currentSize; i++)
		if (shoppingList[i].getItemName() == name)
			return i;

	return -1;
}


/*********************************************************************************
** Function: displayList
** Description: This function prints out the column names for the array,
** calls the display function for each object, and calculates
** the total cost of the trip to display at the bottom of the output.
** Output: displays the array's contents and total cost of the trip.
**********************************************************************************/

void List::displayList()
{
	
	// If the array is empty, inform the user
	if (currentSize == 0)
	{
		std::cout << "\nThe shopping list is empty! Add an item.\n";
		return;
	}

	// column headers and size adjustment to line everything up
	std::cout << "Shopping List:\n" << std::endl;
		std::cout << std::setw(10) << std::left <<
		"Item Name" << std::setw(10) << std::left <<
		"Quantity" << std::setw(10) << std::left <<
		"Unit Type" << std::setw(10) << std::left <<
		"Price" << std::setw(10) << std::left <<
		"Extended Price\n";

	//for each object in the array, call its Display function
	for (int i = 0; i < currentSize; i++)
		shoppingList[i].Display();

	std::cout << "Total cost of trip: " << getTotalCost(); //totalCost
	std::cout << std::endl;
}


/*********************************************************************************
** Function: List class Deconstructor
** Description: This function deallocates the arrays at the end of the program
**********************************************************************************/

List::~List()
{

	delete[] shoppingList;
}


/*********************************************************************************
** Function: menu
** Description: This function is the menu function. It determines what the user
** would like to do next and exits the program after pressing 4.
** Input: User input for what menu function they would like to pursue.
**********************************************************************************/

void List::menu()
{
	std::cout << "Welcome to your shopping list! " << std::endl;
	std::cout << "Please review the menu choices below: \n" << std::endl;

	int choice;
	do
	{
		//Displaying Options for the menu
		std::cout << std::endl;
		std::cout << "1) Add Item " << std::endl;
		std::cout << "2) Remove Item" << std::endl;
		std::cout << "3) Display Shopping List " << std::endl;
		std::cout << "4) End Program. " << std::endl;

		//Prompting user to enter an option according to menu
		std::cout << "Please select an option: ";
		std::cin >> choice;


		if (choice == 1)
		{
			addItem();
		}
		else if (choice == 2)
		{
			removeItem();
		}
		else if (choice == 3)
		{	
			displayList();
		}
		else if (choice == 4)
		{
			std::cout << "Ending the program. \n" << std::endl;
		}
		else //if user has entered invalid choice (other than 1,2,3 or 4)
		{
			//Displaying error message
			std::cout << "\nInvalid choice. Please choose 1-4:" << std::endl;
		}
	} while (choice != 4);

}


/*********************************************************************************
** Function: resize
** Description: This function resizes the array to accomodate more objects. It
** creates a temporary array, copies the objects from the original array, and
** then deletes the original array before setting its name to the new array.
** Output: new, larger array.
**********************************************************************************/

void List::resize()
{
	maxSize = currentSize + 5;
	Items *tempList = new Items[maxSize];

	for (int i = 0; i < currentSize; i++)
		tempList[i] = shoppingList[i];

	delete[] shoppingList;
	shoppingList = tempList;
}


/*********************************************************************************
** Function: getTotalCost
** Description: This function calculates the total cost of the shopping trip.
** If the current cost is 0, it calculates the new cost.
** Output: double of the total cost of the shopping trip. 
**********************************************************************************/

double List::getTotalCost()
{


	for (int i = 0; i < currentSize; i++)
	totalCost += shoppingList[i].getExtendedCost();


	return totalCost;
}


/************************************************************************8
 ** Function: operator overload ==
** Description: This function checks the name of the objects and makes
** sure there are no duplicate item names. I unfortunately wasunable
** to get this working properly before I ran out of time.
**************************************************************************/

/*
 
void List::operator=(const Items &itemName)
{

if (maxSize > 0) delete [] shoppingList;
maxSize = itemName.maxSize;
shoppingList = new Items[maxSize];
for (int i = 0; i < maxSize; i++)
shoppingList[i] = itemName.shoppingList[i];
}
*/
