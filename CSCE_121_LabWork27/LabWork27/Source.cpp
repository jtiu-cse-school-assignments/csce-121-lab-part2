#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
	LinkedList ll;
	int num = 0;
	// Input values until a negative number is entered
	while (num>=0) {
		cout << "Enter Number: ";
		cin >> num;
		ll.add(num);
	}
	ll.print();
	ll.printReverse();
	//system("pause");
}