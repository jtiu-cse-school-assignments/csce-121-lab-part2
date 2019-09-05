#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() :
    head(nullptr), tail(nullptr), name(""), size_(0) {}

LinkedList::LinkedList(string name) : 
    head(nullptr), tail(nullptr), name(name), size_(0) {}

LinkedList::LinkedList(const LinkedList& source) {
    Node* current = source.head;
    while (current != nullptr) {
        this->insertBack(current->value);
        current = current->next;
    }
    this->name = source.name;
    this->size_ = source.size_;
}

LinkedList::~LinkedList() {
    this->clear();
}

void LinkedList::setName(string name) {
    this->name = name;
}

string LinkedList::getName() const {
    return name;
}

int LinkedList::size() const {
    return this->size_;
}

bool LinkedList::empty() const {
    return (this->size_ == 0);
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
    size_ = 0;
}

void LinkedList::remove(Node* removeNode) {
    Node* current = this->head;
    // traverse list and stop at the node before the one we
    //   need to delete. If we stop at the node we need to remove
    //   we can't access the previous node to connect it to the
    //   node after the one we remove
    while (current != nullptr && current->next != removeNode)
        current = current->next;
    // current points to the node before the one to remove
    if (current != nullptr) {
        --size_;
        current->next = removeNode->next;
    }
    delete removeNode;
}

void LinkedList::remove(int value) {
    Node* removeNode = find(value);
    remove(removeNode);
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
    // 1. Don't self assign
    // 2. Delete old data
    // 3. Allocate new data
    // 4. Copy from source
    if (this != &source) {
        this->clear();
        Node* current = source.head;
        while (current != nullptr) {
            this->insertBack(current->value);
            current = current->next;
        }
        this->size_ = source.size_;
    }
    return *this;
}

void LinkedList::insertFront(int value) {
    Node* newNode = new Node(value);
    newNode->next = head; // attach to list
    head = newNode;
    if (tail == nullptr) { // empty list
        tail = newNode; // only node is both head and tail
    }
    ++size_;
}

void LinkedList::insertBack(int value) {
    Node* newNode = new Node(value);
    if (tail != nullptr)
        tail->next = newNode; // attach to list
    tail = newNode;
    if (head == nullptr) { // empty list
        head = newNode; // only node is both head and tail
    }
    ++size_;
}

// FIXME: Lab 30
// Implement insertAfter which will find the Node n in the linked list and
// create a new Node with the given value to insert after it.
// If the Node is not found, insert at the end of the linked list.
void LinkedList::insertAfter(Node* n, int value) {
    Node* newNode = new Node(value);
    if(n->next != 0) {
        newNode->next = n->next;
        n->next = newNode;
    }
    else if (n->next == 0){
        tail = newNode;
    }
    ++size_;
}

Node* LinkedList::at(int index) {
    Node* current = this->head;
    int i = 0;
    while (current != nullptr && i < index) {
        current = current->next;
        ++i;
    }
    return current;
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
    os << this->name << " (size " << this->size() << "): {";
    Node* current = this->head;
    recursePrint(current, os);
    os << "}" << endl << endl;
}

void LinkedList::recursePrint(Node* node, ostream& os) const {
    if (node != nullptr) {
        recursePrint(node->next, os);
        os << node->value << " ";
    }
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
    os << ll.getName() << " (size " << ll.size() << "): {";
    Node* current = ll.head;
    while (current != nullptr) {
        if (current != ll.head)
            cout << ",";
        cout << " " << current->value;
        current = current->next;
    }
    cout << " }";

    return os;
}