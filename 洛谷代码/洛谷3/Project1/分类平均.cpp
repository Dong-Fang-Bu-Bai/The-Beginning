//给定
//𝑛
//n 和
//𝑘
//k，将从 1 到
//𝑛
//n 之间的所有正整数可以分为两类：A 类数可以被
//𝑘
//k 整除（也就是说是
//𝑘
//k 的倍数），而 B 类数不能。请输出这两类数的平均数，精确到小数点后
//1
//1 位，用空格隔开。



#include<iostream>
#include<cstdio>
using namespace std;


int main2()
{
	int n;
	cin >> n;

	int k;
	cin >> k;

	double num1 = 0;
	double total1 = 0;
	double num2 = 0;
	double total2 = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i % k == 0)
		{
			total1 = total1 + i;
			num1++;
		}
		else
		{
			total2 = total2 + i;
			num2++;
		}
	}
		

		printf("%.1f %.1f", total1 / num1, total2 / num2);

	







	system("pause");
	return 0;
}