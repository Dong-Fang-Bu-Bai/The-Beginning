//#include<iostream>
//using namespace std;
//
//
//class Person
//{
//public:
//	Person(int age)
//	{
//		m_Age = age;
//		//this指针指向的是 被调用的成员函数 所属的对象
//		this->m_Age = age;
//	}
//
//	//注意，一定要加上 & ！！！否则返回的是p2的副本，即调用了拷贝构造函数，不改变p2自身
//	Person& PersonAddAge(Person& p)
//	{
//		this->m_Age += p.m_Age;
//
//		//this是指向p2的指针，而*this指向的就是p2这个对象本体
//		return *this;
//	}
//	int m_Age;
//};
//
////1.解决名称冲突
//void test01()
//{
//	Person p1(18);
//	cout << "p1的年龄为： " << p1.m_Age << endl;
//}
////2.返回对象本身用this
//void test02()
//{
//	Person p1(10);
//
//	Person p2(10);
//
//	//链式编程思想
//	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
//	cout << "p2的年龄为：" << p2.m_Age << endl;
//
//}
//
//int main2()
//{
//	//test01();
//
//	test02();
//
//
//
//
//
//	system("pause");
//	return 0;
//}