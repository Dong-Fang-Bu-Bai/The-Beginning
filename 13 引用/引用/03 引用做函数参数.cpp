#include<iostream>
using namespace std;


//��������


//1.ֵ����

void mySwap01(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	/*cout << "swap01 a=" << a << endl;
	cout << "swap01 b=" << b << endl;*/
}

//2.��ַ����
void mySwap02(int*a,int*b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//3�����ô���

void mySwap03(int& a, int& b)//���õķ�ʽ
{
	int temp = a;
	a = b;
	b = temp;
}




int main3()
{
	int a = 10;
	int b = 20;

	/*mySwap01(a,b);*/
	//mySwap02(&a, &b);

	mySwap03(a, b);//���ô��ݣ��β�Ҳ������ʵ��

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;



	system("pause");
	return 0;
}

//���ò���������Ч�����ַ��ͬ�����﷨���򵥡�