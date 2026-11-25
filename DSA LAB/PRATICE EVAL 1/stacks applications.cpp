#include <iostream>
#include <stack>
#include <cctype>
#include <string>
#include <cmath>
using namespace std;

bool isvalid(string P)
{
    stack<char> s;

    for (int i = 0; i < P.length(); i++)
    {
        if (P[i] == '(' || P[i] == '{' || P[i] == '[')
        {
            s.push(P[i]);
        }
        else
        {
            if (s.empty())
            {
                return false;
            }
            else
            {
                if (P[i] == ')' && s.top() == '(')
                {
                    s.pop();
                }

                else if (P[i] == '}' && s.top() == '{')
                {
                    s.pop();
                }

                else if (P[i] == ']' && s.top() == '[')
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
        }
    }

    return s.empty();
}

int postfix(string p)
{
    stack<int> s;
    p = p + ')';
    int T, NT, result;
    for (int i = 0; p[i] != ')'; i++)
    {
        if (p[i] == ' ')
        {
            continue;
        }

        if (p[i] >= '0' && p[i] <= '9')
        {
            int num = 0;
            while (i < p.length() && p[i] >= '0' && p[i] <= '9')
            {
                num = num * 10 + (p[i] - '0');
                i++;
            }

            s.push(num);
            i--;
        }

        else
        {
            T = s.top();
            s.pop();

            NT = s.top();
            s.pop();

            if (p[i] == '+')
            {
                result = NT + T;
            }

            else if (p[i] == '-')
            {
                result = NT - T;
            }

            else if (p[i] == '*')
            {
                result = NT * T;
            }

            else if (p[i] == '/')
            {
                result = NT / T;
            }
            else if (p[i] == '^')
            {
                result = pow(NT, T);
            }

            s.push(result);
        }
    }

    return s.top();
}

int prefix(string p)
{
    p = ')' + p;
    int NT, T, result;
    stack<int> s;

    for (int i = p.length() - 1; p[i] != ')'; i--)
    {
        if (p[i] == ' ')
        {
            continue;
        }
        if (p[i] >= '0' && p[i] <= '9')
        {
            int num = 0;
            int place = 1;
            while (i > 0 && p[i] >= '0' && p[i] <= '9')
            {
                num = (p[i] - '0') * place + num;
                place *= 10;
                i--;
            }
            s.push(num);
            i++;
        }
        else
        {
            T = s.top();
            s.pop();

            NT = s.top();
            s.pop();

            if (p[i] == '+')
            {
                result = T + NT;
            }

            else if (p[i] == '-')
            {
                result = T - NT;
            }

            else if (p[i] == '*')
            {
                result = T * NT;
            }

            else if (p[i] == '/')
            {
                result = T / NT;
            }
            else if (p[i] == '^')
            {
                result = pow(T, NT);
            }

            s.push(result);
        }
    }

    return s.top();
}

int postfixwithoutsentinel(string p)
{
    stack<int> s;

    int T, NT, result;
    for (int i = 0; i < p.length(); i++)
    {
        if (p[i] == ' ')
        {
            continue;
        }

        if (p[i] >= '0' && p[i] <= '9')
        {
            int num = 0;
            while (i < p.length() && p[i] >= '0' && p[i] <= '9')
            {
                num = num * 10 + (p[i] - '0');
                i++;
            }

            s.push(num);
            i--;
        }

        else
        {
            T = s.top();
            s.pop();

            NT = s.top();
            s.pop();

            if (p[i] == '+')
            {
                result = NT + T;
            }

            else if (p[i] == '-')
            {
                result = NT - T;
            }

            else if (p[i] == '*')
            {
                result = NT * T;
            }

            else if (p[i] == '/')
            {
                result = NT / T;
            }
            else if (p[i] == '^')
            {
                result = pow(NT, T);
            }

            s.push(result);
        }
    }

    return s.top();
}

int prefixwithoutsentinel(string p)
{
    int NT, T, result;
    stack<int> s;

    for (int i = p.length() - 1; i >= 0; i--)
    {
        if (p[i] == ' ')
        {
            continue;
        }
        if (p[i] >= '0' && p[i] <= '9')
        {
            int num = 0;
            int place = 1;
            while (i >= 0 && p[i] >= '0' && p[i] <= '9')
            {
                num = (p[i] - '0') * place + num;
                place *= 10;
                i--;
            }
            s.push(num);
            i++;
        }
        else
        {
            T = s.top();
            s.pop();

            NT = s.top();
            s.pop();

            if (p[i] == '+')
            {
                result = T + NT;
            }

            else if (p[i] == '-')
            {
                result = T - NT;
            }

            else if (p[i] == '*')
            {
                result = T * NT;
            }

            else if (p[i] == '/')
            {
                result = T / NT;
            }
            else if (p[i] == '^')
            {
                result = pow(T, NT);
            }

            s.push(result);
        }
    }

    return s.top();
}

int precedence(char op)
{
    if (op == '^')
    {
        return 3;
    }
    else if (op == '/' || op == '*' || op == '%')
    {
        return 2;
    }
    else if (op == '+' || op == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
string infixtopostfix(string inf)
{
    stack<char> s;
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
            while (!s.empty() && s.top() != '(')
            {
                post = post + s.top();
                s.pop();
            }

            s.pop();
        }
        else if (isalnum(inf[i]))
        {
            post = post + inf[i];
        }

        else if (inf[i] == '+' || inf[i] == '-' ||
                 inf[i] == '*' || inf[i] == '/' ||
                 inf[i] == '%' || inf[i] == '^')
        {
            while (!s.empty() && s.top() != '(' && (precedence(s.top()) > precedence(inf[i]) || precedence(s.top()) == precedence(inf[i]) && inf[i] != '^'))
            {
                post = post + s.top();
                s.pop();
            }

            s.push(inf[i]);
        }
    }

    return post;
}
string infixtopostfixdistinction(string inf)
{
    stack<char> s;
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
            while (!s.empty() && s.top() != '(')
            {
                post = post + s.top();
                s.pop();
            }

            s.pop();
        }
        else if (isalnum(inf[i]))
        {
            while (i < inf.length() && isalnum(inf[i]))
            {
                post = post + inf[i];
                i++;
            }
            post = post + ' ';
            i--;
        }

        else if (inf[i] == '+' || inf[i] == '-' ||
                 inf[i] == '*' || inf[i] == '/' ||
                 inf[i] == '%' || inf[i] == '^')
        {
            while (!s.empty() && s.top() != '(' && (precedence(s.top()) > precedence(inf[i]) || precedence(s.top()) == precedence(inf[i]) && inf[i] != '^'))
            {
                post = post + s.top();
                s.pop();
            }

            s.push(inf[i]);
        }
    }

    return post;
}

int main()
{
    string inf;

    cout << "Enter infix expression: ";
    getline(cin, inf);

    cout << "Postfix expression: " << infixtopostfixdistinction(inf) << endl;

    return 0;
}
