#include<iostream>
using namespace std;

//const的使用场景

//创建学生结构体
struct student
{
	string name;
	int age;
	int score;
};
//将函数中的形参改为指针，可以减少内存空间，而且不会复制新的副本出来


void printStudent(const student *s)//用指针可以节省空间，加const可以防止误操作
{
	//s->age=150;   此时就无法修改值了，可以防止误操作
	cout << "姓名：" << s->name << "年龄：" << s->age << "得分：" << s->score << endl;
}


int main6()
{
	//创建结构体变量
	struct student s = { "张三",15,70 };

	//通过函数打印结构体变量信息
	printStudent(&s);


	system("pause");
	return 0;
}