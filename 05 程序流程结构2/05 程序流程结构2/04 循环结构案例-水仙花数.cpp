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
		a = num / 100;//��λ
		b = num / 10 % 10;//ʮλ
		c = num % 10;//��λ
		d = a*a*a + b*b*b + c*c*c;//ˮ�ɻ�������
		if (num == d)
		{
			cout << num << endl;
		}
		num++;//ÿ��ѭ������1
	} while (num < 1000);//ѭ����999
	system("pause");
	return 0;
}