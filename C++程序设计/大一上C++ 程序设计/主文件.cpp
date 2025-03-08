#include<iostream>
#include"GradeBook.h"
using namespace std;

int main1()
{
	GradeBook gradebook1("CS101 Introduction to C++");
	GradeBook gradebook2("CS102 C++ Data Structures");

	system("pause");
	gradebook1.displayMessage();
	gradebook2.displayMessage();

	system("pause");
	cout << gradebook1.getCourseName() << "\n" << gradebook2.getCourseName() << endl;

	system("pause");
	return 0;
}