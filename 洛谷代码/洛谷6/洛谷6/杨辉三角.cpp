//# �����5.ϰ7���������
//
//## ��Ŀ����
//
//���� $n(1\le n\le20)$�����������ǵ�ǰ $n$ �С�
//
//����㲻֪��ʲô��������ǣ����Թ۲��������ҹ��ɡ�
//
//## �����ʽ
//
//## �����ʽ
//
//## ���� #1
//
//### �������� #1
//
//```
//6
//```
//
//### ������� #1
//
//```
//1
//1 1
//1 2 1
//1 3 3 1
//1 4 6 4 1
//1 5 10 10 5 1
//```


#include<iostream>
using namespace std;

long long jiecheng(int k)
{
	long long a = 1;
	if (k == 0)
	{
		return 1;
	}
	else
	{
		for (int p = 1; p <= k; p++)
		{
			a = a * p;
		}
		return a;
	}
}


void yanghui(int j)
{
	for (int s = 0; s <j ; s++)
	{
		long long q = jiecheng(j - 1) / (jiecheng(j - 1 - s) * jiecheng(s));
		cout << q << " ";
	}
	cout << endl;
}



int main4()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		yanghui(i + 1);
	}





	system("pause");
	return 0;
}