#include <bits/stdc++.h>
#include "LinkedList.h"

using namespace std;

int findHashValue(int key) {
    return key % 10;
}

void insert(LinkedList linkedList[], int key) {
    int index = findHashValue(key);
    linkedList[index].insertNode(key);
}

bool search(LinkedList linkedList[], int key) {
    int index = findHashValue(key);
    return linkedList[index].findNode(key);
}

void remove(LinkedList linkedList[10], int key) {
    int index = findHashValue(key);
    if (search(linkedList, key)) {
        linkedList[index].removeNode(key);
        cout << "Item was deleted successfully." << endl;
    } else {
        cout << "Item not found, so not removed." << endl;
    }
}

void printItems(LinkedList linkedList[10]) {
    for (int index = 0; index < 10; index++) {
        linkedList[index].printValues();
    }
}

int main() {
    LinkedList *hashTable = new LinkedList[10];
    cout << "Enter 1 to add elements in the hash table." << endl;
    cout << "Enter 2 to remove elements from the hash table." << endl;
    cout << "Enter 3 to find elements in the hash table." << endl;
    cout << "Enter 4 to print all stored elements in the hash table" << endl;
    cout << "Enter 5 to exit the program." << endl;
    while (1) {
        int option;
        cout << "Enter option: ";
        cin >> option;
        if (option == 1) {
            cout << "Enter value: ";
            int value;
            cin >> value;
            insert(hashTable, value);
        } else if (option == 2) {
            cout << "Enter value: ";
            int value;
            cin >> value;
            remove(hashTable, value);
        } else if (option == 3) {
            cout << "Enter value: ";
            int value;
            cin >> value;
            if (search(hashTable, value)) {
                cout << value << " is found in the hashtable." << endl;
            } else {
                cout << value << " is not present in the hash table." << endl;
            }
        } else if (option == 4) {
            cout << "The items in the hash table are as follows." << endl;
            printItems(hashTable);
        } else if (option == 5) {
            cout << "Thank you for using this program. Bye bye." << endl;
            break;
        } else {
            cout << "Invalid option. Please try again." << endl;
        }
    }
    delete[] hashTable;
}