//============================================================================
// Name        : AbstractFactory.cpp
// Author      : Geza Husi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Entity{

protected:
	 string name;

public:
	 Entity(string x) : name(x){};

	void setname(string x){name = x;};
	string getname(){return name;};
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
};



class Shape{

protected:
	 unsigned int area;

public:
	 Shape(unsigned int x) : area(x){};

	void setarea(unsigned int x){area = x;};
	unsigned int getarea() {return area;};
};

class Polygon : public Shape {
	string color;

public:
	Polygon(unsigned int area, string y) : Shape(area) {
		color = y;
	}
	string getcolor(){
		return color;
	}
};

class Line : public Shape {
	int length;

public:
	Line(int y) : Shape(0){
		length = y;
	}
	int getlength(){
		return length;
	}
};


class AbstractFactory {

public:
	virtual Entity* CreateEntity() = 0;
	virtual Shape* CreateShape() = 0;
};

class FactoryCreator1 : AbstractFactory {

public:
	Human* CreateEntity() override{
		Human *h = new Human("Balazs", "Fly");
		return h;
	}

	Polygon* CreateShape() override{
		Polygon *p = new Polygon(10,"red");
		return p;
	}
};


class FactoryCreator2 : AbstractFactory {

public:
	Animal* CreateEntity() override{
		Animal *a = new Animal("Dog", 4);
		return a;
	}

	Line* CreateShape() override{
		Line *l = new Line(5);
		return l;
	}
};


int main() {

	FactoryCreator1 fc1;
	FactoryCreator2 fc2;

	Human *a1 = fc1.CreateEntity();
	Polygon *s1 = fc1.CreateShape();

	Animal *a2 = fc2.CreateEntity();
	Line *s2 = fc2.CreateShape();


	cout << "Creator1: " << endl;
	cout << "Human name: "<< a1->getname() << endl;
	cout << "Human special ability: "<< a1->getspecial_ability() << endl;
	cout << "Polygon area: " << s1->getarea() << endl;
	cout << "Polygon color: " << s1->getcolor() << endl << endl;

	cout << "Creator2: " << endl;
	cout << "Animal name: "<< a2->getname() << endl;
	cout << "Animal legs: "<< a2->getlegs() << endl;
	cout << "Line area: " << s2->getarea() << endl;
	cout << "Line length " << s2->getlength() << endl;

	return 0;
}
