// Header file for BlueMen Class
// Created by noah2017 on 10/30/17.
//

#ifndef PROJECT3_BLUEMEN_HPP
#define PROJECT3_BLUEMEN_HPP


#include "Character.hpp"

class BlueMen : public Character{
//all variables are inherited
public:
	BlueMen();
	~BlueMen();
	virtual int attack();
	virtual int defend(int);
};



#endif //PROJECT3_BLUEMEN_HPP
