#include <bits/stdc++.h>
using namespace std;

// function to calculate the max element
int calculateMaxElement(int *array, int size)
{
  int maxNumber = -999; // initializing a max number to be negative
  for (int index = 0; index < size; index++)
  {
    if (array[index] > maxNumber)
    {
      maxNumber = array[index];
    }
  }
  return maxNumber;
}

// function to print all missing elements
void printMissingElements(int *array, int size, int maxElement)
{
  int countArray[maxElement + 1] = {0}; // take an array of size equal to the max element in the input array and initialize it to zero.
  int countMissingElements = 0;         // initial count for missing elements
  // loop to set value in the count array
  for (int index = 0; index < size; index++)
  {
    countArray[array[index]]++;
  }

  // loop to count missing elements in the array
  for (int index = 1; index < maxElement + 1; index++)
  {
    if (countArray[index] == 0)
    {
      countMissingElements++;
    }
  }

  if (countMissingElements > 0)
  {
    cout << "The total number of missing element in the array is : " << countMissingElements << "." << endl;
    bool isFirstElement = true; // a Flag to handle the spacing
    cout << "The missing elements are: ";
    for (int index = 1; index < maxElement + 1; index++)
    {
      if (countMissingElements == 0)
      {
        break;
      }
      if (countArray[index] == 0)
      {
        if (isFirstElement)
        {
          cout << index; // if first missing element print it without any trailing space
          isFirstElement = false;
        }
        else
        {
          cout << " " << index; // print with trailing space given that it's not first element
        }
        countMissingElements--;
      }
    }
    cout << endl;
  }
  else
  {
    cout << "No missing element found" << endl;
  }
  return;
}

int main()
{
  cout << "Enter the size of the array." << endl;
  cout << "Size: ";
  int size;
  cin >> size;
  cout << "Enter the elements of the array." << endl;
  int *array = new int[size];
  for (int i = 0; i < size; i++)
  {
    cout << "Array[" << i + 1 << "]: ";
    cin >> array[i];
  }
  int maxElement = calculateMaxElement(array, size);
  cout << maxElement << endl;
  printMissingElements(array, size, maxElement);
  delete array;
}