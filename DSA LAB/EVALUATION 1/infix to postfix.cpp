
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char a)
{
    if (a == '*' || a == '/')
    {
        return 2;
    }
    else if (a == '+' || a == '-')
    {
        return 1;
    }
    else
        return 0;
}

string infixToPostfix(string Q)
{
    stack<char> s;
    string P;

    s.push('(');
    Q = Q + ')';

    for (int i = 0; i < Q.length(); i++)
    {
        if (Q[i] == ' ')
        {
            continue;
        }

        else if (isalnum(Q[i]))
        {
            P = P + Q[i];
        }
        else if (Q[i] == '+' || Q[i] == '-' || Q[i] == '/' || Q[i] == '*')
        {
            while (s.top() != '(' && precedence(s.top()) >= precedence(Q[i]))
            {
                P = P + s.top();
                s.pop();
            }

            s.push(Q[i]);
        }

        else if (Q[i] == ')')
        {
            while (s.top() != '(')
            {
                P = P + s.top();
                s.pop();
            }

            s.pop();
        }
        else if (Q[i] == '(')
        {
            s.push('(');
        }
    }

    return P;
}

int main()
{
    string Q;

    cout << "Enter infix expression: ";
    getline(cin, Q);

    cout << "Postfix expression: " << infixToPostfix(Q);

    return 0;
}
