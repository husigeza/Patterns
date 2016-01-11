//============================================================================
// Name        : Singleton.cpp
// Author      : Geza Husi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Singleton {
private:
	int elem;

	static Singleton *instance;

	Singleton(int x) : elem(x){};

public:
	static Singleton* initialize(int x){
		if(instance == NULL){
			instance = new Singleton(x);

			return instance;
		}
		else return instance;
	}

	int getelem(){return elem;};
};

Singleton* Singleton::instance = NULL;

int main() {



	Singleton *s = Singleton::initialize(5);
	cout <<"Address: " << s << endl;
	cout <<"elem: " << s->getelem() << endl;

	Singleton *p = Singleton::initialize(2);

	cout <<"Address: " << p << endl;
	cout <<"elem: " << p->getelem() << endl;

	return 0;
}
