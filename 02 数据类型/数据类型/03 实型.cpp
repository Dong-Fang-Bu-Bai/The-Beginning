#include<iostream>
using namespace std;

int main3()
{


	//1.单精度 float 6-7位
	//2.双精度 double 15-16位
	//默认情况下，输出一个小鼠，会显示出6位有效数字，需要进行额外编码
	float f1 = 3.14f;//默认实型为双精度，因此须进行强制类型转换

	cout << "f1=" << f1 << endl;

	double d1 = 3.14159265;

	cout << "d1=" << d1 << endl;

	//统计float和double占用内存空间
	cout << "float占用内存空间为：" << sizeof(f1) << endl;//4字节
	
	cout << "double占用内存空间为：" << sizeof(d1) << endl;//8字节
	

	//科学计数法
	float f2 = 3e2;//3*10^2
	cout << "f2=" << f2 << endl;

	float f3 = 3e-2;//3*0.1^2
	cout << "f3=" << f3<< endl;

	system("pause");

	return 0;


}