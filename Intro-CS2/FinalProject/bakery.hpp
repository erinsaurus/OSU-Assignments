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

#ifndef bakery_hpp
#define bakery_hpp
#include "space.hpp"


class Bakery : public Space

{
private:
	int ovenCheck = 0;

public:
	Bakery();
	virtual void stallText(Player* player);
	Inventory * createItem(char purchase, Player* player);
	void displayInventory();
	void setOvenCheck(int done);
	int getOvenCheck();
	void ovenHelp(Player* player);
};

#endif
