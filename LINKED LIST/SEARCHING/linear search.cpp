// Time: O(n)
// Space: O(1)

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int linearSearch(Node *head, int val)
{
    Node *p = head;
    int nd = 1;
    while (p != NULL)
    {
        if (p->data == val)
        {
            return nd;
        }

        nd++;
        p = p->next;
    }

    return -1;
}

int main()
{
    // located memory in heap
    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;

    head->data = 7;
    head->next = second;

    second->data = 23;
    second->next = third;

    third->data = 37;
    third->next = fourth;

    fourth->data = 5;
    fourth->next = NULL;

    int val;
    cout << "ENTER VALUE TO FIND IN THE LIST:";
    cin >> val;

    int found = linearSearch(head, val);

    if (found == -1)
    {
        cout << "VALUE NOT PRESENT IN THE LIST" << endl;
    }
    else
    {
        cout << "VALUE AT NODE " << found << endl;
    }

    return 0;
}