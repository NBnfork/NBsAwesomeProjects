/***************************************************************************
 * Description: The Medusa class is a subclass of Character. They have all
 * the regular character attributes, plus a super attack ability (Glare) that kills
 * an opponent every time
 ***************************************************************************/

#include "Medusa.hpp"
#include <iostream>

using std::cout;
using std::endl;

Medusa::Medusa() {

	this->setArmor(3);
	this->setStrengthPoints(8);
	this->setName("Medusa");
	this->setMaxPoints(8);
}
int Medusa::attack() {

	int roll1;
	int roll2;

	roll1 = ((rand() % 6) + 1);
	roll2 = ((rand() % 6) + 1);
	if(roll1 + roll2 == 12)
	{//Glare ability
		cout << "Medusa unleashes her unholy glare!!!!" << endl;
		roll1 = 96;
	}
	return roll1 + roll2;

}

int Medusa::defend(int attack) {

	int roll1;
	int defense;
	int damage;

	//roll dice
	roll1 = ((rand() % 6) + 1);
	//get total for defense
	defense = roll1;

	cout << this->getUserName()  << " defends! Defense pts:" << defense << endl;

	//print defender stats
	cout << "Armor:" << this->getArmor() << " Strength Pts:" << this->getStrengthPoints() << endl;

	//calculate damage
	damage = attack - (this->getArmor() + defense);

	//since damage can't be less than zero
	if (damage < 0)
		damage = 0;

	//print damage
	cout << "Damage pts:" << damage << " (attack - defense + armor)" << endl;

	return damage;
}

Medusa::~Medusa() {

}
