//【1】猜数游戏。由计算机“想”一个四位数，请人猜这个四位数是多少。人输入四位数字后，
// 计算机首先判断这四位数字中有几位是猜对了，并且在对的数字中又有几位位置也是对的，将结果显示出来，给人以提示，
// 请人再猜，直到人猜出计算机所想的四位数是多少为止。

#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main1()
{
	srand((int)time(0));
	int a = rand()% 9999 + 1;
	if (a < 1000)
	{
		a += 1000;
	}
	cout << a << endl;
	int b = 0;
	int arra[4];
	int c = a;
	for (int i = 0; i < 4; i++)
	{
		arra[3-i] = c % 10;
		c = c / 10;
	}

	while (b != a)
	{
		cout << "请输入一个四位数字" << endl;
		cin >> b;
		int d = b;
		int arrb[4];
		for (int i = 0; i < 4; i++)
		{
			arrb[3-i] = d% 10;
			d = d/ 10;
		}

		int count = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (arrb[i] == arra[j]&&i==j)
				{
					cout << "第" << i + 1 << "位数字"<<arrb[i] << "是对的" << endl;
					count = j;
					break;
				}
				
				if(arrb[i] == arra[j] && i != j && j != count)
				{
					cout << "第" << i + 1 << "位数字"<<arrb[i]<<"的位置不对" << endl;
				}
				
			}
		}

		system("pause");
		system("cls");

	}

	cout << "恭喜您，猜对了！" << endl;


	system("pause");
	return 0;
}

