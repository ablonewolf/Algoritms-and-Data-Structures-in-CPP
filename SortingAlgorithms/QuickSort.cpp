#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}
int partition(int *arr, int low, int high)
{
  int pivot = arr[low];
  int i = low, j = high;
  while (i < j)
  {
    while (arr[i] <= pivot)
    {
      i++;
    }
    while (arr[j] > pivot)
    {
      j--;
    }
    if (i < j)
    {
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[low], &arr[j]);
  return j;
}
void QuickSort(int *arr, int low, int high)
{
  if (low < high)
  {
    int partitionIndex = partition(arr, low, high);
    QuickSort(arr, low, partitionIndex);
    QuickSort(arr, partitionIndex + 1, high);
  }
}

void printArray(int *arr, int n)
{
  cout << "The elements in the array are as below." << endl;
  for (int i = 0; i < n; i++)
  {
    cout << "Array[" << i << "]: " << arr[i] << endl;
  }
}

int main()
{
  cout << "Enter the size of the array." << endl;
  int n;
  cout << "Size: ";
  cin >> n;
  cout << "Enter the elements of the array." << endl;
  int *arr = new int[n];
  for (int i = 0; i < n; i++)
  {
    cout << "Array[" << i << "]: ";
    cin >> arr[i];
  }
  QuickSort(arr, 0, n - 1);
  printArray(arr, n);
}