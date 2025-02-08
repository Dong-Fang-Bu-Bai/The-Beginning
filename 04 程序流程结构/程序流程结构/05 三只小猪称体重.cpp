#include<iostream>
using namespace std;
 int main5()
{
	int	a = 0;
	int	b = 0;
	int	c = 0;
	cout << "请输入小猪A的体重" << endl;
	cin >> a;
	cout << "请输入小猪B的体重" << endl;
	cin >> b;
	cout << "请输入小猪C的体重" << endl;
	cin >> c;
	if(a>b)
	{
		if(a>c)
		{
			cout << "小猪A体重最大" << endl;
		}
		else
		{
			cout << "小猪C体重最大" << endl;
		}
	}
	else
	{
		if(b>c)
		{
			cout << "小猪B体重最大" << endl;
		}
		else
		{
			cout << "小猪C体重最大" << endl;
		}

	}
	//当然并不严谨，没有考虑体重相等的情况，也不是很简洁！！！有待优化























	system("pause");
	return 0;



}