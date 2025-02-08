//#include<iostream>
//using namespace std;
//
////函数调用运算符重载
//
////打印输出类
//class MyPrint
//{
//public:
//
//	//重载函数调用运算符
//	void operator()(string test)
//	{
//		cout<<test << endl;
//	}
//};
//
//class MyAdd
//{
//public:
//
//	int operator()(int num1,int num2)
//	{
//		return num1 + num2;
//	}
//};
//
//void test02()
//{
//	MyAdd myadd;
//	int ret=myadd(100, 2000);
//
//	cout << "ret = " << ret << endl;
//
//	//匿名函数对象
//	cout << MyAdd()(100, 100) << endl;
//}
//
//
//
//void MyPrint02(string test)
//{
//	cout << test << endl;
//}
//
//void test01()
//{
//	MyPrint myPrint;
//
//	myPrint("helloworld");//由于使用起来非常类似于函数调用，因此又称为仿函数
//
//	MyPrint02("hello world");
//}
//
////仿函数非常灵活，没有一个固定的写法
//
//int main()
//{
//	//test01();
//
//	test02();
//
//
//	system("pause");
//	return 0;
//}