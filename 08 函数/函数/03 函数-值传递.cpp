#include<iostream>
using namespace std;
//值传递
//定义函数，实现两个数字进行交换的函数
// void swap(int num1, int num2)
//{
//	cout << "交换前:" << endl;
//	cout << "num1=" << num1 << endl;
//	cout << "num2=" << num2 << endl;
//
//	int temp = num1;
//	num1 = num2;
//	num2 = temp;
//	cout << "交换后：" << endl;
//	cout << "num1=" << num1 << endl;
//	cout << "num2=" << num2 << endl;



	//return;对于不需要返回值的函数，可以不写return

//}

//int main3()
//{
//	int a = 10;
//	int b = 20;
//
//	cout << "a=" << a << endl;
//	cout << "b=" << b<< endl;
//	当我们做值传递的时候，函数的形参发生改变，但并不会影响实参
//	swap(a, b);
//
//
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//
//	值传递时，形参是修饰不了实参的
//
//
//
//
//	system("pause");
//	return 0;
//
//}