#pragma once
#include <string>
#include <ostream>

// FIX 2a
/*
	Write a predicate function object declaration where the class name is "comp_firstname". 
	 1) You can make it a nested class that is public within Person.  
	       - Access it with Person::comp_firstname()
	 2) Make it a separate class. Since this class is so closely related to the Person class,
	      you may write it in the same files where Person resides. You may also create new
		  files for it.
	       - Access it with comp_firstname()

	 The first option provides a scope and avoids a name collision with another class
	   that might be called comp_firstname. This is probably the preferred option.
	 The second option is simpler to implement and does not require the use of the scope
	   resolution operator.
*/

class Person
{
	std::string firstname;
	std::string lastname;

public:
	Person();
	Person(std::string, std::string);

	std::string getFirstname() const;
	std::string getLastname() const;

	void setFirstname(std::string);
	void setLastname(std::string);

	bool operator<(const Person&) const;

	// If you choose option 1, you can put class declaration here.

};

struct comp_firstname {
    bool operator()(const Person& a, const Person& b) const;
};

std::ostream& operator<<(std::ostream&, const Person&);


