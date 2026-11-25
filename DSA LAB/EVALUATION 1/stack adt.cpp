#include <iostream>
using namespace std;

class Stack
{
private:
    int TOS;
    int *arr;
    int maxSize;

public:
    Stack(int s)
    {
        maxSize = s;
        arr = new int[s];
        TOS = -1;
    }

    bool isEmpty()
    {
        return TOS == -1;
    }

    bool isFull()
    {
        return TOS == maxSize - 1;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "STACK UNDERFLOW!" << endl;
            return -1;
        }
        return arr[TOS];
    }

    void push(int val)
    {
        if (isFull())
        {
            cout << "STACK OVERFLOW!" << endl;
            return;
        }
        TOS++;
        arr[TOS] = val;
        cout << "ELEMENT  PUSHED AT POSITION:" << TOS << endl;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "STACK UNDERFLOW!" << endl;
            return -1;
        }
        int temp;
        temp = arr[TOS];
        TOS--;
        // cout << "THE ELEMENT POPPED IS:" << temp << endl;
        return temp;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "STACK UNDERFLOW!" << endl;
            return;
        }
        cout << "TOS: ";
        for (int i = TOS; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    ~Stack()
    {
        delete[] arr;
    }
};

int main()
{
    cout << "=====STACK WALKTHROUGH=====" << endl;
    cout << "--------------------------------" << endl;
    int n;
    cout << "ENTER SIZE OF STACK:";
    cin >> n;

    Stack s(n);
    int choice;

    do
    {
        cout << "1.PUSH" << endl;
        cout << "2.POP" << endl;
        cout << "3.PEEK" << endl;
        cout << "4.IS EMPTY" << endl;
        cout << "5.IS FULL" << endl;
        cout << "6.DISPLAY" << endl;
        cout << "0. EXIT" << endl;

        cout << "ENTER CHOICE:";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int value;
            cout << "ENTER VALUE:";
            cin >> value;
            s.push(value);
            cout << "==============================================" << endl;
            break;
        }
        case 2:
            cout << "THE ELEMENT POPPED IS:" << s.pop() << endl;
            cout << "==============================================" << endl;
            break;
        case 3:
            cout << "THE ELEMENT TOS IS:" << s.peek() << endl;
            cout << "==============================================" << endl;
            break;
        case 4:
            if (s.isEmpty())
            {
                cout << "THE STACK IS EMPTY!" << endl;
            }
            else
            {
                cout << "STACK IS NOT EMPTY!" << endl;
            }
            cout << "==============================================" << endl;
            break;
        case 5:
              if (s.isFull())
            {
                cout << "THE STACK IS FULL!" << endl;
            }
            else
            {
                cout << "STACK IS NOT FULL!" << endl;
            }
            cout << "==============================================" << endl;
            break;
        case 6:
            s.display();
            cout << "==============================================" << endl;
            break;
        case 0:

            cout << "EXITING..." << endl;
            cout << "==============================================" << endl;
            break;
        default:
            cout << "INVALID INPUT!" << endl;
            cout << "==============================================" << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}