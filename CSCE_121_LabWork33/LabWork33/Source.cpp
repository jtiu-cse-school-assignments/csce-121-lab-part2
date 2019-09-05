#include <iostream>
#include <vector>
#include <algorithm>
#include "Person.h"
using namespace std;


void print(const vector<Person>& items) {
	for (int i = 0; i < items.size(); ++i) {
		cout << items.at(i) << endl;
	}
}

int main() {
	vector<Person> v;
	v.push_back(Person("John", "Doe"));
	v.push_back(Person("Jane", "Doe"));
	v.push_back(Person("Jack", "Black"));

	cout << "Unsorted: " << endl;
	print(v);
	cout << endl;

	// FIX 1: Uncomment the following sort
	sort(v.begin(), v.end());
	cout << "Sorted default (lastname):" << endl;
	print(v);
	cout << endl;

	// FIX 2c
	// Uncomment one of the following sort options after you create a 
  //  Predicate Function Object. Which one will depend on 
  //  where you declare the class/struct.
  
	//sort(v.begin(), v.end(), Person::comp_firstname());
	sort(v.begin(), v.end(), comp_firstname());
	cout << "Sorted firstname:" << endl;
	print(v);
	//system("pause");
}