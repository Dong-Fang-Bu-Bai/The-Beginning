//# �����ĺ����
//
//## ��Ŀ����
//
//���������ĺ��� $S$�����ǵĻ�����Ƕ��٣�
//
//## �����ʽ
//
//һ�������� $10000$ �������� $S$��Ϊ���������ĺ͡�
//
//## �����ʽ
//
//һ��������Ϊ�������������˻������ݱ�֤�н⡣
//
//## ���� #1
//
//### �������� #1
//
//```
//50
//```
//
//### ������� #1
//
//```
//589
//```


#include<iostream>
using namespace std;


bool isPrime(int a)
{
	for (int i = 2; i * i <= a; i++)
	{
		if (a % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main2()
{
	
	int S;
	cin >> S;
	int initial = 0;


	for (int i = 2; i <= S / 2; i++)
	{
		if (isPrime(i) && isPrime(S - i))
		{
			int b = i * (S - i);
			if (b > initial)
			{
				initial = b;
			}
		}
		

	}

	
	cout << initial << endl;

	

	system("pause");
	return 0;
}