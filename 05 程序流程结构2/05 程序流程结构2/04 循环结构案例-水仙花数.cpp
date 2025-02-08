#include<iostream>
using namespace std;
int main4()
{
	int num = 100;
	do
	{

		int a = 0;
		int b = 0;
		int	c = 0;
		int d = 0;
		a = num / 100;//百位
		b = num / 10 % 10;//十位
		c = num % 10;//个位
		d = a*a*a + b*b*b + c*c*c;//水仙花数定义
		if (num == d)
		{
			cout << num << endl;
		}
		num++;//每次循环增加1
	} while (num < 1000);//循环至999
	system("pause");
	return 0;
}