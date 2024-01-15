#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack* stack = new Stack();
    while (1) {
        cout << "Enter 1 to push new values to the stack" << endl;
        cout << "Enter 2 to print the top of the stack." << endl;
        cout << "Enter 3 to perform the pop operation." << endl;
        cout << "Enter 4 to print all values stored inside the stack." << endl;
        cout << "Enter 5 to exit the application." << endl;
        int option;
        cout << "Enter option: ";
        cin >> option;
        if (option == 1) {
            cout << "Enter the value to push into the stack: ";
            int value;
            cin >> value;
            stack->push(value);
        } else if (option == 2) {
            cout << "The current top of the stack is " << stack->top() << "." << endl;
        } else if (option == 3) {
            cout << "The popped item from the stack is " << stack->pop() << "." << endl;
            cout << "After popping, the current top of the stack is " << stack->top() << "." << endl;
        } else if (option == 4) {
            stack->printStack();
        } else if (option == 5) {
            cout << "Thank you for using this application." << endl;
            break;
        } else {
            cout << "Invalid option. Please try again." << endl;
        }
    }
    delete stack;
}