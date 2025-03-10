////（4）删除单链表中第i个元素，并输出删除后的单链表中各元素值。
//
//#include<iostream>
//using namespace std;
//
//struct Node
//{
//	Node* next;
//	int data;
//};
//
//
//void list_delete(Node* L, int i)//在带头结点的单链表L中查找第i个元素，如果查找成功则删除该元素所在结点
//{
//	Node* q = L;
//	Node* p = L->next;  /*使指针p指向第1个元素结点*/
//	int  j = 1;        /*计数器赋初值为1*/
//	while (p && j < i)  /*顺着后继指针查找第i个元素结点*/
//	{
//		q = p;
//		p = p->next;
//		j++;
//	}
//	if (!p && j > i)
//	{
//		cout << "ERROR" << endl;
//		return;  /*如果i值不合法，即i值小于1或大于表长，则出错*/
//	}
//		
//	//如果第i个元素存在，则将该元素所在结点删除
//	q->next= p->next;
//	delete p;
//	cout << "OK" << endl;
//	return;
//}
//
//int main4()
//{
//	Node* head = new Node;
//	head->next = NULL;
//	Node* r = head;
//	int Nodenum;
//
//	cin >> Nodenum;
//	while (Nodenum != 0)
//	{
//		Node* p = new Node;
//		p->data = Nodenum;
//		r->next = p;
//		p->next = NULL;
//		r = p;
//		cin >> Nodenum;
//	}
//
//	int i;
//	cin >> i;
//
//	list_delete(head, i);
//
//
//	head = head->next;
//
//
//	while (head != NULL)
//	{
//		cout << head->data << endl;
//		head = head->next;
//	}
//
//
//
//
//	system("pause");
//	return 0;
//}