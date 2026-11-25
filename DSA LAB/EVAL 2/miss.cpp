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

    void deletealternate()
    {
        queue q2(20);
        for (int i = front; i <= rear;i++)
        {
            if(i%2==0)
            {
            q2.enqueue(dequeue());
            }
            else{
                dequeue();
            }
            
        }

        for (int j = q2.front; j <= q2.rear; j++)
        {
            enqueue(q2.dequeue());
        }
    }

    // 10 20 30 40 50 60 70
    // 10 30 50 70
    ~queue()
    {
        delete[] arr;
    }
};
int main()
{
    queue q1(7);
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    q1.enqueue(60);
    q1.enqueue(70);
    q1.display();
    q1.deletealternate();
    q1.display();

    return 0;
}