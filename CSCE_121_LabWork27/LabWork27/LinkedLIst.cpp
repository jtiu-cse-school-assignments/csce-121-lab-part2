#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() : head(nullptr) {}

void LinkedList::add(int i) {
    
    Node* node = new Node(i);
    node->next = head;
    head = node;
}

void LinkedList::print() {
    Node* current = head;
    while( current != 0 ) {
        cout << current->value << ", ";
        current = current->next;
    }
    
    cout << endl;
}

void LinkedList::printReverse() {
}

void LinkedList::recursePrint(Node* node) {
}
