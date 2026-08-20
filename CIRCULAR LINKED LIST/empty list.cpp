#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

};

int main() {
    Node* head = new Node();  
    head->next = head;        
    return 0;
}