#include <iostream>
#include "SinglyLinkedList.h"

using namespace std;

int main() {
    SinglyLinkedList* linkedList = new SinglyLinkedList();
    cout << "Enter the size of the linked list." << endl;
    int size;
    cout << "Size : ";
    cin >> size;
    cout << "Enter the values inside the linkedlist." << endl;
    int iteration = 0;
    while (iteration < size) {
        int value;
        cout << "Enter value: ";
        cin >> value;
        if (linkedList->insertNode(value)) {
            iteration++;
        }
    }
    cout << "Size of the linkgedlist is : " << linkedList->getSize() << endl;
    cout << "Its values are : ";
    linkedList->printValuesRecursively(linkedList->head);
    int option;
    cout
        << "Enter 1 to add more elements, 2 to remove elements, 3 to print the current list, 4 to reverse the list and 5 to exit the application"
        << endl;
    while (1) {
        cout << "Enter option: ";
        cin >> option;
        if (option == 1) {
            int value;
            cout << "Enter the value to add: ";
            cin >> value;
            if (linkedList->insertNode(value)) {
                cout << "Value added successfully." << endl;
            }
        } else if (option == 2) {
            int value;
            cout << "Enter the value to remove: ";
            cin >> value;
            linkedList->removeNode(value);
        } else if (option == 3) {
            cout << "The values present in the linked list are as follows:" << endl;
            linkedList->printValuesRecursively(linkedList->head);
        } else if (option == 4) {
            linkedList->recursiveReverse(linkedList->head, nullptr);
            cout << "After reversing, the list is as follows: " << endl;
            linkedList->printValuesRecursively(linkedList->head);
        } else if (option == 5) {
            cout << "Exiting the application. Thank you for using" << endl;
            break;
        } else {
            cout << "Invalid option. Please try again" << endl;
        }
    }
    delete linkedList;
}