//============================================================================
// Name        : Facory.cpp
// Author      : Geza Husi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class Product
{
	int elem;

public:
	Product(int x):elem(x) {};

	int getelem(){return elem;};
};

class Creator
{

public:
	virtual Product* factoryMethod( int x) = 0;

};

class ConcreteCreator : Creator
{

public:
	Product* factoryMethod(int x) override{
		Product *p = new Product(x);
		return p;
	}
};


int main() {

	ConcreteCreator *c = new ConcreteCreator();
	Product *p = c->factoryMethod(6);


	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	cout << "product x = "<<p->getelem() << endl;
	return 0;
}
