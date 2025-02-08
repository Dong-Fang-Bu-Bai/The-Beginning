//输入三个正整数
//𝑥
//,
//𝑦
//,
//𝑧
//x, y, z，求它们的最大公约数（Greatest Common Divisor）
//𝑔
//g：最大的正整数
//𝑔
//≥
//1
//g≥1，满足
//𝑥
//,
//𝑦
//,
//𝑧
//x, y, z 都是
//𝑔
//g 的倍数，即
//(
//	𝑥
//
//	mod
//
//	𝑔
//)
//=
//(
//	𝑦
//
//	mod
//
//	𝑔
//	)
//	=
//	(
//		𝑧
//
//		mod
//
//		𝑔
//		)
//	=
//	0
//	(xmodg) = (ymodg) = (zmodg) = 0。


#include<iostream>
using namespace std;

int main3()
{
	int x;
	int y;
	int z;
	int same = 1;
	int min = 0;
	cin >> x >> y >> z;

	if (x < y)
	{
		if (x<z)
		{
			min = x;
		}
		else
		{
			min = z;
		}
	}
	else
	{
		if (y < z)
		{
			min = y;
		}
		else
		{
			min = z;
		}
	}

	for (int i = 1; i <= z; i++)
	{
		if (x % i == 0 && y % i == 0 && z % i == 0)
		{
			same = i;
		}
	}

	cout << same << endl;

	system("pause");
	return 0;
}