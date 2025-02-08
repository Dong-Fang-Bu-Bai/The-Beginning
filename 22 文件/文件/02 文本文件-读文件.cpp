//文本文件  读文件
//1.包含头文件
//#include<fstream>
//#include<iostream>
//#include<string>
//using namespace std;
//
//void test01()
//{
//	//2.创建流对象
//	ifstream ifs;
//
//	//3.打开文件  并且判断是否打开成功
//	ifs.open("test.txt", ios::in);
//
//	if (!ifs.is_open())
//	{
//		cout << "文件打开失败" << endl;
//		return;
//	}
//	//4.读数据(共有四种方法)
//
//	//第一种
//	/*char buf[1024] = { 0 };
//	while (ifs >> buf)
//	{
//		cout << buf << endl;
//	}*/
//
//	//第二种
//	/*char buf[1024] = { 0 };
//	while (ifs.getline(buf, sizeof(buf)))
//	{
//		cout << buf << endl;
//	}*/
//
//	//第三种(需要包含string库)
//	/*string buf;
//	while (getline(ifs, buf))
//	{
//		cout << buf << endl;
//	}*/
//	
//	//第四种
//	char c;
//	while ((c = ifs.get()) != EOF) //EOF end of file 文件结束标识
//	{
//		cout << c;
//	}
//
//	//5.关闭文件
//	ifs.close();
//}
//
//
//int main()
//{
//
//	test01();
//
//
//
//	system("pause");
//	return 0;
//}