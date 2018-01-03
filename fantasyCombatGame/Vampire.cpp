/****************************************************************************
 * Description: The Vampire class is a subclass of Character. A Vampire has
 * the special ability (Charm) that gives them a 50% chance of not being
 * attacked.
 ***************************************************************************/
#include <cstdlib>
#include <iostream>
#include "Vampire.hpp"

using std::cout;
using std::endl;

Vampire::Vampire() {

	this->setArmor(1);
	this->setStrengthPoints(18);
	this->setName("Vampire");
	this->setMaxPoints(18);
}

int Vampire::attack() {

	int roll1;


	roll1 = ((rand() % 12) + 1);
	return roll1;

}

int Vampire::defend(int attack) {

	int defense;
	int damage;

	//charm power
	if((rand() % 2 == 0)) {
		std::cout << "Never mind...this vampire is too charming to attack." << std::endl;
		damage = 0;
		return damage;
	}
	else
	//roll defense points
	defense = ((rand() % 6) + 1);
	//print defense
	cout << this->getUserName() << " defends! Defense pts:" << defense << endl;

	//print defender stats
	cout << "Armor:" << this->getArmor() << " Strength Pts:" << this->getStrengthPoints() << endl;

	//calculate damage
	damage = attack - (this->getArmor() + defense);
	//since damage can't be less than zero
	if(damage < 0)
		damage = 0;

	//print damage
	cout << "Damage pts:" << damage << " (attack - defense + armor)" << endl;

	return damage;
}

Vampire::~Vampire() {

}
