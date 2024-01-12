#include <iostream>

using namespace std;

// class definition for node
class Node {
public:
    char value;
    Node *next;

    // default constructor with no value passed,
    // in this case, the value will be null

    // default constructor when value is passed
    Node(char value) {
        this->value = value;
        this->next = nullptr;
    }
};

// class definition for stack
class Stack {
public:
    Node *head;

    // default constructor with no value
    //  in this case, head will be null
    Stack() {
        this->head = nullptr;
    }

    // default constructor with value passed
    Stack(char value) {
        this->head->value = value;
    }

    // method for pushing value into the stack
    // whenever we push a value, it will be saved as the first element; often we call it the top
    void push(char value) {
        Node *node = new Node(value);
        if (this->head == nullptr) {
            this->head = node;
        } else {
            Node *tempNode = this->head;
            node->next = tempNode;
            this->head = node;
        }
    }

    // method for returning the top-most value
    char top() {
        return this->head->value;
    }

    // method for removing the current-top and returning its value
    char pop() {
        int topValue = this->head->value;
        this->head = this->head->next;
        return topValue;
    }

    bool isEmpty() {
        return this->head == nullptr;
    }

    void printStack() {
        if (this->head == nullptr) {
            cout << "The stack is currently empty." << endl;
        } else {
            cout << "The present items in the stack are listed below." << endl;
            Node *tempNode = this->head;
            while (tempNode != nullptr) {
                if (tempNode == this->head) {
                    cout << tempNode->value;
                } else {
                    cout << "->" << tempNode->value;
                }
                tempNode = tempNode->next;
            }
            cout << endl;
        }
    }
};