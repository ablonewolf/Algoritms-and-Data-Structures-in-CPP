#include <bits/stdc++.h>
using namespace std;

int calculateLength(string word)
{
  int length = 0;
  while (word[length] != '\0')
  {
    length++;
  }
  return length;
}

void printPermutation(string word, int initialIndex, int length)
{
  if (initialIndex == length - 1)
  {
    cout << word << endl;
  }

  for (int tempIndex = initialIndex; tempIndex < length; tempIndex++)
  {
    swap(word[initialIndex], word[tempIndex]);
    printPermutation(word, initialIndex + 1, length);
    swap(word[initialIndex], word[tempIndex]);
  }
}

int main()
{
  cout << "Enter the word to print its permutation strings: ";
  string word;
  cin >> word;
  cout << endl;
  int length = calculateLength(word);
  cout << "Its permutation strings are as below:" << endl;
  printPermutation(word, 0, length);
}