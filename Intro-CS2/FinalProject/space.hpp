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

#ifndef space_hpp
#define space_hpp
#include "inventory.hpp"
#include "player.hpp"
#include "menu.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

class Inventory;
class Space
{
private:
	Space* North = NULL;
	Space* West = NULL;
	Space* South = NULL;	
	Space* East = NULL;
	Space* NorthWest = NULL;
	Space* SouthEast = NULL;
	Space* NorthEast = NULL;
	Space* SouthWest = NULL;
	std::string stallName;

public:
	virtual void shopKeeper(Player* player);
	virtual void displayInventory();
	virtual Space* getNorth();
	virtual Space* getWest();
	virtual Space* getSouth();
	virtual Space* getEast();
	virtual void setNorth(Space* n);
	virtual void setWest(Space* w);
	virtual void setSouth(Space* s);
	virtual void setEast(Space* e);
	Space();
	virtual ~Space();
	virtual std::string getStallName();
	virtual void setStallName(std::string name);
	virtual void stallText(Player* player);
	virtual void setNW(Space* nw);
	virtual void setSE(Space* se);
	virtual Space* getNW();
	virtual Space* getSE();
	virtual void setNE(Space* ne);
	virtual void setSW(Space* sw);
	virtual Space* getNE();
	virtual Space* getSW();
	virtual Inventory* createItem(char purchase, Player* player) = 0; //pure virtual function
	virtual void setPtrs(Space* n, Space* s, Space* e, Space* w, Space* nw, Space* se, Space* ne, Space* sw);
	


};


#endif
