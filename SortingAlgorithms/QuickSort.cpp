#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
  int temp = x;
  x = y;
  y = temp;
}
int partition(int *array, int low, int high)
{
  int pivot = array[low];
  int i = low, j = high;
  while (i < j)
  {
    while (array[i] <= pivot)
    {
      i++;
    }
    while (array[j] > pivot)
    {
      j--;
    }
    if (i < j)
    {
      swap(array[i], array[j]);
    }
  }
  swap(array[low], array[j]);
  return j;
}
void QuickSort(int *array, int low, int high)
{
  if (low < high)
  {
    int partitionIndex = partition(array, low, high);
    QuickSort(array, low, partitionIndex);
    QuickSort(array, partitionIndex + 1, high);
  }
}

void printArray(int *array, int n)
{
  for (int i = 0; i < n; i++)
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
  int n;
  cout << "Size: ";
  cin >> n;
  cout << "Enter the elements of the array." << endl;
  int *array = new int[n];
  for (int i = 0; i < n; i++)
  {
    cout << "array[" << i << "]: ";
    cin >> array[i];
  }
  QuickSort(array, 0, n - 1);
  cout << "After sorting, the elements are as below." << endl;
  printArray(array, n);
}