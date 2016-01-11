//============================================================================
// Name        : Lazy_init.cpp
// Author      : Geza Husi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Class{
	int elem = 0;
	bool init;

	int elem_storage;

public:
	Class(int x){
		init = false;
		elem_storage = x;
		cout<<"In constructor, elem is not initialized, elem = " << elem <<endl;
	}
	int getelem(){
		if(init){
			return elem;
		}
		else{
			elem = elem_storage*10; //Assume this operation needs lots of calculation...
			cout<< endl <<"elem is initialized now!" << endl;
			init = true;
			return elem;
		}
	}

};



int main() {

	Class *c = new Class(5);
	cout << "elem: " <<  c->getelem() << endl;
	cout << "elem: " <<  c->getelem() << endl;

	return 0;
}
