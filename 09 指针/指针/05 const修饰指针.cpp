#include<IOSTREAM>
using namespace std;
int main5()
{

	int a = 10;
	int b = 20;
	
	
	
	//1.const���γ���
	//����ָ�룬ָ������ָ��
	const int* p = &a;
	//ָ��ָ���ֵ�����Ըģ�ָ���ָ����Ը�
	//*p=20������ָ��ָ���ֵ�����Ը�
	p = &b;
	
	//2.const����ָ��
	//ָ�볣��,ָ�뱾���ǳ���
	int*const  p2 = &a;
	*p2 = 100;
	//p2=&b;����ָ���ָ�򲻿��Ըģ�ָ��ָ���ֵ���Ը�

	//3.cinst����ָ��ͱ���
	const int* const  p3 = &a;
	//ָ���ָ�� �� ָ��ָ���ֵ �������Ը�




	system("pause");
	return 0;
}
