#include<iostream>
using namespace std;
int main8()
{
	//��ά���鰸��-���Գɼ�ͳ��
	
	//1.������ά����
	int scores[3][3] =
	{
		{100,100,100},
		{ 90,50,100 },
		{ 60,70,80 }

	};
	string names[3] = {"����","����","����"};

	//2.ͳ��ÿ���˵��ۺϷ���
	for (int i = 0; i < 3; i++)
	{
		int sum = 0;
		for (int j = 0; j < 3; j++)
		{
			
			sum += scores[i][j];
			cout << scores[i][j] << "\t";
			
		}
		//cout << "��" << i + 1 << "���˵��ܷ�Ϊ��" << sum << endl;
		cout <<names[i] << "���ܷ�Ϊ��" <<sum<< endl;
	}









		system("pause");
		return 0;




}