//#include<iostream>
//#include<cstdlib>
//#include<ctime>
//#include<iomanip>
//using namespace std;
//
////��Ŀ��������������Ǵ�ģ����ǲ��
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
//		if (insert(&a[0], i, n))//����ֱ���� a Ҳ���ԣ�����ʹ����׵�ַ��
//		{
//			i++;
//		}
//	}
//		cout << "���ɵ����飺" << endl;
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