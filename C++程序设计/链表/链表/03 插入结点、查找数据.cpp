

//#include<iostream>
//using namespace std;
//
////��3���ڵ�����ĵ�i��Ԫ��֮�����һ��ֵΪx��Ԫ�أ�����������ĵ������и�Ԫ��ֵ��
////��5���ڵ������в��ҵ�i��Ԫ�أ�������ҳɹ�������ʾ��Ԫ�ص�ֵ��������ʾ��Ԫ�ز����ڡ�
//
//struct Node
//{
//    Node* next;
//    int data;
//};
//
//enum status { OK, ERROR };
//
//status list_search(Node* L, int i, int& e)//�ڴ�ͷ���ĵ�����L�в��ҵ�i��Ԫ�أ�������ҳɹ�����e������ֵ
//{
//     Node* p = L->next;  /*ʹָ��pָ���1��Ԫ�ؽ��*/
//    int  j = 1;        /*����������ֵΪ1*/
//    while (p && j < i)  /*˳�ź��ָ����ҵ�i��Ԫ�ؽ��*/
//    {
//        p = p->next;
//        j++;
//    }
//    if (!p && j > i)
//        return ERROR;  /*���iֵ���Ϸ�����iֵС��1����ڱ��������*/
//    
//    e = p->data;    /*�����i��Ԫ�ش��ڣ��򽫸�Ԫ��ֵ����e*/
//    return OK;
//}
//
//status list_insert(Node*& L, int i, int x)//�ڴ�ͷ���ĵ�����L�е�i��λ��֮ǰ������Ԫ��x
//{
//    Node* p = L;  
//    int j = 0;
//    while (p != NULL && j < i - 1) /*Ѱ�Ҳ���λ�ã���ʹpָ�����λ�õ�ǰ����㣬��L�еĵ�i-1��λ��*/
//    {
//        p = p->next;
//        ++j;
//    }
//    if (p == NULL || j > i - 1) return ERROR; /*��λ�ò���ȷ,��iС��1����ڱ�ĳ��ȼ�1�������*/
//    Node *s = new Node; /*����һ���½��Ŀռ�*/
//    s->data = x;   /*Ϊ�½��������ֵ*/
//    /*������������������޸��������½��s���뵽p���֮��*/
//    s->next = p->next;  /*�½��ָ����ָ��p�ĺ�̽��*/
//    p->next = s;   /*�½���Ϊp�ĺ�̽��*/
//    return OK;
//}
//
//int main3()
//{
//    Node* head = new Node;
//    head->next = NULL;
//    Node* r = head;
//    int Nodenum;
//
//    cin >> Nodenum;
//    while (Nodenum != 0)
//    {
//        Node* p = new Node;
//        p->data = Nodenum;
//        r->next = p;
//        p->next = NULL;
//        r = p;
//        cin >> Nodenum;
//    }
//    
//    int i;
//    cin >> i;
//    int e = 0;
//     list_search(head, i,e);
//     cout << e << endl;
//
//     int j;
//     cin >> j;
//     int x;
//     cin >> x;
//     list_insert(head, j, x);
//
//     head = head->next;
//
//
//     while (head != NULL)
//     {
//         cout << head->data << endl;;
//         head = head->next;
//     }
//
//    system("pause");
//    return 0;
//
//}