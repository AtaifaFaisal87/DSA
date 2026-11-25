#include <iostream>
using namespace std;
class circular_queue
{
private:
    int f;
    int b;
    int size;
    int *arr;

public:
    circular_queue(int s)
    {
        size = s+1;
        f = size - 1;
        b = size - 1;
        arr = new int[size];
    }
    bool isFull()
    {
        return ((b + 1) % size == f);
    }
    bool isEmpty()
    {
        return (f == b);
    }
    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "QUEUE IS ALREADY FULL" << endl;
        }
        else
        {
            b=(b+1)%size;
            arr[b]=x;
        }
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "QUEUE IS EMPTY" << endl;
            return -1;
        }
        else
        {
            f = (f + 1) % size;
            return arr[f];
        }
    }
    ~circular_queue()
    {
        delete[] arr;
    }
};

int main()
{
    circular_queue q(4);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    return 0;
}