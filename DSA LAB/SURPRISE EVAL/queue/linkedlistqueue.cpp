
#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

class Queue
{
private:
    node* f;
    node* r;

public:
    Queue()
    {
        f = NULL;
        r = NULL;
    }

    bool isEmpty()
    {
        return (f == NULL);
    }

    void enqueue(int x)
    {
        node* temp = new node;
        temp->data = x;
        temp->next = NULL;

        if (isEmpty())
        {
            f = r = temp;
        }
        else
        {
            r->next = temp;
            r = temp;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "QUEUE IS EMPTY" << endl;
            return -1;
        }

        node* temp = f;
        int x = temp->data;

        f = f->next;

        if (f == NULL)
        {
            r = NULL;
        }

        delete temp;
        return x;
    }

    ~Queue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }\
};

int main()
{
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    return 0;
}
