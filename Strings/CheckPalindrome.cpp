#include <bits/stdc++.h>
using namespace std;

int findLength(string str)
{
  int length = 0;
  while (str[length] != '\0')
  {
    length++;
  }
  return length;
}

bool checkPalindrome(string word)
{
  bool isPalindrome = true;
  int lastIndex = findLength(word) - 1;
  int initialIndex = 0;
  while (initialIndex < lastIndex)
  {
    if (word[initialIndex] == word[lastIndex])
    {
      initialIndex++;
      lastIndex--;
    }
    else
    {
      isPalindrome = false;
      break;
    }
  }
  return isPalindrome;
}

int main()
{
  cout << "Enter the word to check whether it's palindrome or not. Please enter all characters in lower case. " << endl;
  cout << "The Word: ";
  string word;
  cin >> word;
  if (checkPalindrome(word))
  {
    cout << "The given word is a palindrome word." << endl;
  }
  else
  {
    cout << "The given word is not a palindrome word." << endl;
  }
}