#pragma once
#include <ostream>
#include "Node.h"

class LinkedList {
	Node* head;

	void recursePrint(Node*);

public:
	LinkedList();
	void add(int);
	void print();
	void printReverse();

};

