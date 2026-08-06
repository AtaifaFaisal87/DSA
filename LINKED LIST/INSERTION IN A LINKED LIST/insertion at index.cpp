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

struct Node *insertionAtIndex(struct Node *head, int data, int index)
{
    Node *ptr = new Node;
    Node *p = head;
    int i=0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    ptr->next = p->next;
    p->next = ptr;
    ptr->data = data;
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
    insertionAtIndex(head, 47, 3);

    cout << "AFTER INSERTION" << endl;
    traversal(head);

    return 0;
}