#include<iostream>
using namespace std;

//��ӡ���ݵĺ���
void showValue(const int& val)
{
	//val = 1000;��ʱ�Ͳ����޸���
	cout << "val=" << val << endl;
}


int main6()
{

	//��������
	

	int a = 10;
	//int& ref = 10; ���� ���ñ�����һ��Ϸ����ڴ�ռ�
	//����const֮��  �������������޸�  int temp=10;  const int &ref=temp;
	//const int& ref = 10; ����
	//ref = 20;����const���Ϊֻ�����������޸�

	//ʹ�ó��������������βΣ���ֹ�����

	showValue(a);

	cout << "a=" << a << endl;


	system("pause");
	return 0;
}