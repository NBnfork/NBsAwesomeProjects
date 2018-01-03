//header file for ADT LoserStack class

#ifndef PROJECT3_LOSERSTACK_HPP
#define PROJECT3_LOSERSTACK_HPP


#include "Character.hpp"

class LoserStack {
	struct StackNode{
		Character* character;
		StackNode* next;
		StackNode(Character* character1, StackNode* nxt)
		{
			character = character1;
			next = nxt;
		}
	};
	StackNode* top;
public:
	LoserStack();
	~LoserStack();
	void push(Character*);
	void printStack();
	void clearStack();
};


#endif //PROJECT3_LOSERSTACK_HPP
