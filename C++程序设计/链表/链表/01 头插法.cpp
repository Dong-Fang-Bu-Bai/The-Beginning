//（1）根据输入的一系列整数，以0标志结束，用头插法建立单链表，并输出单链表中各元素值，
// 观察输入的内容与输出的内容是否一致。

//#include<iostream>
//using namespace std;
//
//struct Node
//{
//	int num;
//	Node* next;
//} *head;
//
//
//int main()
//{
//	head = NULL;
//	int nodenum;
//	cin >> nodenum;
//	while (nodenum != 0)
//	{
//		Node* p = new Node;
//		p->num = nodenum;
//		p->next = head;
//		head = p;
//		cin >> nodenum;
//	}
//	Node* p = head;
//	while (p != NULL)
//	{
//		cout << p->num << endl;
//		p = p->next;
//	}
//	system("pause");
//	return 0;
//}