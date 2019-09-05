#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}
LinkedList::LinkedList(string name) : 
	head(nullptr), tail(nullptr), name(name) {}

// Define destructor

void LinkedList::setName(string name) {
	this->name = name;
}

string LinkedList::getName() const{
	return name;
}

void LinkedList::insertFront(int value) {
	Node* newNode = new Node(value);
	newNode->next = head; // attach to list
	head = newNode;
	if (tail == nullptr) { // empty list
		tail = newNode; // only node is both head and tail
	}
}

void LinkedList::insertBack(int value) {
	Node* newNode = new Node(value);
	if (tail != nullptr)
		tail->next = newNode; // attach to list
	tail = newNode;
	if (head == nullptr) { // empty list
		head = newNode; // only node is both head and tail
	}
}

// Define
void LinkedList::clear() {
// Traverse list and delete nodes as you encounter them.
//  Warning: always maintain a valid pointer to the next
//   item in the list to be deleted. It may not be available
//    after you delete.
// Can be done in ~6 lines of code excluding {}
// What does head point to when you are done?
// What should it point to? 
//    (i.e. What does head point to in an empty list)
    Node* current = this->head;
    while(current != nullptr){
        Node* delNode;
        delNode = current;
        current = current->next;
        this->head = nullptr;
        
        delete delNode;
    }
}

void LinkedList::print() const {
	print(cout);
}

void LinkedList::print(ostream& os) const {
	os << this;
}

void LinkedList::printReverse() const {
	printReverse(cout);
}

void LinkedList::printReverse(ostream& os) const {
	os << this->name << ": ";
	Node* current = this->head;
	if (current == nullptr) {
		os << "<Empty List>";
	}
	else
		recursePrint(current, os);
	os << endl;
}

void LinkedList::recursePrint(Node* node, ostream& os) const {
	if (node != nullptr) {
		recursePrint(node->next, os);
		os << node->value << " ";
	}
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	os << ll.getName() << " {";
	Node* current = ll.head;
	if (current == nullptr) {
		os << " <Empty List>";
	}
	while (current != nullptr) {
		if (current != ll.head)
			cout << ",";
		cout << " " << current->value;
		current = current->next;
	}
	cout << " }";
	return os;
}

