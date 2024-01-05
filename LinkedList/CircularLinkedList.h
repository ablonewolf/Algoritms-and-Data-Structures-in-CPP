#include <bits/stdc++.h>
#include "Node.h"
using namespace std;

class CircularLinkedList
{
public:
  CircularLinkedList()
  {
    this->head = nullptr;
  }

  CircularLinkedList(int value)
  {
    this->head->value = value;
  }
  Node *head;
  bool insertNode(int value)
  {
    Node *node = new Node(value);
    bool isInserted = false;
    if (this->head != nullptr)
    {
      Node *temp = this->head;
      if (temp->next == this->head)
      {
        if (temp->value == value)
        {
          cout << "Value is already present in the list." << endl;
        }
        else
        {
          if (temp->value > node->value)
          {
            node->next = temp;
            this->head = node;
            temp->next = this->head;
          }
          else
          {
            temp->next = node;
            node->next = temp;
          }
          isInserted = true;
        }
      }
      else
      {
        while (1)
        {

          if (temp->next->value > node->value)
          {
            node->next = temp->next;
            temp->next = node;
            isInserted = true;
            break;
          }
          else if (temp->next == this->head)
          {
            node->next = this->head;
            temp->next = node;
            isInserted = true;
            break;
          }
          else if (temp->next->value == node->value)
          {
            cout << "Value is already present in the list." << endl;
            break;
          }
          else
          {
            temp = temp->next;
          }
        }
      }
    }
    else
    {
      this->head = node;
      this->head->next = this->head;
      isInserted = true;
    }

    return isInserted;
  }

  bool removeNode(int value)
  {
    bool isRemoved = false;
    if (this->head == nullptr)
    {
      cout << "Empty List." << endl;
    }
    else if (this->head->value == value)
    {
      if (this->head->next == this->head)
      {
        this->head = nullptr;
      }
      else
      {
        this->head = this->head->next;
      }
      isRemoved = true;
    }
    else
    {
      Node *temp = this->head;
      while (1)
      {
        if (temp->next == this->head)
        {
          break;
        }
        else if (temp->next->value == value)
        {
          temp->next = temp->next->next;
          isRemoved = true;
          break;
        }
        else
        {
          temp = temp->next;
        }
      }
    }
    return isRemoved;
  }

  bool findNode(int value)
  {
    bool isFound = false;
    if (this->head == nullptr)
    {
      cout << "Empty List." << endl;
    }
    else if (this->head->next == this->head)
    {
      if (this->head->value == value)
      {
        isFound = true;
      }
    }
    else
    {
      Node *temp = this->head;
      while (temp->next != this->head)
      {
        if (temp->value == value)
        {
          isFound = true;
          break;
        }
        else if (temp->value > value)
        {
          break;
        }
        else
        {
          temp = temp->next;
        }
      }
      if (temp->next == this->head && !isFound)
      {
        if (temp->value == value)
        {
          isFound = true;
        }
      }
    }
    return isFound;
  }

  void printListRecursively(Node *node)
  {
    if (node == this->head)
    {
      if (this->head == nullptr)
      {
        cout << "Empty List." << endl;
      }
      else if (this->head->next == this->head)
      {
        cout << this->head->value << endl;
      }
      else
      {
        cout << this->head->value;
        printListRecursively(this->head->next);
      }
    }
    else
    {
      if (node->next == this->head)
      {
        cout << "->" << node->value << endl;
        return;
      }
      else
      {
        cout << "->" << node->value;
        printListRecursively(node->next);
      }
    }
  }
};