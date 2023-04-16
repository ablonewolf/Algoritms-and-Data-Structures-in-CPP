#include <iostream>
using namespace std;

bool isValidChar(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
    {
        return true;
    }
    return false;
}

bool isValidString(string str)
{
    bool isValid = true;
    for (int i = 0; str[i]; i++)
    {
        if (!isValidChar(str[i]))
        {
            isValid = false;
            break;
        }
    }
    return isValid;
}

int main()
{
    cout << "Enter the string to check whether it is valid." << endl;
    cout << "The String: ";
    string str;
    cin >> str;
    if (isValidString(str))
    {
        cout << "The string: " << str << ", is a valid string." << endl;
    }
    else
    {
        cout<< "The String: " << str << ", is not a valid string." << endl;
    }
}