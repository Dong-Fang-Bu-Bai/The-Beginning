#include<iostream>
using namespace std;

//模板局限性
//模板并不是万能的，有些特定数据类型，需要用具体化方法做特殊实现

class Person
{
public:

	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string getname()
	{
		return m_Name;
	}

	int getAge()
	{
		return m_Age;
	}

private:

	//姓名
	string m_Name;
	//年龄
	int m_Age;
};

//对比两个数据是否相等的函数
template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//利用具体化的Person版本实现代码，具体化优先调用
template<> bool myCompare(Person& a, Person& b)
{
	if (a.getname() == b.getname() && a.getAge() == b.getAge())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void test02()
{
	Person p1("Tom", 10);
	Person p2("Tom", 11);

	bool ret = myCompare(p1, p2);
	if (ret)
	{
		cout << " p1 == p2 " << endl;
	}
	else
	{
		cout << " p1 != p2 " << endl;
	}
}
	
	
void test01()
{

	int a = 10;
	int b = 20;

	bool ret = myCompare(a, b);

	if (ret)
	{
		cout << " a == b " << endl;
	}
	else
	{
		cout << " a != b " << endl;
	}

}
	


int main()
{

	test01();

	test02();




	system("pause");
	return 0;
}