#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void traversal(Node *head)
{
    if (head == NULL)
    {
        cout << "EMPTY LIST!" << endl;
        return;
    }

    Node *ptr = head;

    do
    {
        cout << "ELEMENT: " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != head);
}

Node *atBeginning(Node *head)
{
    Node *ptr = head;
    Node *p = head;

    while (p->next != head)
    {
        p = p->next;
    }

    head = head->next;
    p->next = head;

    delete ptr;

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

    head->data = 7;
    head->next = second;

    second->data = 23;
    second->next = third;

    third->data = 62;
    third->next = fourth;

    fourth->data = 37;
    fourth->next = fifth;

    fifth->data = 28;
    fifth->next = head;

    traversal(head);

    head = atBeginning(head);

    cout<<"AFTER DELETION"<<endl;
    traversal(head);

    return 0;
}