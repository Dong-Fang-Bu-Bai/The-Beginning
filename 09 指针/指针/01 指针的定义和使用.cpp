#include<iostream>
using namespace std;
int main1()
{
	// 指 针 就 是 地 址
	


	//1.定义指针  整型的变量要对应整型的指针，以此类推
	int a = 10;
	//指针定义的语法：  数据类型 * 指针变量名；
	int* p;
	//让指针记录a的地址，建立关系
	p = &a;
	cout << "a的地址为：" << &a << endl;
	cout << "指针p为：" << p << endl;
	cout << *p << endl;
	//2.使用指针
	//可以通过解引用的方式来找到中指针指向的内存
	//指针前加 * 代表解引用，找到指针指向的内存中的数据
	*p = 1000;
	cout << "a=" << a << endl;
	cout << "*p=" << *p << endl;


	system("pause");
	return 0;
}