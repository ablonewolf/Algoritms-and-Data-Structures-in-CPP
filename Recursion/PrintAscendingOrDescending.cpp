#include <iostream>
using namespace std;

void printAscending(int number)
{
  if (number > 0)
  {
    printAscending(number - 1);
    if (number - 1 == 0)
    {
      cout << number;
    }
    else
    {
      cout << " " << number;
    }
  }
}

void printDescending(int number)
{
  if (number > 0)
  {
    if (number - 1 == 0)
    {
      cout << number;
    }
    else
    {
      cout << number << " ";
    }
    printDescending(number - 1);
  }
}

int main()
{
  cout << "Enter the number to print from 1 to it. It should be greater than 0." << endl;
  cout << "Number: ";
  int number;
  cin >> number;
  if (number == 0)
  {
    cout << "Invalid Input. Ending the program." << endl;
  }
  else
  {
    cout << "Enter 1 to print in ascending order. Enter 2 to print in descending order." << endl;
    int option;
    cout << "Option: ";
    cin >> option;
    if (option == 1)
    {
      printAscending(number);
      cout << endl;
    }
    else if (option == 2)
    {
      printDescending(number);
      cout << endl;
    }
    else
    {
      cout << "Invalid option. Exiting the program right away." << endl;
    }
  }
}