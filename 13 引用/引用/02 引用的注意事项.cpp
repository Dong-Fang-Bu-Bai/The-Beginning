#include<iostream>
using namespace std;

int main2()
{
	int a = 10;
	int& b = a;


	//1.���ñ����ʼ��
	//int &b; ����


	//2.�����ڳ�ʼ���󣬲����Ըı�
	int c = 20;

	b = c;//��ֵ�����������Ǹ�������


	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;

	system("pause");
	return 0;
}