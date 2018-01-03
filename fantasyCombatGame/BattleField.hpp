//header file for BattleField class
// Created by noah2017 on 10/29/17.

#ifndef BATTLEFIELD_HPP
#define BATTLEFIELD_HPP


#include "Character.hpp"
#include "LoserStack.hpp"

enum ChType {BARBARIAN = 1, VAMPIRE, BLUEMEN, MEDUSA, HARRYPOTTER};

class BattleField {
private:
	Character* ch1;
	Character* ch2;
	int rounds; //for display
public:
	BattleField(Character*, Character*);
	int fight(LoserStack*);
};


#endif //BATTTLEFIELD_HPP
