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
                {
                    return false;
                }
            }
        }
    }

    return s.isEmpty();
}

int PostfixEval(string P)
{
    int result, NT, T;
    Stack s(P.length());

    for (int i = 0; i < P.length(); i++)
    {
        if (P[i] == ' ')
        {
            continue;
        }
        if (P[i] >= '0' && P[i] <= '9')
        {
            s.push(P[i] - '0');
        }
        else
        {
            T = s.pop();
            NT = s.pop();

            if (P[i] == '+')
            {
                result = NT + T;
            }

            else if (P[i] == '-')
            {
                result = NT - T;
            }

            else if (P[i] == '*')
            {
                result = NT * T;
            }

            else if (P[i] == '/')
            {
                result = NT / T;
            }

            s.push(result);
        }
    }

    return s.peek();
}

int PrefixEval(string P)
{
    Stack s(P.length());
    int NT, T, result;

    for (int i = P.length() - 1; i >= 0; i--)
    {
        if (P[i] == 0)
        {
            continue;
        }

        if (P[i] >= '0' && P[i] <= '9')
        {
            s.push(P[i] - '0');
        }

        else
        {

            T = s.pop();
            NT = s.pop();
            if (P[i] == '+')
            {
                result = T + NT;
            }

            else if (P[i] == '-')
            {
                result = T - NT;
            }

            else if (P[i] == '*')
            {
                result = T * NT;
            }

            else if (P[i] == '/')
            {
                result = T / NT;
            }

            s.push(result);
        }
    }

    return s.peek();
}

int main()
{
    int choice, val;
    string P;

    Stack s(100);

    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Peek" << endl;
    cout << "4. Display" << endl;
    cout << "5. Valid Parentheses" << endl;
    cout << "6. Postfix Evaluation" << endl;
    cout << "7. Prefix Evaluation" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter value: ";
        cin >> val;
        s.push(val);
        s.display();
    }
    else if (choice == 2)
    {
        if (!s.isEmpty())
            cout << "Popped: " << s.pop() << endl;
        else
            cout << "Stack is empty!" << endl;
    }
    else if (choice == 3)
    {
        if (!s.isEmpty())
            cout << "Top element: " << s.peek() << endl;
        else
            cout << "Stack is empty!" << endl;
    }
    else if (choice == 4)
    {
        s.display();
    }
    else if (choice == 5)
    {
        cout << "Enter brackets: ";
        cin >> P;

        if (isValid(P))
            cout << "Valid Parentheses" << endl;
        else
            cout << "Invalid Parentheses" << endl;
    }
    else if (choice == 6)
    {
        cout << "Enter postfix expression: ";
        cin.ignore();
        getline(cin, P);
        cout << "Result: " << PostfixEval(P) << endl;
    }
    else if (choice == 7)
    {
        cout << "Enter prefix expression: ";
        cin.ignore();
        getline(cin, P);
        cout << "Result: " << PrefixEval(P) << endl;
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
