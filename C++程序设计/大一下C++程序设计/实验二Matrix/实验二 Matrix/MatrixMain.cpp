#include<iostream>
#include"Matrix.h"

using namespace std;


//测试一 无参构造
void test1()
{
	Matrix a;
	a.printnum();
}


//测试二 插入操作符和提取运算符重载
void test2()
{
	Matrix a;
	cout << a;

	Matrix b;
	cin >> b;
	

	cout << a << b<<endl;
}


//测试三 矩阵的加减乘运算
void test3()
{
	Matrix a;
	cin >> a;
	Matrix b;
	cin >> b;

	cout << "a+b ";
	cout<<a + b;

	cout << "a-b ";
	cout << a - b;

	Matrix c;
	cin >> c;

	cout << "a+b+c ";
	cout<<a + b + c;

	cout << "a-b-c ";
	cout << a - b - c;

	cout << "a*b ";
	cout << a * b;

	cout << "a*b*c ";
	cout << a *b * c;


}


//测试四 +=、-=和*=运算符

void test4()
{
	Matrix a;
	cin >> a;
	Matrix b;
	cin >> b;

	cout << "a+=b ";
	a+=b ;
	cout << a;

	cin >> a;
	cin >> b;
	cout << "a-=b ";
	a -= b;
	cout << a;


	cin >> a;
	cin >> b;
	cout << "a*=b ";
	a *= b;
	cout << a;
}


//测试五  *的标量运算
void test5()
{
	Matrix a;
	cin >> a;
	cout << "请输入数字：" << endl;
	int b;
	cin >> b;

	cout << b * a;
}

//测试六  超载等式和不等式算子
void test6()
{
	Matrix a;
	cin >> a;
	Matrix b;
	cin >> b;
	cout << "a==b " << (a == b) << endl;
	cout << "a!=b "<<(a!=b) << endl;

}



int main()
{
	//test1();

	//test2();

	//test3();

	//test4();

	//test5();

	test6();


	system("pause");
	return 0;
}





