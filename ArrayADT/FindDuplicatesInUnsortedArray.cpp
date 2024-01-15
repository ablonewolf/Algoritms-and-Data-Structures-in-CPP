#include <iostream>

using namespace std;

void printDuplicatesInArray(int* array, int size, int maxElement) {
    int j, count = 0;
    int countArray[maxElement + 1] = { 0 }; // initializing a counter array equal to size of the max element in the array plus one.
    for (int i = 0; i < size; i++) {
        countArray[array[i]]++;
    }
    for (int i = 0; i < maxElement + 1; i++) {
        if (countArray[i] > 1) {
            count++;
            cout << i << " appeard, with the count of " << countArray[i] << " times." << endl;
        }
    }
    if (count > 0) {
        cout << "Total number of duplicates in this array is: " << count << endl;
    } else {
        cout << "No duplicates found in this array." << endl;
    }
}

int main() {
    cout << "Enter the size of the array" << endl;
    int size, maxElement = -9999;
    cout << "Size: ";
    cin >> size;
    int* array = new int[size];
    cout << "Enter the elements of the array in ascending order." << endl;
    for (int i = 0; i < size; i++) {
        cout << "Array[" << i + 1 << "]: ";
        cin >> array[i];
        if (array[i] > maxElement) {
            maxElement = array[i];
        }
    }
    printDuplicatesInArray(array, size, maxElement);
    delete[] array;
}