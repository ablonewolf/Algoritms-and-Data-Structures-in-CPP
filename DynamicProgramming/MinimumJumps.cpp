#include <iostream>
#include <vector>
using namespace std;


void reachLastIndex(vector<int> array, int currentIndex, int& count) {
  // check if we have already reached the end
  if (currentIndex == array.size() - 1) {
    return;
    // check if make a jump using the current value takes us beyond the array.
    // if true, increment the count and return. 
  } else if (currentIndex + array[currentIndex] >= array.size()) {
    ++count;
    return;
  } else {
    // find the next max item available to jump into
    int maxItem = 0, nextIndex = currentIndex;
    for (int j = currentIndex + 1; j <= currentIndex + array[currentIndex]; j++) {
      if (array[j] > maxItem) {
        maxItem = array[j];
        nextIndex = j;
      }
    }
    ++count;
    reachLastIndex(array, nextIndex, count);
  }
}

int main() {
  cout << "Enter the size of the array: ";
  int size;
  cin >> size;
  vector<int>array(size);
  cout << "Enter the elements of the array." << endl;
  for (int i = 0; i < size; i++) {
    int item;
    cout << "Element no " << i + 1 << ": ";
    cin >> item;
    array[i] = item;
  }
  int count = 0;
  reachLastIndex(array, 0, count);

  cout << "The min number of steps to reach last index is: " << count << endl;
}