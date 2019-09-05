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

	ll_one.clear();
	cout << "Outputting Linked List one..." << endl;
	cout << ll_one << endl;

	//system("pause");
}