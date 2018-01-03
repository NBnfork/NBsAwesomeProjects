// Created by noah2017 on 10/30/17.
//Header file for Vampire Class

#ifndef PROJECT3_VAMPIRE_HPP
#define PROJECT3_VAMPIRE_HPP


#include "Character.hpp"

class Vampire : public Character {

//all variables are inherited
public:
	Vampire();
	~Vampire();
	virtual int attack();
	virtual int defend(int);
};


#endif //PROJECT3_VAMPIRE_HPP
