#include<iostream>
using namespace std;

int main2()
{
	int a = 2;
	int* p = &a;

	cout << &p << endl;//此时输出的是指针p的地址
	cout << p << endl;//此时输出的是指针p指向的a变量的地址
	cout << &*p << endl;//此时输出的是指针p指向的a变量的地址
	cout << *&p << endl;//此时输出的是指针p指向的a变量的地址

	//结论：  & 和  *  互为逆运算



	system("pause");
	return 0;
}