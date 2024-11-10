#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* topNode; 
    int size;

public:
    // Constructor
    Stack() : topNode(nullptr), size(0) {}

   
    ~Stack() {
        while (topNode != nullptr) {
            pop();
        }
    }

  
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
        size++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow! No elements to pop." << endl;
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        size--;
    }


    int top() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return topNode->data;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }


    int getSize() {
        return size;
    }
};

int main() {
    Stack myStack;


    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "Top element: " << myStack.top() << endl; 
    cout << "Stack size: " << myStack.getSize() << endl;

    myStack.pop();
    cout << "Top element after pop: " << myStack.top() << endl;

    myStack.pop();
    myStack.pop();
    myStack.pop(); 

    cout << "Is stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
