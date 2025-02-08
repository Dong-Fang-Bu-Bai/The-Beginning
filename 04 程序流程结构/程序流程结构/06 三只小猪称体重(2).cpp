#include<iostream>
using namespace std;

 int main6()
{

	int max = 0;//先定义一个max，再根据ABC大小对max进行赋值，最后根据max的值反向输出ABC。
	int	a = 0;
	int	b = 0;
	int	c = 0;
	cout << "请输入小猪A的体重" << endl;
	cin >> a;
	cout << "请输入小猪B的体重" << endl;
	cin >> b;
	cout << "请输入小猪C的体重" << endl;
	cin >> c;
	max = (a > b ? a : b);
	max = (max > c ? max : c);
	if (a==max)
	{
		cout << "小猪A最重，体重为" << max << endl;
	}
	else if (b ==max)
	{
		cout << "小猪B最重，体重为" << max << endl;
	}
	else 
	{
		cout << "小猪C最重，体重为" << max << endl;
	}
	




















	system("pause");
	return 0;



}