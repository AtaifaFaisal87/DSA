#include <iostream>
using namespace std;

class queue
{
private:
    int *arr;
    int f;
    int r;
    int maxSize;

public:
    queue(int size)
    {
        maxSize = size;
        arr = new int[maxSize];
        f = r = -1;
    }

    bool isEmpty()
    {
        return f == -1;
    }

    bool isFull()
    {
        return r == maxSize - 1;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "EMPTY QUEUE!" << endl;
            return -1;
        }

        return arr[f];
    }

    // lagana
    void enqueue(int v)
    {
        if (isFull())
        {
            cout << "NO SPACE LEFT!" << endl;
            return;
        }

        if (isEmpty())
        {
            f = 0;
        }

        r++;
        arr[r] = v;
    }

    // nikalna
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "EMPTY QUEUE!" << endl;
            return -1;
        }

        int temp = arr[f];
        if (f == r)
        {
            // removes the last element present
            f = -1;
            r = -1;
        }
        else
        {
            // there are more than one elemnt
            f++;
        }

        return temp;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "EMPTY QUEUE!" << endl;
            return;
        }

        cout << "DISPLAYING QUEUE!" << endl;

        for (int i = f; i <= r; i++)
        {
            cout << arr[i] << " ";
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
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.display();
    cout<<"peek:"<<q1.peek()<<endl;
    cout<<"dequeued element:"<<q1.dequeue()<<endl;
    q1.display();
    cout<<"dequeued element:"<<q1.dequeue()<<endl;
    q1.display();
    cout<<"dequeued element:"<<q1.dequeue()<<endl;
    q1.display();
    cout<<"dequeued element:"<<q1.dequeue()<<endl;
    q1.display();
    cout<<"dequeued element:"<<q1.dequeue()<<endl;
    q1.display();
    cout<<"dequeued element:"<<q1.dequeue()<<endl;
    q1.display();

    return 0;
}