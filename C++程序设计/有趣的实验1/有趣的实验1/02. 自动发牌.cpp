//��2��       �Զ����ơ�һ���˿���52���ƣ�������ʱӦ���Ʒָ��ĸ��ˡ�
// �����һ����������Զ����ƵĹ�����Ҫ�󣺺�����S(Spaces)��ʾ��������H(Hearts)��ʾ��
// ������D(Diamonds)��ʾ��÷����C(Clubs)��ʾ�����մ����ƵĹ涨��ÿ��Ӧ����13���ơ�
// ���˹�����ʱ���Ƚ���ϴ�ơ���

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main2()
{
	srand((int)time(0));
	int arr[52];
	for (int i = 1; i <= 52; i++)
	{
		arr[i - 1] = i;//����ֵ
	}

	int arr1[13];
	int S[4] = { 0 }, H[4] = { 0 }, D[4] = { 0 }, C[4] = { 0 };

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			int b = rand() % 52;
			while (arr[b] == 0)
			{
				b = rand() % 52;
			}

			arr1[j] = arr[b];
			if (arr1[j] >= 1 && arr1[j] <= 13)
			{
				S[i]++;
			}
			else if (arr1[j] > 13 && arr1[j] <= 26)
			{
				H[i]++;
			}
			else if (arr1[j] > 26 && arr1[j] <= 39)
			{
				D[i]++;
			}
			else
			{
				C[i]++;
			}
			arr[b] = 0;

		}
	}

	

	cout << "A�ĺ�������" << S[0] << " " << "A�ĺ�������" << H[0] << endl;
	cout << "A�ķ�������" << D[0] << " " << "A��÷������" << C[0] << endl;
	cout << "B�ĺ�������" << S[1] << " " << "B�ĺ�������" << H[1] << endl;
	cout << "B�ķ�������" << D[1] << " " << "B��÷������" << C[1] << endl;
	cout << "C�ĺ�������" << S[2] << " " << "C�ĺ�������" << H[2] << endl;
	cout << "C�ķ�������" << D[2] << " " << "C��÷������" << C[2] << endl;
	cout << "D�ĺ�������" << S[3] << " " << "D�ĺ�������" << H[3] << endl;
	cout << "D�ķ�������" << D[3] << " " << "D��÷������" << C[3] << endl;



	system("pause");
	return 0;
}
