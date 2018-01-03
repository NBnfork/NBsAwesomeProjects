/***************************************************************************
 * Description: The LoserStack is a simple dynamic stack that will hold the
 * losers of each battle and then give the user the option to print out the
 * names of all the characters that lost during the tournament. Large amounts
 * of code for this class are taken from C++Early Objects, 9th ed.
 * pg. 1093-1095
 * *************************************************************************/

#include <iostream>
#include "LoserStack.hpp"

using std::cout;
using std::endl;

LoserStack::LoserStack() {
	top = nullptr;
}

LoserStack::~LoserStack() {
	StackNode* garbage = top;
	while (garbage != nullptr){
		top = top->next;
		garbage->next = nullptr;

		delete garbage;
		garbage = top;
	}
}
// This function will push the fighter pointer onto the top of the stack
void LoserStack::push(Character * ch1) {
	if(top == nullptr)
		top = new StackNode(ch1, nullptr);
	else
		top = new StackNode(ch1, top);
}

void LoserStack::printStack() {

	StackNode *printer = top;
	std::cout << "Fighters lost: (most recent death first)" << std::endl;
	while(printer != nullptr){
		cout << printer->character->getName() << " " << printer->character->getUserName() << endl;
		printer = printer->next;
	}


}
//just like the destructor, but used before a replay
void LoserStack::clearStack() {
	StackNode* garbage = top;
	while (garbage != nullptr) {
		top = top->next;
		garbage->next = nullptr;
		delete garbage->character;
		delete garbage;
		garbage = top;
	}
}










