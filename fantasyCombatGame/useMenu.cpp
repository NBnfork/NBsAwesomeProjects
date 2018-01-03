/*************************************************************
** Description: The useMenu function displays a menu and returns
 * the choice the user makes. It is limited to a single choice. It's parameter controls the
 * different menu types.
*************************************************************/

#include "useMenu.hpp"
#include <iostream>
#include<string>
#include "getChoice.hpp"

using std::string;
using std::cout;
using std::endl;
using std::cin;

int useMenu(int menuOption) {
	if(menuOption == 1) {//main menu
		cout << endl;
		cout << "**************************************" << endl;
		cout << " Welcome to Fantasy Combat Tournament! " << endl;
		cout << "**************************************" << endl;
		cout << "Enter [1] to create the tournament." << endl;
		cout << "Enter [2] to exit." << endl;
	return getChoice(1,20);
	}

	else if(menuOption == 2){
		cout << "**************************************" << endl;
		cout << "Please choose how many characters will fight on each team." << endl;
		cout << "Press [enter] after each amount. 20 characters maximum." << endl;
		return 1;//dummy return
	}

	else if(menuOption == 3){
		//line-up menu creates a Character and puts it into the TeamQueue
		cout << "Types are:" << endl;
		cout <<	"[1] Barbarian" << endl;
		cout << "[2] Vampire" << endl;
		cout << "[3] Blue Men" << endl;
		cout << "[4] Medusa" << endl;
		cout << "[5] Harry Potter" << endl;
		return getChoice(1,5);

	}

	else //exit menu
	{
		cout << endl;
		cout << "**************************************" << endl;
		cout << "Enter [1] to play again." << endl;
		cout << "Enter [2] to quit." << endl;
		return getChoice(1,2);
	}
	return 0;
}
