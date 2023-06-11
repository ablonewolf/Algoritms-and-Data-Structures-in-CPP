#include <iostream>
using namespace std;

void printArray(int *array, int size)
{
  for (int i = 0; i < size; i++)
  {
    if (i == 0)
    {
      cout << array[i];
    }
    else
    {
      cout << " " << array[i];
    }
  }
  cout << endl;
}

void countSort(int *array, int max, int size)
{
  int countArray[max + 1] = {0};
  for (int i = 0; i < size; i++)
  {
    countArray[array[i]]++;
  }
  int i = 0, j = 0;
  while (i < max + 1)
  {
    if (countArray[i] > 0)
    {
      array[j++] = i;
      countArray[i]--;
    }
    else
    {
      i++;
    }
  }
  printArray(array, size);
}

int main()
{
  cout << "Enter the size of the array." << endl;
  int max = -9999;
  int size;
  cout << "Size: ";
  cin >> size;
  int *array = new int[size];
  cout << "Enter the elements of the array." << endl;
  for (int i = 0; i < size; i++)
  {
    cout << "Array[" << i << "]: ";
    cin >> array[i];
    if (array[i] > max)
    {
      max = array[i];
    }
  }
  cout << "After sorting, the elements are as below." << endl;
  countSort(array, max, size);
  delete array;
}