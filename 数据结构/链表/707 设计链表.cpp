#include<iostream>
using namespace std;

struct LNode
{
    int val;
    LNode* next;

    LNode(int x) :val(x), next(NULL) {};

    LNode() :next(NULL) {};
};

class MyLinkedList {
private:
    int length = 0;
    LNode* head = new LNode;

public:

    MyLinkedList() {
        head->next = NULL;
        length = 0;
    }

    int get(int index) {
        if (index < 0 || index >= length)
        {
            return -1;
        }

        LNode* pointer = head;
        for (int i = 0; i <= index; i++)
        {
            pointer = pointer->next;
        }
        return pointer->val;

        delete pointer;

    }

    void addAtHead(int val) {
        LNode* add = new LNode(val);
        add->next = head->next;
        head->next = add;
        length++;


    }

    void addAtTail(int val) {
        LNode* pointer = head;
        for (int i = 0; i < length; i++)
        {
            pointer = pointer->next;
        }

        LNode* add = new LNode(val);
        pointer->next = add;

        length++;

        delete pointer;

    }

    void addAtIndex(int index, int val) {
        if (index > length)
        {
            return;
        }

        else if (index == length)
        {
            addAtTail(val);
            return;
        }

        else if (index == 0)
        {
            addAtHead(val);
            return;
        }

        else
        {


            LNode* pointer = head;
            for (int i = 0; i < index; i++)
            {
                pointer = pointer->next;
            }

            LNode* add = new LNode(val);

            add->next = pointer->next;
            pointer->next = add;
            length++;
            delete pointer;
            return;

        }



    }

    void deleteAtIndex(int index) {

        if (length == 0 || index < 0 || index >= length)
        {
            return;
        }
        else
        {
            LNode* pointer = head;
            for (int i = 0; i < index; i++)
            {
                pointer = pointer->next;
            }

            LNode* del = pointer->next;
            pointer->next = del->next;
            length--;
            delete del;
            return;
        }

    }


};

int main()
{
    MyLinkedList mylist;
    mylist.addAtIndex(0, 13);
    mylist.addAtIndex(3, 10);

    system("pause");
    return 0;
}


/*
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */