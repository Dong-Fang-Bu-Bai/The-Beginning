#include<iostream>
using namespace std;

//函数重载的注意事项
//1.引用作为重载的条件
void fun(int &a)//int &a=10;不合法
{
	cout << "func(int &a)的调用" << endl;
}

void fun( const int& a)//const int &a=10;合法
{
	cout << "func(const int &a)的调用" << endl;
}

//2.函数重载碰到默认参数 ==>  《编译器的疑惑》
void func2(int a,int b=10)
{
	cout << "func2(int a,int b=10)的调用" << endl;
}


void func2(int a)
{
	cout << "func2(int a)的调用" << endl;
}






int main4()
{
	/*int a = 10;

	fun(a);*/

	//fun(10);

	//《编译器的疑惑》
	func2(10);
		//当函数重载碰到默认参数，出现二义性，报错，尽量避免这种情况


	system("pause");
	return 0;
}