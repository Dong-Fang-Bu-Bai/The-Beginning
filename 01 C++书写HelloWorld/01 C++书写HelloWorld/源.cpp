#include<iostream>
#include<string>
using namespace std;

int main7()
{

	int a = '\101';//��ʱa��ֵΪ�˽����µ�101
	cout << a << endl;

	int b = '\x0A';//x����λ����ĸ��ʾʮ��������
	cout << b << endl;


	cout << char('A' + 1) << endl;//�ַ��ͱ����ı���������

	string c;
	getline(cin, c);//��ʹ�����ú���ʱ����Ҫ����string��
	cout << c;

	system("pause");
	return 0;
}