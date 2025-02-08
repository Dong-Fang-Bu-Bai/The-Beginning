/*
这道题有以下几点需要注意：
1.可以在前一天就出发，因此算剩余时间时要先加上1440分钟，再用1440取余进行运算；
2.当路程除以时间为小数时，默认向下取整，因此需要在这种情况下加一分钟；
3.需要输出“00：00”格式的时间，因此需要判断小时和分钟是否大于10，否则要先补个0；
4.这道题要先把时间转化为分钟再进行运算，否则很难操作；
*/

#include<iostream>
using namespace std;
int main6()
{
	int s = 0;
	int v = 0;
	cin >> s;
	cin >> v;
	int t1 = s / v + 10;
	if (s % v != 0)
	{
		t1++;
	}
	int t2 = (480 - t1 + 1440 ) % 1440;
	int a = t2 / 60;
	int b = t2 - a * 60;
	if (a < 10)
	{
		cout << 0;
	}
	cout << a << ":";
	if (b< 10)
	{
		cout << 0;
	}
	cout << b;

	system("pause");

	return 0;


}