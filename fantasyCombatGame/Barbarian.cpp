/***************************************************************************
 * Description: The Barabian Class is a subclass of Character. The Barbarian
 * has an overriden attack and defend function as well as armor and strength
 * points.
 **************************************************************************/

#include <cstdlib>
#include <iostream>
#include "Barbarian.hpp"

using std::cout;
using std::endl;

Barbarian::Barbarian() {

	this->setArmor(0);
	this->setStrengthPoints(12);
	this->setName("Barbarian");
	this->setMaxPoints(12);
}

Barbarian::~Barbarian() {}

int Barbarian::attack() {

	int roll1;
	int roll2;

	roll1 = ((rand() % 6) + 1);
	roll2 = ((rand() % 6) + 1);
	return roll1 + roll2;

}

int Barbarian::defend(int attack) {
	
	int roll1;
	int roll2;
	int defense;
	int damage;

	//roll dice
	roll1 = ((rand() % 6) + 1);
	roll2 = ((rand() % 6) + 1);
	//get total for defense
	defense = roll1 + roll2;
	
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






