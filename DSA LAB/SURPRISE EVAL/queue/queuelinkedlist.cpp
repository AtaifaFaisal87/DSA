#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
class queue
{
private:
    node *f;
    node *b;

public:
    queue()
    {
        f = NULL;
        b = NULL;
    }
    bool isEmpty()
    {
        return (f == NULL);
    }
    void makeEmpty()
    {
        f = NULL;
        b = NULL;
    }
    void enqueue(int x)
    {
        node *p = new node;
        p->data = x;
        p->next = NULL;
        if (isEmpty())
        {
            f = b = p;
        }

        b->next = p;
        b = p;
    }
    int dequeue()
    {
        if (isEmpty())
        {
            return -1;
        }
        node *p = f;
        int x = f->data;
        f = f->next;
        delete p;
        return x;
    }
    ~queue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

};

int main()
{ 
    queue q;
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(77);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;y
  
    return 0;
}