//#include <iostream>
//#include <fstream>  
//#include <iomanip>
//#include <cstdlib> 
//#include<string>
//using namespace std;
//
///*
//定义一个Pari类模板，用上述的第一个数据作为key，第二个数据作为value，根据数据类型生成不同的类对象。
//在Pari类模板内重载<(小于号）运算符，用于比较两个Pari对象的大小。
//编写程序，读入以上数据，分别这两类数据中值最大的数据。
//不能把所有数据都保存起来，最后才求最大值，应该一边读入数据一边比较，只保留最大值的类对象。
//*/
//
//
//
//template <class T1, class T2>class Pair 
//{
//private:
//	T1 key;
//	T2 value;
//public:
//	Pair(T1 _key, T2 _value) :key(_key), value(_value) {};//使用初始化列表的构造函数
//
//	bool operator < (const Pair& x)//成员函数实现小于号重载
//	{
//		return value < x.value;
//	};
//
//	//T1和T2的公共接口
//	T1 GetKey()
//	{
//		return key;
//	}
//
//	T2 GetValue()
//	{
//		return value;
//	}
//
//	//打印函数
//	void Show()
//	{
//		cout << key << ":" << value << endl;
//	}
//};
//
//class MyInput 
//{
//private:
//	string data[10];
//	int len;
//public:
//	MyInput(string in = "")  // 把输入的字符串按逗号分成单独的字符串
//	{
//		int j = 0;
//		string temp = "";
//		len = 0;
//		for (int i = 0; i < in.size(); i++)
//		{
//			if (in[i] == ',')
//			{
//				data[j++] = temp;
//				temp = "";
//			}
//			else
//				temp = temp + in[i];
//		}
//		data[j] = temp;
//		len = j + 1;   //记录有效的数据个数
//	}
//	string GetInput(int index)
//	{
//		if (index < len)
//			return data[index];
//		else
//			return "";
//	}
//
//	int GetDataCount()  //返回数据个数
//	{
//		return len;
//	}
//
//	bool IsDigit(int index)  //判断某个字符串是否都是数字
//	{
//		string s = data[index];
//		for (int i = 0; i < s.size(); i++)
//			if (s[i] < '0' || s[i]>'9')
//				return false;
//		return true;
//	}
//};
//int main() 
//{
//	//freopen("test.txt", "r", stdin);
//
//	Pair <int, int> max1(-1, 0); //创建对象用于保存最大值
//	Pair <string, double> max2("", 0);
//
//	string s;
//	while (getline(cin, s))
//	{
//		if (s.empty())
//		{
//			break;
//		}
//		MyInput in(s);
//		if (in.IsDigit(0))  //判断第一个数据是不是数字
//		{
//			Pair <int, int> a(stoi(in.GetInput(0)), stoi(in.GetInput(1)));
//			if (max1.GetKey() == -1)
//				max1 = a;
//			else
//				if (max1 < a)
//					max1 = a;
//		}
//		else   // key 是字符串类型
//		{
//			Pair <string, double> a(in.GetInput(0), stod(in.GetInput(1)));
//			if (max2.GetKey() == "")
//				max2 = a;
//			else
//				if (max2 < a)
//					max2 = a;
//		}
//	}
//
//	max1.Show();
//	max2.Show();
//
//	system("pause");
//	return 0;
//}