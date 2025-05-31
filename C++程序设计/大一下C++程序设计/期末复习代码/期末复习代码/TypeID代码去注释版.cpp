#include<iostream>
#include<typeinfo>
#include<vector>
using namespace std;

class Base
{
public:
	virtual void speak() = 0;

	
};

class A :public Base
{
public:
	void speak()override
	{
		cout << "A is here" << endl;
	}
};

class B :public Base
{
public:
	void speak()override
	{
		cout << "B is here" << endl;
	}
};































