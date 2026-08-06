#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void traversal(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "ELEMENT: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

Node *deletionAtIndex(Node *head, int index)
{
    Node *ptr = head;
    int i = 0;

    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }

    Node *p = ptr->next;
    ptr->next = p->next;

    delete (p);

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

    head = deletionAtIndex(head, 2);

    cout << "AFTER DELETION" << endl;
    traversal(head);

    return 0;
}