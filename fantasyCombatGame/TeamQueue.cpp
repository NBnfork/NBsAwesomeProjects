/***************************************************************************
 * Description: The TeamQueue is a simple linked list that
 * will manage the teams during tournament play. It will contain a pointer
 * to each Character obj.
 **************************************************************************/
#include "TeamQueue.hpp"
#include <string>
#include <iostream>

using std::string;

TeamQueue::TeamQueue() {
	this->head = nullptr;
}
// delete all memory used by the queNodes
TeamQueue::~TeamQueue() {

	if(!isEmpty())
	{
		QueueNode *deleter = head;
		while (deleter->next);
			QueueNode *garbage = deleter;
			deleter = deleter->next;
			delete garbage;
		}
}


bool TeamQueue::isEmpty() {
	if(head == nullptr)
		return true;
	else
		return false;
}

void TeamQueue::addBack(Character* character1) {
	if (isEmpty()) {
		head = new QueueNode(character1, nullptr);
	}
	else {
		//make traverser to find end of queue
		QueueNode *traverser = head;
		while (traverser->next) {
			traverser = traverser->next;
		}
		traverser->next = new QueueNode(character1, nullptr);
	}
}

Character* TeamQueue::getFront() {
	return head->character;
}

void TeamQueue::removeFront() {

	if (head->next == nullptr){

		delete head;
		head = nullptr;
		//for testing
		std::cout << "your team has no members" << std::endl;
	}
	else{
		//make deleteMe
		QueueNode* deleteMe = head;
		//next in line becomes head
		// move head
		head = head->next;
		delete deleteMe;

	}
}
/*for testing purposes only
void TeamQueue::printQueue() {

	QueueNode *printer = head;
	std::cout << "Current team available: ";
	while (printer){
		std::cout << printer->character->getUserName() << "  ";
		printer = printer->next;
	}

	std::cout << std::endl;
}
*/
bool TeamQueue::onlyOne() {
	if ((head != nullptr) && (head->next == nullptr)) {
		return true;
	}
	else {
		return false;
	}
}

//needed to be ready to play a new game
void TeamQueue::clearQueue() {
	while(head){
		//make deleteMe
		QueueNode* deleteMe = head;
		//next in line becomes head
		// move head
		delete deleteMe->character;
		head = head->next;
		delete deleteMe;
	}
}



