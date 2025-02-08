#include<iostream>
using namespace std;
 int main7()
{
	//三目运算符
	//包含符号	？	与	：	
	//赋值的是变量，可以继续赋值

	//创建三个变量 a b c
	//将a和b作比较，将大的变量赋值给变量c

	int a = 10;
	int	b = 20;
	int	c = 0;

	c = (a > b ? a : b);
	cout << "c=" << c<<endl;

	//在C++中三目运算符返回的是变量，可以继续赋值
	(a > b ? a : b) = 100;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
















	system("pause");
	return 0;


}