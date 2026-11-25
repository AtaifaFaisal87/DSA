#include <iostream>
using namespace std;

class circular_queue
{
private:
    int *arr;
    int f;
    int r;
    int maxsize;

public:
    circular_queue(int size)
    {
        maxsize = size;
        arr = new int[size];
        f = r = -1;
    }

    bool isempty()
    {
        return f == -1;
    }
    bool isfull()
    {
        return (r + 1) % maxsize == f;

        // r==maxsize-1
    }

    void enqueue(int val)
    {
        if (isfull())
        {
            return;
        }
        if (isempty())
        {
            f = 0;
        }
        r = (r + 1) % maxsize;
        arr[r] = val;
    }

    int dequeue()
    {

        if (isempty())
        {
            return -1;
        }

        int temp = arr[f];

        if (f == r)
        {
            f = -1;
            r = -1;
        }
        else
        {
            f = (f + 1) % maxsize;
            // f++;
        }

        return temp;
    }

    int peek()
    {
        if (isempty())
        {
            cout << "EMPTY QUEUE!" << endl;
            return -1;
        }

        return arr[f];
    }

    void display()
    {
        if (isempty())
        {
            cout << "EMPTY QUEUE!" << endl;
            return;
        }

        cout << "DISPLAYING ELEMENTS!" << endl;

        int i = f;

        while (true)
        {
            cout << arr[i] << " ";
            if (i == r)
            {
                break;
            }

            i = (i + 1) % maxsize;
        }
        cout << endl;
    }

    ~circular_queue()
    {
        delete[] arr;
    }
};
int main()
{
    return 0;
}