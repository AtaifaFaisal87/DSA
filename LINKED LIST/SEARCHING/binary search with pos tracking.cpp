// Time: O(logn)
// Space: O(1)

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// solution for getmiddle of linked list
Node *getmid(Node *start, Node *end)
{
    Node *slow = start;
    Node *fast = start;

    while (fast != end && fast->next != end)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int BinarySearch(Node* head, int val)
{
    Node* start = head;
    Node* end = NULL;

    int startPos = 1;

    while (start != end)
    {
        Node* mid = getmid(start, end);

        // Find position of mid
        Node* temp = head;
        int midPos = 1;

        while (temp != mid)
        {
            temp = temp->next;
            midPos++;
        }

        if (mid->data == val)
        {
            return midPos;
        }
        else if (mid->data < val)
        {
            start = mid->next;
        }
        else
        {
            end = mid;
        }
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

    head->data = 5;
    head->next = second;

    second->data = 7;
    second->next = third;

    third->data = 23;
    third->next = fourth;

    fourth->data = 65;
    fourth->next = NULL;

    int val;
    cout << "ENTER VALUE TO FIND IN THE LIST:";
    cin >> val;

    int found = BinarySearch(head, val);

    if (!found)
    {
        cout << "VALUE NOT PRESENT IN THE LIST" << endl;
    }
    else
    {
        cout << "VALUE IS PRESENT "<< endl;
    }

    return 0;
}