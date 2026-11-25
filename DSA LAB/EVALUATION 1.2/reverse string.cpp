
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

string reverseString(string str)
{
    Stack s(str.length());

    for (int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }

    int i = 0;

    while (!s.isEmpty())
    {
        str[i] = s.pop();
        i++;
    }

    return str;
}

int main()
{
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Reversed string: " << reverseString(str) << endl;

    return 0;
}
