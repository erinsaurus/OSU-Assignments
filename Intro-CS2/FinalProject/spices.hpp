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

#ifndef spices_hpp
#define spices_hpp
#include "space.hpp"

class Spices : public Space
{
private:
	int guessCheck = 0;

public:
	void displayInventory();
	virtual void stallText(Player* player);
	Spices();
	Inventory* createItem(char purchase, Player* player);
	void guessThePrice(Player* player, double price);
	void setGuessCheck(int done);
	int getGuessCheck();


};

#endif