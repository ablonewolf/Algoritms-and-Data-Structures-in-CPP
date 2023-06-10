#include <iostream>
using namespace std;

void swap(int &number1, int &number2)
{
  int temp = number1;
  number1 = number2;
  number2 = temp;
}

void SelectionSort(int *array, int size)
{
  for (int i = 0; i < size; i++)
  {
    int k = i;
    for (int j = i + 1; j < size; j++)
    {
      if (array[k] > array[j])
      {
        k = j;
      }
    }
    swap(array[i], array[k]);
  }
}

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

int main()
{
  cout << "Enter the size of the array." << endl;
  int size;
  cout << "Size: ";
  cin >> size;
  int *array = new int[size];
  cout << "Enter the elements of the array." << endl;
  for (int i = 0; i < size; i++)
  {
    cout << "Array[" << i << "]: ";
    cin >> array[i];
  }
  SelectionSort(array, size);
  cout << "After sorting, the elements are as below." << endl;
  printArray(array, size);
  delete array;
}