/***************************************************************************
 * Description: The Character Class is an abstract class that will be used
 * to create the different types of characters.
***************************************************************************/

#include "Character.hpp"
#include <iostream>

Character::Character() {}

Character::~Character() {}

void Character::setArmor(int a) {
	this->armor = a;
}

void Character::setStrengthPoints(int sp) {
	this->strengthPoints = sp;
}

void Character::setUserName(std::string userN) {
	this->userName = userN;
}

void Character::setName(std::string n) {
	this->name = n;
}

void Character::setMaxPoints(int max) {
	this->maxPoints = max;
}

int Character::getArmor() {
	return armor;
}

int Character::getStrengthPoints() {
	return strengthPoints;
}

std::string Character::getName() {
	return name;
}

std::string Character::getUserName() {
	return userName;
}

/***************************************************************************
 * Description: The recover function is used after a battle to add pts back
 * to the winning players strength.
***************************************************************************/
void Character::recover() {
//strength points will increase by 50% until max reached
	int pointsAdded = strengthPoints * .5; //some rounding down will happen

	setStrengthPoints(strengthPoints += pointsAdded);
	if (strengthPoints > maxPoints)
		setStrengthPoints(maxPoints);
	//print recovery info
	std::cout << name << " " << userName << " will recover some strength before the next fight." << std::endl;
	std::cout << "Strength Points +" << pointsAdded << std::endl;
}






