#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int value;
  Node *next;
  Node *prev;
  Node(int value)
  {
    this->value = value;
    this->next = nullptr;
    this->prev = nullptr;
  }
};

class DoublyLinkedList
{
public:
  Node *head;
  Node *tail;

  DoublyLinkedList()
  {
    this->head = this->tail = nullptr;
  }
  bool isSortedAscending()
  {
    if (this->head == nullptr || this->head == this->tail || this->head->value < this->head->next->value)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  bool insertNode(int value)
  {
    bool isInserted = false;
    bool isSortedAscending = this->isSortedAscending();
    Node *node = new Node(value);
    if (this->head != nullptr)
    {
      if (this->tail != this->head)
      {
        if (isSortedAscending)
        {
          Node *tempNode = this->head;
          while (tempNode != nullptr)
          {
            if (tempNode->value > node->value)
            {
              if (tempNode == this->head)
              {
                node->next = tempNode;
                node->prev = nullptr;
                this->head = node;
                tempNode->prev = node;
              }
              else
              {
                Node *prevNode = tempNode->prev;
                prevNode->next = node;
                node->prev = prevNode;
                node->next = tempNode;
                tempNode->prev = node;
              }
              isInserted = true;
              break;
            }
            else if (tempNode->value == node->value)
            {
              cout << "Value already exists." << endl;
              break;
            }
            else
            {
              if (tempNode == this->tail)
              {
                tempNode->next = node;
                node->prev = tempNode;
                this->tail = node;
                isInserted = true;
                break;
              }
              tempNode = tempNode->next;
            }
          }
        }
        else
        {
          Node *tempNode = this->head;
          while (tempNode != nullptr)
          {
            if (tempNode->value < node->value)
            {
              if (tempNode == this->head)
              {
                node->next = tempNode;
                node->prev = nullptr;
                this->head = node;
                tempNode->prev = node;
              }
              else
              {
                Node *prevNode = tempNode->prev;
                prevNode->next = node;
                node->prev = prevNode;
                node->next = tempNode;
                tempNode->prev = node;
              }
              isInserted = true;
              break;
            }
            else if (tempNode->value == node->value)
            {
              cout << "Value already exists." << endl;
              break;
            }
            else
            {
              if (tempNode == this->tail)
              {
                tempNode->next = node;
                node->prev = tempNode;
                this->tail = node;
                isInserted = true;
                break;
              }
              tempNode = tempNode->next;
            }
          }
        }
      }
      else
      {
        if (this->head->value > node->value)
        {
          node->next = this->head;
          this->head->prev = node;
          this->head = node;
          isInserted = true;
        }
        else if (this->head->value < node->value)
        {
          this->head->next = node;
          node->prev = this->head;
          node->next = nullptr;
          this->tail = node;
          isInserted = true;
        }
        else
        {
          cout << "Value already exists." << endl;
        }
      }
    }
    else
    {
      this->head = node;
      this->tail = node;
      isInserted = true;
    }
    return isInserted;
  }

  bool removeNode(int value)
  {
    bool isRemoved = false;
    if (this->head == nullptr)
    {
      cout << "This List is empty" << endl;
    }
    else if (this->head == this->tail)
    {
      if (this->head->value = value)
      {
        this->head = nullptr;
        this->tail = nullptr;
        isRemoved = true;
      }
    }
    else
    {
      if (this->head->value == value)
      {
        this->head = this->head->next;
        this->head->prev = nullptr;
        isRemoved = true;
      }
      else
      {
        Node *tempNode = this->head;
        while (1)
        {
          if (tempNode->next == nullptr)
          {
            break;
          }
          else if (tempNode->next->value == value)
          {
            if (tempNode->next == this->tail)
            {
              tempNode->next = nullptr;
              this->tail = tempNode;
            }
            else
            {
              tempNode->next->next->prev = tempNode;
              tempNode->next = tempNode->next->next;
            }
            isRemoved = true;
            break;
          }
          else
          {
            tempNode = tempNode->next;
          }
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
      cout << "Empty Linked List." << endl;
    }
    else
    {
      if (this->head->value == value)
      {
        isFound = true;
      }
      else if (this->head->value > value)
      {
        return isFound;
      }
      else
      {
        Node *tempNode = this->head;
        while (1)
        {
          if (tempNode->next == nullptr || tempNode->next->value > value)
          {
            break;
          }
          else if (tempNode->next->value == value)
          {
            isFound = true;
            break;
          }
          else
          {
            tempNode = tempNode->next;
          }
        }
      }
    }
    return isFound;
  }

  void printList(Node *node)
  {
    if (node == this->head)
    {
      if (this->head == this->tail)
      {
        cout << node->value << endl;
        return;
      }
      else
      {
        cout << node->value << "->";
        printList(node->next);
      }
    }
    else if (node != nullptr)
    {
      if (node == this->tail)
      {
        cout << node->value << endl;
        return;
      }
      else
      {
        cout << node->value << "->";
        printList(node->next);
      }
    }
    else
    {
      return;
    }
  }

  void reverseList()
  {
    Node *tempNode = this->head;
    Node *node;
    while (tempNode != nullptr)
    {
      node = tempNode->next;
      tempNode->next = tempNode->prev;
      tempNode->prev = node;
      if (tempNode->next == nullptr)
      {
        this->tail = tempNode;
      }
      if (tempNode->prev == nullptr)
      {
        this->head = tempNode;
        break;
      }
      tempNode = tempNode->prev;
    }
  }
};