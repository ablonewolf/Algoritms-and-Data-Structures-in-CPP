#include <iostream>

using namespace std;

void leftShiftArray(int *&array, int size) {
    int index = 0;
    while (index < size) {
        array[index] = array[index + 1];
        index++;
    }
    array[index] = 0;
}

void rightShiftArray(int *&array, int size) {
    while (size > 0) {
        array[size] = array[size - 1];
        size--;
    }
    array[size] = 0;
}

void leftRotateArray(int *&array, int size) {
    int index = 0, temp;
    while (index < size) {
        if (index == 0) {
            temp = array[index];
            cout << temp << endl;
        }
        array[index] = array[index + 1];
        index++;
    }
    array[index] = temp;
}

void rightRotateArray(int *&array, int size) {
    int temp;
    int lastEntry = array[size];
    while (size > 0) {
        array[size] = array[size - 1];
        size--;
    }
    array[size] = lastEntry;
}

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        cout << "array[" << i + 1 << "]: " << array[i] << endl;
    }
}

int main() {
    cout << "Enter the size of the array" << endl;
    int size;
    cout << "Size: ";
    cin >> size;
    int *array = new int[size];
    cout << "Enter the elements of the array." << endl;
    for (int i = 0; i < size; i++) {
        cout << "array[" << i + 1 << "]: ";
        cin >> array[i];
    }
    cout << "Select your desired Operation" << endl;
    cout << "Option 1: Left Shift the array." << endl;
    cout << "Option 2: Right Shift the array." << endl;
    cout << "Option 3: Left Rotate the array." << endl;
    cout << "Option 4: Right Rotate the array." << endl;
    int option;
    cout << "Enter option, from 1 to 4." << endl;
    cout << "Option: ";
    cin >> option;
    if (option == 1) {
        cout << "Left Shifting the array." << endl;
        leftShiftArray(array, size - 1);
        cout << "After left shifting the array, the elements are as below." << endl;
        printArray(array, size);
    } else if (option == 2) {
        cout << "Right Shifting the array." << endl;
        rightShiftArray(array, size - 1);
        cout << "After right shifting the array, the elements are as below." << endl;
        printArray(array, size);
    } else if (option == 3) {
        cout << "Left Rotating the array." << endl;
        leftRotateArray(array, size - 1);
        cout << "After left rotating the array, the elements are as below." << endl;
        printArray(array, size);
    } else if (option == 4) {
        cout << "Right Rotating the array." << endl;
        rightRotateArray(array, size - 1);
        cout << "After right rotating the array, the elements are as below." << endl;
        printArray(array, size);
    } else {
        cout << "Invalid option. Quitting the program. Try again later" << endl;
    }
    delete[] array;
}