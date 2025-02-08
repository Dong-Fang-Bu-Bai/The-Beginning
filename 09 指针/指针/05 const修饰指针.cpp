#include<IOSTREAM>
using namespace std;
int main5()
{

	int a = 10;
	int b = 20;
	
	
	
	//1.const修饰常量
	//常量指针，指向常量的指针
	const int* p = &a;
	//指针指向的值不可以改，指针的指向可以改
	//*p=20；错误，指针指向的值不可以改
	p = &b;
	
	//2.const修饰指针
	//指针常量,指针本身是常量
	int*const  p2 = &a;
	*p2 = 100;
	//p2=&b;错误，指针的指向不可以改，指针指向的值可以改

	//3.cinst修饰指针和变量
	const int* const  p3 = &a;
	//指针的指向 和 指针指向的值 都不可以改




	system("pause");
	return 0;
}
