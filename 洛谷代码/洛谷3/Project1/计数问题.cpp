//
//试计算在区间
//1
//1 到
//𝑛
//n 的所有整数中，数字
//𝑥
//x（
//0
//≤
//𝑥
//≤
//9
//0≤x≤9）共出现了多少次？例如，在
//1
//1 到
//11
//11 中，即在
//1
//,
//2
//,
//3
//,
//4
//,
//5
//,
//6
//,
//7
//,
//8
//,
//9
//,
//10
//,
//11
//1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 中，数字
//1
//1 出现了
//4
//4 次。

#include<iostream>
#include<string>
using namespace std;

int main6()
{
	int n;
	int x;
	cin >> n >> x;
	
	int num1 = 0;


	for (int i = 1; i <= n; i++)
	{
		string str1 = to_string(i);
		string str2 = to_string(x);
		int num2 = str1.size();
		for (int j = 0; j < num2; j++)
		{
			if (str1[j] == str2[0])
			{
				num1++;
			}
		}
		
	}

	
	cout << num1 << endl;




	system("pause");
	return 0;
}