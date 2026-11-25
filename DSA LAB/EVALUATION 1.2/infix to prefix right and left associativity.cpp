
#include <iostream>
#include <cctype>
#include <string>
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
        TOS = -1;
        arr = new char[s];
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

    char peek()
    {
        if (isEmpty())
        {
            cout << "STACK UNDERFLOW!" << endl;
            return '\0';
        }

        return arr[TOS];
    }

    char pop()
    {
        if (isEmpty())
        {
            cout << "STACK UNDERFLOW!" << endl;
            return '\0';
        }

        char temp = arr[TOS];
        TOS--;
        return temp;
    }

    void push(char val)
    {
        if (isFull())
        {
            cout << "STACK OVERFLOW!" << endl;
            return;
        }

        TOS++;
        arr[TOS] = val;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "STACK UNDERFLOW!" << endl;
            return;
        }

        cout << "TOS:";

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
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

string infixtopostfix(string inf)
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

        if (inf[i] == '(')
        {
            s.push('(');
        }
        else if (inf[i] == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
            {
                post = post + s.pop();
            }

            s.pop();
        }
        else if (isalnum(inf[i]))
        {
            post = post + inf[i];
        }
        else if (inf[i] == '+' || inf[i] == '-' ||
                 inf[i] == '*' || inf[i] == '/' || inf[i] == '^')
        {
            while (!s.isEmpty() && s.peek() != '(' &&
                   (precedence(s.peek()) > precedence(inf[i]) ||
                   (precedence(s.peek()) == precedence(inf[i]) && inf[i] != '^')))
            {
                post = post + s.pop();
            }

            s.push(inf[i]);
        }
    }

    return post;
}

int main()
{
    string inf;

    cout << "Enter an infix expression: ";
    getline(cin, inf);

    cout << "Postfix expression: " << infixtopostfix(inf) << endl;

    return 0;
}
