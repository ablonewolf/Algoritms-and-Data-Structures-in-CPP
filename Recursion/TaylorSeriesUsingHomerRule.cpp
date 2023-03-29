#include <iostream>
using namespace std;

float getExponentialValue(int number, int power)
{
  static float sum = 1.0;
  if (power == 0)
  {
    return sum;
  }
  sum = 1.0 + (number * sum) / power;
  return getExponentialValue(number, power - 1);
}

int main()
{
  cout << "Enter the number and power to find the exponent value of exponential function using Taylor Series" << endl;
  int number, power;
  cout << "Number: ";
  cin >> number;
  cout << "Power: ";
  cin >> power;
  cout << "The exponential value using Taylor Series is : " << getExponentialValue(number, power) << endl;
}