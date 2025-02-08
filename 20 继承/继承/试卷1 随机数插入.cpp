//#include<iostream>
//#include<cstdlib>
//#include<ctime>
//#include<iomanip>
//using namespace std;
//
////题目本身给的条件就是错的，真是差劲！
//bool insert(int array[], int i, int n);
//
//int main2()
//{
//	const int M = 20;
//	int n, i = 0;
//	int a[M] = { 0 };
//	srand(time(0));
//	while (i < M)
//	{
//		do
//		{
//			n = rand() % 100;
//		} 
//		while (n < 10);
//
//		if (insert(&a[0], i, n))//或者直接填 a 也可以，本身就代表首地址！
//		{
//			i++;
//		}
//	}
//		cout << "生成的数组：" << endl;
//		for (i = 0; i <M; i++)
//		{
//			cout << a[i] << " ";
//			if ((i+1) % 10 == 0)
//			{
//				cout << endl;
//			}
//		}
//	system("pause");
//	return 0;
//}
//
//bool insert(int array[], int i, int n)
//{
//	int k = 0;
//	for (k; k < i; k++)
//	{
//		if (array[k] == n)
//		{
//			return false;
//		}
//	}
//
//	array[i] = n;
//	return true;
//}