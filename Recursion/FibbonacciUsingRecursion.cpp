#include <iostream>
using namespace std;

int Fibbonacci(int n)
{
  if (n <= 1)
    return n;
  return Fibbonacci(n - 1) + Fibbonacci(n - 2);
}

int main()
{
  cout << "Enter the value of n to find nth Fibbonacci number." << endl;
  cout << "n: ";
  int n;
  cin >> n;
  cout << "The nth Fibbonacci number is: " << Fibbonacci(n) << endl;
}