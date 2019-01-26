/**************************************************************************************************
** Author: Erin Alltop
** Date: 5/6/16
** Description: This program is a fantasy combat game. It allows the user to pick two opponents
** to battle to the death. There are 5 different types of opponents that can battle each other or
** themselves. They each have different stats and abilities. Once one of them runs of out Strength
** Points then the game ends and the program terminates.
** Input: User choices for two opponents to battle
** Output: Step-by-step battle stats until one opponent loses
**************************************************************************************************/

/** This class is only used
 ** for menu purposes to help
 ** reduce clutter in the main
 ** program. This can also be
 ** reused in future programs.
 **/


#ifndef menu_hpp
#define menu_hpp

class Menu
{

public:
	void menu();
};


#endif