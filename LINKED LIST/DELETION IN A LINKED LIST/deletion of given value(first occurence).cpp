#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void traversal(Node *ptr)
{
       if(ptr ==NULL)
    {
        cout<<"EMPTY LIST!"<<endl;
    }
    
    while (ptr != NULL)
    {
        cout << "ELEMENT: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

Node *deletionOfGivenValue(Node *head, int val)
{
    // empty list
    if (head == NULL)
    {
        return NULL;
    }

    // deleting first node
    if (head->data == val)
    {
        Node *ptr = head;
        head = head->next;
        delete ptr;
        return head;
    }

    Node *ptr = head;

    while (ptr->next != NULL && ptr->next->data != val)
    {
        ptr = ptr->next;
    }

    // value not found
    if (ptr->next == NULL)
    {
        return head;
    }

    Node *p = ptr->next;
    ptr->next = p->next;

    delete p;

    return head;
}

int main()
{
    // located memory in heap
    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;
    Node *fifth = new Node;

    // 0
    head->data = 7;
    head->next = second;

    // 1
    second->data = 23;
    second->next = third;

    // 2
    third->data = 46;
    third->next = fourth;

    // 3
    fourth->data = 18;
    fourth->next = fifth;

    // 4
    fifth->data = 35;
    fifth->next = NULL;

    traversal(head);

    head = deletionOfGivenValue(head, 23);

    cout << "AFTER DELETION" << endl;
    traversal(head);

    return 0;
}