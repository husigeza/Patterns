//============================================================================
// Name        : Visitor.cpp
// Author      : Geza Husi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

class Entity;

class Visitor{

public:
	virtual void visit(Entity & entity) = 0;

};

class EatVisitor : public Visitor{

public:
	void visit(Entity & entity) override{
		cout  <<"Nyam nyam nyam..." << endl;
	}

};

class DrinkVisitor : public Visitor{

public:
	void visit(Entity & entity) override{
		cout <<"Glugy glugy glugy..." << endl;
	}
};


class Entity{
protected:
	 string name;
public:
	 Entity(string x) : name(x){};

	void setname(string x){name = x;};
	string getname(){return name;};

	virtual void accept(Visitor &visitor) = 0;


};


class Human : public Entity {
	string special_ability;
public:
	Human(string name, string y) : Entity(name){
		special_ability = y;
	}
	string getspecial_ability(){
		return special_ability;
	}
	void accept(Visitor &visitor) override{
		visitor.visit(*this);
	}
};

class Animal : public Entity {
	int legs;
public:
	Animal(string name, int y) : Entity(name){
		legs = y;
	}
	int getlegs(){
		return legs;
	}
	void accept(Visitor &visitor) override{
		visitor.visit(*this);
	}


};



int main() {


	EatVisitor *ev = new EatVisitor;
	DrinkVisitor *dv = new DrinkVisitor;

	Human h("Balazska","alvas");
	Animal a("Lajka kutya",4);

	h.accept(*ev);
	a.accept(*dv);

	return 0;
}
