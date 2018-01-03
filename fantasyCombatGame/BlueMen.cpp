/***************************************************************************
 * Description: The BlueMen are a subclass of Character with an overidden
 * attack and defend function. The Blue Men are actually three small men
 * with 4 strength points each. As they die the defense ability of the Blue
 * Men decreases.
***************************************************************************/
#include <cstdlib>
#include <iostream>
#include "BlueMen.hpp"

using std::cout;
using std::endl;

BlueMen::BlueMen() {

	this->setArmor(3);
	this->setStrengthPoints(12);
	this->setName("Blue Men");
	this->setMaxPoints(12);
}

int BlueMen::attack() {

	int roll1;
	int roll2;

	roll1 = ((rand() % 10) + 1);
	roll2 = ((rand() % 10) + 1);
	return roll1 + roll2;
}

int BlueMen::defend(int attack) {

	int roll1;
	int roll2;
	int roll3;
	int defense;
	int damage;

	//Special "Mob" ability
	if(this-> getStrengthPoints() >= 9)
	{
		//roll dice
		roll1 = ((rand() % 6) + 1);
		roll2 = ((rand() % 6) + 1);
		roll3 = ((rand() % 6) + 1);
	}
	else if(this-> getStrengthPoints() <= 4)
	{
		cout << "One Blue Man is left. Defense-66%." << endl;
		roll1 = ((rand() % 6) + 1);
		roll2 = 0;
		roll3 = 0;
	}
	else
	{
		cout << "Only two Blue Men are still fighting. Defense-33%." << endl;
		roll1 = ((rand() % 6) + 1);
		roll2 = ((rand() % 6) + 1);
		roll3 = 0;

	}

	//get total for defense
	defense = roll1 + roll2 + roll3;

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

BlueMen::~BlueMen() {

}
