//任务二：
//在实验任务一的基础上，实现插入排序

//#include<iostream>
//using namespace std;
//
//struct Node
//{
//    Node* next;
//    int data;
//};
//
//bool list_search(Node* L, int i, int& e)//在带头结点的单链表L中查找第i个元素，如果查找成功则用e返回其值
//{
//    Node* p = L->next;  /*使指针p指向第1个元素结点*/
//    int  j = 1;        /*计数器赋初值为1*/
//    while (p && j < i)  /*顺着后继指针查找第i个元素结点*/
//    {
//        p = p->next;
//        j++;
//    }
//    if (!p && j > i)
//        return 0;  /*如果i值不合法，即i值小于1或大于表长，则出错*/
//
//    e = p->data;    /*如果第i个元素存在，则将该元素值赋给e*/
//    return 1;
//}
//
//bool list_insert(Node*& L, int i, int x)//在带头结点的单链表L中第i个位置之前插入新元素x
//{
//    Node* p = L;
//    int j = 0;
//    while (p != NULL && j < i - 1) /*寻找插入位置，并使p指向插入位置的前驱结点，即L中的第i-1个位置*/
//    {
//        p = p->next;
//        ++j;
//    }
//    if (p == NULL || j > i - 1)
//    {
//        cout << "ERROR" << endl;
//        return 0; /*若位置不正确,即i小于1或大于表的长度加1，则出错*/
//    }
//    Node* s = new Node; /*分配一个新结点的空间*/
//    s->data = x;   /*为新结点数据域赋值*/
//    /*下面两条语句就是完成修改链，将新结点s插入到p结点之后*/
//    s->next = p->next;  /*新结点指针域指向p的后继结点*/
//    p->next = s;   /*新结点成为p的后继结点*/
//    return 1;
//}
//
//void list_delete(Node* L, int i)//在带头结点的单链表L中查找第i个元素，如果查找成功则删除该元素所在结点
//{
//    Node* q = L;
//    Node* p = L->next;  /*使指针p指向第1个元素结点*/
//    int  j = 1;        /*计数器赋初值为1*/
//    while (p && j < i)  /*顺着后继指针查找第i个元素结点*/
//    {
//        q = p;
//        p = p->next;
//        j++;
//    }
//    if (!p && j > i)
//    {
//        cout << "ERROR" << endl;
//        return;  /*如果i值不合法，即i值小于1或大于表长，则出错*/
//    }
//
//    //如果第i个元素存在，则将该元素所在结点删除
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


