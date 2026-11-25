#include <iostream>
using namespace std;

class Stack
{
private:
    int TOS;
    char *arr;
    int maxSize;

public:
    Stack(int s)
    {
        maxSize = s;
        arr = new char[s];
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

    char peek()
    {
        if (isEmpty())
        {
            cout << "STACK UNDERFLOW!" << endl;
            return '\0';
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

    char pop()
    {
        if (isEmpty())
        {
            cout << "STACK UNDERFLOW!" << endl;
            return '\0';
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

int precedence(char op)
{
    if (op == '*' || op == '/')
    {
        return 2;
    }
    else if (op == '+' || op == '-')
    {
        return 1;
    }
    else
        return 0;
}
string infixToPostfix(string inf)
{
    Stack s(inf.length() + 1);
    string post;

    s.push('(');
    inf = inf + ')';

    for (int i = 0; i < inf.length(); i++)
    {
        if (inf[i] == ' ')
        {
            continue;
        }

        else if (inf[i] == '(')
        {
            s.push('(');
        }

        else if (inf[i] == ')')
        {
            while (s.peek() != '(' && !s.isEmpty())
            {
                post = post + s.pop();
            }

            s.pop();
        }

        else if (isalnum(inf[i]))
        {
            post = post + inf[i];
        }

        else if (inf[i] == '+' || inf[i] == '-' || inf[i] == '*' || inf[i] == '/')
        {
            while (s.peek() != '(' && precedence(s.peek()) >= precedence(inf[i]))
            {
                post = post + s.peek();
                s.pop();
            }

            s.push(inf[i]);
        }
    }

    return post;
}
int main()
{
    string Q;

    cout << "Enter infix expression: ";
    getline(cin, Q);

    cout << "Postfix expression: " << infixToPostfix(Q);

    return 0;
}