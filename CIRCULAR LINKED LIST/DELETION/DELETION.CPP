#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// Traversal
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

// Delete from beginning
Node *deleteBeginning(Node *head)
{
    if (head == NULL)
    {
        cout << "LIST IS EMPTY!" << endl;
        return head;
    }

    // Only one node
    if (head->next == head)
    {
        delete head;
        return NULL;
    }

    Node *p = head;

    // Find last node
    while (p->next != head)
    {
        p = p->next;
    }

    Node *temp = head;

    head = head->next;
    p->next = head;

    delete temp;

    return head;
}

// Delete from end
Node *deleteEnd(Node *head)
{
    if (head == NULL)
    {
        cout << "LIST IS EMPTY!" << endl;
        return head;
    }

    // Only one node
    if (head->next == head)
    {
        delete head;
        return NULL;
    }

    Node *p = head;

    // Find second-last node
    while (p->next->next != head)
    {
        p = p->next;
    }

    Node *temp = p->next;

    p->next = head;

    delete temp;

    return head;
}

// Delete at specific index
Node *deleteSpecificNode(Node *head, int index)
{
    if (head == NULL)
    {
        cout << "LIST IS EMPTY!" << endl;
        return head;
    }

    // Delete first node
    if (index == 0)
    {
        return deleteBeginning(head);
    }

    Node *p = head;
    int i = 0;

    // Find node before required index
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

    // Index doesn't exist
    if (p->next == head)
    {
        cout << "INVALID INDEX!" << endl;
        return head;
    }

    Node *temp = p->next;

    p->next = temp->next;

    delete temp;

    return head;
}

int main()
{
    // Creating circular linked list manually
    Node *head = new Node{10, NULL};
    Node *second = new Node{20, NULL};
    Node *third = new Node{30, NULL};
    Node *fourth = new Node{40, NULL};

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = head;

    cout << "ORIGINAL LIST:" << endl;
    traversal(head);

    // Delete beginning
    head = deleteBeginning(head);

    cout << "\nAFTER DELETING BEGINNING:" << endl;
    traversal(head);

    // Delete end
    head = deleteEnd(head);

    cout << "\nAFTER DELETING END:" << endl;
    traversal(head);

    // Delete index 1
    head = deleteSpecificNode(head, 1);

    cout << "\nAFTER DELETING INDEX 1:" << endl;
    traversal(head);

    return 0;
}