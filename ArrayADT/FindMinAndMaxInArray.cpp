#include <iostream>
using namespace std;

void printMinAndMaxElement(int *array, int size)
{
  int min = array[0], max = array[0];
  for (int i = 0; i < size; i++)
  {
    if (array[i] < min)
    {
      min = array[i];
    }
    if (array[i] > max)
    {
      max = array[i];
    }
  }
  cout << "The minimum element in this array is: " << min << endl;
  cout << "The maximum element in this array is: " << max << endl;
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
  printMinAndMaxElement(array, size);
  delete array;
}