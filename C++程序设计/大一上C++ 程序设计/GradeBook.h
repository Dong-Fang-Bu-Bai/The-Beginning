//头文件中写类的定义与成员函数的公开界面（接口）
#include<string>

class GradeBook
{

public:
	explicit GradeBook(std::string);
	void setCourseName(std::string);
	std::string getCourseName() const;
	void displayMessage() const;
private:
	std::string courseName;

};