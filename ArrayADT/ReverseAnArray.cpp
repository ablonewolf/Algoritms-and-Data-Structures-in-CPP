#include <iostream>
using namespace std;

void ReverseArray(int *&array, int size)
{
  int temp = size;
  static int index = 0;
  if (index > size / 2)
  {
    return;
  }
  else
  {
    swap(array[index], array[temp]);
    index++;
    ReverseArray(array, temp - 1);
  }
}

void swap(int &num1, int &num2)
{
  int temp = num1;
  num1 = num2;
  num2 = temp;
}
int main()
{
  cout << "Enter the size of the array" << endl;
  int size;
  cout << "Size: ";
  cin >> size;
  int *array = new int[size];
  cout << "Enter the elements of the array." << endl;
  for (int i = 0; i < size; i++)
  {
    cout << "array[" << i + 1 << "]: ";
    cin >> array[i];
  }
  cout << "Reversing the array." << endl;
  ReverseArray(array, size - 1);
  cout << "After reversing, the elements are as below" << endl;
  for (int i = 0; i < size; i++)
  {
    cout << "array[" << i + 1 << "]: " << array[i] << endl;
  }
  delete array;
}