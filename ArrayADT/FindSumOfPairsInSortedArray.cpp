#include <iostream>

using namespace std;

void printPairOfSum(int* array, int size, int expectedSum) {
    int i = 0, j = size - 1, count = 0;
    while (i < j) {
        if (array[i] + array[j] == expectedSum) {
            cout << "Pair found which equals to the given sum: " << expectedSum << ". One element is: " << array[i]
                << ", another element is: " << array[j] << "." << endl;
            i++;
            j--;
            count++;
        } else if (array[i] + array[j] > expectedSum) {
            j--;
        } else {
            i++;
        }
    }
    if (count > 0) {
        if (count == 1) {
            cout << count << " pair found whose sum is equal to " << expectedSum << "." << endl;
        } else {
            cout << count << " pairs found whose sum is equal to " << expectedSum << "." << endl;
        }
    } else {
        cout << "No pair of sums found to be equal to " << expectedSum << "." << endl;
    }
}

bool isSequentiallySorted(int* array, int size) {
    bool sequentiallySorted = true;
    for (int i = 0; i < size - 1; i++) {
        if (array[i] < array[i + 1] && array[i] > 0) {
            continue;
        } else {
            sequentiallySorted = false;
            break;
        }
    }
    return sequentiallySorted;
}

int main() {
    cout << "Enter the size of the array." << endl;
    cout << "Size: ";
    int size;
    cin >> size;
    int* array = new int[size];
    cout << "Enter the elements of the array in ascending order." << endl;
    for (int i = 0; i < size; i++) {
        cout << "Array[" << i + 1 << "]: ";
        cin >> array[i];
    }
    cout << "Enter the sum." << endl;
    int sum;
    cout << "Sum: ";
    cin >> sum;
    if (isSequentiallySorted(array, size)) {
        printPairOfSum(array, size, sum);
    } else {
        cout << "The array given is not sorted. So terminating the operation." << endl;
    }
    delete[] array;
}