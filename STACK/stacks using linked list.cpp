
#include<iostream>
#include<new>
using namespace std;

struct Node {
    int info;
    Node *next;
};

class stack {
private:
    Node* top;

public:
    stack() {
        top = NULL;
    }

    bool isEmpty() {
        return top == NULL;
    }

    bool isFull() {
        Node* temp = new(nothrow) Node;

        if (temp == NULL) {
            return true;
        }

        delete temp;
        return false;
    }

    void push(int value) {
        if (isFull()) {
            cout << "STACK OVERFLOW" << endl;
            return;
        }

        Node* newNode = new(nothrow) Node;

        if (newNode == NULL) {
            cout << "STACK OVERFLOW" << endl;
            return;
        }

        newNode->info = value;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "STACK UNDERFLOW" << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void makeEmpty() {
        while (!isEmpty()) {
            pop();
        }
    }

    void display() {
        Node* temp = top;

        while (temp != NULL) {
            cout << temp->info << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    ~stack() {
        makeEmpty();
    }
};

int main() {
    stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "STACK: ";
    s.display();

    s.pop();

    cout << "AFTER POP: ";
    s.display();

    s.makeEmpty();

    cout << "IS EMPTY? " << s.isEmpty() << endl;

    return 0;
}
