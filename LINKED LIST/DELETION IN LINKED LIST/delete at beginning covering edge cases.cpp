#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void traversal(Node *ptr)
{
    if (ptr == NULL)
    {
        cout << "EMPTY LIST!" << endl;
    }

    while (ptr != NULL)
    {
        cout << "ELEMENT: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

Node *deletionAtBegnning(Node *head)
{

    if (head == NULL)
    {
        return NULL;
    }

    Node *ptr = head;
    head = head->next;
    delete (ptr);
    return head;
}

int main()
{
    // located memory in heap
    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;

    head->data = 7;
    head->next = second;

    second->data = 23;
    second->next = third;

    third->data = 2;
    third->next = NULL;

    traversal(head);

    head = deletionAtBegnning(head);

    cout << "AFTER DELETION" << endl;
    traversal(head);

    return 0;
}