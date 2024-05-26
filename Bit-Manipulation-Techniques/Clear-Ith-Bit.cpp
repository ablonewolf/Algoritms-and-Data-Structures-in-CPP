#include<iostream>
using namespace std;

void clearIthBit(int& number, int i) {
    int mask = ~(1 << i);
    number = (number & mask);
}

int main() {
    int number, position;

    cout << "Enter the number: ";
    cin >> number;

    cout << "Enter the position where you want to clear the bit(position starts from 0): ";
    cin >> position;

    clearIthBit(number, position);
    cout << "After clearing, the resultant number is " << number << "." << endl;
}