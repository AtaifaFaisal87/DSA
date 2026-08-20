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

Node *atSpecificNode(Node *head, int data,int index)
{
   Node* ptr=new Node;
   ptr->data=data;

   Node* p=head;

   int i=0;

   while(i != index-1)
   {
     p=p->next;
     i++;
   }
  ptr->next=p->next;
   p->next=ptr;

   return head;

   
}

int main()
{
     // located memory in heap
    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;
    Node *fifth = new Node;

    head->data = 7;
    head->next = second;

    second->data = 23;
    second->next = third;

    third->data = 62;
    third->next = fourth;

    fourth->data = 37;
    fourth->next = fifth;

    fifth->data = 28;
    fifth->next = head;

    traversal(head);

    head = atSpecificNode(head, 45,3);

    cout<<"AFTER INSERTION"<<endl;
    traversal(head);

    return 0;
}