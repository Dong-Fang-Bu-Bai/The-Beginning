#include<iostream>
using namespace std;

//1.ʵ��Ҫ��
//��1����������ĳ��Ⱥ͸�Ԫ�ص�ֵ����β�巨����˫��ѭ����������������и�Ԫ��ֵ���۲����������������������Ƿ�һ�¡�
//��2����˫��ѭ������ĵ�i��Ԫ��֮ǰ / �����һ��ֵΪx��Ԫ�أ�����������������и�Ԫ��ֵ��
// int position;
//cin >> position;
//cin >> data;
//insertbehind(Head, position, data);
// 
//��3��ɾ��˫��ѭ�������е�i��Ԫ�أ������ɾ����������и�Ԫ��ֵ��
// int position;
//cin >> position;
//deletenode(Head, position);
// 
// 
//��4����˫��ѭ�������в���ֵΪxԪ�أ�������ҳɹ�������ʾ��Ԫ���������е�λ�ã�������ʾ��Ԫ�ز����ڡ�



struct DULNODE
{
    int data;  /*������*/
    struct DULNODE* prior; /*ָ��ǰ������ָ����*/
    struct DULNODE* next;/*ָ���̽���ָ����*/
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
        cout << "�ǵ�" << i << "��Ԫ��" << endl;
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