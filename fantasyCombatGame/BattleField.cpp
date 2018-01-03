/***************************************************************************
 * Description: The BattleField class will encapsulate all the combat
 * that will take place during the game. Two character pointers will be passed
 * into the function and then the function will control the combat and print
 * the results.
 ****************************************************************************/
#include "BattleField.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

BattleField::BattleField(Character *choice1 , Character* choice2) {

	this->rounds = 1;//for game flow
	this->ch1 = choice1;
	this->ch2 = choice2;


}
/***************************************************************************
 * Description: The fight function will control an entire battle including
 * the printing of all activities and stats along the way.
***************************************************************************/
int BattleField::fight(LoserStack* loserStack) {

	int attack;
	int damage;
	int newStrength;
	do {
		cout << "******* Round " << rounds << " *******" << endl;

		//call attack
		attack = ch1->attack();//character 1 will always attack first
		cout << "P1 " << ch1->getUserName() << " attacks! Attack pts:" << attack << endl;

		//call defend to calculate damage
		damage = ch2->defend(attack);
		//calculate new Strength points
		newStrength = ch2->getStrengthPoints() - damage;

		//setStrength and print
		ch2->setStrengthPoints(newStrength);
		cout << ch2->getUserName() << "'s Strength Pts:" << ch2->getStrengthPoints() << endl;
		cout << endl;
		//check for defeat
		if (ch2->getStrengthPoints() <= 0) {
			cout << ch2->getName() << " " << ch2->getUserName()
				 << " has been defeated!" << endl;
			// send loser to the stack
			loserStack->push(ch2);
			return 1;
		}
		else {
			//ch2 attacks
			attack = ch2->attack();//character 1 will always attack first
			cout << "P2 " << ch2->getUserName() << " attacks! Attack pts:" << attack << endl;

			//call defend to calculate damage
			damage = ch1->defend(attack);
			//calculate new Strength points
			newStrength = ch1->getStrengthPoints() - damage;

			//setStrength and print
			ch1->setStrengthPoints(newStrength);
			cout << ch1->getUserName() << "'s Strength Pts:" << ch1->getStrengthPoints() << endl;
			cout << endl;
			//check for defeat
			if (ch1->getStrengthPoints() <= 0) {
				cout << ch1->getName() << " " << ch1->getUserName()
					 << " has been defeated!" << endl;
				//send loser to the stack
				loserStack->push(ch1);
				return 2;
		}
		rounds++;
		}
	}while(rounds !=0);
	return false;
}




