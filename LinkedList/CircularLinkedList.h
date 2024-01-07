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
    // we are inserting nodes in ascending order
    // given that the head is null, we simply assign that value to be the value of the head.
    // otherwise, we will determine its order and assign likewise.
    // if there is already a value in the list equal to the value we are to insert, the latter will be discarded.
    // if not, we will make comparisons and will move forward to find its position for insertion.
    Node *node = new Node(value);
    bool isInserted = false;
    if (this->head != nullptr)
    {
      Node *temp = this->head;
      // if this is the only node in the list
      if (temp->next == this->head)
      {
        if (temp->value == value)
        {
          cout << "Value is already present in the list." << endl;
        }
        else
        {
          // if the current head is greater than the newly added node, head will point to the new node.
          // else new node will be the next node of the head
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
      // if there are more than one nodes in the list, we will adopt this approach.
      //
      else
      {
        // traverse until we encounter the last node
        while (temp->next != this->head)
        {
          // if the current encountered node has a value greater than the to be added value, we will be adding the value here.
          if (temp->value > node->value)
          {
            // if the current encountered node is head, we need to make some arrangements
            // first we will set the new node to be head
            // we will traverse to the last node and point its next to the new head
            // new head's next will point to the old head
            if (temp == this->head)
            {
              Node *tempNode = temp;
              while (tempNode->next != this->head)
              {
                tempNode = tempNode->next;
              }
              node->next = temp;
              this->head = node;
              tempNode->next = this->head;
            }
            // if the encountered node is other than head, we will do the following
            // we will add the newly node right after the encountered node
            // then we will swap the values between two nodes
            else
            {
              node->next = temp->next;
              temp->next = node;
              int tempValue = node->value;
              node->value = temp->value;
              temp->value = tempValue;
            }
            isInserted = true;
            break;
          }
          // if we see that the value already exists, we will terminate the operation right away.
          else if (temp->value == node->value)
          {
            cout << "Value is already present in the list." << endl;
            break;
          }
          else
          {
            temp = temp->next;
          }
        }
        // if we reach at the end of the list, we will do following

        if (temp->next == this->head && !isInserted)
        {
          // if the last node's value is greater than the newly node's value,
          // we will place the new node after the last node, point its next to head and then swap the values
          if (temp->value > node->value)
          {
            node->next = this->head;
            temp->next = node;
            int tempValue = node->value;
            node->value = temp->value;
            temp->value = tempValue;
            isInserted = true;
          }
          // if the last node's value equals to the newly node's value, we will avoid the insertion
          else if (temp->value == node->value)
          {
            cout << "Value is already present in the list." << endl;
          }
          // else the newly node will be the last node in the list and its next will point to head
          else
          {
            node->next = this->head;
            temp->next = node;
            isInserted = true;
          }
        }
      }
    }
    // if the list is empty, we just have to assign the head to the new node and its next will be itself.
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
    // check to see if the list is empty. If the head is null, the entire list will be empty.
    if (this->head == nullptr)
    {
      cout << "Empty List." << endl;
    }
    // check if we are to remove the head from the list
    else if (this->head->value == value)
    {
      // if this is the only element in the list, then setting this node to null is sufficient
      if (this->head->next == this->head)
      {
        this->head = nullptr;
      }
      // otherwise, traverse to the last node in the list. make it point to the second node of the list as well as make the second node as head.
      else
      {
        Node *tempNode = this->head;
        while (tempNode->next != this->head)
        {
          tempNode = tempNode->next;
        }
        tempNode->next = this->head->next;
        this->head = this->head->next;
      }
      isRemoved = true;
    }
    // if it's the node other than head
    else
    {
      // here, we are checking the value of the next node, starting our traversal from head node.
      // since the list is sorted, if the value of the next node is less than the searched node, we traverse next.
      // if it is greater, we stop our traversal.
      // or else, we point the current node to the next of its current next node.
      Node *temp = this->head;
      while (1)
      {
        // break if we traverse pass the list; that is, already encountered the last node
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
    // checking whether the list is empty by checking whether head is null or not
    if (this->head == nullptr)
    {
      cout << "Empty List." << endl;
    }
    // if this is the only element in the list
    else if (this->head->next == this->head)
    {
      if (this->head->value == value)
      {
        isFound = true;
      }
    }
    else
    {
      // traverse to the end of the list
      Node *temp = this->head;
      while (temp->next != this->head)
      {
        // if the value is found, set is found to true and break the loop
        if (temp->value == value)
        {
          isFound = true;
          break;
        }
        // if the encountered node is greater than the searched value, break the loop since the list is sorted in ascending order
        else if (temp->value > value)
        {
          break;
        }
        // otherwise, point to the next node
        else
        {
          temp = temp->next;
        }
      }
      // if we have reached the last node of the list
      if (temp->next == this->head && !isFound)
      {
        // if the last node's value equals to the searched value, set is found to true.
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
    // check if the current node is head
    if (node == this->head)
    {
      // checking to ensure whether the list is empty
      if (this->head == nullptr)
      {
        cout << "Empty List." << endl;
        return;
      }
      // checking to ensure whether the list has only one entry
      else if (this->head->next == this->head)
      {
        cout << this->head->value << endl;
        return;
      }
      // print the value of head and recursively call the next node
      else
      {
        cout << this->head->value;
        printListRecursively(this->head->next);
      }
    }
    else
    {
      // if the next node is head, finish printing the current node value and return from the function
      if (node->next == this->head)
      {
        cout << "->" << node->value << endl;
        return;
      }
      // else, print the current node and recursively call the next node of the current node
      else
      {
        cout << "->" << node->value;
        printListRecursively(node->next);
      }
    }
  }
};