//庄子》中说到，“一尺之棰，日取其半，万世不竭”。第一天有一根长度为
//𝑎
//a 的木棍，从第二天开始，每天都要将这根木棍锯掉一半（每次除
//2
//2，向下取整）。第几天的时候木棍的长度会变为
//1
//1？


#include<iostream>
using namespace std;

int main3()
{
	int a;
	cin >> a;

	int num1 = 1;

	if (a == 1)
	{
		num1 = 1;
	}
	else
	{
		while (a != 1)
		{
			a /= 2;
			num1++;
		}
	}

	cout << num1;


	system("pause");
	return 0;


}