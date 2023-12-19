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

bool checkAnagram(string word1, string word2)
{
  if (calculateLength(word1) == calculateLength(word2))
  {
    int countArray[26] = {0};
    int initialIndex = 0;
    bool isAnagram = true;
    while (word1[initialIndex] != '\0')
    {
      if (word1[initialIndex] >= 65 && word1[initialIndex] <= 90)
      {
        countArray[word1[initialIndex] - 65]++;
      }
      else
      {
        countArray[word1[initialIndex] - 97]++;
      }
      initialIndex++;
    }
    initialIndex = 0;
    while (word2[initialIndex] != '\0')
    {
      if (word2[initialIndex] >= 65 && word2[initialIndex] <= 90)
      {
        countArray[word2[initialIndex] - 65]++;
      }
      else
      {
        countArray[word2[initialIndex] - 97]++;
      }
      initialIndex++;
    }
    for (int index = 0; index < 26; index++)
    {
      if (countArray[index] > 0)
      {
        if (countArray[index] % 2 == 1)
        {
          isAnagram = false;
          break;
        }
      }
    }
    return isAnagram;
  }
  else
  {
    cout << "These two words are not of equal length." << endl;
    return false;
  }
}

int main()
{
  cout << "Enter two words to check whether they are anagram to each other or not." << endl;
  string firstWord, secondWord;
  cout << "Enter the first word: ";
  cin >> firstWord;
  cout << endl;
  cout << "Enter the second word: ";
  cin >> secondWord;
  cout << endl;
  if (checkAnagram(firstWord, secondWord))
  {
    cout << "These two words are anagram to each other." << endl;
  }
  else
  {
    cout << "These two words are not anagram to each other." << endl;
  }
}