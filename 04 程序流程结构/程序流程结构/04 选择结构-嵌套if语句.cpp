#include<iostream>
using namespace std;

 int main4()
{


	//1.��ʾ����߿�����
	int	score = 0;
	cout << "������߿����Է�����" << endl;
	cin >> score;
	//2.��ʾ�߿�����
	cout << "������ķ���Ϊ��" << score << endl;

	//3.�ж�
	//�������600	һ��
		//����700	����
		// ����650	�廪
		// ����		�˴�
	//�������500	����
	//�������400	����
	//�������	δ���ϱ���
	if (score>600)
	{
		cout << "��ϲ������һ����ѧ" << endl;
		if (score>700)
		{
			cout << "��ϲ�����뱱��" << endl;
		}
		else if (score>650)
		{
			cout << "��ϲ�������廪" << endl;
		}
		else
		{
			cout << "��ϲ�������˴�" << endl;
		}
	}
	else if(score>500)
	{
		cout << "��ϲ�����������ѧ" << endl;
	}
	else if (score > 400)
	{
		cout << "��ϲ������������ѧ" << endl;
	}
	else
	{
		cout << "��ϲ��δ���ϴ�ѧ" << endl;
	}





	system("pause");
	return 0;


}