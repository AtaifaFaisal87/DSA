#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *ptr)
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

void bubbleSort(Node *head)
{
    for (Node *i = head; i != NULL; i = i->next)
    {
        for (Node *j = head; j->next != NULL; j = j->next)
        {
            if (j->data > j->next->data)
            {
                int temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
}

int main()
{
    // located memory in heap
    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;

    head->data = 65;
    head->next = second;

    second->data = 27;
    second->next = third;

    third->data = 23;
    third->next = fourth;

    fourth->data = 2;
    fourth->next = NULL;

    traversal(head);
    bubbleSort(head);

    cout<<"AFTER SORT"<<endl;
    traversal(head);

    return 0;
}