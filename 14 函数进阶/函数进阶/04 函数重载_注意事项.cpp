#include<iostream>
using namespace std;

//�������ص�ע������
//1.������Ϊ���ص�����
void fun(int &a)//int &a=10;���Ϸ�
{
	cout << "func(int &a)�ĵ���" << endl;
}

void fun( const int& a)//const int &a=10;�Ϸ�
{
	cout << "func(const int &a)�ĵ���" << endl;
}

//2.������������Ĭ�ϲ��� ==>  �����������ɻ�
void func2(int a,int b=10)
{
	cout << "func2(int a,int b=10)�ĵ���" << endl;
}


void func2(int a)
{
	cout << "func2(int a)�ĵ���" << endl;
}






int main4()
{
	/*int a = 10;

	fun(a);*/

	//fun(10);

	//�����������ɻ�
	func2(10);
		//��������������Ĭ�ϲ��������ֶ����ԣ��������������������


	system("pause");
	return 0;
}