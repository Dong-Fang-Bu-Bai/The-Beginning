#include<iostream>
using namespace std;

int main2()
{





     //整型：short（2） int（4） long（4） long long（8）
	//可以用sizeof求出数据类型所占内存大小
	//语法：sizeeof（数据类型或变量）

	short num1 = 10;
	cout << "short所占内存为" << sizeof(short) << endl;
	cout << "short所占内存为" << sizeof(num1) << endl;
	


	//整型大小比较
	//short<int<=long<=long long

	system("pause");

	return 0;
}