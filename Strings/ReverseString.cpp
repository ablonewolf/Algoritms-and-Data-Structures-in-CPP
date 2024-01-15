#include <iostream>

using namespace std;

void swapCharacters(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

string reverseString(string str) {
    int j;
    for (int i = 0; str[i]; i++) {
        j++;
    }
    j--;
    int i = 0;
    while (i < j) {
        swapCharacters(str[i], str[j]);
        i++;
        j--;
    }
    return str;
}

int main() {
    cout << "Enter the string to reverse." << endl;
    cout << "The String: ";
    string str;
    cin >> str;
    cout << "After reversing, the string is: " << reverseString(str) << "." << endl;
}