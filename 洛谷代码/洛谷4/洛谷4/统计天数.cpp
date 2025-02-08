//# 统计天数
//
//## 题目描述
//
//炎热的夏日，KC 非常的不爽。他宁可忍受北极的寒冷，也不愿忍受厦门的夏天。最近，他开始研究天气的变化。他希望用研究的结果预测未来的天气。
//
//
//经历千辛万苦，他收集了连续 $N(1 \leq N \leq 10 ^ 6)$ 天的最高气温数据。
//
//现在，他想知道最高气温一直上升的最长连续天数。
//
//## 输入格式
//
//第 1 行：一个整数 $N$ 。$1 \leq N \leq 10 ^ 6$
//
//第 2 行：$N$个空格隔开的整数，表示连续 $N$ 天的最高气温。$0 \leq$ 最高气温 $\leq 10 ^ 9$ 。
//
//## 输出格式
//
//1 行：一个整数，表示最高气温一直上升的最长连续天数。
//
//## 样例 #1
//
//### 样例输入 #1
//
//```
//10
//1 2 3 2 4 5 6 8 5 9
//```
//
//### 样例输出 #1
//
//```
//5
//```

#include<iostream>
using namespace std;
long long days[1000000];

int main4()
{
	long long N;
	cin >> N;
	long long length = 0;
	long long temp1 = 1;
	

	
	for (long long i = 0; i < N; i++)
	{
		long long temp;
		cin >> temp;
		days[i] = temp;
	}

	for (long long j = 0; j <N; j++)
	{
	
		
			
			if (days[j] < days[j + 1])
			{
				temp1++;
				if (temp1 > length)
				{
					length = temp1;
				}
			}
			else
			{
				temp1 = 1;
			}
		
		
	}

	cout << length << endl;


	system("pause");
	return 0;
}