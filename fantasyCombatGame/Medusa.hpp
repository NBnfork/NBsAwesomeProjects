//
// Created by noah2017 on 10/30/17.
//

#ifndef PROJECT3_MEDUSA_HPP
#define PROJECT3_MEDUSA_HPP

#include "Character.hpp"

class Medusa : public Character{
	//all variables are inherited
public:
	Medusa();
	~Medusa();
	virtual int attack();
	virtual int defend(int);
};



#endif //PROJECT3_MEDUSA_HPP
