//#include<iostream>
//using namespace std;
//
////继承中的构造和析构顺序
//class Base
//{
//public:
//	Base()
//	{
//		cout << "Base的构造函数！" << endl;
//	}
//
//	~Base()
//	{
//		cout << "Base的析构函数！" << endl;
//	}
//
//
//};
//
//class Son :public Base
//{
//public:
//	Son()
//	{
//		cout << "Son的构造函数！" << endl;
//	}
//
//	~Son()
//	{
//		cout << "Son的析构函数！" << endl;
//	}
//
//};
//
//void test01()
//{
//	//Base b1;
//	
//	//继承中的构造和析构顺序如下：
//	//先构造父类，再构造子类，析构的顺序和构造的顺序相反
//	Son s1;
//
//}
//
//int main()
//{
//
//	/*int shuzu[][2] = { {1,2},{3,4} };在二维数组中，{ { }  }里面的中括号代表一行，可以是缺省的
//	cout << **shuzu << endl;*/
//
//	test01();
//
//
//
//
//	system("pause");
//	return 0;
//}