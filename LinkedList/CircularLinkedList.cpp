#include <bits/stdc++.h>
#include "CircularLinkedList.h"

using namespace std;

int main() {
    CircularLinkedList *linkedList = new CircularLinkedList();
    cout << "Enter the size for circular linked list: ";
    int size;
    cin >> size;
    int iteration = 0;
    while (iteration < size) {
        int value;
        cout << "Enter value: ";
        cin >> value;
        if (linkedList->insertNode(value)) {
            cout << value << " is added successfully." << endl;
            iteration++;
        } else {
            cout << value << " could not be added." << endl;
        }
    }
    while (1) {
        cout << "Enter 1 to insert value in the list." << endl;
        cout << "Enter 2 to remove value in the list." << endl;
        cout << "Enter 3 to find value in the list." << endl;
        cout << "Enter 4 to print all values in the list." << endl;
        cout << "Enter 5 to reverse the current list." << endl;
        cout << "Enter 6 to exit the application." << endl;
        int option;
        cout << "Enter option: ";
        cin >> option;
        if (option == 1) {
            int value;
            cout << "Enter value to be inserted: ";
            cin >> value;
            bool insertionSuccess = linkedList->insertNode(value);
            if (insertionSuccess) {
                cout << value << " is added successfully." << endl;
            } else {
                cout << value << " could not be added." << endl;
            }
        } else if (option == 2) {
            int value;
            cout << "Enter value to be removed: ";
            cin >> value;
            bool removeSuccess = linkedList->removeNode(value);
            if (removeSuccess) {
                cout << value << " is removed successfully." << endl;
            } else {
                cout << value << " could not be removed." << endl;
            }
        } else if (option == 3) {
            int value;
            cout << "Enter value to be searched: ";
            cin >> value;
            bool searchSuccess = linkedList->findNode(value);
            if (searchSuccess) {
                cout << value << " exists in the list." << endl;
            } else {
                cout << value << " does not exist in the list." << endl;
            }
        } else if (option == 4) {
            linkedList->printListRecursively(linkedList->head);
        } else if (option == 5) {
            Node *tempNode = linkedList->head;
            while (tempNode->next != linkedList->head) {
                tempNode = tempNode->next;
            }
            linkedList->recursiveReverse(linkedList->head, tempNode);
            cout << "After reversing, the list is as follows: " << endl;
            linkedList->printListRecursively(linkedList->head);
        } else if (option == 6) {
            cout << "Thank you for using the application." << endl;
            break;
        } else {
            cout << "Invalid option. Please try again." << endl;
        }
    }
}