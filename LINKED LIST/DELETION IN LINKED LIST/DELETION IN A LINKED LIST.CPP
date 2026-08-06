#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void traversal(Node *p)
{
    if (p == NULL)
    {
        cout << "EMPTY LIST!" << endl;
    }

    while (p != NULL)
    {
        cout << "ELEMENT: " << p->data << endl;
        p = p->next;
    }
}

Node *deletionAtStart(Node *head)
{
    if (head == NULL)
    {
        cout << "LIST IS EMPTY!" << endl;
        return head;
    }

    Node *p = head;
    head = head->next;
    delete p;

    return head;
}

Node *deletionAtEnd(Node *head)
{
    if (head == NULL)
    {
        cout << "LIST IS EMPTY!" << endl;
        return head;
    }

    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node *ptr = head;
    Node *p = head->next;

    while (p->next != NULL)
    {
        ptr = ptr->next;
        p = p->next;
    }

    ptr->next = NULL;
    delete (p);

    return head;
}

Node *deletionAtIndex(Node *head, int index)
{
    if (head == NULL)
    {
        cout << "LIST IS EMPTY!" << endl;
        return head;
    }

    if (index == 0)
    {
        Node *ptr = head;
        head = head->next;
        delete ptr;
        return head;
    }

    Node *ptr = head;
    int i = 0;

    while (i != index - 1 && ptr != NULL)
    {
        ptr = ptr->next;
        i++;
    }

    if (ptr == NULL || ptr->next == NULL)
    {
        cout << "INVALID INDEX!" << endl;
        return head;
    }

    Node *p = ptr->next;
    ptr->next = p->next;

    delete p;

    return head;
}

Node *deletionAtValue(Node *head, int value)
{
    if (head == NULL)
    {
        cout << "LIST IS EMPTY!" << endl;
        return head;
    }

    if (head->data == value)
    {
        Node *ptr = head;
        head = head->next;
        delete ptr;
        return head;
    }

    Node *ptr = head;

    while (ptr->next != NULL && ptr->next->data != value)
    {
        ptr = ptr->next;
    }

    if (ptr->next == NULL)
    {
        cout << "VALUE NOT FOUND!" << endl;
        return head;
    }

    Node *p = ptr->next;
    ptr->next = p->next;
    delete p;

    return head;
}

int main()
{
    // Creating nodes in heap
    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;
    Node *fifth = new Node;

    // Linking nodes
    head->data = 7;
    head->next = second;

    second->data = 23;
    second->next = third;

    third->data = 46;
    third->next = fourth;

    fourth->data = 18;
    fourth->next = fifth;

    fifth->data = 35;
    fifth->next = NULL;


    cout << "ORIGINAL LIST" << endl;
    traversal(head);


    // Delete first node
    // head = deletionAtStart(head);


    // Delete last node
    // head = deletionAtEnd(head);


    // Delete node at index
    // head = deletionAtIndex(head, 2);


    // Delete node by value
    head = deletionAtValue(head, 23);


    cout << "\nAFTER DELETION" << endl;
    traversal(head);


    return 0;
}