#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
	LinkedList ll_one("Linked List one");
	int num = 0;
	for (unsigned int i = 15; i < 20; ++i) {
		ll_one.insertFront(i);
	}
	cout << "Outputting Linked List one..." << endl;
	cout << ll_one << endl;
	LinkedList ll_two("Linked List two");
	cout << "Outputting Linked List two..." << endl;
	cout << ll_two << endl;
	cout << endl;

	cout << "Assigning List one to List two" << endl;
	ll_two = ll_one;
	cout << "Outputting Linked List one..." << endl;
	cout << ll_one << endl;
	cout << "Outputting Linked List two..." << endl;
	cout << ll_two << endl;
	cout << endl;

	cout << "Inserting 55 to the front Linked List two..." << endl;
	ll_two.insertFront(55);
	cout << "Outputting Linked List one..." << endl;
	cout << ll_one << endl;
	cout << "Outputting Linked List two..." << endl;
	cout << ll_two << endl;
	cout << endl;

	cout << "Removing 18 from Linked List one..." << endl;
	ll_one.remove(18);
	cout << "Outputting Linked List one..." << endl;
	cout << ll_one << endl;
	cout << "Outputting Linked List two..." << endl;
	cout << ll_two << endl;
	cout << endl;

	// End copy Assignment

	//system("pause");
}