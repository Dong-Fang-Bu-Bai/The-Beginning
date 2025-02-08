#include<iostream>
using namespace std;


int main5()
{

	


	//转义字符	举例如下

	//换行符	\n
	cout << "hello world" << endl;//C++中可以使用
	cout << "hello world\n";//C语言都可以识别的

	//反斜杠	\\
	//作用：输出一些特殊字符,如反斜杠
	cout << "\\" << endl;//输入两个反斜杠，只会输出一个反斜杠，因为第一个反斜杠代表后面的特殊字符的提示语
	

	//水平制表符	\t
	//作用:可以整齐地输出数据，一个“\t”会占用总共8个字符,非常滴美观
	cout << "aa\thello world" << endl;
	cout << "aaa\thello world" << endl;
	cout << "aaaa\thello world" << endl;
	cout << "\tkkk" << endl;

	system("pause");
	return 0;





}