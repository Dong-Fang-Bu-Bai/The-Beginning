//
//【1】 
// 编写一个函数multiple，用于确定一对整数中第二个整数是否是第一个整数的倍数。
// 函数应该需要两个整数参数，并且如果第二个整数是第一个整数的倍数的话，返回1，否则返回0。
// 在程序中使用这个函数判断输入的一系列整数对     
// bool multiple(int a, int b)
//{
//	if (b % a == 0)
//	{
//		return 1;
//	}
//	return 0;
//}
//
//
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//
//	cout << multiple(a, b) << endl;
//
//
//
//
//	system("pause");
//	return 0;
//}
//【2】
// 编写一个程序求一系列整数之和。假定输入的第一个整数制定了继续输入的值的个数，
// 比如输入 5 100 200 300 400 500，代表计算5个数的和，总和是1500。     
// int a;
//cin >> a;
//int sum = 0;
//for (int i = 0; i < a; i++)
//{
//	int k;
//	cin >> k;
//	sum += k;
//}
//
//cout << sum << endl;
//【3】
// 现有21根火柴，两人轮流取，每人每次可以取走1至4根，不可多取，也不能不取，
// 谁取最后一楰火柴谁输。任务一：请编写一个程序进行人机对弈，要求人先取，计算机后取（随机取）；
// 任务二：计算机一方为“常胜将军”，即找出必胜策略。  




#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	int sum = 0;
	srand((unsigned int)time(nullptr));

	while (sum < 21)
	{
		cout <<"当前已取火柴数：" << sum << endl;
		int a;
		cout << "请输入取走的火柴数(1~4)：" << endl;
		cin >> a;
		sum += a;
		if (sum == 21)
		{
			cout << "您输了！" << endl;
			break;
		}
		
	
		int b = 5 - a;
		cout << "机器取了" << b << "根火柴" << endl;
		sum += b;
		
		if (sum == 21)
		{
			cout << "您赢了！" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
	

	system("pause");
	return 0;
}