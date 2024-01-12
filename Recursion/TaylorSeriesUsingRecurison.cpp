#include <iostream>

using namespace std;

float factorialValue(int number) {
    if (number == 0) {
        return 1.0;
    }
    return number * factorialValue(number - 1);
}

float getExponent(int number, int power) {
    if (power == 0) {
        return 1.0;
    }
    return number * getExponent(number, power - 1);
}

float getValue(int x, int power) {
    if (power == 0) {
        return 1.0;
    }
    return (getExponent(x, power) / factorialValue(power)) + getValue(x, power - 1);
}

int main() {
    cout << "Enter the number and power to find the exponent value of exponential function using Taylor Series" << endl;
    int number, power;
    cout << "Number: ";
    cin >> number;
    cout << "Power: ";
    cin >> power;
    cout << "The exponential value using Taylor Series is : " << getValue(number, power) << endl;
}