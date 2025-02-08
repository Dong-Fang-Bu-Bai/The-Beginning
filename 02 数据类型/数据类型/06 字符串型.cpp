#include<iostream>
using namespace std;


int main6()
{


//1.C风格字符串
	//格式：char 字符串名 []
	char str1[] = "hello world";//注意此时定义的字符串是用双引号而不是单引号
	cout <<str1<< endl;//注意cout后就不需要双引号了


//2.C++风格字符串
	string str2 = "hello world";
	cout << str2 << endl;


	system("pause");
	return 0;



}