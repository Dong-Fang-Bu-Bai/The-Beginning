//# [NOIP2012 普及组] 质因数分解
//
//## 题目描述
//
//已知正整数 $n$ 是两个不同的质数的乘积，试求出两者中较大的那个质数。
//
//## 输入格式
//
//输入一个正整数 $n$。
//
//## 输出格式
//
//输出一个正整数 $p$，即较大的那个质数。
//
//## 样例 #1
//
//### 样例输入 #1
//
//```
//21
//```
//
//### 样例输出 #1
//
//```
//7
//```
//
//## 提示
//
//$1 \le n\le 2\times 10 ^ 9$
//
//NOIP 2012 普及组 第一题

#include<iostream>
using namespace std;

bool isPrime1(int a)
{
	for (int i = 2; i * i <= a; i++)
	{
		if (a % i == 0)
		{
			return false;
		}
	}
	return true;
}


int main3()
{
	int n;
	cin >> n;
	for (int i = 2; i*i<=n; i++)
	{
		if (n % i == 0)
		{
			if (isPrime1(i) && isPrime1(n / i))
			{
				int max = i > n / i ? i : n / i;
				cout << max << endl;;
			}
		}
	}


	system("pause");
	return 0;
}
