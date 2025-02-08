#include<iostream>
using namespace std;
int main2()
{

	//指针所占内存空间
	int a = 10;
	int * p = &a;//这才是真正的初始化指针变量

	//在64位操作系统中，指针占8个字节（x64)
	//在32位操作系统中，指针占4个字节（x86）
	cout << "sizeof(int *)=" << sizeof(int*) << endl;
	cout << "sizeof(int *)=" << sizeof(float*) << endl;
	cout << "sizeof(int *)=" << sizeof(double*) << endl;
	cout << "sizeof(int *)=" << sizeof(char*) << endl;


	system("pause");
	return 0;
}