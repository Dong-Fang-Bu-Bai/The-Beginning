//��2�����������һϵ����������0��־��������β�巨����������������������и�Ԫ��ֵ��
// �۲����������������������Ƿ�һ�¡�



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