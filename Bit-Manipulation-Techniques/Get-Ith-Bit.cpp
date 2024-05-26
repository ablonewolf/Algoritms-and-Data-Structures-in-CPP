#include<iostream>
using namespace std;

int getIthBit(int number, int i) {
    int mask = (1 << i);

    return (number & mask) > 0 ? 1 : 0;
}

int main() {
    cout << "Enter the number: ";
    int number;
    cin >> number;

    cout << "Enter the bit position: ";
    int position;
    cin >> position;

    cout << "The Ith bit is " << getIthBit(number, position) << "." << endl;

}