#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList ll_one("Linked List one");
    int num = 0;
    for (unsigned int i = 15; i < 20; ++i) {
        ll_one.insertFront(i);
    }
    cout << ll_one << endl << endl;

    // Start insertAfter

    const int NUM = 5;
    for (unsigned int i = 0; i < NUM; ++i) {
        // get a random (valid) index in the range of the linked list
        int index = rand() % ll_one.size();
        // get a pointer to the Node at that index
        Node* n = ll_one.at(index);

        // insert a new Node after that one
        cout << "Inserting (" << i * 100 << ") after the Node at index " << index << " (value: " << n->value << ")." << endl;

        ll_one.insertAfter(n, i * 100);

        cout << ll_one << endl << endl;
    }

    // End insertAfter

    system("pause");
}