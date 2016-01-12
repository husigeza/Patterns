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
	 void function(int x,int y){
		cout<<"In Class's function, x = "<< x <<" y = "<< y << endl;
	}
};

class Facade : public Class{


public:
	Facade(){;};

	void function_wrapper(int x){
		cout<< "Before calling function" << endl;
		int y = 10;
		this->function(x,y);
		cout<<"After calling function" << endl;
	}
};


int main() {

	Facade *f = new Facade();

	f->function_wrapper(5);

	return 0;
}
