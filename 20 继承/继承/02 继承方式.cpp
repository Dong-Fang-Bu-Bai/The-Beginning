//#include<iostream>
//using namespace std;
//
////继承方式
//
////公共继承
//class Base1
//{
//public:
//	int m_A;
//protected:
//	int m_B;
//private:
//	int m_C;
//};
//
//class Son1 :public Base1
//{
//public:
//
//	void func()
//	{
//		m_A = 10;//父类中的公共权限成员 到子类中依然是公共权限
//		m_B = 10;//父类中的保护权限成员 到子类中依然是保护权限
//		//m_C = 10;//父类中的私有权限成员 子类中无法访问
//	}
//};
//
//void test01()
//{
//	Son1 s1;
//	s1.m_A = 100;
//	//s1.m_B = 100;//保护权限在类外无法访问
//}
//
////保护继承
//class Base2
//{
//public:
//	int m_A;
//protected:
//	int m_B;
//private:
//	int m_C;
//};
//
//class Son2 :protected Base2
//{
//public:
//	void func()
//	{
//		m_A = 100;//父类中公共成员 到子类中变为保护权限
//		m_B = 100;//父类中保护成员 子类中仍然为保护权限
//		m_C = 100;//父类中私有成员 子类访问不到
//	}
//};
//
//void test02()
//{
//	Son2 s1;
//	//s1.m_A = 100;//在Son2中 m_A变为保护权限 ，因此类外无法访问
//	//s1.m_B = 100;//在Son2中 m_B为保护权限  类外无法访问
//}
//
////私有继承
//class Base3
//{
//public:
//	int m_A;
//protected:
//	int m_B;
//private:
//	int m_C;
//};
//
//class Son3 :private Base3
//{
//public:
//	void func()
//	{
//		m_A = 10;//父类中公共成员 到子类中变为 私有成员
//		m_B = 10;//父类中保护成员 到子类中变为 私有成员
//		//m_C = 10;//父类中私有成员 ，子类无法访问
//	}
//};
//
//class GrandSon3 :public Son3
//{
//public:
//	void func()
//	{
//		m_A = 1000;//到了Son3中 m_A变为私有 ，即使是其儿子 ，也访问不到
//		m_B = 1000;//到了Son3中 m_B变为私有 ，即使是其儿子 ，也访问不到
//	}
//};
//
//void test03()
//{
//	Son3 s1;
//	s1.m_A = 10;//到Son3中 变为私有成员 类外无法访问
//	s1.m_B = 10;//到Son3中 变为私有成员 类外无法访问
//
//
//}
//
//
//int main()
//{
//
//
//
//
//
//
//
//
//
//
//	system("pause");
//	return 0;
//}