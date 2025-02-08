#include<iostream>
using namespace std;

//空指针调用成员函数

class Person
{
public:

	void showClassName()
	{
		cout << "this is Person class" << endl;
	}

	void showPersonAge()
	{
		//报错原因是因为传入的指针是为NULL（nullptr）

		if (this == NULL)//防止别人瞎传指针
		{
			return;
		}

		cout << "age = " <<this-> m_Age << endl;
	}

	int m_Age;
};

void test01()
{
	Person* p = NULL;

	//p->showClassName();

	p->showPersonAge();
}

int main3()
{

	test01();




	system("pause");
	return 0;
}