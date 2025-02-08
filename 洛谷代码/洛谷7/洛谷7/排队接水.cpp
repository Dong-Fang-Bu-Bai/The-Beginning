//# 排队接水
//
//## 题目描述
//
//有 $n$ 个人在一个水龙头前排队接水，假如每个人接水的时间为 $T_i$，请编程找出这 $n$ 个人排队的一种顺序，使得 $n$ 个人的平均等待时间最小。
//
//## 输入格式
//
//第一行为一个整数 $n$。
//
//第二行 $n$ 个整数，第 $i$ 个整数 $T_i$ 表示第 $i$ 个人的接水时间 $T_i$。
//
//## 输出格式
//
//输出文件有两行，第一行为一种平均时间最短的排队顺序；第二行为这种排列方案下的平均等待时间（输出结果精确到小数点后两位）。
//
//## 样例 #1
//
//### 样例输入 #1
//
//```
//10
//56 12 1 99 1000 234 33 55 99 812
//```
//
//### 样例输出 #1
//
//```
//3 2 7 8 1 4 9 6 10 5
//291.90
//```
//
//## 提示
//
//$1\le n \leq 1000$，$1\le t_i \leq 10 ^ 6$，不保证 $t_i$ 不重复。


#include<iostream>
#include<iomanip>
using namespace std;
int s1[2][1001];


int main2()
{
	int n;
	cin >> n;
	int a;
	long long total = 0;//小心大数据！！！

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s1[0][i] = a;
		s1[1][i] = i + 1;
	} 

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (s1[0][j] > s1[0][j + 1])
			{
				int temp1;
				int temp2;
				temp1 = s1[0][j];
				s1[0][j] = s1[0][j + 1];
				s1[0][j + 1] = temp1;
				temp2 = s1[1][j];
				s1[1][j] = s1[1][j + 1];
				s1[1][j + 1] = temp2;
			}
			
			
		}
	}

	for (int i = 1; i <=n; i++)   //这个循环用来计算总时间 
	{
		total+=s1[0][i-1] * (n - i);
	}
	

	double avg = (total * 1.00) / n;



	for (int i = 0; i < n; i++)
	{
		cout << s1[1][i] << " ";
	}

	cout << endl;

	
	printf("%.2f\n", avg);









	system("pause");
	return 0;
}