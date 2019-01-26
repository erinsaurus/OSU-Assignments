/**********************************************************************************
** Author: Erin Alltop
** Date: 4/10/16
** Description: This program creates a shopping list for the user. They can add
** or remove items, and display the list. The list contains the name of item
** the type of item, the quantity, cost, extended cost, and total cost of the trip.
***********************************************************************************/



#ifndef list_hpp
#define list_hpp

#include "items.hpp"

class List
{
private:
	Items *shoppingList;
	int maxSize;
	int objCount;
	int currentSize;
	double totalCost;
	
public:
	void addItem();
	void removeItem();
	void displayList();
	List();
	~List();
	void menu();
	void resize();
	int lookFor(std::string name);
	double getTotalCost();
//	void operator=(const Items &itemName);
};

#endif
