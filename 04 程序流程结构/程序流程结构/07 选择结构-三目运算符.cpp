#include<iostream>
using namespace std;
 int main7()
{
	//��Ŀ�����
	//��������	��	��	��	
	//��ֵ���Ǳ��������Լ�����ֵ

	//������������ a b c
	//��a��b���Ƚϣ�����ı�����ֵ������c

	int a = 10;
	int	b = 20;
	int	c = 0;

	c = (a > b ? a : b);
	cout << "c=" << c<<endl;

	//��C++����Ŀ��������ص��Ǳ��������Լ�����ֵ
	(a > b ? a : b) = 100;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
















	system("pause");
	return 0;


}