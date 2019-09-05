#pragma once
#include <ostream>
#include "Node.h"

class LinkedList {
	Node* head;
	Node* tail;
	std::string name;

	void recursePrint(Node*, std::ostream&) const;

public:
	LinkedList();
	LinkedList(std::string);
	// destrcutor declaration
    //~LinkedList();

	void setName(std::string);
	std::string getName() const;

	void insertFront(int);
	void insertBack(int);
	void clear();
	void print() const;
	void print(std::ostream&) const;
	void printReverse() const;
	void printReverse(std::ostream&) const;

	friend std::ostream& operator<<(std::ostream&, const LinkedList&);

};



