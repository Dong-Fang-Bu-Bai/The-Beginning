//#include<iostream>
//using namespace std;
//
////左移运算符重载
//
//class Person
//{
//	friend ostream& operator<<(ostream& cout, Person& p);//作为友元
//
//public:
//	Person(int a, int b)
//	{
//		m_A = a;
//		m_B = b;
//	}
//
//private:
//	//利用成员函数来重载 左移运算符 p.operator<<(cout)  简化版本 p << cout
//	//不会利用成员函数重载 << 运算符，因为无法实现 cout 在左侧
//	/*void operator<<(cout)
//	{
//
//	}*/
//
//	int m_A;
//	int m_B;
//};
//
////只能利用全局函数重载左移运算符，否则要加上类的前缀
//ostream& operator<<(ostream &cout,Person &p)  //本质  operator<<(cout,p)  简化cout<<p
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