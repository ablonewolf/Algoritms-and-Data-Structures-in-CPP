#include <iostream>

using namespace std;

string changeCase(string str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 97 && str[i] <= 122) {
            str[i] = str[i] - 32;
        } else if (str[i] >= 65 && str[i] <= 90) {
            str[i] = str[i] + 32;
        } else {
            continue;
        }
    }
    return str;
}

int main() {
    string str;
    cout << "Please enter the string : ";
    getline(cin, str);
    cout << "After changing the case, the string is: " << changeCase(str) << endl;
}