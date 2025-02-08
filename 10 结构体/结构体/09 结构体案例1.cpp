#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

//分别定义老师和学生的结构体

struct Student
{
	string Sname;
	int score;
};


struct Teacher
{
	string Tname;
	struct Student sArray[5];
};


//下面写为老师名称赋值、为学生名字和成绩赋值的函数
void distribution( struct Teacher tArray[3],int len1)
{
	
	for (int i = 0; i < len1; i++)
	{
		char a = 'A';
		tArray[i].Tname = char(a+ i);
		for (int j = 0; j < 5; j++)
		{
			char b = 'A';
			tArray[i].sArray[j].Sname = char(b + j);
			int random = rand() % 61 + 40;
			tArray[i].sArray[j].score = random;
		}
	}
	
}





//下面写输出所有内容的函数
void printall( struct Teacher tArray[3], int len1)
{
	for (int i = 0; i < len1; i++)
	{
		cout << "老师姓名_" << tArray[i].Tname << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "学生姓名_" << tArray[i].sArray[j].Sname
				<< "  " << "成绩：" << tArray[i].sArray[j].score
				<< endl;

		}
	}
}



int main9()
{
	//设定随机数种子
	srand((unsigned int)time(NULL));

   //下面要创建老师和学生的结构体数组

	struct Teacher tArray[3];
	

	

	//下面要创建长度参数len1和len2，分别代表老师和学生数组中元素数量
	int len1 = sizeof(tArray) / sizeof(tArray[0]);
	
	

	//下面分别引用函数

	distribution(tArray, len1);

	printall(tArray, len1);


	system("pause");
	return 0;

}