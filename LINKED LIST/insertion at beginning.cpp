#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "ELEMENT: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

struct Node *insertionAtBeginning(struct Node *head, int data)
{
    Node *ptr = new Node;
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

int main()
{
    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;

    head->data = 7;
    head->next = second;

    second->data = 43;
    second->next = third;

    third->data = 11;
    third->next = fourth;

    fourth->data = 2;
    fourth->next = NULL;

    traversal(head);
    head=insertionAtBeginning(head,47);

    cout<<"AFTER INSERTION"<<endl;
    traversal(head);

    return 0;
}