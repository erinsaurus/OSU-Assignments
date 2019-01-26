/**********************************************************************************
** Author: Erin Alltop
** Date: 4/10/16
** Description: This program creates a shopping list for the user. They can add
** or remove items, and display the list. The list contains the name of item
** the type of item, the quantity, cost, extended cost, and total cost of the trip.
***********************************************************************************/

#ifndef items_hpp
#define items_hpp

#include <string>

class Items
{
private:
	std::string itemName;
	int quantity;
	double price;
	std::string unitType;
	double extendedCost;
	
public:
	Items();
	void setQuantity(int numItems);
	int getQuantity();
	void setPrice(double cost);
	double getPrice();
	void setItemName(std::string name);
	std::string getItemName();
	void setUnitType(std::string unit);
	std::string getUnitType();
	void Display();
	void Enter();
	double getExtendedCost();

};
#endif