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

#ifndef street_hpp
#define street_hpp
#include "space.hpp"
#include <iomanip>


class Street : public Space
{
private:

public:
	Street();
	~Street() {}
	virtual void stallText(Player* player);
	bool stallSE();
	bool stallNW();
	void displayMenus();
	Inventory* createItem(char, Player*);
};

#endif