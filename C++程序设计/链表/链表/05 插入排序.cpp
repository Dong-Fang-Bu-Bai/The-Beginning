//�������
//��ʵ������һ�Ļ����ϣ�ʵ�ֲ�������

//#include<iostream>
//using namespace std;
//
//struct Node
//{
//    Node* next;
//    int data;
//};
//
//bool list_search(Node* L, int i, int& e)//�ڴ�ͷ���ĵ�����L�в��ҵ�i��Ԫ�أ�������ҳɹ�����e������ֵ
//{
//    Node* p = L->next;  /*ʹָ��pָ���1��Ԫ�ؽ��*/
//    int  j = 1;        /*����������ֵΪ1*/
//    while (p && j < i)  /*˳�ź��ָ����ҵ�i��Ԫ�ؽ��*/
//    {
//        p = p->next;
//        j++;
//    }
//    if (!p && j > i)
//        return 0;  /*���iֵ���Ϸ�����iֵС��1����ڱ��������*/
//
//    e = p->data;    /*�����i��Ԫ�ش��ڣ��򽫸�Ԫ��ֵ����e*/
//    return 1;
//}
//
//bool list_insert(Node*& L, int i, int x)//�ڴ�ͷ���ĵ�����L�е�i��λ��֮ǰ������Ԫ��x
//{
//    Node* p = L;
//    int j = 0;
//    while (p != NULL && j < i - 1) /*Ѱ�Ҳ���λ�ã���ʹpָ�����λ�õ�ǰ����㣬��L�еĵ�i-1��λ��*/
//    {
//        p = p->next;
//        ++j;
//    }
//    if (p == NULL || j > i - 1)
//    {
//        cout << "ERROR" << endl;
//        return 0; /*��λ�ò���ȷ,��iС��1����ڱ�ĳ��ȼ�1�������*/
//    }
//    Node* s = new Node; /*����һ���½��Ŀռ�*/
//    s->data = x;   /*Ϊ�½��������ֵ*/
//    /*������������������޸��������½��s���뵽p���֮��*/
//    s->next = p->next;  /*�½��ָ����ָ��p�ĺ�̽��*/
//    p->next = s;   /*�½���Ϊp�ĺ�̽��*/
//    return 1;
//}
//
//void list_delete(Node* L, int i)//�ڴ�ͷ���ĵ�����L�в��ҵ�i��Ԫ�أ�������ҳɹ���ɾ����Ԫ�����ڽ��
//{
//    Node* q = L;
//    Node* p = L->next;  /*ʹָ��pָ���1��Ԫ�ؽ��*/
//    int  j = 1;        /*����������ֵΪ1*/
//    while (p && j < i)  /*˳�ź��ָ����ҵ�i��Ԫ�ؽ��*/
//    {
//        q = p;
//        p = p->next;
//        j++;
//    }
//    if (!p && j > i)
//    {
//        cout << "ERROR" << endl;
//        return;  /*���iֵ���Ϸ�����iֵС��1����ڱ��������*/
//    }
//
//    //�����i��Ԫ�ش��ڣ��򽫸�Ԫ�����ڽ��ɾ��
//    q->next = p->next;
//    delete p;
//    return;
//}
//
//void insertsort(Node* L, int n)
//{
//    for (int i = 1; i <= n - 1; i++)
//    {
//    
//         int max = 0;
//         int maxp = 1;
//         for (int j=i;j<=n;j++)
//         {
//             int e = 0;
//             list_search(L, j, e);
//             if (e > max)
//             {
//                 max = e;
//                 maxp = j;
//             }
//         }
//         list_delete(L, maxp);
//         list_insert(L, i, max);
//
//    }
//}
//
//int main5()
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
//    int nums;
//    cin >> nums;
//    insertsort(head, nums);
//    cout << "OK" << endl;
//
//    head = head->next;
//    while (head != NULL)
//    {
//        cout << head->data << endl;;
//        head = head->next;
//    }
//
//    system("pause");
//    return 0;
//}


