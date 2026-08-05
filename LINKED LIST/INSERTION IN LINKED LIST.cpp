#include <iostream>
using namespace std;

struct Node
{

    int data;
    struct Node *next;
};

void Traversal(struct Node *ptr)
{
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
    Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    
  ptr->data=data;
    ptr->next=NULL;
    p->next=ptr;

    return ptr;
}

//================CASE 3=================
Node *InsertAtIndex(Node *head, int data, int index)
{
    Node *ptr = new Node;
    ptr->data = data;

    Node *p = head;
    int i = 0;

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

//================CASE 4=================
Node *InsertAfterNode(Node *prevNode, int data)
{
    Node *ptr = new Node;
    Node *p = prevNode;

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return ptr;
}

int main()
{
    return 0;
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
    InsertAtEnd(head, 200);
    Traversal(head);


    cout << "\nINSERT AT INDEX" << endl;
    InsertAtIndex(head, 300, 2);
    Traversal(head);


    cout << "\nINSERT AFTER NODE" << endl;
    InsertAfterNode(third, 400);
    Traversal(head);


    return 0;
}