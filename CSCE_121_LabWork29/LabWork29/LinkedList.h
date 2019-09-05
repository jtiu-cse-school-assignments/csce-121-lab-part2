#pragma once
#include <ostream>
#include "Node.h"

class LinkedList {
	Node* head;
	Node* tail;
	std::string name;

	void recursePrint(Node*, std::ostream&) const;
	void remove(Node* node);
	Node* find(int);

public:
	LinkedList();
	LinkedList(std::string);

	// Put Copy Assignment declaration here
    LinkedList& operator=(const LinkedList& source);
    

	void setName(std::string);
	std::string getName() const;

	void insertFront(int);
	void insertBack(int);
	void clear();
	void print() const;
	void print(std::ostream&) const;
	void printReverse() const;
	void printReverse(std::ostream&) const;
	void remove(int value);

	friend std::ostream& operator<<(std::ostream&, const LinkedList&);

};



