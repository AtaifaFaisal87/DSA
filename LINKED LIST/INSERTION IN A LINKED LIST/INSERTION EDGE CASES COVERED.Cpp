#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void Traversal(Node *ptr)
{
    if (ptr == NULL)
    {
        cout << "EMPTY LIST!" << endl;
        return;
    }

    while (ptr != NULL)
    {
        cout << "ELEMENT: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

//================CASE 1=================
Node *InsertAtStart(Node *head, int data)
{
    Node *ptr = new Node;

    ptr->data = data;
    ptr->next = head;

    return ptr;
}

//================CASE 2=================
Node *InsertAtEnd(Node *head, int data)
{
    Node *ptr = new Node;
    ptr->data = data;
    ptr->next = NULL;

    // Edge Case: Empty List
    if (head == NULL)
    {
        return ptr;
    }

    Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr;

    return head;      // Return head, not new node
}

//================CASE 3=================
Node *InsertAtIndex(Node *head, int data, int index)
{
    // Edge Case: Invalid Index
    if (index < 0)
    {
        cout << "INVALID INDEX!" << endl;
        return head;
    }

    // Edge Case: Insert at Start
    if (index == 0)
    {
        return InsertAtStart(head, data);
    }

    // Edge Case: Empty List
    if (head == NULL)
    {
        cout << "EMPTY LIST!" << endl;
        return head;
    }

    Node *ptr = new Node;
    ptr->data = data;

    Node *p = head;
    int i = 0;

    while (i != index - 1)
    {
        if (p == NULL)
        {
            cout << "INVALID INDEX!" << endl;
            delete ptr;
            return head;
        }

        p = p->next;
        i++;
    }

    // Edge Case: Index greater than length
    if (p == NULL)
    {
        cout << "INVALID INDEX!" << endl;
        delete ptr;
        return head;
    }

    ptr->next = p->next;
    p->next = ptr;

    return head;      // Return head
}

//================CASE 4=================
Node *InsertAfterNode(Node *prevNode, int data)
{
    // Edge Case
    if (prevNode == NULL)
    {
        cout << "INVALID NODE!" << endl;
        return NULL;
    }

    Node *ptr = new Node;

    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;

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

    cout << "ORIGINAL LINKED LIST" << endl;
    Traversal(head);

    cout << "\nINSERT AT START" << endl;
    head = InsertAtStart(head, 100);
    Traversal(head);

    cout << "\nINSERT AT END" << endl;
    head = InsertAtEnd(head, 200);
    Traversal(head);

    cout << "\nINSERT AT INDEX" << endl;
    head = InsertAtIndex(head, 300, 2);
    Traversal(head);

    cout << "\nINSERT AFTER NODE" << endl;
    InsertAfterNode(third, 400);
    Traversal(head);

    return 0;
}