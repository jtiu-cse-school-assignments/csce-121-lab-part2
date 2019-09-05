#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}
LinkedList::LinkedList(string name) : 
	head(nullptr), tail(nullptr), name(name) {}
  
// Implement Copy Assignment here
LinkedList& LinkedList::operator=(const LinkedList& source) {
    Node* current = source.head;
    if(this != &source) {
        this->clear();
        while (current != nullptr) {
            this->insertBack(current->value);
            current = current->next;
        }
    }
    
    return *this;
}

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

// finds and returns first occurence of value in the list
Node* LinkedList::find(int value) {
	Node* current = this->head;
	while (current != nullptr) {
		if (current->value == value)
			return current;
		current = current->next;
	}
	return nullptr; 
	// we could also throw an exception but returning
	//  nullptr is a standard way to indicate the
	//  element with the desired pointer was not found
}

void LinkedList::clear() {
	Node* current = head;
	while (current != nullptr) {
		Node* deleteNode = current;
		current = current->next;
		delete deleteNode;
	}
	head = nullptr;
  tail = nullptr;
}

void LinkedList::remove(Node* removeNode) {
	Node* current = this->head;
	// traverse list and stop and node before the one we
	//   need to delete. If we stop at the node we need to remove
	//   we can't access the previous node to connect it to the
	//   node after the one we remove
	while ((current != nullptr) && (current->next != removeNode))
		current = current->next;
	// current points to the node before the one to remove
	current->next = removeNode->next;
	delete removeNode;
}

void LinkedList::remove(int value) {
	Node* removeNode = find(value);
	remove(removeNode);
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

