#include <iostream>

using namespace std;

int findSize(int *array) {
    return sizeof(array) / sizeof(array[0]);
}

void merge(int *array, int low, int mid, int high) {
    int size = findSize(array);
    int i = low, j = mid + 1, k = low;
    int sortedArray[size];
    while (i <= mid && j <= high) {
        if (array[i] < array[j])
            sortedArray[k++] = array[i++];
        else
            sortedArray[k++] = array[j++];
    }
    while (i <= mid) {
        sortedArray[k++] = array[i++];
    }
    while (j <= high) {
        sortedArray[k++] = array[j++];
    }

    for (i = low; i <= high; i++)
        array[i] = sortedArray[i];
}

void mergeSort(int *array, int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergeSort(array, low, mid);
        mergeSort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}

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
    mergeSort(array, 0, size - 1);
    cout << "After sorting, the elements are as below." << endl;
    printArray(array, size);
    delete[] array;
}