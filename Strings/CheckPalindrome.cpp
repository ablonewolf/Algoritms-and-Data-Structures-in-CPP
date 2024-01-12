#include <bits/stdc++.h>

using namespace std;

int findLength(string str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

string makeLowerCase(string word) {
    int index = 0;
    while (word[index] != '\0') {
        if (word[index] >= 65 && word[index] <= 90) {
            word[index] = word[index] + 32;
        }
        index++;
    }
    return word;
}

bool checkPalindrome(string word) {
    string convertedLowerCaseWord = makeLowerCase(word);
    bool isPalindrome = true;
    int lastIndex = findLength(convertedLowerCaseWord) - 1;
    int initialIndex = 0;
    while (initialIndex < lastIndex) {
        if (convertedLowerCaseWord[initialIndex] == convertedLowerCaseWord[lastIndex]) {
            initialIndex++;
            lastIndex--;
        } else {
            isPalindrome = false;
            break;
        }
    }
    return isPalindrome;
}

int main() {
    cout << "Enter the word to check whether it's palindrome or not. Please enter all characters in lower case."
         << endl;
    cout << "The Word: ";
    string word;
    cin >> word;
    if (checkPalindrome(word)) {
        cout << "The given word is a palindrome word." << endl;
    } else {
        cout << "The given word is not a palindrome word." << endl;
    }
}