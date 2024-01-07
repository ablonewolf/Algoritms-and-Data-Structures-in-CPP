#include <bits/stdc++.h>
#include "Node.h"
#define default_value -9999999
using namespace std;

class SinglyLinkedList
{
public:
  SinglyLinkedList()
  {
    this->head = nullptr;
  }
  SinglyLinkedList(int initialValue)
  {
    this->head->value = initialValue;
  }
  Node *head;

  // method to check whether the list is sorted in ascending or descending order
  // if the list is empty or has only one element, we will assume it's sorted in ascending order
  // otherwise, we will compare the first value with the second value
  // if the former is less than the latter, we will assume the list is sorted in ascending order
  // otherwise the list is sorted in descending order
  bool isSortedAscending()
  {
    if (this->head == nullptr || this->head->next == nullptr || this->head->value < this->head->next->value)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  // method to insert a new node in the list
  // if it returns true, node insertion is successful
  // if it returns false, node insertion is failed
  bool insertNode(int value)
  {
    // first we will check whether the list is sorted in ascending or descending order
    // our insertion will vary based on the sort order
    // if the head is null, we will simply set the new node to be head
    bool isAdditionSuccessful = false;
    bool sortedAsynchronously = this->isSortedAscending();
    Node *node = new Node(value);
    // the list is not empty since the head is not null
    if (this->head != nullptr)
    {
      // if sorted in ascending order
      if (sortedAsynchronously)
      {
        // we will first determine the new node's position
        // we will keep traversing the list until we find a node whose value is greater than that of new node
        // if found, we will place the new node right before the found node
        // otherwise, we will place the new node at the end of the list
        Node *tempNode = this->head;
        // traversing throughout the list to find the appropriate position
        while (tempNode != nullptr)
        {
          // if we have reached the last node, we will do the following.
          if (tempNode->next == nullptr)
          {
            // if the last node's value is greater than the inserted value
            // we will add the new node after the last node and swap the values
            if (tempNode->value > node->value)
            {
              tempNode->next = node;
              int tempValue = node->value;
              node->value = tempNode->value;
              tempNode->value = tempValue;
              isAdditionSuccessful = true;
              break;
            }
            // if the last node's value is smaller than the inserted value
            // we will add the new node after the previous last node.
            else if (tempNode->value < node->value)
            {
              tempNode->next = node;
              isAdditionSuccessful = true;
              break;
            }
            // if they are of same value, insertion will be discarded.
            else
            {
              cout << "This value already exists in the list. So not adding it" << endl;
              break;
            }
          }
          // if the current node is not the last node
          // if the node satisfies the above condition, we will insert the new node before this node
          else if (tempNode->value > node->value)
          {
            // we will add the newly node right after the encountered node
            // then we will swap the values between two nodes
            node->next = tempNode->next;
            tempNode->next = node;
            int tempValue = node->value;
            node->value = tempNode->value;
            tempNode->value = tempValue;
            isAdditionSuccessful = true;
            break;
          }
          // if we see that the value already exists, we will terminate the operation right away.
          else if (tempNode->value == value)
          {
            cout << "This value already exists in the list. So not adding it" << endl;
            break;
          }
          // other than that, point to the next node and continue traversing
          else
          {
            tempNode = tempNode->next;
          }
        }
      }
      // if sorted in descending order
      else
      {
        // we will first determine the new node's position
        // we will keep traversing the list until we find a node whose value is less than that of new node
        // if found, we will place the new node right before the found node
        // otherwise, we will place the new node at the end of the list
        Node *tempNode = this->head;
        // traversing throughout the list to find the appropriate position
        while (tempNode != nullptr)
        {
          // if we have reached the last node, we will do the following.
          if (tempNode->next == nullptr)
          {
            // if the last node's value is smaller than the inserted value
            // we will add the new node after the last node and swap the values
            if (tempNode->value < node->value)
            {
              tempNode->next = node;
              int tempValue = node->value;
              node->value = tempNode->value;
              tempNode->value = tempValue;
              isAdditionSuccessful = true;
              break;
            }
            // if the last node's value is larger than the inserted value
            // we will add the new node after the previous last node.
            else if (tempNode->value > node->value)
            {
              tempNode->next = node;
              isAdditionSuccessful = true;
              break;
            }
            // if they are of same value, insertion will be discarded.
            else
            {
              cout << "This value already exists in the list. So not adding it" << endl;
              break;
            }
          }
          // if the current node is not the last node
          // if the node satisfies the above condition, we will insert the new node before this node
          else if (tempNode->value < node->value)
          {
            // we will add the newly node right after the encountered node
            // then we will swap the values between two nodes
            node->next = tempNode->next;
            tempNode->next = node;
            int tempValue = node->value;
            node->value = tempNode->value;
            tempNode->value = tempValue;
            isAdditionSuccessful = true;
            break;
          }
          // if we see that the value already exists, we will terminate the operation right away.
          else if (tempNode->value == value)
          {
            cout << "This value already exists in the list. So not adding it" << endl;
            break;
          }
          // other than that, point to the next node and continue traversing
          else
          {
            tempNode = tempNode->next;
          }
        }
      }
    }
    // the list is empty. So the new node will be the head
    else
    {
      this->head = node;
      isAdditionSuccessful = true;
    }
    return isAdditionSuccessful;
  }

  // method to remove a node using its value
  void removeNode(int value)
  {
    bool found = false;
    if (this->head == nullptr)
    {
      cout << "This LinkedList is empty." << endl;
    }
    else
    {
      // check if we are to remove the head from the list
      if (this->head->value == value)
      {
        this->head = this->head->next;
        cout << "Node with value : " << value << " has been removed." << endl;
      }
      // if it's the node other than head
      else
      {
        // here, we are checking the value of the next node, starting our traversal from head node.
        // if the value of the next node is not equal to the searched node, we traverse next.
        // if the next node is null, we stop our traversal
        // or else, we point the current node to the next of its current next node.
        Node *temp = this->head;
        while (1)
        {
          if (temp->next == nullptr)
          {
            break;
          }
          else
          {
            if (temp->next->value == value)
            {
              Node *newNext = temp->next->next;
              found = true;
              temp->next = newNext;
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
  void printValuesRecursively(Node *node)
  {
    // if the passed node is null, return from the method
    if (node == nullptr)
    {
      cout << endl;
      return;
    }
    else
    {
      // if the node is not null and is the head, print its value and call the next node
      if (node == this->head)
      {
        cout << node->value;
      }
      else
      {
        cout << "->" << node->value;
      }
      printValuesRecursively(node->next);
    }
  }

  // method to reverse the list recursively
  void recursiveReverse(Node *currentNode, Node *prevNode)
  {
    // the logic is to call the method with two nodes, one node and its previous
    // in each call, we will make its previous as its next node
    // that's how we are inverting the direction and the list will be reversed
    // check if the current node is not null
    if (currentNode != nullptr)
    {
      // if yes, recursively call the method with its next node and itself
      recursiveReverse(currentNode->next, currentNode);
      // make its previous node as its next node
      currentNode->next = prevNode;
    }
    else
    {
      // if the current node is null, the previous node will be the head
      this->head = prevNode;
      return;
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
};
