#include <iostream>
using namespace std;
class queue
{
private:
    int size;
    int f;
    int b;
    int *arr;

public:
    queue(int s)
    {
        size = s;
        arr = new int[size];
        f = -1;
        b = -1;
    }
    bool isfull()
    {
        return (b == size - 1);
    }
    bool isempty()
    {
        return (f == -1 && b == -1);
    }
    void enqueue(int x)
    {
        if (isfull())
        {
            cout << "Queue is full" << endl;
            return;
        }

        if (isempty())
        {
            f = 0;
        }

        b++;
        arr[b] = x;
    }
  
int dequeue()
{
    if (isempty())
    {
        cout << "Queue Is Empty" << endl;
        return -1;
    }
    else
    {
        int x = arr[f];

        if (f == b)
        {
            f = -1;
            b = -1;
        }
        else
        {
            f++;
        }

        return x;
    }
}

};
int main()
{
    queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    return 0;
}