#include <bits/stdc++.h>
using namespace std;

class LinkedList
{
public:
  class Node
  {
  public:
    int value;
    Node *next = nullptr;
    Node(int value)
    {
      this->value = value;
      this->next = nullptr;
    }
  };
  LinkedList()
  {
    this->head = nullptr;
  }
  LinkedList(int initialValue)
  {
    this->head->value = initialValue;
  }
  Node *head;

  void insertNode(int value)
  {
    Node *node = new Node(value);
    if (this->head != nullptr)
    {
      Node *temp = this->head;
      while (1)
      {
        if (temp->next == nullptr)
        {
          temp->next = node;
          break;
        }
        temp = temp->next;
      }
    }
    else
    {
      this->head = node;
    }
  }

  bool insertNodeInOrder(int value)
  {
    bool isAdditionSuccessful = false;
    Node *node = new Node(value);
    if (this->head != nullptr)
    {
      if (this->head->value > node->value)
      {
        Node *temp = this->head;
        node->next = temp;
        this->head = node;
        isAdditionSuccessful = true;
      }
      else
      {
        Node *temp = this->head;
        while (1)
        {
          if (temp->next == nullptr)
          {
            temp->next = node;
            isAdditionSuccessful = true;
            break;
          }
          else if (temp->next->value < node->value)
          {
            if (temp->next->next == nullptr)
            {
              temp->next->next = node;
              isAdditionSuccessful = true;
              break;
            }
            temp = temp->next;
          }
          else if (temp->next->value == value)
          {
            cout << "This value already exists in the list. So not adding it" << endl;
            break;
          }
          else
          {
            node->next = temp->next;
            temp->next = node;
            isAdditionSuccessful = true;
            break;
          }
        }
      }
    }
    else
    {
      this->head = node;
      isAdditionSuccessful = true;
    }
    return isAdditionSuccessful;
  }

  bool findNode(int value)
  {
    bool found = false;
    if (this->head == nullptr)
    {
      cout << "This LinkedList is empty." << endl;
    }
    else
    {
      if (this->head->value == value)
      {
        found = true;
      }
      else
      {
        Node *temp = this->head->next;
        while (1)
        {
          if (temp == nullptr)
          {
            break;
          }
          else
          {
            if (temp->value == value)
            {
              found = true;
              break;
            }
            else
            {
              temp = temp->next;
            }
          }
        }
      }
    }
    return found;
  }
  void removeNode(int value)
  {
    bool found = false;
    if (this->head == nullptr)
    {
      cout << "This LinkedList is empty." << endl;
    }
    else
    {
      if (this->head->value == value)
      {
        this->head = this->head->next;
        cout << "Node with value : " << value << " has been removed." << endl;
      }
      else
      {
        Node *temp = this->head->next;
        while (1)
        {
          if (temp == nullptr)
          {
            break;
          }
          else
          {
            if (temp->value == value)
            {
              found = true;
              temp = temp->next;
              break;
            }
            else
            {
              temp = temp->next;
            }
          }
        }
        if (found)
        {
          cout << "Node with value : " << value << " has been removed." << endl;
        }
        else
        {
          cout << "Node with value: " << value << "was not found" << endl;
        }
      }
    }
  }

  int getSize()
  {
    int count = 0;
    if (this->head == nullptr)
    {
      return count;
    }
    else
    {
      count++;
      Node *temp = this->head;
      while (temp->next != nullptr)
      {
        count++;
        temp = temp->next;
      }
      return count;
    }
  }
  void printValues()
  {
    Node *temp = this->head;
    if (temp == nullptr)
    {
      cout << "No item exists at this index." << endl;
    }
    else
    {
      while (temp != nullptr)
      {
        cout << temp->value;
        if (temp->next != nullptr)
        {
          cout << " -> ";
          temp = temp->next;
        }
        else
        {
          cout << endl;
          break;
        }
      }
    }
  }
};