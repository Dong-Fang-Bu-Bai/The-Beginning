//（2）根据输入的一系列整数，以0标志结束，用尾插法建立单链表，并输出单链表中各元素值，
// 观察输入的内容与输出的内容是否一致。



#include<iostream>
using namespace std;

struct Node
{
	Node* next;
	int data;
};


int main2()
{
	Node* head=new Node;
	head->next = NULL;
	Node* r = head;
	int Nodenum;

	cin >> Nodenum;
	while (Nodenum != 0)
	{
		Node* p = new Node;
		p->data = Nodenum;
		r->next = p;
		p->next = NULL;
		r = p;
		cin >> Nodenum;
	}

	
		head = head->next;
	

	while (head != NULL)
	{
		cout << head->data << endl;;
		head = head->next;
	}








	system("pause");
	return 0;
}