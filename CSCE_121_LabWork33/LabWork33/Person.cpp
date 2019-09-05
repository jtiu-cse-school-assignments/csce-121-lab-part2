#include <string>
#include <ostream>
#include "Person.h"
using namespace std;

// Fix 2b
/*
	 Write the definitions for any functions in the
	   predicate function object class: comp_firstname
		- If you do option 1, you'll need to apply
			the scope resolution operator twice.
*/


// Default Constructor
Person::Person() : firstname(""), lastname("") {}

Person::Person(string firstname, string lastname) :
	firstname(firstname), lastname(lastname) {}

// Accessor Functions
string Person::getFirstname() const {
	return firstname;
}

string Person::getLastname() const {
	return lastname;
}

void Person::setFirstname(string firstname) {
	this->firstname = firstname;
}

void Person::setLastname(string lastname) {
	this->lastname = lastname;
}


// Required for default sorting in an STL container
bool Person::operator<(const Person& p) const {
	if (lastname < p.lastname) 
		return true;

	if (lastname == p.lastname) {
		if (firstname < p.firstname)
			return true;
	}

	return false;
}

ostream& operator<<(ostream& os, const Person& p) {
	os << p.getFirstname() << " " << p.getLastname();
	return os;
}

bool comp_firstname::operator()(const Person& a, const Person& b) const {

    return a.getFirstname() < b.getFirstname();
}







