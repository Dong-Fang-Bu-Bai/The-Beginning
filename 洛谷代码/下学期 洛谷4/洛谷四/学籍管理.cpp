//# P5266 【深基17.例6】学籍管理
//
//## 题目描述
//
//您要设计一个学籍管理系统，最开始学籍数据是空的，然后该系统能够支持下面的操作（不超过 $10 ^ 5$ 条）：
//
//- 插入与修改，格式`1 NAME SCORE`：在系统中插入姓名为 NAME(由字母和数字组成不超过 20 个字符的字符串，区分大小写) ，分数为 $\texttt{ SCORE }$（$0 < \texttt{ SCORE } < 2 ^ {31}$） 的学生。如果已经有同名的学生则更新这名学生的成绩为 SCORE。如果成功插入或者修改则输出`OK`。
//	- 查询，格式`2 NAME`：在系统中查询姓名为 NAME 的学生的成绩。如果没能找到这名学生则输出`Not found`，否则输出该生成绩。
//	- 删除，格式`3 NAME`：在系统中删除姓名为 NAME 的学生信息。如果没能找到这名学生则输出`Not found`，否则输出`Deleted successfully`。
//	- 汇总，格式`4`：输出系统中学生数量。
//
//	## 输入格式
//
//	无
//
//	## 输出格式
//
//	无
//
//	## 输入输出样例 #1
//
//	### 输入 #1
//
//	```
//	5
//	1 lxl 10
//	2 lxl
//	3 lxl
//	2 lxl
//	4
//	```
//
//	### 输出 #1
//
//	```
//	OK
//	10
//	Deleted successfully
//	Not found
//	0
//	```

//注意运行时间限制！

#include<iostream>
using namespace std;

struct Student
{

	string Name="";
	unsigned int Score = 0;

}; 

Student a[100005];

int Stu_Count = 0;

void Change()
{
	string name;
	cin >> name;

	int score;
	cin >> score;

	for (int i = 0; i < Stu_Count; i++)
	{
		if (a[i].Name == name)
		{
			a[i].Score = score;
			cout << "OK" << endl;
			return;
		}
	}

	a[Stu_Count].Name = name;
	a[Stu_Count].Score = score;
	Stu_Count++;
	cout << "OK" << endl;
	return;
}


void Find()
{
	string name;
	cin >> name;

	for (int i = 0; i < Stu_Count; i++)
	{
		if (a[i].Name == name)
		{
			cout << a[i].Score << endl;
			return;
		}

	}

	cout << "Not found" << endl;
	return;

}

void Delete()
{
	string name;
	cin >> name;

	for (int i = 0; i < Stu_Count; i++)
	{
		if (a[i].Name == name)
		{
			a[i].Name = a[Stu_Count-1].Name;
			a[i].Score = a[Stu_Count - 1].Score;
			Stu_Count--;
			cout << "Deleted successfully" << endl;
			return;
		}
	}

	cout << "Not found" << endl;
	return;

}



void CountOn()
{

	cout << Stu_Count << endl;

}

int main()
{
	int num;
	cin >> num;


	for (int i = 0; i < num; i++)
	{
		int mode;
		cin >> mode;

		switch (mode)
		{
		case 1:
			Change();
			break;

		case 2:
			Find();
			break;

		case 3:
			Delete();
			break;


		case 4:
			CountOn();
			break;


		}
	}


	system("pause");
	return 0;
}

