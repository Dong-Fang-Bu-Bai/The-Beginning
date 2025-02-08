#include<iostream>
using namespace std;

//1.实验要求
//（1）输入链表的长度和各元素的值，用尾插法建立双向循环链表，并输出链表中各元素值，观察输入的内容与输出的内容是否一致。
//（2）在双向循环链表的第i个元素之前 / 后插入一个值为x的元素，并输出插入后的链表中各元素值。
// int position;
//cin >> position;
//cin >> data;
//insertbehind(Head, position, data);
// 
//（3）删除双向循环链表中第i个元素，并输出删除后的链表中各元素值。
// int position;
//cin >> position;
//deletenode(Head, position);
// 
// 
//（4）在双向循环链表中查找值为x元素，如果查找成功，则显示该元素在链表中的位置，否则显示该元素不存在。



struct DULNODE
{
    int data;  /*数据域*/
    struct DULNODE* prior; /*指向前驱结点的指针域*/
    struct DULNODE* next;/*指向后继结点的指针域*/
};

void insertfront(DULNODE* head, int position,int data)
{
    int i = 1;
    DULNODE* p = head;
    while (i<=position)
    {
        p= p->next;
        
        i++;

        if (p == head)
        {
            cout << "ERROR" << endl;
            return;
        }
    }

    DULNODE* s = new DULNODE;
    s->data = data;
     (p->prior)->next=s;
     s->prior = p->prior;
     s->next = p;
     p->prior = s;
}

void insertbehind(DULNODE* head, int position,int data)
{
    int i = 1;
    DULNODE* s = head;
    while (i <= position)
    {
        s = s->next;

        i++;
        if (s == head)
        {
         cout << "ERROR" << endl;
         return;
        }
    }

    DULNODE* k = new DULNODE;
    k->data = data;
    (s->next)->prior = k;
    k->prior = s;
    k->next = s->next;
    s->next = k;


}

void deletenode(DULNODE* head, int position)
{
    int i = 1;
    DULNODE* s = head;
    while (i <= position)
    {
        s = s->next;

        i++;
        if (s == head)
        {
            cout << "ERROR" << endl;
            return;
        }
    }

    (s->prior)->next = s->next;
    (s->next)->prior = s->prior;
    delete s;
}

void search(DULNODE* head, int num)
{
    DULNODE* s = head->next;
    int i = 1;
    while (s != head)
    {
        if (s->data == num)
        {
            break;
        }
        s = s->next;
        i++;
    }

    if (s->data != num)
    {
        cout << "404 NOT FOUND" << endl;
        return;
    }
    else
    {
        cout << "是第" << i << "个元素" << endl;
    }
}


int main6()
{

    DULNODE* Head = new DULNODE;
    DULNODE* r;
    r = Head;

    int data;
    cin >> data;
    while (data)
    {
        DULNODE* L = new DULNODE;
        L->data = data;
        r->next = L;
        L->next = Head;
        L->prior = r;
        r = L;
        cin >> data;
    }


    int num;
    cin >> num;
    search(Head, num);




    


	system("pause");
	return 0;
}

//int num;
//cin >> num;
//search(Head, num);



//
//DULNODE* s;
//s = Head->next;
//while (s != Head)
//{
//    cout << s->data << endl;;
//    s = s->next;
//}


//int position;
//cin >> position;
//int num;
//cin >> num;
//insertbehind(Head, position, num);


//int position;
//cin >> position;
//deletenode(Head, position);