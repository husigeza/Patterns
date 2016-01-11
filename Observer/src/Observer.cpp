//============================================================================
// Name        : Observer.cpp
// Author      : Geza Husi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Document;

class Observer {

public:
	Observer(){cout << "Address of Observer: " << this << endl;}
	void SomethingChanged(Document &doc){
		cout << "Observer is notified with address: "<< this << endl;
		cout << "Document with address: "<< &doc << " changed"<< endl;

	}
};


class Document {
	int elem;
	vector<Observer*>  observers;
public:

	Document(int x):elem(x){cout << "Address of this Document: "<< this << endl;};

	int Getelem(){return elem;};

	void Setelem(int x){
		elem = x;
		for(auto element : observers){
			element->SomethingChanged(*this);
		}
	}

	void AddObserver(Observer *obs){
		observers.push_back(obs);
	}


};

int main() {

	Observer *obs = new Observer();
	Document *doc = new Document(2);
	doc->AddObserver(obs);

	cout << "Before setting element!" << endl;
	doc->Setelem(5);
	cout << "New value: " << doc->Getelem() << endl;

	return 0;
}



