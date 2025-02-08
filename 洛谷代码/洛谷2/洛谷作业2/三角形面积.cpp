//一个三角形的三边长分别是
//𝑎
//a、
//𝑏
//b、
//𝑐
//c，那么它的面积为
//𝑝
//(
//	𝑝
//	−
//	𝑎
//)
//(
//	𝑝
//	−
//	𝑏
//	)
//	(
//		𝑝
//		−
//		𝑐
//		)
//	p(p−a)(p−b)(p−c)
//	​
//	，其中
//	𝑝
//	=
//	1
//	2
//	(
//		𝑎
//		+
//		𝑏
//		+
//		𝑐
//		)
//	p =
//	2
//	1
//	​
//	(a + b + c)。输入这三个数字，计算三角形的面积，四舍五入精确到
//	1
//	1 位小数。
//
//	输入格式
//	第一行输入三个实数
//	𝑎
//	,
//	𝑏
//	,
//	𝑐
//	a, b, c，以空格隔开。
//
//	输出格式
//	输出一个实数，表示三角形面积。精确到小数点后
//	1
//	1 位。

#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

int main1()
{
	double a, b, c;
	cin >> a >> b >> c;
	double p = (a + b + c) / 2;
	double S =pow( (p * (p - a) * (p - b) * (p - c)) ,0.5);
	cout << fixed << setprecision(1) << S;

	system("pause");
	return 0;

}