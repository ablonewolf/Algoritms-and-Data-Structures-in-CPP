#include <iostream>

using namespace std;

int calculateFactorial(int number) {
    if (number == 0)
        return 1;
    return number * calculateFactorial(number - 1);
}

int main() {
    cout << "Enter the number to find its factorial." << endl;
    cout << "Number: ";
    int number;
    cin >> number;
    cout << "The factorial of " << number << " is : " << calculateFactorial(number) << endl;
}