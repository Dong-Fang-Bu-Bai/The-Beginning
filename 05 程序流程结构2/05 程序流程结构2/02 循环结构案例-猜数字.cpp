#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main2()
{
	//������������	���ã����õ�ǰϵͳʱ���������������ֹһ��
	//srand(time(0));����Ҳ���ԣ���������Ҳ����Ҫ��<cstdlib>�����,�Լ�<ctime>�����
	srand((unsigned int)time(NULL));
	//1.ϵͳ���������
	//rand()%100	//����0~99�����
	int num = rand() % 100 + 1;
	//cout << num << endl;//����������
	//2.��ҽ��в²�
	int val = 0;//������������
	int	q = 0;//��ҳ��Դ���
	while (1)
	{
		cin >> val;
		//3.�ж���ҵĲ²�
		if (val > num&&q<=4)
		{
			cout << "�²����" << endl;
			q++;
		}
		else if (val < num&&q<=4)
		{
			cout << "�²��С" << endl;
			q++;
		}
		else if(val==num&&q<=5)
		{
			cout << "��ϲ���¶���" << endl;
			cout << "�㳢�ԵĴ���Ϊ:" << q + 1 << endl;
			//�¶�	�˳���Ϸ
			break;//�Ըùؼ����˳�ѭ��
		}
		else if(q>4&&q!=num)
		{
			cout << "��Ǹ����ʧ����" << endl;
			cout << num << endl;
			break;
		}
	}
	//�¶�	�˳���Ϸ
	//�´�	��ʾ�µĽ��	������С	���·��ص�2��
	system("pause");
	return 0;



}