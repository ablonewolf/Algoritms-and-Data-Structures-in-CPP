#include <iostream>
#include "Node.h"

using namespace std;

class Queue {
public:
    Node* front;
    Node* rear;

    Queue() {
        this->front = nullptr;
        this->rear = nullptr;
    }

    bool isEmpty() {
        if (this->front == nullptr) {
            return true;
        }
        return false;
    }

    void enqueue(int value) {
        Node* node = new Node(value);
        if (this->isEmpty()) {
            this->front = node;
            this->rear = node;
        } else {
            this->rear->next = node;
            this->rear = node;
        }
    }

    int getFront() {
        if (this->front != nullptr) {
            return this->front->value;
        }
        return -99999;
    }

    int dequeue() {
        if (this->front != nullptr) {
            int value = this->front->value;
            this->front = this->front->next;
            return value;
        }
        return -99999;
    }

    void printQueue() {
        if (this->isEmpty()) {
            cout << "This queue is empty" << endl;
        } else {
            Node* temp = this->front;
            cout << "The present items in the queue are as below:" << endl;
            while (temp) {
                if (!temp->next) {
                    cout << temp->value << endl;
                } else {
                    cout << temp->value << "->";
                }
                temp = temp->next;
            }
        }
    }
};