//#include<iostream>
//#include<string>
//using namespace std;
//
//int main3()
//{
//
//	//cout << "Hello,\nHi\041" << strlen("Hello,\nHi\041")<<endl;
//	//注意，换行符也算一个有效字符！
//
//	/*int A[2][3] = { 0 };
//
//	cout << A << endl;
//	cout << *A << endl;
//	cout << **A << endl;*/
//
//	/*double A[6] = { 0 },* p = new double[6];
//
//	cout << sizeof(A) << endl << sizeof(p) << endl;*/
//	//在64位操作系统中，一个指针占用内存为8个字节
//
//	
//	string ab= "12343564";
//	cout << sizeof(ab) << endl;//string类的大小是固定的，为40（64位）/28（32位）
//	//cout << strlen(ab) << endl;  strlen不支持string类模板的读取,要用.size()
//	
//	//char str[10] = "1234";
//	//cout << strlen(str) << endl;//结果为4,不包括定义的空字符以及末尾的'\0'.
//	
//	char str[] = "1234";//此时 [ ] 应填5，包括末尾的'\0'
//	cout << sizeof(str) << endl;//结果为5，包括了末尾的'\0'
//	cout << strlen(str) << endl;//结果为4，不包括结尾的'\0'（即有效字符长度）
//
//
//	system("pause");
//	return 0;
//}