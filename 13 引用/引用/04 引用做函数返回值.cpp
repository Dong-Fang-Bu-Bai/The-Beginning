#include<iostream>
using namespace std;

//引用做函数的返回值

	//1.不要返回局部变量的引用
int& test01()
{
	int a = 10;//局部变量存放在四区中的栈区
	return a;
}

	//2.函数的调用可以作为左值
int& test02()
{
	static int a = 10;//静态变量，存放在全局区，在程序结束后才释放
	return a;
}




int main4()
{
	//int& ref = test01();


	//cout << "ref=" << ref << endl;//编译器帮我们保存了第一次
	//cout << "ref=" << ref << endl;//实际上是非法操作（和指针一样）

	int& ref2 = test02();
	cout << "ref2 ="<< ref2 << endl;
	cout << "ref2 =" << ref2 << endl;


	test02() = 1000;//如果函数的返回值是引用，这个函数调用可以作为左值

	cout << "ref2 =" << ref2 << endl;
	cout << "ref2 =" << ref2 << endl;



	system("pause");
	return 0;

}


