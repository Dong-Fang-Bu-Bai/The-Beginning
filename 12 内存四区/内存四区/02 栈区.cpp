#include<iostream>
using namespace std;

//栈区数据注意事项  ----  不要试图返回局部变量的地址
//栈区的数据由编译器管理、开辟和释放

int* func1(int b)//形参数据也会放在栈区
{
	b = 100;
	int a = 10;//局部变量   存放在栈区，栈区的数据在函数执行完后自动释放
	return &a;//返回局部变量地址
}

int main2()
{
	//接受func函数的返回值
	int* p = func1(1);
	//出去了局部变量所在的函数体，再调用地址就属于非法操作了
	cout << *p <<*p<< endl;//第一次可以打印正确的数字，是因为编译器做了保留
	cout << *p << endl;//第二次就不给你机会了(x64是给你面子),而如果想返回形参地址，那谁也不行

	system("pause");
	return 0;
}