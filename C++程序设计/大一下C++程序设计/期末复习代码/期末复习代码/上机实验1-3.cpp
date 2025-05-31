//定义一个MyInput类，接受一个字符串作为构造函数的输入，把该字符串按逗号拆成多个数据。
// 编写一个GetInput(int)函数，获取字符串的第i个数据（i从0开始）。
// 
//定义一个Point类，有两个数据成员，记录平面直角坐标系的x, y坐标。
// 
//定义一个Quadrilateral类，有4个数据成员（Point），表示平面上四个坐标点。
// 
//编写以下成员函数：
// 
//（1）按4个点的顺序判断该四边形是否是矩形
//（2）计算面积：如果四边形是矩形，则计算该矩形的面积，否则面积当成0
//
//编写一个main函数，读入数据，每行有8个数据，表示四边形4个点的坐标，输出该四边形的面积(保留4位小数)。
// 
//输入数据：
//1, 2, 3, 4, 5, 6, 7, 8
//1, 0, 0, 1, -1, 0, 0, -1
// 
//输出结果：
//0
//2.0000
//说明：第一行8个数据表示4个坐标点：(1, 2), (3, 4), (5, 6), (7, 8)，
// 
// 这四个点并不构成矩形，所以输出0.第二行表示(1, 0), (0, 1), (-1, 0), (0, -1) 四个点，
// 
// 按顺序连接起来构成矩形，其面积为2。(本题分数:25)


//#include<iostream>
//#include<iomanip>
//#include<cmath>
//#include <string>
//using namespace std;
//
////MyInput
//class MyInput 
//{
//private:
//	string data[10];
//
//public:
//	MyInput(string in)  // 把输入的字符串按逗号分成单独的字符串
//	{
//		int j = 0;
//		string temp = "";
//		for (int i = 0; i < in.size(); i++)
//		{
//			if (in[i] == ',')
//			{
//				data[j++] = temp;
//				temp = "";
//			}
//			else
//			{
//				temp += in[i];
//			}
//		}
//
//		data[j] = temp;
//	}
//
//	string GetInput(int index) const
//	{
//		if (index > 9)
//		{
//			cerr << "错误：超出索引上限！" << endl;
//			exit(0);
//		}
//
//		return data[index];
//	}
//};
//
////Point
//class Point 
//{
//private:
//
//	double x, y;
//
//public:
//
//	Point(double _x = 0, double _y = 0)
//	{
//		x = _x;
//		y = _y;
//	}
//
//	double GetX() const
//	{
//		return x;
//	}
//
//	double GetY() const
//	{
//		return y;
//	}
//
//	double Distance(Point b) const //计算两点之间的距离
//	{
//		return sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
//	}
//
//	void Display() //显示坐标点，测试用
//	{
//		cout << "(" << x << "," << y << ") ";
//		return;
//	}
//
//};
//   
////Quadrilateral
//class Quadrilateral 
//{
//private:
//
//	Point p[4];		//4个点的坐标
//
//public:
//	Quadrilateral(double _x[], double _y[])
//	{
//
//		for (int i = 0; i < 4; i++)
//		{
//			p[i] = Point(_x[i], _y[i]);
//		}
//
//	}
//
//	bool IsRectangle() //判断是否是矩形
//	{
//		//采用对角线相等并平分的方法
//		//先判断中点是否重合
//		if (abs(p[0].GetX() + p[2].GetX() - p[1].GetX() - p[3].GetX()) < 1e-8 
//			&& abs(p[0].GetY() + p[2].GetY() - p[1].GetY() - p[3].GetY()) < 1e-8)
//		{
//			//判断长度是否一样
//			double len1 = p[0].Distance(p[2]);
//			double len2 = p[1].Distance(p[3]);
//
//			if (abs(len1 - len2) < 1e-8 && len1 > 1e-8 && len2 > 1e-8) //对角线长度要大于0，排除4个点重合的情况
//			{
//				return true;
//			}
//		}
//
//		return false;
//	}
//
//
//	double Area() //计算矩形的面积
//	{
//		if (IsRectangle())
//		{
//
//			double len1 = p[0].Distance(p[1]);
//			double len2 = p[1].Distance(p[2]);
//
//			return len1 * len2;
//		}
//		else
//		{
//			return 0;
//		}
//	}
//
//
//	void Display()
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			p[i].Display();
//		}
//		cout << endl;
//	}
//};
//
////根据输入的8个数据，生成一个矩形对象
//Quadrilateral MakeQuadrilateral(string s)
//{
//
//	MyInput in(s);
//	double x[4], y[4];
//
//	for (int i = 0; i < 4; i++)
//	{
//		x[i] = stod(in.GetInput(i * 2));
//		y[i] = stod(in.GetInput(i * 2 + 1));
//	}
//	return Quadrilateral(x, y);
//}
//
//int main() 
//{
//	//freopen("s:\\temp\\12.txt","r",stdin);
//	string s;
//
//	while (getline(cin, s))
//	{
//		if (s.empty())
//		{
//			break;
//		}
//
//		Quadrilateral x = MakeQuadrilateral(s);
//
//		double y = x.Area();
//		if (y == 0)
//		{
//			cout << "0" << endl;
//		}
//		else
//		{
//			cout << fixed << setprecision(4) << y << endl;
//		}
//			
//	}
//
//	system("pause");
//	return 0;
//}

