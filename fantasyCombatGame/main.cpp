/***************************************************************************
 * Program: Fantasy Combat Tournament
 * Author: Noah Buchen
 * Date: 19 November 2017
 * Description: This program is a tournament style battle between teams of
 * fantasy players. After setting up the tournament the results from each
 * battle will print as well as the overall winner of the tournament.
 * Each battle outcome is scored and the defeated characters will be placed
 * on the loser list, which can be printed at the end of the tournament.
 **************************************************************************/
#include <iostream>
#include <ctime>
#include "useMenu.hpp"
#include "getChoice.hpp"
#include "BattleField.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "TeamQueue.hpp"
#include "LoserStack.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

enum MenuType {MAIN =1, NUMFIGHTERS, LINEUP, EXIT};
int main() {
	//seed rand()
	std::srand(time(nullptr));

	int menuChoice; //from user input
	unsigned int numFightersA; //for user input
	unsigned int numFightersB;//for user input
	int battleCount = 1; //for game flow control

	//create queues and stacks
	TeamQueue* teamAQueue = new TeamQueue;
	TeamQueue* teamBQueue = new TeamQueue;
	LoserStack* loserStack = new LoserStack;

	//display main menu
	menuChoice = useMenu(MAIN);

	do
	{
		bool gameOver; // to end a tournament
		int scoreA = 0; //to score tournament
		int scoreB = 0;
		int winner; //of individual battle
		int loserPrint;//for user input

		//intialize game
		gameOver = false;

		if(menuChoice != 2) {//for game flow

			//user will choose how many fighers per team
			useMenu(NUMFIGHTERS);
			//set numbers
			numFightersA = getChoice(1, 20);
			numFightersB = getChoice(1, 20);
			//print
			cout << "***" << endl;
			cout << "Team A will have " << numFightersA << " fighters." << endl;

			//loop to create team A;
			for (unsigned int x = 1; x <= numFightersA; x++) {
				cout << "Chose a character type for Fighter " << x << endl;

				//use lineup menu to display choices
				int characterType = useMenu(LINEUP);

				//make ptr to pass to queue
				Character *character;

				switch (characterType) {
					case BARBARIAN:
						character = new Barbarian;
						break;
					case VAMPIRE:
						character = new Vampire;
						break;
					case BLUEMEN:
						character = new BlueMen;
						break;
					case MEDUSA:
						character = new Medusa;
						break;
					case HARRYPOTTER:
						character = new HarryPotter;
						break;
				}

				//user names character
				string characterName;
				cout << "Please give your " << character->getName() << " a name." << endl;
				getline(cin, characterName);
				//validate
				while (characterName.length() == 0) {
					cout << "You forgot to enter a name." << endl;
					getline(cin, characterName);//set the objects name
				}
				character->setUserName(characterName);
				//put new character in the queue
				teamAQueue->addBack(character);
			}
			//print
			cout << "***" << endl;
			cout << "Team B will have " << numFightersB << " fighters." << endl;
			//loop to create team B;
			for (unsigned int x = 1; x <= numFightersB; x++) {
				cout << "Chose a character type for Fighter " << x << endl;
				//use lineup menu to display choices
				int characterType = useMenu(LINEUP);
				//make ptr to pass to queue
				Character *character;

				switch (characterType) {
					case BARBARIAN:
						character = new Barbarian;
						break;
					case VAMPIRE:
						character = new Vampire;
						break;
					case BLUEMEN:
						character = new BlueMen;
						break;
					case MEDUSA:
						character = new Medusa;
						break;
					case HARRYPOTTER:
						character = new HarryPotter;
						break;
				}
				//name character
				string characterName;
				cout << "Please give your " << character->getName() << " a name." << endl;
				getline(cin, characterName);
				//validate
				while (characterName.length() == 0) {
					cout << "You forgot to enter a name." << endl;
					getline(cin, characterName);
				}
				character->setUserName(characterName);
				//put new character in the queue
				teamBQueue->addBack(character);
			}
			//Start tournament
			do {


				//get fighters from the front of the queue
				Character *teamAFighter = teamAQueue->getFront();
				Character *teamBFighter = teamBQueue->getFront();
				//print fight info
				cout << "----------Battle #" << battleCount << "----------" << endl;
				cout << teamAFighter->getName() << " " << teamAFighter->getUserName() << endl;
				cout << "       VS" << endl;
				cout << teamBFighter->getName() << " " << teamBFighter->getUserName() << endl;
				//have fight  (loser will be passed to LoserStack in function)
				BattleField battleField(teamAFighter, teamBFighter);
				winner = battleField.fight(loserStack);
				//fight results
				if (winner == 1) {
					//fighter recovers
					teamAFighter->recover();
					//check for last fighter
					if (!teamAQueue->onlyOne()) {
						//fighter moves to the end of the line
						teamAQueue->addBack(teamAFighter);
						teamAQueue->removeFront();
					}
					//loser moved to stack in battlefield, now delete from queue
					teamBQueue->removeFront();
					//adjust scores;
					scoreA += 2;
					scoreB -= 1;
				}
				else {
					//fighter recovers
					teamBFighter->recover();
					//check for last fighter
					if (!teamBQueue->onlyOne()) {
						//fighter moves to the end of the line
						teamBQueue->addBack(teamBFighter);
						teamBQueue->removeFront();
					}
					//loser moved to stack in battlefield, now delete from queue
					teamAQueue->removeFront();
					//adjust scores
					scoreA -= 1;
					scoreB += 2;
				}
				//check for game over
				//team A is out of fighters
				if (teamAQueue->isEmpty()) {
					cout << "***The Tournament is over! Team A is out of fighters.***" << endl;
					//print scores
					if (battleCount == 1) {
						cout << "After 1 battle:" << endl;
					} else {
						cout << "After " << battleCount << " battles:" << endl;
					}
					cout << "***Final Score***" << endl;
					cout << "Team A:" << scoreA << " pts" << endl;
					cout << "Team B:" << scoreB << " pts" << endl;
					//print results
					if (scoreA == scoreB)
						cout << "The tournament was a tie!" << endl;
					else if (scoreA <= scoreB)
						cout << "Team B wins!" << endl;
					else
						cout << "Team A wins!" << endl;
					// ask for loser display
					cout << "Would you like to display a list of the losing fighters?" << endl;
					cout << "Enter [1] for yes and [2] for no." << endl;
					loserPrint = getChoice(1, 2);
					if (loserPrint == 1) {
						loserStack->printStack();
					}
					//in case of replay clear winning queue and loser stack
					teamBQueue->clearQueue();
					loserStack->clearStack();
					//end or replay
					gameOver = true;
					menuChoice = useMenu(EXIT);
				}
				else if (teamBQueue->isEmpty()) {
					cout << "***The Tournament is over! Team B is out of fighters. ***" << endl;
					if (battleCount == 1) {
						cout << "After 1 battle:" << endl;
					} else {
						cout << "After " << battleCount << " battles:" << endl;
					}
					cout << "***Final Score***" << endl;
					cout << "Team A:" << scoreA << " pts" << endl;
					cout << "Team B:" << scoreB << " pts" << endl;
					if (scoreA == scoreB)
						cout << "The tournament was a tie!" << endl;
					else if (scoreA <= scoreB)
						cout << "Team B wins!" << endl;
					else
						cout << "Team A wins!" << endl;
					// ask for loser display
					cout << "Would you like to display a list of the losing fighters?" << endl;
					cout << "Enter [1] for yes and [2] for no." << endl;
					loserPrint = getChoice(1, 2);
					if (loserPrint == 1) {
						loserStack->printStack();
					}
					//in case of replay clear winning queue and losing stack
					teamAQueue->clearQueue();
					loserStack->clearStack();
					//end or replay
					gameOver = true;
					menuChoice = useMenu(EXIT);
				}
				else{

					//print scores
					if (battleCount == 1) {
						cout << "****************" << endl;
						cout << "After 1 battle:" << endl;
					} else {
						cout << "After " << battleCount << " battles:" << endl;
					}
					cout << "Team A:" << scoreA << " pts" << endl;
					cout << "Team B:" << scoreB << " pts" << endl;
					battleCount++;
				}

			} while(!gameOver);
		}
	}while(menuChoice != 2);

	//memory clean up
	delete teamAQueue;
	delete teamBQueue;
	delete loserStack;

	return 0;
}
