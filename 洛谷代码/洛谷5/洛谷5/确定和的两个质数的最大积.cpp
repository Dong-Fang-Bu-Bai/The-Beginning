//# 质数的和与积
//
//## 题目描述
//
//两个质数的和是 $S$，它们的积最大是多少？
//
//## 输入格式
//
//一个不大于 $10000$ 的正整数 $S$，为两个质数的和。
//
//## 输出格式
//
//一个整数，为两个质数的最大乘积。数据保证有解。
//
//## 样例 #1
//
//### 样例输入 #1
//
//```
//50
//```
//
//### 样例输出 #1
//
//```
//589
//```


#include<iostream>
using namespace std;


bool isPrime(int a)
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

int main2()
{
	
	int S;
	cin >> S;
	int initial = 0;


	for (int i = 2; i <= S / 2; i++)
	{
		if (isPrime(i) && isPrime(S - i))
		{
			int b = i * (S - i);
			if (b > initial)
			{
				initial = b;
			}
		}
		

	}

	
	cout << initial << endl;

	

	system("pause");
	return 0;
}