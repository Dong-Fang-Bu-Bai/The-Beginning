//1.����ͷ�ļ�
#include<fstream>
#include<iostream>
using namespace std;

class Person
{
public:

	char m_Name[64];//����
	int m_Age;//����
};

//�������ļ�  ���ļ�
void test01()
{
	//2.����������
	ifstream ifs;
	//3.���ļ�   �ж��ļ��Ƿ�򿪳ɹ�
	ifs.open("person.txt", ios::in | ios::binary);

	if (!(ifs.is_open()))
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	//4.���ļ�
	Person p;

	ifs.read((char*)&p, sizeof(Person));

	cout << "���� ��" << p.m_Name << endl;
	cout << "���� ��" << p.m_Age << endl;

	//5.�ر��ļ�
	ifs.close();
}

int main()
{
	test01();



	system("pause");
	return 0;
}