//============================================================================
// Name        : Decorator.cpp
// Author      : Geza Husi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class Class {

public:
	virtual void function() const{
		cout<<"In Class's function!" << endl;
	}
};

class Decorator : public Class{

 const Class &internalClass;
public:
	 Decorator(Class &cl) : internalClass(cl){};

	void function(){
		cout<< "Before calling function" << endl;
		internalClass.function();
		cout<<"After calling function" << endl;
	}
};



int main() {

	Class *c = new Class();
	Decorator *d = new Decorator(*c);

	d->function();

	return 0;
}
