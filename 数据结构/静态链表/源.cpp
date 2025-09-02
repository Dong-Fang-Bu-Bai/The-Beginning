#include<iostream>

using namespace std;

//typedef struct
//{
//	int data;
//	int next;
//
//}Linklist[10];

typedef struct Node
{
	int data;
	int next;

}Linklist;



int main()
{
	Linklist a;
	cout << sizeof(a);



	system("pause");
	return 0;
}