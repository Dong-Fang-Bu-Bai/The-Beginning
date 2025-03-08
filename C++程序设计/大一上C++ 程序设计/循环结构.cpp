//【1】                      编写单条C++语句，完成下述任务  
//a)       输入整型变量x；
//b)       输入整型变量y；
//c)       设置整型变量i为1；
//d)       设置整型变量power为1；
//e)       变量power乘以变量x后，结果赋值给变量power；
//f)       变量i后置方式自增1；
//g)       判断变量i是否小于或等于变量y；
//h)       输出变量power。
//【2】                      利用任务【1】的语句，编写计算x的y次幂的程序，要求使用while循环语句。  

//int x, y;
//cin >> x >> y;
//int i = 1;
//int power = 1;
//while (i <= y)
//{
//	power = power*x;
//	i++;
//}
//
//
//cout << power << endl;


//【3】                      在计算机应用中，我们常常会遇到寻找最大数的问题。请通过循环语句判定和打印用户输入的10个数中的最大数。你的程序应用到下面3个变量：
//counter：计数器，用于记录已输入数的个数；
//number：当前输入到程序的数；    
//largest：截至当前输入已经找到的最大数。
//int counter = 0;
//int largest = 0;
//
//for (counter; counter < 10; counter++)
//{
//	int number;
//	cin >> number;
//	if (number > largest)
//	{
//		largest = number;
//	}
//
//}
//
//
//cout << largest << endl;

//
//【4】                      用类似任务【3】的方法，从10个数中寻找最大的数和最小的数。并解决歌星大奖赛问题。在歌星大奖赛中，有10个评委为参赛的选手打分，
//分数为1~100分。选手最后得分为：去掉一个最高分和一个最低分后其余8个分数的平均值。请编写一个程序实现。
//int array[10];
//	int total = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		int num;
//		cin >> num;
//		array[i] = num;
//	}
//
//	for (int i = 0; i < 9; i++)
//	{
//		for (int j = 0; j < 9 - i; j++)
//		{
//			int temp;
//			if (array[j] > array[j + 1])
//			{
//				temp = array[j];
//				array[j] = array[j + 1];
//				array[j+ 1] = temp;
//			}
//		}
//	}
//
//
//	for (int k = 1; k <= 8; k++)
//	{
//		total = total + array[k];
//	}
//
//	double avg = double(total / 8);
//	cout << avg << endl;
//


//【5】                      中国有句俗语叫“三天打鱼两天晒网”。某人从1990年1月1日起开始“三天打鱼两天晒网”，问这个人在以后的某一天中是“打鱼”还是“晒网”。 （选做）
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int num;
class Date
{
private:
	int _year;
	int _day;
	int _month = 0;

	int getMonthDay(int year, int month)
	{
		int monthArr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		//闰年 二月不同
		if (month == 2 && ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)))
		{
			return 29;
		}

		return monthArr[month];
	}
public:
	Date(int year, int month, int day) :
		_year(year), _month(month), _day(day)
	{
	}
	//有参数的构造函数

	bool operator>(const Date& d)
	{
		if (_year > d._year)
		{
			return true;
		}
		else if (_year == d._year && _month > d._month)
		{
			return true;
		}
		else if (_year == d._year && _month == d._month && _day > d._day)
		{
			return true;
		}

		return false;
	}

	bool operator==(const Date& d)
	{
		if (_year == d._year && _month == d._month && _day == d._day)
		{
			return true;
		}
		return false;
	}
	Date& operator-=(int day) {
		if (day < 0) {
			return *this += (-day);
		}

		_day -= day;
		while (_day < 0)
		{
			_month--;
			if (_month == 0)
			{
				_month = 12;
				_year--;
			}
			_day += getMonthDay(_year, _month);

		}

		return *this;
	}

	bool operator != (const Date& d)
	{
		if (*this == d)
			return false;
		return true;
	}

	Date& operator+=(int day)
	{
		// a+=b,a本身变化了，因此最后返回a


		if (day < 0)
		{
			return *this -= day;
		}

		_day += day;

		while (_day > getMonthDay(_year, _month)) { //天数已经超过当前月份
			_day -= getMonthDay(_year, _month);
			_month++;
			if (_month > 12) {
				_year++;
				_month = 1;
			}
		}

		return *this;
	}

	Date operator++(int)
	{
		Date temp(*this);
		*this += 1;
		return temp;
	}

	void getDaynums(const Date& d)
	{
		Date max = d;
		Date min = *this;

		if (!(max > min))
		{
			max = *this;
			min = d;
		}

		int day = 0;
		while (min != max)
		{
			min++;
			day++;
		}


		day++;
		num = day;
	}

};

int main3()
{
	//判断天数
	int day1, day2, mon1, mon2, year1, year2;
	scanf("%4d%2d%2d", &year1, &mon1, &day1);
	scanf("%4d%2d%2d", &year2, &mon2, &day2);
	Date d(year1, mon1, day1);
	Date d2(year2, mon2, day2);
	d.getDaynums(d2);

	cout << num << endl;


	//在得出天数后，判断是打鱼还是晒网

	switch (num % 5)
	{
	case 1:
	case 2:
	case 3:
		cout << "打鱼" << endl;
		break;
	case 4:
	case 0:
		cout << "晒网" << endl;
		break;
	}



	system("pause");
	return 0;
}