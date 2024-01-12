#include <bits/stdc++.h>

using namespace std;

void insertElement(int value, int hashTable[], int collisionIndex = 0) {
    int hashedValue = (value + collisionIndex * collisionIndex) % 10;
    if (hashTable[hashedValue] == 0) {
        hashTable[hashedValue] = value;
        cout << value << " is added successfully" << endl;
    } else {
        insertElement(value, hashTable, ++collisionIndex);
    }
}

bool findElement(int value, int hashTable[]) {
    bool found = false;
    int hashedValue = (value) % 10;
    while (1) {
        if (hashTable[hashedValue] == value) {
            found = true;
            break;
        } else {
            if (hashTable[hashedValue] != 0) {
                hashedValue = (hashedValue + 1) % 10;
            } else {
                break;
            }
        }
    }
    return found;
}

int main() {
    int hashtable[10] = {0};
    int totalElements = 0;
    cout << "Welcome." << endl;
    while (1) {
        int option;
        cout << "Enter 1 to insert new elements in the hash table." << endl;
        cout << "Enter 2 to find element in the hash table." << endl;
        cout << "Enter 3 to print all inserted elements in the hashtable." << endl;
        cout << "Enter 4 to exit the program." << endl;
        cout << "Option: ";
        cin >> option;
        if (option == 1) {
            if (totalElements < 5) {
                int value;
                cout << "Enter the value: ";
                cin >> value;
                insertElement(value, hashtable);
                ++totalElements;
            } else {
                cout << "Cannot add more elements. Loading factor cannot exceed 0.5 when quadratic probing is applied."
                     << endl;
            }
        } else if (option == 2) {
            int value;
            cout << "Enter the value: ";
            cin >> value;
            if (findElement(value, hashtable)) {
                cout << "Element has been found." << endl;
            } else {
                cout << "Element is absent." << endl;
            }
        } else if (option == 3) {
            bool isFirstPrinted = false;
            for (int index = 0; index < 10; index++) {
                if (hashtable[index] != 0) {
                    if (isFirstPrinted) {
                        cout << " " << hashtable[index];
                    } else {
                        cout << hashtable[index];
                        isFirstPrinted = true;
                    }
                }
            }
            cout << endl;
        } else if (option == 4) {
            cout << "Thank you for using the application. Have a nice day." << endl;
            break;
        } else {
            cout << "Invalid option. Please try again." << endl;
        }
    }
}