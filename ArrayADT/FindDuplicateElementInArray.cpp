#include <iostream>
using namespace std;

int printDuplicateElements(int *array, int size)
{
  int j, count = 0;
  for (int i = 0; i < size; i++)
  {
    if (array[i] == array[i + 1])
    {
      count++;
      j = i + 1;
      while (array[i] == array[j])
      {
        j++;
      }
      cout << array[i] << " is appearing " << j - i << " times." << endl;
      i = j - 1;
    }
    else
    {
      continue;
    }
  }
  return count;
}

int main()
{
  cout << "Enter the size of the array." << endl;
  cout << "Size: ";
  int size;
  cin >> size;
  int *array = new int[size];
  cout << "Enter the elements of the array." << endl;
  for (int i = 0; i < size; i++)
  {
    cout << "Array[" << i + 1 << "]: ";
    cin >> array[i];
  }
  int count = printDuplicateElements(array, size);
  if (count == 0)
  {
    cout << "No duplicates found in this array" << endl;
  }
  else
  {
    cout << "Number of duplicates in this array is: " << count << "." << endl;
  }
}