//# [NOIP2012 �ռ���] �������ֽ�
//
//## ��Ŀ����
//
//��֪������ $n$ ��������ͬ�������ĳ˻�������������нϴ���Ǹ�������
//
//## �����ʽ
//
//����һ�������� $n$��
//
//## �����ʽ
//
//���һ�������� $p$�����ϴ���Ǹ�������
//
//## ���� #1
//
//### �������� #1
//
//```
//21
//```
//
//### ������� #1
//
//```
//7
//```
//
//## ��ʾ
//
//$1 \le n\le 2\times 10 ^ 9$
//
//NOIP 2012 �ռ��� ��һ��

#include<iostream>
using namespace std;

bool isPrime1(int a)
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


int main3()
{
	int n;
	cin >> n;
	for (int i = 2; i*i<=n; i++)
	{
		if (n % i == 0)
		{
			if (isPrime1(i) && isPrime1(n / i))
			{
				int max = i > n / i ? i : n / i;
				cout << max << endl;;
			}
		}
	}


	system("pause");
	return 0;
}
