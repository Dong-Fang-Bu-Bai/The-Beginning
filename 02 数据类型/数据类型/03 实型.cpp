#include<iostream>
using namespace std;

int main3()
{


	//1.������ float 6-7λ
	//2.˫���� double 15-16λ
	//Ĭ������£����һ��С�󣬻���ʾ��6λ��Ч���֣���Ҫ���ж������
	float f1 = 3.14f;//Ĭ��ʵ��Ϊ˫���ȣ���������ǿ������ת��

	cout << "f1=" << f1 << endl;

	double d1 = 3.14159265;

	cout << "d1=" << d1 << endl;

	//ͳ��float��doubleռ���ڴ�ռ�
	cout << "floatռ���ڴ�ռ�Ϊ��" << sizeof(f1) << endl;//4�ֽ�
	
	cout << "doubleռ���ڴ�ռ�Ϊ��" << sizeof(d1) << endl;//8�ֽ�
	

	//��ѧ������
	float f2 = 3e2;//3*10^2
	cout << "f2=" << f2 << endl;

	float f3 = 3e-2;//3*0.1^2
	cout << "f3=" << f3<< endl;

	system("pause");

	return 0;


}