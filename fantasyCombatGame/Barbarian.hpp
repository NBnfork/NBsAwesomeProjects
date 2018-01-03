// header file for Barbarian class
// Created by noah2017 on 10/29/17.

#ifndef PROJECT3_BARBARIAN_HPP
#define PROJECT3_BARBARIAN_HPP


#include "Character.hpp"

class Barbarian : public Character{
//all variables are inherited
public:
	Barbarian();
	~Barbarian();
	virtual int attack();
	virtual int defend(int);
};


#endif //PROJECT3_BARBARIAN_HPP
