#include<iostream>
using namespace std;
int main2()
{

	for (int i = 0; i <=100; i++)
	{
		//如果是奇数输出，偶数不输出
		if (i % 2 == 0)
		{
			continue;//可以筛选条件，执行到此就不再向下执行，执行下一次循环
		}
		cout << i << endl;

	}











	system("pause");
	return 0;


}