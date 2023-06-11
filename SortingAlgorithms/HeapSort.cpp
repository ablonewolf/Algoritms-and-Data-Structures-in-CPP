#include <iostream>
using namespace std;

void swap(int &number1, int &number2)
{
  int temp = number1;
  number1 = number2;
  number2 = temp;
}
struct Node
{
  int data;
  Node *parent;
  Node *leftChild;
  Node *rightChild;
  Node *next;

  Node(int data)
  {
    this->data = data;
    this->parent = nullptr;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
    this->next = nullptr;
  }
};

class Queue
{
public:
  Node *head;
  Queue()
  {
    this->head = nullptr;
  }

  void push(Node *node)
  {
    if (this->head == nullptr)
    {
      this->head = node;
    }
    else
    {
      Node *currentNode = this->head;
      while (currentNode != nullptr)
      {
        currentNode = currentNode->next;
      }
      currentNode = node;
    }
  }

  Node *top()
  {
    return this->head;
  }

  Node *pop()
  {
    if (this->head != nullptr)
    {
      Node *node = this->head;
      this->head = this->head->next;
      return node;
    }
    else
      return nullptr;
  }

  bool isEmpty()
  {
    if (this->head == nullptr)
    {
      return true;
    }
    else
      return false;
  }
};

class MinHeap
{
private:
  int count = 0;

public:
  Node *root;

  MinHeap()
  {
    this->root = nullptr;
  }

  void insert(int data)
  {
    Node *node = new Node(data);
    Node *newNode;
    if (this->root == nullptr)
    {
      this->root = node;
    }
    else
    {
      Queue *queue = new Queue();
      queue->push(this->root);

      while (!queue->isEmpty())
      {
        Node *currentNode = queue->top();
        if (currentNode != nullptr)
        {
          if (currentNode->leftChild != nullptr && currentNode->rightChild != nullptr)
          {
            queue->push(currentNode->leftChild);
            queue->push(currentNode->rightChild);
            queue->pop();
          }
          else
          {
            if (currentNode->leftChild == nullptr)
            {
              currentNode->leftChild = node;
              currentNode->leftChild->parent = currentNode;
              newNode = currentNode->leftChild;
              queue->pop();
              count++;
              break;
            }
            else
            {
              currentNode->rightChild = node;
              currentNode->rightChild->parent = currentNode;
              newNode = currentNode->rightChild;
              queue->pop();
              count++;
              break;
            }
          }

          heapify(newNode);
        }
      }
    }
  }

  void heapify(Node *currentNode)
  {
    if (currentNode == nullptr)
    {
      return;
    }
    else
    {
      if (currentNode->parent != nullptr)
      {
        if (currentNode->data < currentNode->parent->data)
        {
          swap(currentNode->data, currentNode->parent->data);
          heapify(currentNode->parent);
        }
      }
    }
  }

  void printNodes()
  {
    Queue *queue = new Queue();
    if (this->root != nullptr)
    {
      queue->push(this->root);
      while (!queue->isEmpty())
      {
        Node *node = queue->top();
        if (node != nullptr)
        {
          if (node->leftChild != nullptr || node->rightChild != nullptr)
          {
            if (count >= 1)
            {
              cout << node->data << " ";
              count--;
            }
            else
            {
              cout << node->data;
            }

            if (node->leftChild->data <= node->rightChild->data)
            {
              queue->push(node->leftChild);
              queue->push(node->rightChild);
            }
            else
            {
              queue->push(node->rightChild);
              queue->push(node->leftChild);
            }

            queue->pop();
          }
        }
      }
    }
  }
};

int main()
{
  int count;
  cout << "Enter the number of elements." << endl;
  cout << "Count: ";
  cin >> count;
  cout << "Enter the elements" << endl;
  MinHeap *minheap = new MinHeap();
  while (count >= 1)
  {
    cout << "Value: ";
    int data;
    cin >> data;
    minheap->insert(data);
    // cout << minheap->root->data;
    // minheap->printNodes();
    count--;
  }
  cout << "After sorting, the elements are as below." << endl;
  minheap->printNodes();
}