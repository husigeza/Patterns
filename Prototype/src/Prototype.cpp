//============================================================================
// Name        : Prototype.cpp
// Author      : Geza Husi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Item{
	int elem;
public:
	Item(){;};
	Item(int x):elem(x){};
	void setelem(int x){elem = x;};
	int getelem(){return elem;};
};


class Prototype{
	Item item;

public:

	Prototype(int x){
		item.setelem(x);
		cout << "Prototype address: " << &item <<endl;
	}

	Item Clone(){
		return item;
	}
};


int main() {

	Prototype *p1 = new Prototype(2);
	Prototype *p2 = new Prototype(5);

	Item i1 = p1->Clone();
	Item i2 = p1->Clone();
	Item i3 = p1->Clone();

	Item i4 = p2->Clone();
	Item i5 = p2->Clone();
	Item i6 = p2->Clone();

	cout << i1.getelem() << "  Address: " << &i1 <<endl;
	cout << i2.getelem() << "  Address: " << &i2 <<endl;
	cout << i3.getelem() << "  Address: " << &i3 <<endl;

	cout << i4.getelem() << "  Address: " << &i4 <<endl;
	cout << i5.getelem() << "  Address: " << &i5 <<endl;
	cout << i6.getelem() << "  Address: " << &i6 <<endl;



	return 0;
}
