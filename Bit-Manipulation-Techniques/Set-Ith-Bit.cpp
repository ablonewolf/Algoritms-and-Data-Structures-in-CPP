#include<iostream>
using namespace std;

void setIthBit(int& number, int i) {
    int mask = (1 << i);
    number = (number | mask);
}

int main() {
    int number, position;

    cout << "Enter the number: ";
    cin >> number;

    cout << "Enter the position where you want to set the bit(position starts from 0): ";
    cin >> position;

    setIthBit(number, position);
    cout << "After setting the bit at position " << position << ", the resultant number is " << number << "." << endl;
}