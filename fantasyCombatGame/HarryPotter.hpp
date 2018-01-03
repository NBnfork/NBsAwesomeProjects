//
// Created by noah2017 on 10/30/17.
//

#ifndef PROJECT3_HARRYPOTTER_HPP
#define PROJECT3_HARRYPOTTER_HPP


#include "Character.hpp"

class HarryPotter : public Character{
private:
	bool hogwartsUsed = false; //special ability can only be used once.

public:
	HarryPotter();
	~HarryPotter();
	virtual int attack();
	virtual int defend(int);
};


#endif //PROJECT3_HARRYPOTTER_HPP
