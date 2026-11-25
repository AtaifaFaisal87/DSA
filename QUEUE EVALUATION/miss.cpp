#include <iostream>
using namespace std;

class queue
{
private:
    int *arr;
    int front;
    int rear;
    int maxsize;

public:
    queue(int size)
    {
        maxsize = size;
        arr = new int[maxsize];
        front = -1;
        rear = -1;
    }

    bool isempty()
    {
        return front == -1;
    }

    bool isfull()
    {
        return rear == maxsize - 1;
    }

    void enqueue(int val)
    {
        if (isfull())
        {
            cout << "SPACE FULL!" << endl;
            return;
        }

        if (isempty())
        {
            front = 0;
        }

        rear++;
        arr[rear] = val;
    }

    int dequeue()
    {
        if (isempty())
        {
            cout << "EMPTY LIST!" << endl;
            return -1;
        }

        int temp = arr[front];

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }

        else
        {
            front++;
        }

        return temp;
    }

    int peek()
    {
        if (isempty())
        {
            cout << "EMPTY LIST!" << endl;
            return -1;
        }

        return arr[front];
    }
    void display()
    {
        if (isempty())
        {
            cout << "EMPTY LIST!" << endl;
            return;
        }

        cout << "DISPLAYING!" << endl;

        for (int i = front; i <= rear; i++)
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
    cout << "peek:" << q1.peek() << endl;
    cout << "dequeued element:" << q1.dequeue() << endl;
    q1.display();
    cout << "dequeued element:" << q1.dequeue() << endl;
    q1.display();
    cout << "dequeued element:" << q1.dequeue() << endl;
    q1.display();
    cout << "dequeued element:" << q1.dequeue() << endl;
    q1.display();
    cout << "dequeued element:" << q1.dequeue() << endl;
    q1.display();
    cout << "dequeued element:" << q1.dequeue() << endl;
    q1.display();
 

    return 0;
}