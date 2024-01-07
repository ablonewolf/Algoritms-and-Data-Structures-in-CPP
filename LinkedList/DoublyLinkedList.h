#include <bits/stdc++.h>
using namespace std;

// defining the class for double-ended node
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

// class for double-ended linked list, by default it will have two nodes, head and tail
// initially both head and tail will be null
class DoublyLinkedList
{
public:
  Node *head;
  Node *tail;

  DoublyLinkedList()
  {
    this->head = this->tail = nullptr;
  }
  // method to check whether the list is sorted in ascending or descending order
  // if the list is empty or has only one element, we will assume it's sorted in ascending order
  // otherwise, we will compare the first value with the second value
  // if the former is less than the latter, we will assume the list is sorted in ascending order
  // otherwise the list is sorted in descending order
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

  // method to insert a new node in the list
  // if it returns true, node insertion is successful
  // if it returns false, node insertion is failed
  bool insertNode(int value)
  {
    // first we will check whether the list is sorted in ascending or descending order
    // our insertion will vary based on the sort order
    // if the head is null, we will simply set the new node to be head
    bool isInserted = false;
    bool isSortedAscending = this->isSortedAscending();
    Node *node = new Node(value);
    // the list is not empty since the head is not null
    if (this->head != nullptr)
    {
      // if head and tail are not the same, the list has more than one element
      // in this case, we will determine the new node's position and add the node there
      if (this->tail != this->head)
      {
        // if sorted in ascending order
        if (isSortedAscending)
        {
          // we will first determine the new node's position
          // we will keep traversing the list until we find a node whose value is greater than that of new node
          // if found, we will place the new node right before the found node
          // otherwise, we will place the new node at the end of the list
          Node *tempNode = this->head;
          // traversing throughout the list to find the appropriate position
          while (tempNode != nullptr)
          {
            // if the node satisfies the above condition, we will insert the new node before this node
            if (tempNode->value > node->value)
            {
              // if the found node is head, we will do the following
              // the new node will be the new head of the list
              // and the previous head will be the next node of the new node
              if (tempNode == this->head)
              {
                node->next = tempNode;
                this->head = node;
                tempNode->prev = node;
              }
              // if the found node is any node other than the head, we will do the following
              // we will find its previous node and set the new node to be its next node
              // new node's next will be the found node
              // found node's previous node will be the new node
              else
              {
                Node *prevNode = tempNode->prev;
                prevNode->next = node;
                node->prev = prevNode;
                node->next = tempNode;
                tempNode->prev = node;
              }
              // setting the flag to true to indicate that the insertion is successful
              isInserted = true;
              break;
            }
            // if we find that a node with same value already exists, we will discard the insertion
            else if (tempNode->value == node->value)
            {
              cout << "Value already exists." << endl;
              break;
            }
            else
            {
              // if we have reached the end of the list and value of the last node is not greater than that of the new node
              // the new node will be the new tail of the list
              // and we will set the flag to indicate that the insertion is successful
              if (tempNode == this->tail)
              {
                tempNode->next = node;
                node->prev = tempNode;
                this->tail = node;
                isInserted = true;
                break;
              }
              // otherwise, simply point to the next node and continue the traversal
              else
              {
                tempNode = tempNode->next;
              }
            }
          }
        }
        // if the list is sorted in descending order, we will do the following
        // the process is similar except that we will look for a node whose value is less than that of new node
        // if found, we will add the new node right before it
        // or else, we will place the new node at the end of the list
        else
        {
          Node *tempNode = this->head;
          // traversing through the list to find the node's appropriate position
          while (tempNode != nullptr)
          {
            // if the node satisfies the above condition, we will insert the new node before this node
            if (tempNode->value < node->value)
            {
              // if the found node is head, we will do the following
              // the new node will be the new head of the list
              // and the previous head will be the next node of the new node
              if (tempNode == this->head)
              {
                node->next = tempNode;
                this->head = node;
                tempNode->prev = node;
              }
              // if the found node is any node other than the head, we will do the following
              // we will find its previous node and set the new node to be its next node
              // new node's next will be the found node
              // found node's previous node will be the new node
              else
              {
                Node *prevNode = tempNode->prev;
                prevNode->next = node;
                node->prev = prevNode;
                node->next = tempNode;
                tempNode->prev = node;
              }
              // setting the flag to true to indicate that the insertion is successful
              isInserted = true;
              break;
            }
            // if we find that a node with same value already exists, we will discard the insertion
            else if (tempNode->value == node->value)
            {
              cout << "Value already exists." << endl;
              break;
            }
            else
            {
              // if we have reached the end of the list and value of the last node is not greater than that of the new node
              // the new node will be the new tail of the list
              // and we will set the flag to indicate that the insertion is successful
              if (tempNode == this->tail)
              {
                tempNode->next = node;
                node->prev = tempNode;
                this->tail = node;
                isInserted = true;
                break;
              }
              // otherwise, simply point to the next node and continue the traversal
              tempNode = tempNode->next;
            }
          }
        }
      }
      // if the list has only one element, we will insert the new node in ascending order
      else
      {
        // if the value of the head is greater than that of the new node, the latter will be the new head
        // so, its next will be the previous head of the list.
        // the previous head will be the new tail of the list
        if (this->head->value > node->value)
        {
          node->next = this->head;
          this->head->prev = node;
          this->head = node;
          this->tail = node->next;
          isInserted = true;
        }
        // if the value of the head is less that that of the new node, the head will be the same
        // the head's next will be the new node and the new node will be the new tail of the list
        else if (this->head->value < node->value)
        {
          this->head->next = node;
          node->prev = this->head;
          node->next = nullptr;
          this->tail = node;
          isInserted = true;
        }
        // if neither, the value of the head is equal to that of the new node, so insertion will be discarded
        else
        {
          cout << "Value already exists." << endl;
        }
      }
    }
    // the list has no head and tail, so the new node will be the new head and new tail of the list.
    else
    {
      this->head = node;
      this->tail = node;
      isInserted = true;
    }
    return isInserted;
  }

  // method to remove a node using its value
  bool removeNode(int value)
  {
    bool isRemoved = false;
    // if the head is already null, the list is empty. so no removal will occur.
    if (this->head == nullptr)
    {
      cout << "This List is empty" << endl;
    }
    // if the list has only one element, we will do the following
    // if the value equals to that of the only node, both head and tail will be null
    // and we will set the flag to indicate that removal is successful
    else if (this->head == this->tail)
    {
      if (this->head->value = value)
      {
        this->head = nullptr;
        this->tail = nullptr;
        isRemoved = true;
      }
    }
    // if the list has more than one element, we will do the following
    else
    {
      // if the node to be deleted is head, the new head will the next element of the previous head
      // the new head's previous node will be null.
      if (this->head->value == value)
      {
        this->head = this->head->next;
        this->head->prev = nullptr;
        isRemoved = true;
      }
      else
      // if the node to be deleted is any node other than the head, we will do the following
      // we will start traversing from the next node of the head.
      {
        Node *tempNode = this->head->next;
        // traverse until the end of the list is reached.
        while (tempNode != nullptr)
        {
          // check if the desired node is found
          if (tempNode->value == value)
          {
            // the previous node of the desired node
            Node *prevNode = tempNode->prev;
            // if the desired node is the tail, the previous node of the former will be the new tail
            // so we will make necessary arrangements for that
            if (tempNode == this->tail)
            {
              prevNode->next = nullptr;
              this->tail = prevNode;
            }
            // if the node to be deleted is other than the tail, we will do the following.
            // the next of the previous node will be the next node of the node to be deleted.
            // similarly, the previous of the latter will be the previous node of the would-be deleted node.
            else
            {
              Node *nextNode = tempNode->next;
              prevNode->next = nextNode;
              nextNode->prev = prevNode;
            }
            // and we will set the flag to indicate that removal is successful
            isRemoved = true;
            break;
          }
          // otherwise, traverse to the next node
          else
          {
            tempNode = tempNode->next;
          }
        }
      }
    }
    return isRemoved;
  }

  // method to find the desired node
  bool findNode(int value)
  {
    bool isFound = false;
    // if the head is null, the entire list will be empty
    // so, no point in searching
    if (this->head == nullptr)
    {
      cout << "Empty Linked List." << endl;
    }
    else
    {
      // start traversing from the head and look for the value in each node.
      // if found, modify the value of the flag and break the loop.
      Node *tempNode = this->head;
      while (tempNode != nullptr)
      {
        // if the desired node is found, set the value of the flag and break from the loop
        if (tempNode->value == value)
        {
          isFound = true;
          break;
        }
        // else continue to the next node
        else
        {
          tempNode = tempNode->next;
        }
      }
    }
    return isFound;
  }

  // method to print the nodes in the list recursively.
  void printList(Node *node)
  {
    // check if the passed node reference is the head of the list
    if (node == this->head)
    {
      // if the list has only one node, print the value of the node and return from the function
      if (this->head == this->tail)
      {
        cout << node->value << endl;
        return;
      }
      // else print the value and recursively call the next node
      else
      {
        cout << node->value << "->";
        printList(node->next);
      }
    }
    // if the passed node reference is other than the head and not null
    else if (node != nullptr)
    {
      // if this is the tail, then print its value and return from the function
      if (node == this->tail)
      {
        cout << node->value << endl;
        return;
      }
      // else print the value and recursively call the next node
      else
      {
        cout << node->value << "->";
        printList(node->next);
      }
    }
    // if passed node reference is null
    else
    {
      cout << "Invalid Node." << endl;
      return;
    }
  }

  // method for reversing all the nodes in the list
  void reverseList()
  {
    // the main logic to swap the links of the previous and next of the current node
    // the old previous node will be the new next node
    // the old next node will be the new previuos node
    // after doing that, move to the newly made previous node which was previously the next node
    // in this way, the current head will be the new tail and the current tail will be the new head
    Node *tempNode = this->head;
    Node *node;
    // traverse until the end of the list is reached
    while (tempNode != nullptr)
    {
      // store the next node of the current node
      node = tempNode->next;
      // point the next of the current node to its previous node
      tempNode->next = tempNode->prev;
      // make the previous next node as the new previous node of the current node
      tempNode->prev = node;
      // if the next of current node becomes null, it is the new tail
      if (tempNode->next == nullptr)
      {
        this->tail = tempNode;
      }
      // if the previous of current node becomes null, it is the new head
      // and terminate the loop
      if (tempNode->prev == nullptr)
      {
        this->head = tempNode;
        break;
      }
      // move to the new previous node of the current node
      tempNode = tempNode->prev;
    }
  }
};