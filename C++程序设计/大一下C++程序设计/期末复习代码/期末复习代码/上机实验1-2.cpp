//定义一个 Book（图书）类，在该类定义中包括以下数据成员和成员函数。 
// 数据成员：bookname（书名）、price（价格）和 number（存书数量）。 
// 成员函数：display()显示图书的情况；
// borrow()将存书数量减 1，并显示当前存书数量；
// restore()将存书数量加 1，并显示当前存书数量。
//在 main 函数中，要求创建某一种图书对象，并对该图书进行简单的显示、借阅和归还管理。(本题分数:25)


#include <iostream> 
#include <string>
using namespace std; 

class Book 
{

public:
	void setBook(string, double, int);
	void borrow();

	void restore();
	void display();

private:
	string  bookname;
	double price; int number;
};

//在类外定义 Book 类的成员函数
void Book::setBook(string name, double pri, int num) 
{

	bookname = name;
	price = pri;
	number = num;
}

void Book::borrow()
{
	if (number == 0) 
	{
		cout << "已无存书，退出！" << endl;
		abort();
	}

	number = number - 1;
	cout << "借一次，现存书量为：" << number << endl;
}

void Book::restore() 
{
	number = number + 1;
	cout << "还一次，现存书量为：" << number << endl;
}

void Book::display() 
{

	cout << "存书情况：" << endl << "bookname:" << bookname << endl << "price:" << price << endl << "number:" << number << endl;

}

int main() 
{

	char flag, ch;

	Book computer;

	computer.setBook("C++程序设计基础", 32, 1000);

	computer.display();

	ch = 'y'; 

	while (ch == 'y')
	{
		cout << "请输入借阅或归还标志(b/r)："; 
		cin >> flag;
		switch (flag) 
		{
			case 'b':   computer.borrow(); break;
			case 'r':   computer.restore();
		}
		cout << "是否继续？(y/n)";
		cin >> ch;
	}

	computer.display();

	system("pause");
	return 0;

}