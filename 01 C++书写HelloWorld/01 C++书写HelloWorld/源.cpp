#include<iostream>
#include<string>
using namespace std;

int main7()
{

	int a = '\101';//此时a赋值为八进制下的101
	cout << a << endl;

	int b = '\x0A';//x加两位带字母表示十六进制数
	cout << b << endl;


	cout << char('A' + 1) << endl;//字符型变量的本质是整型

	string c;
	getline(cin, c);//在使用内置函数时，需要引入string库
	cout << c;

	system("pause");
	return 0;
}