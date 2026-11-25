#include <iostream>
using namespace std;

class node
{
public:
    int value;
    node *next;
    node(int v)
    {
        value = v;
        next = NULL;
    }
};

class LinkedList
{
private:
    node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void addLL(int value)
    {
        node *newnode = new node(value);

        if (head == NULL)
        {
            head = newnode;
            return;
        }

        node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
        return;
    }

    void deletenode(int val)
    {
        if (head == nullptr)
        {
            cout << "LIST IS EMPTY!" << endl;
            return;
        }

        if (head->value == val)
        {
            node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        node *temp = head;

        while (temp->next != nullptr && temp->next->value != val)
        {
            temp = temp->next;
        }

        if (temp->next != nullptr)
        {
            node *dnode = temp->next;
            temp->next = dnode->next;
            delete dnode;
        }
    }

    void insertAfterTarget(int t, int val)
    {
        if (head == nullptr)
        {
            return;
        }
        node *newnode = new node(val);

        if (head->value == t)
        {
            newnode->next = head->next;
            head->next = newnode;
            return;
        }
        node *temp = head;

        while (temp->next != nullptr && temp->value != t)
        {
            temp = temp->next;
        }

        if (temp->next != nullptr)
        {

            newnode->next = temp->next;
            temp->next = newnode;
        }
    }

    void search(int val)
    {
        if (head == nullptr)
        {
            cout << "EMPTY LIST!" << endl;
            return;
        }

        node *temp = head;
        int i = 0;
        while (temp != nullptr)
        {
            if (temp->value == val)
            {
                cout << "VALUE FOUND AT INDEX: " << i << endl;
                return;
            }
            temp = temp->next;
            i++;
        }

        if (temp == nullptr)
        {
            cout << "VALUE NOT FOUND!" << endl;
        }
    }
    void display()
    {
        node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};
int main()
{
    LinkedList l1;
    l1.addLL(2);
    l1.addLL(4);
    l1.addLL(25);
    l1.addLL(32);
    l1.addLL(76);
    l1.display();
    l1.deletenode(32);
    l1.display();
    l1.insertAfterTarget(25, 45);
    l1.display();
    l1.search(76);
    return 0;
}