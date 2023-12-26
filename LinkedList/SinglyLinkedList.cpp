#include <iostream>
using namespace std;

class SinglyLinkedList
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
  SinglyLinkedList()
  {
    this->head = nullptr;
  }
  SinglyLinkedList(int initialValue)
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
        Node *temp = this->head;
        while (1)
        {
          cout << temp->value << endl;
          if (temp == nullptr)
          {
            break;
          }
          else
          {
            if (temp->next->value == value)
            {
              Node *newNext = temp->next->next;
              temp->next = newNext;
              found = true;
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
      cout << "Empty linked list" << endl;
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

int main()
{
  SinglyLinkedList *linkedList = new SinglyLinkedList();
  cout << "Enter the size of the linked list : " << endl;
  int size;
  cout << "Size : ";
  cin >> size;
  cout << "Enter the values inside the linkedlist." << endl;
  int iteration = 0;
  while (iteration < size)
  {
    int value;
    cout << "Enter value: ";
    cin >> value;
    if (linkedList->insertNodeInOrder(value))
    {
      iteration++;
    }
  }
  cout << "Size of the linkgedlist is : " << linkedList->getSize() << endl;
  cout << "Its values are : ";
  linkedList->printValues();
  int option;
  cout << "Enter 1 to add more elements, 2 to remove elements, 3 to print the current list, and 4 to exit the application" << endl;
  while (1)
  {
    cout << "Enter option: ";
    cin >> option;
    if (option == 1)
    {
      int value;
      cout << "Enter the value to add: ";
      cin >> value;
      if (linkedList->insertNodeInOrder(value))
      {
        cout << "Value added successfully." << endl;
      }
    }
    else if (option == 2)
    {
      int value;
      cout << "Enter the value to remove: ";
      cin >> value;
      linkedList->removeNode(value);
    }
    else if (option == 3)
    {
      cout << "The values present in the linked list are as follows:" << endl;
      linkedList->printValues();
    }
    else if (option == 4)
    {
      cout << "Exiting the application. Thank you for using" << endl;
      break;
    }
    else
    {
      cout << "Invalid option. Please try again" << endl;
    }
  }
  delete linkedList;
}