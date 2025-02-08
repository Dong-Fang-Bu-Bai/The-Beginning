//# Hermite ����ʽ
//
//## ��Ŀ����
//
//�� Hermite ����ʽ��ֵ��
//
//$$
//h_n(x) = \left\{
//	\begin{ aligned }
//		1 & �� & n = 0\\
//		2x & �� & n = 1\\
//		2xh_{ n - 1 }(x)-2(n - 1)h_ { n - 2 }(x)&��& n > 1
//		\end{ aligned }
//		\right.
//		$$
//
//
//
//		�Ը����� $x$ �������� $n$�������ʽ��ֵ��
//
//		## �����ʽ
//
//		���� $n$ �� $x$ ��
//
//		## �����ʽ
//
//		�����ʽ��ֵ��
//
//		## ���� #1
//
//		### �������� #1
//
//		```
//		1 2
//		```
//
//		### ������� #1
//
//		```
//		4
//		```
//
//		## ��ʾ
//
//		$(n \le 8��x \le 8)$

#include<iostream>
using namespace std;

int h(int n,int x)
{
	if (n == 0)
	{
		return 1;
	}
	else if (n == 1)
	{
		return 2*x;
	}
	else
	{
		return 2*x*h(n - 1,x)-2*(n-1)*h(n-2,x);
	}
}


int main2()
{
	
	int x;
	int n;
	cin >> n;
	cin >> x;



	cout << h(n,x) << endl;






	system("pause");
	return 0;
}