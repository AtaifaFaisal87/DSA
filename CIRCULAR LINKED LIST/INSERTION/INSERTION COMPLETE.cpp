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

// Insert at beginning
Node *atBeginning(Node *head, int data)
{
    Node *ptr = new Node;
    ptr->data = data;

    // Empty list
    if (head == NULL)
    {
        ptr->next = ptr;
        return ptr;
    }

    Node *p = head;

    while (p->next != head)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = head;
    head = ptr;

    return head;
}

//  Insert at end
Node *atEnd(Node *head, int data)
{
    Node *ptr = new Node;
    ptr->data = data;

    // Empty list
    if (head == NULL)
    {
        ptr->next = ptr;
        return ptr;
    }

    Node *p = head;

    while (p->next != head)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = head;

    return head;
}

// Insert after a specific index
Node *afterSpecificNode(Node *head, int data, int index)
{
    // Empty list
    if (head == NULL)
    {
        cout << "LIST IS EMPTY!" << endl;
        return head;
    }

    Node *p = head;
    int i = 0;

    // Find the index
    while (i < index)
    {
        p = p->next;
        i++;

        // We came back to head -> index doesn't exist
        if (p == head)
        {
            cout << "INVALID INDEX!" << endl;
            return head;
        }
    }

    Node *ptr = new Node;
    ptr->data = data;

    ptr->next = p->next;
    p->next = ptr;

    return head;
}

// Insert at a specific index
Node *atSpecificNode(Node *head, int data, int index)
{
    // Empty list
    if (head == NULL)
    {
        if (index == 0)
        {
            Node *ptr = new Node;
            ptr->data = data;
            ptr->next = ptr;
            return ptr;
        }

        cout << "INVALID INDEX!" << endl;
        return head;
    }

    // Insert at beginning
    if (index == 0)
    {
        return atBeginning(head, data);
    }

    Node *p = head;
    int i = 0;

    // Find node before the required index
    while (i < index - 1)
    {
        p = p->next;
        i++;

        if (p == head)
        {
            cout << "INVALID INDEX!" << endl;
            return head;
        }
    }

    Node *ptr = new Node;
    ptr->data = data;

    ptr->next = p->next;
    p->next = ptr;

    return head;
}

int main()
{
    Node *head = NULL;

    // Empty list
    cout << "EMPTY LIST:" << endl;
    traversal(head);

    // Insert into empty list
    head = atBeginning(head, 7);

    cout << "\nAFTER INSERTING 7:" << endl;
    traversal(head);

    // Insert at beginning
    head = atBeginning(head, 23);

    cout << "\nAFTER INSERTING AT BEGINNING:" << endl;
    traversal(head);

    // Insert at end
    head = atEnd(head, 62);

    cout << "\nAFTER INSERTING AT END:" << endl;
    traversal(head);

    // Insert after index 1
    head = afterSpecificNode(head, 37, 1);

    cout << "\nAFTER INSERTING AFTER INDEX 1:" << endl;
    traversal(head);

    // Insert at index 2
    head = atSpecificNode(head, 45, 2);

    cout << "\nAFTER INSERTING AT INDEX 2:" << endl;
    traversal(head);

    // Invalid index
    head = atSpecificNode(head, 100, 20);

    return 0;
}