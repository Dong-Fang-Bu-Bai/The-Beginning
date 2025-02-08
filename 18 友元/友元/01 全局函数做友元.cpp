//#include<iostream>
//using namespace std;
//
//class Building
//{
//	//goodGay是Building好朋友，可以访问Building类内私有成员变量
//	friend void goodGay(Building* building);
//
//public:
//	Building()
//	{
//		m_SittingRoom = "客厅";
//		m_BedRoom = "卧室";
//	}
//
//
//public:
//	string m_SittingRoom;//客厅
//
//private:
//	string m_BedRoom;//卧室
//};
//
////全局函数
//void goodGay(Building *building)
//{
//	cout << "好基友全局函数 正在访问" << building->m_SittingRoom << endl;
//
//	cout << "好基友全局函数 正在访问" << building->m_BedRoom << endl;
//
//}
//
//void test01()
//{
//	Building building;
//	goodGay(&building);
//}
//
//int main1()
//{
//	test01();
//
//	system("pause");
//	return 0;
//}