//源文件用来定义类的成员函数

#include<iostream>
#include"GradeBook.h"
using namespace std;

GradeBook::GradeBook(string name)
{
	setCourseName(name);
}

void GradeBook::setCourseName(string name)
{
	if (name.size() <= 25)
	{
		courseName = name;
	}
	if (name.size() > 25)
	{
		courseName = name.substr(0, 25);

		cerr << "Name\"" << name << "\"超过了最大长度（25）\n" << "请确保名称长度在25个字节内" << endl;
	}
}

string GradeBook::getCourseName() const
{
	return courseName;
}

void GradeBook::displayMessage() const
{
	cout << "Welcome to the grade book for\n" << getCourseName() << "!" << endl;
}