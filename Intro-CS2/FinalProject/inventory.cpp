/**************************************************************************************************
** Name: Erin Alltop
** Date: 6/1/16
** Description: Final Project. This program is a text based game. The play is in a street market
** and has to collect certain ingredients on her shopping list. Points can be earned by buying
** or earning rare ingredients, performing small tasks, winning short games, and other
** various ways for bonus points. The final score is displayed at the end.
** This program makes use of polymorphism and containers. The player has a shopping bag that is
** a stack, and each shop is a derived class of the "space" class.
***************************************************************************************************/

#include "inventory.hpp"

void Inventory::setName(std::string name)
{
	itemName = name;
}

std::string Inventory::getName()
{
	return itemName;
}

void Inventory::setPrice(double cost)
{
	Price = cost;
}

double Inventory::getPrice()
{
	return Price;
}

Inventory::Inventory(std::string name, double cost)
{
	setName(name);
	setPrice(cost);
}


