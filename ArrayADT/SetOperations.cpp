#include <iostream>

using namespace std;

// passed a reference to the output array, returned the size of the union array
int findUnionArray(int* array1, int* array2, int*& unionArray) {
    int i = 0, j = 0, count = 0;
    while (array1[i] && array2[j]) {
        if (array1[i] == array2[j]) {
            count++;
            i++;
            j++;
        } else if (array1[i] < array2[j]) {
            count++;
            i++;
        } else {
            count++;
            j++;
        }
    }
    unionArray = new int[count];
    i = 0, j = 0;
    int k = 0;
    while (k < count) {
        if (array1[i] == array2[j]) {
            unionArray[k++] = array1[i++];
            j++;
        } else if (array1[i] < array2[j]) {
            unionArray[k++] = array1[i++];
        } else {
            unionArray[k++] = array2[j++];
        }
    }
    if (k == count) {
        return count;
    }
}

// passed a reference to the output array, returned the size of the intersection array
int findIntersectionArray(int* array1, int* array2, int*& intersectionArray) {
    int i = 0, j = 0, count = 0;
    while (array1[i] && array2[j]) {
        if (array1[i] == array2[j]) {
            count++;
            i++;
            j++;
        } else if (array1[i] < array2[j]) {
            i++;
        } else {
            j++;
        }
    }
    i = 0, j = 0;
    intersectionArray = new int[count];
    int k = 0;
    while (k < count) {
        if (array1[i] == array2[j]) {
            intersectionArray[k++] = array1[i++];
            j++;
        } else if (array1[i] < array2[j]) {
            i++;
        } else {
            j++;
        }
    }
    if (k == count) {
        return count;
    }
}

int findDiffsArray(int* array1, int* array2, int*& diffsArray) {
    int i = 0, j = 0, count = 0;
    while (array1[i]) {
        if (array1[i] == array2[j]) {
            i++;
            j++;
        } else if (array1[i] < array2[j]) {
            count++;
            i++;
        } else {
            j++;
        }
    }
    i = 0;
    j = 0;
    diffsArray = new int[count];
    int k = 0;
    while (k < count) {
        if (array1[i] == array2[j]) {
            i++;
            j++;
        } else if (array1[i] < array2[j]) {
            diffsArray[k++] = array1[i++];
        } else {
            j++;
        }
    }
    if (k == count) {
        return count;
    }
}

bool isArraySorted(int* array, int length) {
    int i = 0, sorted = 0;
    while (i < length - 1) {
        if (array[i] < array[i + 1] && array[i] > 0) {
            i++;
        } else {
            sorted = 1;
            break;
        }
    }
    if (sorted == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cout << "Enter the size of two arrays." << endl;
    int size1, size2;
    cout << "Size of the first array: ";
    cin >> size1;
    cout << "Size of the second array: ";
    cin >> size2;
    int array1[size1], array2[size2];
    cout << "Enter the elements of first array in sorted ascending order." << endl;
    for (int i = 0; i < size1; i++) {
        cout << "Array1[" << i + 1 << "]: ";
        cin >> array1[i];
    }
    cout << "Enter the elements of second array in sorted ascending order." << endl;
    for (int i = 0; i < size2; i++) {
        cout << "Array2[" << i + 1 << "]: ";
        cin >> array2[i];
    }
    if (isArraySorted(array1, size1) && isArraySorted(array2, size2)) {
        while (1) {
            cout << "Here are the available set operations. Please select your desired operation." << endl;
            cout << "Press 1 to find union of the two arrays." << endl;
            cout << "Press 2 to find intersection of the two arrays." << endl;
            cout << "Press 3 to find the difference between the two arrays." << endl;
            cout << "Press 4 to end the program." << endl;
            int option;
            cin >> option;
            if (option == 4) {
                cout << "Exiting the program. Thanks for using it." << endl;
                break;
            } else if (option == 1) {
                int* unionArray;
                int sizeOfUnionArray = findUnionArray(array1, array2, unionArray);
                int i = 0;
                cout << "After the union of the two arrays, the result is below." << endl;
                while (i < sizeOfUnionArray) {
                    if (i == 0) {
                        cout << unionArray[i];
                        i++;
                    } else {
                        cout << " " << unionArray[i];
                        i++;
                    }
                }
                delete unionArray;
                cout << endl;
            } else if (option == 2) {
                int* intersectionArray;
                int sizeOfIntersectionArray = findIntersectionArray(array1, array2, intersectionArray);
                int i = 0;
                cout << "After the intersection of the two arrays, the result is below." << endl;
                while (i < sizeOfIntersectionArray) {
                    if (i == 0) {
                        cout << intersectionArray[i];
                        i++;
                    } else {
                        cout << " " << intersectionArray[i];
                        i++;
                    }
                }
                delete intersectionArray;
                cout << endl;
            } else if (option == 3) {
                cout
                    << "Enter 1 to find difference from 1st Array to 2nd Array or Enter 2 to find difference from 2nd Array to 1st Array."
                    << endl;
                int option;
                cin >> option;
                if (option == 1) {
                    int* diffArray;
                    int sizeOfDiffsArray = findDiffsArray(array1, array2, diffArray);
                    int i = 0;
                    cout << "The difference between the first array and the second array is below." << endl;
                    while (i < sizeOfDiffsArray) {
                        if (i == 0) {
                            cout << diffArray[i];
                            i++;
                        } else {
                            cout << " " << diffArray[i];
                            i++;
                        }
                    }
                    delete diffArray;
                    cout << endl;
                } else if (option == 2) {
                    int* diffArray;
                    int sizeOfDiffArray = findDiffsArray(array2, array1, diffArray);
                    int i = 0;
                    cout << "The difference between the second array and the first array is below." << endl;
                    while (i < sizeOfDiffArray) {
                        if (i == 0) {
                            cout << diffArray[i++];
                        } else {
                            cout << " " << diffArray[i++];
                        }
                    }
                    delete diffArray;
                    cout << endl;
                } else {
                    cout << "Invalid option. Please try again." << endl;
                }
            } else {
                cout << "Invalid option. Please try again." << endl;
            }
        }
    } else {
        cout << "One or both of the arrays are not sorted. Aborting the program." << endl;
    }
}