//#include<iostream>
//using namespace std;
//#include<string>
//
////类对象作为类的一个成员
//
////手机类
//class Phone
//{
//public:
//
//	Phone(string pName)
//	{
//		cout << "Phone的构造函数调用" << endl;
//		m_PName = pName;
//	}
//
//	~Phone()
//	{
//		cout << "Phone的析构函数调用" << endl;
//	}
//
//	//手机品牌名称
//	string m_PName;
//};
//
////人类
//class Person
//{
//
//public:
//
//	Person(string name, string pName):m_Name(name),m_Phone(pName)
//	{
//		cout << "Person的构造函数调用" << endl;
//	}
//
//	~Person()
//	{
//		cout << "Person的析构函数调用" << endl;
//	}
//
//	//姓名
//	string m_Name;
//	//手机
//	Phone m_Phone;
//
//};
//
////当其他类对象作为本类成员，构造时候先构造类对象，再构造自身
////析构的顺序则与构造相反
//
//void test03()
//{
//	Person p("张三", "苹果MAX");
//
//	cout << p.m_Name << "拿着:" << p.m_Phone.m_PName << endl;
//}
//
//int main7()
//{
//	test03();
//
//
//
//
//
//	system("pause");
//	return 0;
//}