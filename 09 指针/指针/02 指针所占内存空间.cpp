#include<iostream>
using namespace std;
int main2()
{

	//ָ����ռ�ڴ�ռ�
	int a = 10;
	int * p = &a;//����������ĳ�ʼ��ָ�����

	//��64λ����ϵͳ�У�ָ��ռ8���ֽڣ�x64)
	//��32λ����ϵͳ�У�ָ��ռ4���ֽڣ�x86��
	cout << "sizeof(int *)=" << sizeof(int*) << endl;
	cout << "sizeof(int *)=" << sizeof(float*) << endl;
	cout << "sizeof(int *)=" << sizeof(double*) << endl;
	cout << "sizeof(int *)=" << sizeof(char*) << endl;


	system("pause");
	return 0;
}