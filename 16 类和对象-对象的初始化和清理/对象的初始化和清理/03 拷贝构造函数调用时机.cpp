#include<iostream>
using namespace std;



class Person
{
public:
	Person()
	{
		cout << "Person默认构造函数调用" << endl;
	}

	Person(int age)
	{
		cout << "Person有参构造函数调用" << endl;
		m_Age = age;
	}

	Person(const Person& p)
	{
		cout << "Person拷贝构造函数调用" << endl;
		m_Age = p.m_Age;
	}

	~Person()
	{
		cout << "Person析构函数调用" << endl;
	}


	int m_Age;
};

//拷贝构造函数调用时间

//1.使用一个已经创建完毕的对象来初始化一个新对象
void test01()
{
	Person p1(20);
	Person p2(p1);

	cout << "p2的年龄为：" << p2.m_Age << endl;
}
//2.值传递的方式给函数参数传值

void doWork(Person p)
{
	//此时在内部改变值
	//如： p.m_Age=1000;
	//并不会改编外面的p的值
	//因为值传递的本质为拷贝构造，相当于建立了一个副本
}

void test02()
{
	Person p;
	doWork(p);

}


//3.值方式返回局部对象
//在目前C++中已经优化，不再调用拷贝构造函数进行赋值，因此地址是一样的
Person doWork2()
{
	Person p1;
	cout << (int*)&p1 << endl;
	return p1;
}

void test03()
{
	Person p = doWork2();
	cout << (int*)&p << endl;
}

int main3()
{
	//test01();

	//test02();

	test03();

	system("pause");
	return 0;
}