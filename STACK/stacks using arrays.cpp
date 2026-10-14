#include<iostream>
using namespace std;

class stack {
private:
    int top;
    int size;
    int *arr;

public:

    stack(int s) {
        top = -1;
        arr = new int[s];
        size = s;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "STACK OVERFLOW" << endl;
            return;
        }

        arr[++top] = value;
    }

    void pop() {
        if (isEmpty()) {
            cout << "STACK UNDERFLOW" << endl;
            return;
        }

        cout << "ELEMENT POPPED: " << arr[top] << endl;
        top--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "STACK UNDERFLOW" << endl;
            return -1;
        }

        return arr[top];
    }

    void makeEmpty() {
        top = -1;
    }

    void display() {
        if (isEmpty()) {
            cout << "STACK UNDERFLOW" << endl;
            return;
        }

        cout << "DISPLAYING ELEMENTS IN STACK!" << endl;

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    ~stack() {
        delete[] arr;
    }
};

int main() {
    int n, value, choice;

    do {
        cout << "ENTER THE SIZE OF STACK: ";
        cin >> n;

        if (n <= 0) {
            cout << "INVALID STACK SIZE...TRY AGAIN!" << endl;
        }

    } while (n <= 0);

    stack s(n);

    do {
        cout << "1. PUSH" << endl
             << "2. POP" << endl
             << "3. PEEK" << endl
             << "4. CHECK EMPTY" << endl
             << "5. CHECK FULL" << endl
             << "6. MAKE EMPTY" << endl
             << "7. DISPLAY" << endl
             << "0. EXIT" << endl;

        cout << "ENTER YOUR CHOICE: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "ENTER VALUE: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                if (!s.isEmpty()) {
                    cout << "TOP ELEMENT: " << s.peek() << endl;
                } else {
                    s.peek();
                }
                break;

            case 4:
                cout << "IS STACK EMPTY? " << s.isEmpty() << endl;
                break;

            case 5:
                cout << "IS STACK FULL? " << s.isFull() << endl;
                break;

            case 6:
                s.makeEmpty();
                cout << "STACK CLEARED!" << endl;
                break;

            case 7:
                s.display();
                break;

            case 0:
                cout << "PROGRAM ENDED." << endl;
                break;

            default:
                cout << "INVALID CHOICE!" << endl;
        }

    } while (choice != 0);

    return 0;
}
