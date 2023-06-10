#include <iostream>
using namespace std;

void swap(int &firstNumber, int &secondNumber)
{
  int temp = firstNumber;
  firstNumber = secondNumber;
  secondNumber = temp;
}

void BubbleSort(int *array, int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = i + 1; j < size; j++)
    {
      if (array[i] > array[j])
      {
        swap(array[i], array[j]);
      }
    }
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
  BubbleSort(array, size);
  cout << "After sorting, the elements are as below." << endl;
  printArray(array, size);
  delete array;
}