//��1��������Ϸ���ɼ�������롱һ����λ�������˲������λ���Ƕ��١���������λ���ֺ�
// ����������ж�����λ�������м�λ�ǲ¶��ˣ������ڶԵ����������м�λλ��Ҳ�ǶԵģ��������ʾ��������������ʾ��
// �����ٲ£�ֱ���˲³�������������λ���Ƕ���Ϊֹ��

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
		cout << "������һ����λ����" << endl;
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
					cout << "��" << i + 1 << "λ����"<<arrb[i] << "�ǶԵ�" << endl;
					count = j;
					break;
				}
				
				if(arrb[i] == arra[j] && i != j && j != count)
				{
					cout << "��" << i + 1 << "λ����"<<arrb[i]<<"��λ�ò���" << endl;
				}
				
			}
		}

		system("pause");
		system("cls");

	}

	cout << "��ϲ�����¶��ˣ�" << endl;


	system("pause");
	return 0;
}

