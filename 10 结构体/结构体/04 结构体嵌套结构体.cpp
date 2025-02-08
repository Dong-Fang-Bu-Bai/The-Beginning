#include<iostream>
using namespace std;

//定义学生结构体
struct student
{
	string name;//姓名
	int age;//年龄
	int score;//分数
};



//定义老师结构体
struct teacher
{
	int id;
	string name;
	int age;
	struct student stu;

};



int main4()
{

	//结构体嵌套结构体
	//创建老师
	teacher t;
	t.id = 10000;
	t.name = "老王";
	t.age = 50;
	t.stu.name = "小王";
	t.stu.age = 20;
	t.stu.score = 60;


	cout << "老师姓名:" << t.name << endl
		<< "老师编号:" << t.id << endl
		<< "老师年龄：" << t.age << endl
		<< "老师辅导的学生姓名：" << t.stu.name << endl
		<< "学生年龄：" << t.stu.age << endl
		<< "学生的考试分数为：" << t.stu.score << endl;





	system("pause");
	return 0;
}