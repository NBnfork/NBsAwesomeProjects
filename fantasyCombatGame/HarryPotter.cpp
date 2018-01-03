/***************************************************************************
 * Description: The Harry Potter class is a subclass of Character. Harry
 * has all the typical characteristics, plus the ability to regenerate
 * with double his original strength pts after his first "death".
***************************************************************************/
#include "HarryPotter.hpp"
#include <iostream>

using std::cout;
using std::endl;

HarryPotter::HarryPotter() {

	this->setArmor(0);
	this->setStrengthPoints(10);
	this->setName("Harry Potter");
	this->setMaxPoints(10);
}
int HarryPotter::attack() {

	int roll1;
	int roll2;

	roll1 = ((rand() % 6) + 1);
	roll2 = ((rand() % 6) + 1);
	return roll1 + roll2;

}

int HarryPotter::defend(int attack) {

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
	if (damage < 0)
		damage = 0;

	//print damage
	cout << "Damage pts:" << damage << " (attack - defense + armor)" << endl;

	//"Hogwarts" ability to regenerate
	//check if strength - damage will be less than zero
	if (!hogwartsUsed)
		if ((this->getStrengthPoints() - damage) <= 0) {
			cout << "Did you think you just killed Harry Potter..." << endl;
			cout << "you're wrong. Harry is just getting started!" << endl;
			//He comes back from the dead with 20 strength points.
			this->setStrengthPoints(20 + damage);
			//change max points
			this->setMaxPoints(20);
			hogwartsUsed = true;
		}

	return damage;
}

HarryPotter::~HarryPotter() {

}
