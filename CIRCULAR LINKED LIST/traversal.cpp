#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void traversal(Node *head)
{
    Node *p = head;

    do
    {
        cout << p->data << endl;
        p = p->next;
    } while (p != head);
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

    return 0;
}