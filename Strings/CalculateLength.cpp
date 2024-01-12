#include <iostream>

using namespace std;

int findLength(string str) {
    int length = 0;
    for (int i = 0; str[i]; i++) {
        length++;
    }
    return length;
}

int main() {
    string str;
    cout << "Please enter the string : ";
    getline(cin, str);
    cout << "The length of the string is : " << findLength(str) << endl;
}