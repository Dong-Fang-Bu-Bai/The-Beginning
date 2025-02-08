#include<iostream>
using namespace std;


int main8()
{

//1.整型
	int a = 0;
	cout << "请给整型变量a赋值\n";
	cin >> a;
	cout << "整型变量a=" << a << endl;
//2.浮点型
	float b = 6.98f;
	cout << "请为浮点型变量b赋值" << endl;
	cin >> b;
	cout << "浮点型变量b=" << b << endl;
//3.字符型
	char ch = 'a';
	cout << "请为字符型变量ch赋值" << endl;
	cin >> ch;
	cout << "字符型变量ch=" << ch << endl;
//4.字符串型
	string str = "hello";
	cout << "请给字符串str赋值" << endl;
	cin >> str;
	cout << "字符串str=" << str << endl;
//5.布尔数据类型
	bool flag = true;
	cout << "请为bool数据类型变量flag赋值" << endl;
	cin >> flag;//bool类型，只要非零都代表真（绝对值要大于1才行）
	cout << "bool型数据flag=" << flag << endl;



system("pause");
	return 0;





}