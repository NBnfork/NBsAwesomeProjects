//header file for Character Class.
// Created by noah2017 on 10/29/17.

#ifndef PROJECT3_CHARACTER_HPP
#define PROJECT3_CHARACTER_HPP

#include <string>

class Character {
protected:
	std::string name;
	std::string userName;
	int armor;
	int strengthPoints;
	int maxPoints;

public:
	Character();
	virtual ~Character() =0;
	virtual int attack() =0;
	virtual int defend(int) =0;
	//added for tournament play
	void setMaxPoints(int);
	void setUserName(std::string);
	void setName(std::string);
	void setArmor(int);
	void setStrengthPoints(int);
	int getMaxPoints();
	std:: string getUserName();
	std:: string getName();
	int getArmor();
	int getStrengthPoints();
	void recover();

};


#endif //PROJECT3_CHARACTER_HPP
