#include<iostream>
using namespace std;
int main6()
{



	//指针和数组
	//利用指针访问数组中的元素

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	cout << "第一个元素为：" << arr[0] << endl;



	int* p = &arr[0];
	//      int*p=arr;     也可以     arr就是数组的首地址

	cout << "利用指针访问第一个元素：" << *p << endl;

	p++;//让指针向后偏移4个字节,因为它是一个整型指针

	cout << "利用指针访问第二个元素：" << *p << endl;


	cout << "利用指针遍历数组" << endl;

	//int* p2 = arr;
	//for (int i=0;i<10;i++)
	//{
	//	//cout << arr[i] << endl;
	//	cout << *p2 << endl;
	//	p2++;
	//}
	//       我还想出来下面这种，也行得通
	for (int* p2 = arr; p2 < arr + 10; p2++)
	{
		cout << *p2 << endl;
	}


	system("pause");
	return 0;
}