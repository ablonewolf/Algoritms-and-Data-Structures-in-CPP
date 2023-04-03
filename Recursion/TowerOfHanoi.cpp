#include <iostream>
using namespace std;

void TowerOfHanoi(int n, char a, char b, char c)
{
  if (n > 0)
  {
    TowerOfHanoi(n - 1, a, c, b);
    cout << "Moving the " << n << "th disk from " << a << " to " << c << endl;
    TowerOfHanoi(n - 1, b, a, c);
  }
}

int main()
{
  cout << "Enter the number of disks to move in the Tower of Hanoi" << endl;
  int n;
  cout << "n: ";
  cin >> n;
  TowerOfHanoi(n, 'A', 'B', 'C');
}