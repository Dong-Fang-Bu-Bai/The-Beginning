/*
 这道题有以下几点需要注意：
1.这道题不能用取余和整除进行运算，因为输入值为小数，很难操作
2.可以将输入值看作一个字符串，然后用for语句进行倒置输入
3。要注意的是字符串的长度是其最后一个字符所占位置加一，因为第一个字符位置为0
4.新学习读取字符串长度方法：
"             字符串名 . size ()                 "

*/
#include<iostream>
using namespace std;
int main5()
{
	string a;
	cin >> a;
	for (int i = a.size() - 1; i >= 0; cout << a[i], i--);
	
	system("pause");

	return 0;


}