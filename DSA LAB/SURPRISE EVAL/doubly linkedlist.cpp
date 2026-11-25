#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int d)
    {
        data = d;
        next = nullptr;
        prev = nullptr;
    }
};

class dlinkedlist
{
private:
    node *head;

public:
    dlinkedlist()
    {
        head = nullptr;
    }

    void addDll(int val)
    {
        node *newnode = new node(val);
        if (head == nullptr)
        {
            head = newnode;
            return;
        }
        node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->prev = temp;
    }

    void deletell(int val)
    {
        if (head == nullptr)
        {
            cout << "EMPTY LIST!" << endl;
            return;
        }
        if (head->data == val)
        {
            node *temp = head;
            head = head->next;

            if (head != nullptr)
            {
                head->prev = nullptr;
            }

            delete temp;
            return;
        }
        node *temp = head;
        while (temp != nullptr && temp->data != val)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "VALUE NOT FOUND!" << endl;
            return;
        }

        temp->prev->next = temp->next;

        if (temp->next != nullptr)
        {
            temp->next->prev = temp->prev;
        }

        delete temp;
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
            if (temp->data == val)
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
};

int main()
{
    dlinkedlist l1;

    l1.addDll(10);
    l1.addDll(20);
    l1.addDll(30);
    l1.addDll(40);
    l1.addDll(50);

    cout << "Searching for 30:" << endl;
    l1.search(30);

    cout << "\nDeleting 30:" << endl;
    l1.deletell(30);

    cout << "\nSearching for 30 again:" << endl;
    l1.search(30);

    cout << "\nDeleting head (10):" << endl;
    l1.deletell(10);

    cout << "\nDeleting last node (50):" << endl;
    l1.deletell(50);

    return 0;
}