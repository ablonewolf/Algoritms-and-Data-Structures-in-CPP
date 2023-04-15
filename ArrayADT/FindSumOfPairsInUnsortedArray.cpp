#include <iostream>
using namespace std;

void printPair(int *array, int size, int expectedSum, int maxElement)
{
  int count = 0;
  int countArray[maxElement + 1] = {0};
  for (int i = 0; i < size; i++)
  {
    countArray[array[i]]++;
  }
  for (int i = 0; i < size; i++)
  {
    if (array[i] <= expectedSum)
    {
      int k = expectedSum - array[i];
      if (countArray[k] == 1 && array[i] != k)
      {
        count++;
        cout << "Pair found. One element is: " << array[i] << ", another element is: " << k << endl;
        countArray[k]++;
        countArray[array[i]]++;
      }
    }
    else
    {
      continue;
    }
  }
  if (count > 0)
  {
    if (count == 1)
    {
      cout << count << " pair found whose sum is equal to " << expectedSum << "." << endl;
    }
    else
    {
      cout << count << " pairs found whose sum is equal to " << expectedSum << "." << endl;
    }
  }
  else
  {
    cout << "No pair of sums found to be equal to " << expectedSum << "." << endl;
  }
}

int main()
{
  cout << "Enter the size of the array." << endl;
  int size, maxElement = -9999;
  cout << "Size: ";
  cin >> size;
  int *array = new int[size];
  cout << "Enter the elements of the array." << endl;
  for (int i = 0; i < size; i++)
  {
    cout << "Array[" << i + 1 << "]: ";
    cin >> array[i];
    if (array[i] > maxElement)
    {
      maxElement = array[i];
    }
  }
  cout << "Enter the sum." << endl;
  int sum;
  cout << "Sum: ";
  cin >> sum;
  printPair(array, size, sum, maxElement);
  delete array;
}