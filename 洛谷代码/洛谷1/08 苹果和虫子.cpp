/*
 这道题有以下几点需要注意：
1.吃一个苹果的时间可以定义为0，此时需要特别讨论
2既要考虑整不整除、加不加1的问题，也要考虑在给定时间内是否已将所有苹果吃完，因为剩余苹果数不能小于0

*/

#include<iostream>
using namespace std;
int main8()
{
	int m = 0;//苹果总数
	int t = 0;//吃一个苹果的时间
	int s = 0;//吃了多少时间
	int k = 0;//还剩多少苹果
	cin >> m >> t >> s;
	if (t == 0)
	{
		k = 0;
		cout << k << endl;
	}
	else
	{
		int n = s / t;//吃了多少苹果
		if (s % t != 0)
		{
			n++;
		}
		k = m - n;
		if (m < n)
		{
			k = 0;
		}
		cout << k << endl;
	}
	
	
	system("pause");

	return 0;


}