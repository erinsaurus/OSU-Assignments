/**********************************************************************************
** Author: Erin Alltop
** Date: 4/10/16
** Description: This program creates a shopping list for the user. They can add
** or remove items, and display the list. The list contains the name of item
** the type of item, the quantity, cost, extended cost, and total cost of the trip.
***********************************************************************************/


#include "items.hpp"
#include <cstring>
#include <iostream>
#include <iomanip>


/*********************************************************************************
** Function: Items Constructor
** Description: This function initializes the data members to null/zero.
**********************************************************************************/

Items::Items()
{
	quantity = 0;
	price = 0;
	itemName = ""; 
	unitType = "";
	extendedCost = 0;
}


/*********************************************************************************
** Function: getExtended Cost
** Description: This function calculates and returned the extended cost of the
** items the customer inputs. This is calculated using the get functions for
** quantity and price.
**********************************************************************************/

double Items::getExtendedCost()
{
	extendedCost = getQuantity() * getPrice();
	return extendedCost;
}


/*********************************************************************************
** Function: setQuantity
** Description: This function sets the quantity of items
** Input: number of items to buy from the user
**********************************************************************************/

void Items::setQuantity(int numItems)
{
	quantity = numItems;
}

/*********************************************************************************
** Function: getQuantity
** Description: This function returns the quantity of items. 
** Output: int of quantity of items to buy
**********************************************************************************/

int Items::getQuantity()
{
	return quantity;
}


/*********************************************************************************
** Function: setPrice
** Description: This function sets the price per item.
** Input: price per item from user input. 
**********************************************************************************/

void Items::setPrice(double cost)
{
	price = cost;
}


/*********************************************************************************
** Function: getPrice
** Description: This function returns the price of items.
** Output: double of price of items to buy
**********************************************************************************/

double Items::getPrice()
{
	return price;
}


/*********************************************************************************
** Function: setItemName
** Description: This function sets the name of the item.
** Input: string name from the user
**********************************************************************************/

void Items::setItemName(std::string name)
{
	name = itemName;
}


/*********************************************************************************
** Function: getItemName
** Description: This function returns the name of the item to buy
** Output: string of the item name
**********************************************************************************/

std::string Items::getItemName()
{
	return itemName;
}

/*********************************************************************************
** Function: setUnitType
** Description: This function sets the unit type the customer indicates
** Input: user input for unit type
**********************************************************************************/

void Items::setUnitType(std::string unit)
{
	unitType = unit;
}

/*********************************************************************************
** Function: getUnitType
** Description: This function returns the unit type
** Output: string of unit type to buy
**********************************************************************************/

std::string Items::getUnitType()
{
	return unitType;
}


/*********************************************************************************
** Function: Display
** Description: This function outputs the different categories on the list for
** the user for an object. This also creates a table for easier reading.
** Output: A table of the item name, quantity, unit type, price, and extended
** cost for the object in question. 
**********************************************************************************/

void Items::Display() 
{
		std::cout << std::setw(10) << std::left << 
		getItemName() << std::setw(10) << std::left << 
		getQuantity() << std::setw(10) << std::left << 
		getUnitType() << std::setw(10) << std::left << 
		getPrice() << std::setw(10) << std::left << 
		getExtendedCost();

		std::cout << std::endl;
}

/*********************************************************************************
** Function: Enter
** Description: When a new object (list item) is created, this function is called
** so that the user can enter on the items on the list.
** Input: The user inputs the item name, quantity, price, and unit type for each
** new item on the list.
**********************************************************************************/
void Items::Enter()
{
	std::cin.ignore();
	std::cout << "\nType the name of the item: ";
	std::getline(std::cin, itemName);
	
	int numWant;
	std::cout << "\nType the quantity needed: "; 
	std::cin >> numWant;
	setQuantity(numWant);

	double cost;
	std::cout << "\nType the unit cost in the format '1.00': ";
	std::cin >> cost;
	setPrice(cost);

	std::cin.ignore();
	std::cout << "\nEnter the type of item this is. (e.g. can, box, pounds, or ounces): ";
	std::getline(std::cin, unitType);
	
}

