#include<iostream>
using namespace std;

 int main6()
{

	int max = 0;//�ȶ���һ��max���ٸ���ABC��С��max���и�ֵ��������max��ֵ�������ABC��
	int	a = 0;
	int	b = 0;
	int	c = 0;
	cout << "������С��A������" << endl;
	cin >> a;
	cout << "������С��B������" << endl;
	cin >> b;
	cout << "������С��C������" << endl;
	cin >> c;
	max = (a > b ? a : b);
	max = (max > c ? max : c);
	if (a==max)
	{
		cout << "С��A���أ�����Ϊ" << max << endl;
	}
	else if (b ==max)
	{
		cout << "С��B���أ�����Ϊ" << max << endl;
	}
	else 
	{
		cout << "С��C���أ�����Ϊ" << max << endl;
	}
	




















	system("pause");
	return 0;



}