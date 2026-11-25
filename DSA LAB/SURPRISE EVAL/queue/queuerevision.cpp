#include <iostream>
using namespace std;
class queue
{
private:
    int f;
    int b;
    int size;
    int *arr;

public:
    queue(int s)
    {
        size = s;
        f = -1;
        b = -1;
        arr = new int[s];
    }
    bool isFull()
    {
        return (b == size - 1);
    }
    bool isEmpty()
    {
        return (f == -1 && b == -1);
    }
    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "QUEUE IS ALREADY FULL" << endl;
        }
        else
        {
            if (isEmpty())
            {
                f++;
            }
            b++;
            arr[b] = x;
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
            int x = arr[f];
            if (f == b)
            {
                f = -1;
                b = -1;
            }
            f++;
            return x;
        }
    }
};

int main()
{  
    queue q(3);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;


    return 0;
}