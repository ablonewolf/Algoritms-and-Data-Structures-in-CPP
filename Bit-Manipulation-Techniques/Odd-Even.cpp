#include <iostream>
using namespace std;

bool isOdd(int number) {
    return (number & 1);
}

int main() {
    cout << "Enter the number: ";
    int number;
    cin >> number;

    if (isOdd(number)) {
        cout << number << " is odd." << endl;
    } else {
        cout << number << " is even." << endl;
    }
}