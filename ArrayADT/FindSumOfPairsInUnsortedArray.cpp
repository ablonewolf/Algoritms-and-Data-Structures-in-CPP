#include <iostream>
using namespace std;

void printPair(int *array, int size, int expectedSum, int maxElement)
{
  int count = 0;
  int countArray[maxElement + 1] = {0};
  for (int i = 0; i < size; i++)
  {
    countArray[array[i]]++; // setting the count for each element in the array;
  }
  for (int i = 0; i < size; i++)
  {
    if (array[i] <= expectedSum && countArray[array[i]] > 0) // only process that element which is less than expectedSum and has not been processed yet
    {
      int k = expectedSum - array[i];
      if (k == array[i] && countArray[k] > 1) // if the subtraction equals to the element itself, it means we need two of it to equal to the sum, so looking for the duplicate
      {
        count++;
        cout << "Pair found. One element is: " << array[i] << ", another element is: " << k << endl;
        countArray[k] = -1; // setting it to negative value so that we don't have to process the next element again.
      }
      else if (countArray[k] > 0 && array[i] != k) // if the subtracted value exists in the array and it is not equal to the first found element
      {
        count++;
        cout << "Pair found. One element is: " << array[i] << ", another element is: " << k << endl;
        countArray[k] = -1;        // setting negative value as count so that we don't possess that value again
        countArray[array[i]] = -1; // setting negative value as count of element so that we don't have to process it again
      }
    }
    else
    {
      continue;
    }
  }
  if (count > 0)
  {
    if (count == 1) // checking if the count of pair is exactly one to print the message accurately
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
      maxElement = array[i]; // checking the maximum element in the array
    }
  }
  cout << "Enter the sum." << endl;
  int sum;
  cout << "Sum: ";
  cin >> sum;
  printPair(array, size, sum, maxElement);
  delete array;
}