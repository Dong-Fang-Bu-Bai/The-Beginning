//#include<iostream>
//using namespace std;
//
//
//class Person
//{
//public:
//	Person(int age)
//	{
//		m_Age = age;
//		//thisָ��ָ����� �����õĳ�Ա���� �����Ķ���
//		this->m_Age = age;
//	}
//
//	//ע�⣬һ��Ҫ���� & ���������򷵻ص���p2�ĸ������������˿������캯�������ı�p2����
//	Person& PersonAddAge(Person& p)
//	{
//		this->m_Age += p.m_Age;
//
//		//this��ָ��p2��ָ�룬��*thisָ��ľ���p2���������
//		return *this;
//	}
//	int m_Age;
//};
//
////1.������Ƴ�ͻ
//void test01()
//{
//	Person p1(18);
//	cout << "p1������Ϊ�� " << p1.m_Age << endl;
//}
////2.���ض�������this
//void test02()
//{
//	Person p1(10);
//
//	Person p2(10);
//
//	//��ʽ���˼��
//	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);
//	cout << "p2������Ϊ��" << p2.m_Age << endl;
//
//}
//
//int main2()
//{
//	//test01();
//
//	test02();
//
//
//
//
//
//	system("pause");
//	return 0;
//}