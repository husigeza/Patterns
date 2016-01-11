//============================================================================
// Name        : Composite.cpp
// Author      : Geza Husi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>


using namespace std;

class Control{
public:
	virtual void write() = 0;
};

class ControlItem1 : public Control{
	string s;
public:
	ControlItem1(string s_param) : s(s_param){};
	void write() override{
		cout <<"My element is a string: " << s << endl;
	}
};

class ControlItem2 : public Control{
	int x;
public:
	ControlItem2(int x_param) : x(x_param){};
	void write() override{
		cout <<"My element is a number: " << x << endl;
	}
};

class ControlComposite : public Control{
	vector<Control*> control_list;
public:

	void add_to_composite(Control *cont){
		control_list.push_back(cont);
	}

	void write() override{
		cout << "Printing out elements: " << endl;
		for(auto elem : control_list){
			elem->write();
		}

	}
};


int main() {

	ControlComposite *cc = new ControlComposite();
	cc->add_to_composite(new ControlItem2(1));
	cc->add_to_composite(new ControlItem2(3));
	cc->add_to_composite(new ControlItem2(2));

	cc->add_to_composite(new ControlItem1("egy"));
	cc->add_to_composite(new ControlItem1("ketto"));
	cc->add_to_composite(new ControlItem1("harom"));

	cc->write();


	return 0;
}
