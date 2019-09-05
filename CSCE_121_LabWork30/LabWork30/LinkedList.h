#pragma once
#include <ostream>
#include <string>
#include "Node.h"

/*
For Lab 30, I need to Add:
size data member, update with each modifying funciton.
int size()
Node* at(index)
bool empty()
operator== (or some other operator)

Lab 30: students implement insertAfter(Node*) function
*/

/*
For Lab 31, I need to Add:
void insertAfter(Node*)

Lab 30: students implement insertAfter(Node*) function
*/

class LinkedList {
    Node* head;
    Node* tail;
    std::string name;
    int size_;

    void recursePrint(Node*, std::ostream&) const;
    void remove(Node* node);
    Node* find(int);

public:
    LinkedList();
    LinkedList(std::string);
    LinkedList(const LinkedList& source);
    ~LinkedList();

    void setName(std::string);
    std::string getName() const;
    
    int size() const;
    bool empty() const;

    void remove(int value);
    void clear();
    LinkedList& operator=(const LinkedList& source);

    void insertFront(int);
    void insertBack(int);
    void insertAfter(Node*, int);   // Lab 30

    Node* at(int index);

    void print() const;
    void print(std::ostream&) const;
    void printReverse() const;
    void printReverse(std::ostream&) const;

    friend std::ostream& operator<<(std::ostream&, const LinkedList&);
};