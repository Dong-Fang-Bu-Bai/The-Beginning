#include<iostream>
using namespace std;

//打印数据的函数
void showValue(const int& val)
{
	//val = 1000;此时就不能修改了
	cout << "val=" << val << endl;
}


int main6()
{

	//常量引用
	

	int a = 10;
	//int& ref = 10; 错误 引用必须引一块合法的内存空间
	//加上const之后  编译器将代码修改  int temp=10;  const int &ref=temp;
	//const int& ref = 10; 允许
	//ref = 20;加入const后变为只读，不可以修改

	//使用场景：用来修饰形参，防止误操作

	showValue(a);

	cout << "a=" << a << endl;


	system("pause");
	return 0;
}