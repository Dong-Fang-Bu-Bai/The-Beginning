//#include<iostream>
//using namespace std;
//
////�������������
//
//class Person
//{
//	friend ostream& operator<<(ostream& cout, Person& p);//��Ϊ��Ԫ
//
//public:
//	Person(int a, int b)
//	{
//		m_A = a;
//		m_B = b;
//	}
//
//private:
//	//���ó�Ա���������� ��������� p.operator<<(cout)  �򻯰汾 p << cout
//	//�������ó�Ա�������� << ���������Ϊ�޷�ʵ�� cout �����
//	/*void operator<<(cout)
//	{
//
//	}*/
//
//	int m_A;
//	int m_B;
//};
//
////ֻ������ȫ�ֺ����������������������Ҫ�������ǰ׺
//ostream& operator<<(ostream &cout,Person &p)  //����  operator<<(cout,p)  ��cout<<p
//{
//	cout << "m_A = " << p.m_A << " m_B = " << p.m_B;
//	return cout;
//}
//
//void test01()
//{
//	Person p(10, 10);
//	
//
//	//cout << p.m_A << endl;
//	cout << p << endl;
//}
//
//int main2()
//{
//
//	test01();
//
//
//
//
//
//
//	system("pause");
//	return 0;
//}