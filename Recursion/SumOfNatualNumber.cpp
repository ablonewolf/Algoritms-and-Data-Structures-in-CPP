#include <iostream>
using namespace std;

int sumOfNumbers(int number)
{
  if (number > 0)
  {
    return number + sumOfNumbers(number - 1);
  }
  return 0;
}

int main()
{
  cout << "Enter the number to find the sum of natural numbers." << endl;
  cout << "Number: ";
  int number;
  cin >> number;
  cout << "Sum of natural number for " << number << " is:  " << sumOfNumbers(number) << endl;
}