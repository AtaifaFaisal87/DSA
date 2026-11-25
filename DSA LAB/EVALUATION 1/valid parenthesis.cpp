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

bool isValid(string P)
{
    Stack s(P.length());

    for (int i = 0; i < P.length(); i++)
    {
        if (P[i] == '(' || P[i] == '{' || P[i] == '[')
        {
            s.push(P[i]);
        }

        else
        {
            if (s.isEmpty())
            {
                return false;
            }
            else
            {
                if (P[i] == ')' && s.peek() == '(')
                {
                    s.pop();
                }
                else if (P[i] == '}' && s.peek() == '{')
                {
                    s.pop();
                }
                else if (P[i] == ']' && s.peek() == '[')
                {
                    s.pop();
                }
                else
                    return false;
            }
        }
    }

    return s.isEmpty();
}

int main()
{
    string s;

    cout << "Enter parentheses: ";
    cin >> s;

    if (isValid(s))
        cout << "Valid Parentheses";
    else
        cout << "Invalid Parentheses";

    return 0;
}