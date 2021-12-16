/** @file DynamicDispatch.cpp
 *  @brief File shows example of dynamic dispatch
 *
 *  LO3 Dynamic dispatch in this program is used to correctly pick the
 *  appropriate function when iterating through the getinfo() function
 *
 *  L05. Relationship between OO inheritance and subtyping:
 *  Subtyping refers to compatibility of interfaces 
 *  Inheritance refers to reuse of implementations
 *  Inheritance is usually used with subtyping when there are abstract 
 *  datatypes in a hierarchy of classes. Although they usually are used together
 *  they don't need each other.
 *
 *  @author Nicholas Cotugno
 *  @bug No known bugs.
 */

#include <iostream>
#include <list>
using namespace std;

class ColorBlind { //base class
public: //access modifier
	virtual void getInfo() {
		cout << "Color blind people can only see some colors" << endl;
	}
};
class notColorBlind:public ColorBlind {// derived class
	void getInfo() {
		cout << "People that are not color blind can see all colors" << endl;
	}
};

int main() {
	
	ColorBlind y;
	notColorBlind n;

	//list of person pointers 
	list<ColorBlind*>person;
	person.push_back(&y);
	person.push_back(&n);

	for (ColorBlind* usrPtr : person)
		usrPtr->getInfo(); //invokes function that dynamically dispatches appropiate function

	return 0;
}
