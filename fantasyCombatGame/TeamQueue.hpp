//header file for TeamQueue Class

#ifndef TEAMQUEUE_HPP
#define TEAMQUEUE_HPP


#include "Character.hpp"

class TeamQueue {
private:
	struct QueueNode {
		Character* character;
		QueueNode* next;
		QueueNode(Character* character1, QueueNode* nxt ){
			this->character = character1;
			this->next = nxt;
		}
};
	QueueNode* head;

public:
	TeamQueue();
	~TeamQueue();
	bool isEmpty();
	bool onlyOne();
	void addBack(Character*);
	Character* getFront();
	void removeFront();
	void clearQueue();
//for testing	void printQueue();

};


#endif
