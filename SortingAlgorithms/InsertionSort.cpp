#include <iostream>

using namespace std;

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            cout << array[i];
        } else {
            cout << " " << array[i];
        }
    }
    cout << endl;
}

void InsertionSort(int *array, int size) {
    for (int index = 1; index < size - 1; index++) {
        int key = array[index];
        int j = index - 1;
        while (j >= 0 && array[j] >= key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

int main() {
    cout << "Enter the size of the array." << endl;
    int size;
    cout << "Size: ";
    cin >> size;
    int *array = new int[size];
    cout << "Enter the elements of the array." << endl;
    for (int i = 0; i < size; i++) {
        cout << "Array[" << i << "]: ";
        cin >> array[i];
    }
    InsertionSort(array, size);
    cout << "After sorting, the elements are as below." << endl;
    printArray(array, size);
    delete[] array;
}