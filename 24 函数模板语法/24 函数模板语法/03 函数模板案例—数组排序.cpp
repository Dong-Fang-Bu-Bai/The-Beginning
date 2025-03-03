//#include<iostream>
//using namespace std;
//
////交换模板
//template<class T>
//void myswap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
////排序模板
//template<class T>
//void Risesort(T *a,int b)
//{
//	
//	for (int i = 0; i < b-1; i++)
//	{
//		int min = i;
//		for (int j = i; j < b-1; j++)
//		{
//			
//			if (a[min] > a[j+1])
//			{
//				min = j+1 ;
//			}
//		}
//
//		myswap(a[i], a[min]);
//
//	}
//}
//
//
////打印模板
//template <class T>
//void print(T* a,int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		cout<<a[i]<<endl;
//	}
//}
//
//
//void test01()
//{
//	//整型
//	int arr1[5] = { 3,5,7,1,2 };
//	//双精度型
//	double arr2[6] = { 2.2 , 7.6 , 1.3 , 5.7 , 4.5 , 4.1 };
//	//字符型
//	char arr3[7] = "ehusyt";
//
//	int len1 = sizeof(arr1) / sizeof(int);
//	Risesort(arr1,len1);
//
//	int len2 = sizeof(arr2) / sizeof(double);
//	Risesort(arr2,len2);
//
//	int len3 = sizeof(arr3) / sizeof(char);
//	Risesort(arr3, len3);
//
//	/*for (int i = 0; i < 5; i++)
//	{
//		cout << arr1[i] << endl;
//	}
//
//	for (int i = 0; i < 6; i++)
//	{
//		cout << arr2[i] << endl;
//	}*/
//
//	print(arr1, len1);
//	print(arr2, len2);
//	print(arr3, len3);
//}
//
//
//int main()
//{
//
//	test01();
//
//
//	system("pause");
//	return 0;
//}