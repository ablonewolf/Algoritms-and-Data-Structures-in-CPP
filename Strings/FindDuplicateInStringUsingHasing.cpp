#include <bits/stdc++.h>

using namespace std;

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

void findDuplicates(string word) {
    string modifiedWord = makeLowerCase(word);
    int index = 0;
    int countArray[26] = {0};
    while (modifiedWord[index] != '\0') {
        countArray[modifiedWord[index] - 97]++;
        index++;
    }
    int numberOfDuplicates = 0;
    for (index = 0; index < 26; index++) {
        if (countArray[index] > 1) {
            numberOfDuplicates++;
        }
    }
    if (numberOfDuplicates > 0) {
        cout << "The word has " << numberOfDuplicates << " duplicate characters. They are the following: ";
        for (index = 0; index < 26; index++) {
            if (numberOfDuplicates > 0) {
                if (countArray[index] > 1) {
                    if (numberOfDuplicates != 1) {
                        cout << char(index + 97) << ", ";
                    } else {
                        cout << char(index + 97) << ".";
                    }
                    numberOfDuplicates--;
                }
            }
        }
        cout << endl;
    } else {
        cout << "The word has no duplicate characters" << endl;
    }
}

int main() {
    cout << "Enter the word to check whether it has duplicates or not." << endl;
    cout << "The Word: ";
    string word;
    cin >> word;
    findDuplicates(word);
}
