#include <iostream>

using namespace std;

void swap(int& number1, int& number2) {
    int temp = number1;
    number1 = number2;
    number2 = temp;
}

class Node {
public:
    int data;
    Node* parent;
    Node* leftChild;
    Node* rightChild;

    Node(int data) {
        this->data = data;
        this->parent = nullptr;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
    }
};

class QueueNode {
public:
    Node* node;
    QueueNode* next;

    QueueNode(Node* node) {
        this->node = node;
        this->next = nullptr;
    }
};

class Queue {
public:
    QueueNode* head;
    QueueNode* tail;

    Queue() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void push(Node* node) {
        QueueNode* queueNode = new QueueNode(node);
        if (this->head == nullptr) {
            this->head = queueNode;
            this->tail = queueNode;
        } else {
            this->tail->next = queueNode;
            this->tail = this->tail->next;
        }
    }

    Node* top() {
        return this->head->node;
    }

    Node* pop() {
        if (this->head != nullptr) {
            if (this->head == this->tail) {
                Node* node = this->head->node;
                this->head = nullptr;
                this->tail = nullptr;
                return node;
            } else {
                Node* node = this->head->node;
                this->head = this->head->next;
                return node;
            }
        } else
            return nullptr;
    }

    bool isEmpty() {
        if (this->head == nullptr) {
            return true;
        } else
            return false;
    }
};

class MinHeap {
private:
    int count;

public:
    Node* root;

    MinHeap() {
        this->root = nullptr;
        this->count = 0;
    }

    void insert(int data) {
        Node* node = new Node(data);

        if (this->root == nullptr) {
            this->root = node;
            this->count++;
            return;
        }

        Queue* queue = new Queue();
        queue->push(this->root);

        while (!queue->isEmpty()) {
            Node* currentNode = queue->pop();

            if (currentNode->leftChild == nullptr) {
                currentNode->leftChild = node;
                node->parent = currentNode;
                this->count++;
                break;
            } else if (currentNode->rightChild == nullptr) {
                currentNode->rightChild = node;
                node->parent = currentNode;
                this->count++;
                break;
            } else {
                queue->push(currentNode->leftChild);
                queue->push(currentNode->rightChild);
            }
        }

        heapify(node);
    }

    void heapify(Node* currentNode) {
        if (currentNode == nullptr) {
            return;
        } else {
            if (currentNode->parent != nullptr) {
                if (currentNode->data < currentNode->parent->data) {
                    swap(currentNode->data, currentNode->parent->data);
                    heapify(currentNode->parent);
                }
            }
        }
    }

    void printData(Node* node) {
        if (this->count > 1) {
            cout << node->data << " ";
            this->count--;
        } else {
            cout << node->data;
            cout << endl;
        }
    }

    void printNodes() {
        Queue* queue = new Queue();
        if (this->root != nullptr) {
            queue->push(this->root);
            while (!queue->isEmpty()) {
                Node* node = queue->top();
                if (node != nullptr) {
                    if (node->leftChild != nullptr || node->rightChild != nullptr) {
                        printData(node);

                        if (node->rightChild == nullptr && node->leftChild != nullptr) {
                            queue->push(node->leftChild);
                            queue->pop();
                        } else if (node->leftChild == nullptr && node->rightChild != nullptr) {
                            queue->push(node->rightChild);
                            queue->pop();
                        } else {
                            if (node->leftChild->data <= node->rightChild->data) {
                                queue->push(node->leftChild);
                                queue->push(node->rightChild);
                                queue->pop();
                            } else {
                                queue->push(node->rightChild);
                                queue->push(node->leftChild);
                                queue->pop();
                            }
                        }
                    } else {
                        printData(node);
                        queue->pop();
                    }
                }
            }
        }
    }
};

int main() {
    int count;
    cout << "Enter the number of elements." << endl;
    cout << "Count: ";
    cin >> count;
    cout << "Enter the elements" << endl;
    MinHeap* minheap = new MinHeap();
    Node* node;
    while (count >= 1) {
        cout << "Value: ";
        int data;
        cin >> data;
        minheap->insert(data);
        node = new Node(data);
        count--;
    }
    cout << "After sorting, the elements are as below." << endl;
    minheap->printNodes();
    delete node;
    delete minheap;
}