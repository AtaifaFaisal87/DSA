
#include <iostream>
#include <string>
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
        TOS = -1;
        arr = new int[s];
        maxSize = s;
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

    int pop()
    {
        if (isEmpty())
        {
            cout << "STACK UNDERFLOW!" << endl;
            return -1;
        }

        int temp = arr[TOS];
        TOS--;
        return temp;
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

    ~Stack()
    {
        delete[] arr;
    }
};

int evaluatePrefix(string s)
{
    s = ')' + s;
    int NT, T, result;
    Stack ans(s.length());

    for (int i = s.length() - 1; s[i] != ')'; i--)
    {
        if (s[i] == ' ')
        {
            continue;
        }

        if (s[i] >= '0' && s[i] <= '9')
        {
            int num = 0;
            int place = 1;

            while (i > 0 && s[i] >= '0' && s[i] <= '9')
            {
                num = (s[i] - '0') * place + num;
                place *= 10;
                i--;
            }

            ans.push(num);
            i++;
        }

        else
        {
            T = ans.pop();
            NT = ans.pop();

            if (s[i] == '+')
                result = T + NT;
            else if (s[i] == '-')
                result = T - NT;
            else if (s[i] == '*')
                result = T * NT;
            else if (s[i] == '/')
                result = T / NT;
            else
                continue;

            ans.push(result);
        }
    }

    return ans.peek();

}

int main()
{
    string prefix;

    cout << "Enter a prefix expression: ";
    getline(cin, prefix);

    cout << "Result: " << evaluatePrefix(prefix) << endl;

    return 0;
}
