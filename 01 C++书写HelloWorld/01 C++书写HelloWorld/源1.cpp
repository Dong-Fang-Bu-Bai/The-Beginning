#include<iostream>
using namespace std;

int asignment()
{
	int a = 1;
	cout << a << endl;  
	return a;
}




int main()
{

	int a = 0;

	asignment();
	/*
	就近原则：在同一范围内变量如果重名，优先读取最近的值
	*/


	system("pause");
	return 0;


}