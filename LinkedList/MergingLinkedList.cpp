#include <bits/stdc++.h>
#include "SinglyLinkedList.h"
#include "Node.h"
using namespace std;

void mergeTwoLinkedLists(SinglyLinkedList *linkedList1, SinglyLinkedList *linkedList2)
{
  if (linkedList2->head == nullptr)
  {
    cout << "Second Linked List is empty. So there is no point in merging this list with another." << endl;
  }
  else
  {
    Node *temp = linkedList2->head;
    while (temp != nullptr)
    {
      linkedList1->insertNode(temp->value);
      temp = temp->next;
    }
    if (temp == nullptr)
    {
      cout << "After merging, the linked list is as follows: ";
      linkedList1->printValuesRecursively(linkedList1->head);
    }
  }
}

int main()
{
  SinglyLinkedList *linkedList1 = new SinglyLinkedList();
  SinglyLinkedList *linkedList2 = new SinglyLinkedList();
  cout << "Enter the size for first Linked list." << endl;
  int iteration = 0;
  int size;
  cout << "Enter size for first list: ";
  cin >> size;
  cout << "Enter values for the first linked list." << endl;
  while (iteration < size)
  {
    cout << "Enter value: ";
    int value;
    cin >> value;
    linkedList1->insertNode(value);
    iteration++;
  }
  iteration = 0;
  cout << "Enter the size for second linked list." << endl;
  cout << "Enter size for second list: ";
  cin >> size;
  cout << "Enter values for the first linked list." << endl;
  while (iteration < size)
  {
    cout << "Enter value: ";
    int value;
    cin >> value;
    linkedList2->insertNode(value);
    iteration++;
  }

  mergeTwoLinkedLists(linkedList1, linkedList2);
}
