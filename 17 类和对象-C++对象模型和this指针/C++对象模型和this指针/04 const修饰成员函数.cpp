#include<iostream>
using namespace std;


//������
class Person
{
public:

	//thisָ��ı���  ��ָ�볣��  ָ���ָ���ǲ������޸ĵ�
	//�൱�� Person * const this;
	//�ڳ�Ա���������const�����ε���thisָ�룬��ָ��ָ���ֵҲ�������޸�
	void shoePerson() const //�൱��const Person * const this;
	{
		this->m_B = 100;
		//this->m_A = 100;
		//this-NULL://this ָ�벻�����޸���ָ��
	}

	void func()
	{

	}


	int m_A;
	mutable int m_B;//�����������ʹ�ڳ������У�Ҳ�����޸����ֵ,���Ϲؼ���mutable
};

void test01()
{
	Person p;
	p.shoePerson();
}

//������

void test02()
{
	const Person p;//�ڶ���ǰ��const����Ϊ������
	//p.m_A = 100;
	p.m_B = 100;//m_B������ֵ���ڳ�������Ҳ�����޸�

	//������ֻ�ܵ��ó�����
	p.shoePerson();
	//p.func();������  �����Ե�����ͨ��Ա���� �� ��Ϊ��ͨ��Ա���������޸�����
}



int main4()
{




	system("pause");
	return 0;
}