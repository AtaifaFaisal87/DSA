#include <iostream>
using namespace std;

class queue
{
private:
    int *arr;
    int f;
    int r;
    int maxsize;

public:
    queue(int size)
    {
        maxsize = size;
        arr = new int[size];
        f = 0;
        r=maxsize-1;
    }

    int ADDONE(int i)
    {
        return (i + 1) % maxsize;
    }

    bool isempty()
    {
        return ADDONE(r) == f;
    }

    void enqueue(int val)
    {
        if (ADDONE(ADDONE(r)) == f)
        {
            return;
        }

        r = ADDONE(r);
        arr[r] = val;
    }

    int dequeue()
    {
        if (isempty())
        {
            return -1;
        }

        int temp = arr[f];
        f = ADDONE(f);
        return temp;
    }

    void display()
    {
        if (isempty())
        {
            return;
        }

        cout << "display:" << endl;

        int i = f;

        while (true)
        {
            cout << arr[i] << endl;

            if (i == r)
            {
                break;
            }

            i = ADDONE(i);
        }

        cout << endl;
    }

    ~queue()
    {
        delete[] arr;
    }
};
int main()
{

    queue q1(5);

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);

    q1.display();


    cout << "Dequeued: " << q1.dequeue() << endl;
    cout << "Dequeued: " << q1.dequeue() << endl;

    q1.display();

    q1.enqueue(50);
    q1.enqueue(60);

    q1.display();

    return 0;
}