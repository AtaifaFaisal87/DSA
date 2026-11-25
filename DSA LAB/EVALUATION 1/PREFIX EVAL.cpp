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

int evaluatePrefix(string s)
{
    int T, NT, result;
    Stack ans(s.length());

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            continue;
        }
        else
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                ans.push(s[i] - '0');
            }
            else
            {
                T = ans.peek();
                ans.pop();

                NT = ans.peek();
                ans.pop();

                if (s[i] == '+')
                {
                    result = T + NT;
                }
                else if (s[i] == '-')
                {
                    result = T - NT;
                }
                else if (s[i] == '*')
                {
                    result = T * NT;
                }
                else if (s[i] == '/')
                {
                    result = T / NT;
                }

                ans.push(result);
            }
        }
    }

    return ans.peek();
}

int main()
{
    string P = "+5*32";

    cout << "THE ANSWER IS: " << evaluatePrefix(P);

    return 0;
}