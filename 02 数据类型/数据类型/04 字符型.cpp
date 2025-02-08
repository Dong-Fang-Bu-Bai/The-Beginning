#include<iostream>
using namespace std;


int main4()
{

//1.字符型变量创建方式
	char ch='A';
cout << "ch=" << ch<< endl;

//2.char字符型变量所占内存	为1字节
cout << "char字符型变量所占内存=" << sizeof(ch) << endl;

//3.字符型变量常见错误
//不能用双引号
//创建字符型变量，单引号内只能有一个字符


//4.字符型变量对应ASCII编码
cout << (int)ch << endl;
//也可以这样写:cout << (int)'a' << endl;
//a - 97
//A - 65

if (ch < 'a')//可以直接比较字符型变量的大小（本质是整型）
{
	cout << "haha" << endl;
}

system("pause");
return 0;



}