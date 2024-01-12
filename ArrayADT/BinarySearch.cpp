#include <iostream>

using namespace std;

bool BinarySearch(int *arr, int end, int start, int num) {
    bool found = false;
    int mid;

    if (end == start) {
        if (arr[end] == num) {
            return true;
        } else {
            return false;
        }
    } else {
        if ((end + start) % 2 == 0) {
            mid = (end + start - 1) / 2;
        } else {
            mid = ((end + start - 1) / 2) + 1;
        }
        if (arr[mid] == num) {
            found = true;
            return found;
        } else if (arr[mid] < num) {
            return BinarySearch(arr, end, mid + 1, num);
        } else {
            return BinarySearch(arr, mid - 1, start, num);
        }
    }
}

int main() {
    cout << "Enter the array in an ascending order." << endl;
    cout << "Size: ";
    int size;
    cin >> size;
    int *arr = new int[size];
    cout << "Enter the values for the array." << endl;
    for (int i = 0; i < size; i++) {
        cout << "Value for index " << i + 1 << ": ";
        cin >> arr[i];
    }
    cout << "Enter the number to find." << endl;
    cout << "Number: ";
    int number;
    cin >> number;
    bool found = BinarySearch(arr, size - 1, 0, number);
    if (found) {
        cout << number << " exists in the array." << endl;
    } else {
        cout << number << " does not exist in the array." << endl;
    }
    delete arr;
}