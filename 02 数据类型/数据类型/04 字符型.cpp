#include<iostream>
using namespace std;


int main4()
{

//1.�ַ��ͱ���������ʽ
	char ch='A';
cout << "ch=" << ch<< endl;

//2.char�ַ��ͱ�����ռ�ڴ�	Ϊ1�ֽ�
cout << "char�ַ��ͱ�����ռ�ڴ�=" << sizeof(ch) << endl;

//3.�ַ��ͱ�����������
//������˫����
//�����ַ��ͱ�������������ֻ����һ���ַ�


//4.�ַ��ͱ�����ӦASCII����
cout << (int)ch << endl;
//Ҳ��������д:cout << (int)'a' << endl;
//a - 97
//A - 65

if (ch < 'a')//����ֱ�ӱȽ��ַ��ͱ����Ĵ�С�����������ͣ�
{
	cout << "haha" << endl;
}

system("pause");
return 0;



}