#include <iostream>
using namespace std;

float expectedSum(int firstElement, int lastElement)
{
  cout << "First element: " << firstElement << endl;
  cout << "Last element: " << lastElement << endl;
  int numberOfElements = lastElement - firstElement + 1;
  float sum = (numberOfElements / 2.0) * (firstElement + lastElement);
  return sum;
}

float actualSum(int *array, int size)
{
  float sum = 0;
  for (int i = 0; i < size; i++)
  {
    sum += array[i];
  }
  return sum;
}

bool isSequentaillySorted(int *array, int size)
{
  bool sequentiallySorted = true;
  for (int i = 0; i < size - 1; i++)
  {
    if (array[i] < array[i + 1])
    {
      continue;
    }
    else
    {
      sequentiallySorted = false;
      break;
    }
  }
  return sequentiallySorted;
}

int main()
{
  cout << "Enter the size of the array." << endl;
  int size;
  cout << "Size: ";
  cin >> size;
  cout << "Enter the elements of the array in ascending order." << endl;
  int *array = new int[size];
  for (int i = 0; i < size; i++)
  {
    cout << "Array[" << i + 1 << "]: ";
    cin >> array[i];
  }
  if (isSequentaillySorted(array, size))
  {
    int missingElement = expectedSum(array[0], array[size - 1]) - actualSum(array, size);
    if (missingElement == 0)
    {
      cout << "No element is missing from this array." << endl;
    }
    else
    {
      cout << "The element missing in this array is: " << missingElement << "." << endl;
    }
  }
  else
  {
    cout << "The array is not sequentially sorted." << endl;
  }
  delete array;
}