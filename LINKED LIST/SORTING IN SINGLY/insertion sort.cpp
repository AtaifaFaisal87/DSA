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
        return;
    }

    while (ptr != NULL)
    {
        cout << "ELEMENT: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

void insertionSort(Node *head)
{
    if (head == NULL)
        return;

    Node *current = head->next;

    while (current != NULL)
    {
        Node *temp = current;

        // Find the previous node
        Node *previous = head;

        while (previous->next != temp)
        {
            previous = previous->next;
        }

        // Move current backwards by swapping data
        while (temp != head && previous->data > temp->data)
        {
            int value = previous->data;
            previous->data = temp->data;
            temp->data = value;

            temp = previous;

            if (temp == head)
                break;

            previous = head;

            while (previous->next != temp)
            {
                previous = previous->next;
            }
        }

        current = current->next;
    }
}

int main()
{
    // Allocate memory in heap
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

    insertionSort(head);

    cout << "AFTER SORT" << endl;

    traversal(head);

    return 0;
}