#include <bits/stdc++.h>
#include "findMaxPrime.h"

using namespace std;

int firstHashFunction(int number, int range) {
    return (number % range);
}

int secondHashFunction(int number, int maxPrime) {
    return (maxPrime - (number % maxPrime));
}

void placeItemAtIndex(int number, int firstHashedValue, int secondHashedValue, int collisionIndex, int hashTable[],
                      int size) {
    if (collisionIndex < size) {
        int index = (firstHashedValue + collisionIndex * secondHashedValue) % size;
        if (hashTable[index] == 0) {
            hashTable[index] = number;
            cout << number << " has been added at index no: " << index << " successfully." << endl;
        } else {
            placeItemAtIndex(number, firstHashedValue, secondHashedValue, ++collisionIndex, hashTable, size);
        }
    } else {
        cout << "Cannot insert this element. Hashtable is seemingly full." << endl;
    }
}

void insertElement(int number, int hashTable[], int maxPrime, int size) {
    int firstHashedValue = firstHashFunction(number, size);
    int secondHashedValue = secondHashFunction(number, maxPrime);
    placeItemAtIndex(number, firstHashedValue, secondHashedValue, 0, hashTable, size);
}

bool searchItem(int number, int hashTable[], int maxPrime, int size) {
    bool isFound = false;
    int firstHashedValue = firstHashFunction(number, size);
    int secondHashedValue = secondHashFunction(number, maxPrime);
    int collisionIndex = 0;
    while (collisionIndex < size) {
        int index = (firstHashedValue + collisionIndex * secondHashedValue) % size;
        if (hashTable[index] == 0) {
            break;
        } else if (hashTable[index] == number) {
            isFound = true;
            break;
        } else {
            collisionIndex++;
        }
    }
    return isFound;
}

int main() {
    int size;
    cout << "Enter the size for hashtable: ";
    cin >> size;
    int maxPrime = findMaxPrime(size);
    int hashtable[size] = { 0 };
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
            if (totalElements < size / 2) {
                int value;
                cout << "Enter the value: ";
                cin >> value;
                insertElement(value, hashtable, maxPrime, size);
                ++totalElements;
            } else {
                cout << "Cannot add more elements. Loading factor cannot exceed 0.5 when linear probing is applied."
                    << endl;
            }
        } else if (option == 2) {
            int value;
            cout << "Enter the value: ";
            cin >> value;
            if (searchItem(value, hashtable, maxPrime, size)) {
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