////��4��ɾ���������е�i��Ԫ�أ������ɾ����ĵ������и�Ԫ��ֵ��
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
//void list_delete(Node* L, int i)//�ڴ�ͷ���ĵ�����L�в��ҵ�i��Ԫ�أ�������ҳɹ���ɾ����Ԫ�����ڽ��
//{
//	Node* q = L;
//	Node* p = L->next;  /*ʹָ��pָ���1��Ԫ�ؽ��*/
//	int  j = 1;        /*����������ֵΪ1*/
//	while (p && j < i)  /*˳�ź��ָ����ҵ�i��Ԫ�ؽ��*/
//	{
//		q = p;
//		p = p->next;
//		j++;
//	}
//	if (!p && j > i)
//	{
//		cout << "ERROR" << endl;
//		return;  /*���iֵ���Ϸ�����iֵС��1����ڱ��������*/
//	}
//		
//	//�����i��Ԫ�ش��ڣ��򽫸�Ԫ�����ڽ��ɾ��
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