#include <iostream>
using namespace std;

int powerOfNumber(int number, int power)
{
  if (power == 0)
  {
    return 1;
  }
  return number * powerOfNumber(number, power - 1);
}

int main()
{
  cout << "Enter the number and its exponent to find the power of it." << endl;
  int number, power;
  cout << "Enter the number: ";
  cin >> number;
  cout << "And its exponent: ";
  cin >> power;
  cout << "The power of the number is: " << powerOfNumber(number, power) << endl;
}