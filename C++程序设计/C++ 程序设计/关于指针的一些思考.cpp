#include<iostream>
using namespace std;

int main2()
{
	int a = 2;
	int* p = &a;

	cout << &p << endl;//��ʱ�������ָ��p�ĵ�ַ
	cout << p << endl;//��ʱ�������ָ��pָ���a�����ĵ�ַ
	cout << &*p << endl;//��ʱ�������ָ��pָ���a�����ĵ�ַ
	cout << *&p << endl;//��ʱ�������ָ��pָ���a�����ĵ�ַ

	//���ۣ�  & ��  *  ��Ϊ������



	system("pause");
	return 0;
}