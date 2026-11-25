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

int evaluatePostfix(string s)
{
    int result;
    Stack ans(s.length());
    int T, NT;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            continue;
        }
        else
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                int num = 0;

                while (i < s.length() && s[i] >= '0' && s[i] <= '9')
                {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }

                ans.push(num);
                i--;
            }

            else
            {
                T = ans.peek();
                ans.pop();

                NT = ans.peek();
                ans.pop();

                if (s[i] == '+')
                {
                    result = NT + T;
                }
                else if (s[i] == '-')
                {
                    result = NT - T;
                }
                else if (s[i] == '*')
                {
                    result = NT * T;
                }
                else if (s[i] == '/')
                {
                    result = NT / T;
                }

                ans.push(result);
            }
        }
    }

    return ans.peek();
}

int main()
{
    string P = "12 5 +";

    cout << "THE ANSWER IS: " << evaluatePostfix(P);

    return 0;
}