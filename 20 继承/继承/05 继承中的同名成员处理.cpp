//#include<iostream>
//using namespace std;
//
//class Base
//{
//public:
//	Base()
//	{
//		m_A = 100;
//	}
//	void func()
//	{
//		cout << "Base - func()函数调用" << endl;
//	}
//
//	void func(int a)
//	{
//		cout << "Base - func(int a)函数调用" << endl;
//	}
//
//	int m_A;
//};
//
//class Son :public  Base
//{
//public:
//
//	Son()
//	{
//		m_A = 200;
//	}
//
//	void func()
//	{
//		cout << "Son - func()调用" << endl;
//	}
//
//	int m_A;
//
//};
//
//void test01()
//{
//	Son s;
//	cout << "Son m_A=" <<s.m_A << endl;
//	//如果通过子类对象访问父类中的同名成员，需要加父类作用域
//	cout << "Base m_A=" << s.Base::m_A << endl;
//}
//
////同名成员函数处理
//void test02()
//{
//	Son s;
//
//	s.func();//直接调用 调用是子类中的同名成员
//
//	//如何调用到父类中的同名成员函数？
//	s.Base::func();
//
//	//如果子类中出现和父类同名的成员函数，子类中的同名成员会隐藏掉父类中所有的同名成员函数
//	//如果想访问到父类中被隐藏的同名成员函数，需要加作用域
//	s.Base::func(100);
//
//}
//
//int main()
//{
//	//test01();
//
//
//	test02();
//
//
//
//
//
//
//	system("pause");
//	return 0;
//}