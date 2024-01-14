#include <iostream>
#include "CharacterStack.h"

using namespace std;


// the approach is a bit different here.
// As we are considering brackets in the equation, so their precedence will matter too.
// that's why, whenever we encounter a opening bracket, we will immediately push that into the stack.
// And whenever we encounter a closing bracket, we will pop the latest operators until we find an opening bracket in the stack

int getOutStackPrecedence(char item) {
    if (item == '+' || item == '-') {
        return 1;
    } else if (item == '*' || item == '/') {
        return 3;
    } else if (item == '^') {
        return 6;
    } else if (item == '(') {
        return 7;
    }
    return 0;
}

int getInStackPrecedence(char item) {
    if (item == '+' || item == '-') {
        return 2;
    } else if (item == '*' || item == '/') {
        return 4;
    } else if (item == '^') {
        return 5;
    } else {
        return 0;
    }
}

int main() {
    string equation;
    cout << "Enter an infix equation to convert it to a postfix equation: ";
    cin >> equation;
    // a character array to store the newly formed postfix equation
    char *postfixEquation = new char[equation.length()];
    // in this stack, we will be pushing the operators
    Stack operationStack;
    int index = 0;
    int postFixIndex = 0;
    while (equation[index] != '\0') {
        char tempChar = equation[index];
        if (getOutStackPrecedence(tempChar) == 0 && tempChar != ')') {
            postfixEquation[postFixIndex++] = tempChar;
            index++;
        } else {
            if (operationStack.isEmpty()) {
                operationStack.push(tempChar);
                index++;
            } else {
                char currentTop = operationStack.top();
                if (getOutStackPrecedence(tempChar) <= getInStackPrecedence(currentTop)) {
                    char poppedItem = operationStack.pop();
                    if (poppedItem != '(') {
                        postfixEquation[postFixIndex++] = poppedItem;
                        if (tempChar == ')') {
                            if (!operationStack.isEmpty() && operationStack.top() == '(') {
                                operationStack.pop();
                            }
                        }
                    }
                } else {
                    operationStack.push(tempChar);
                }
                index = index + 1;
            }
        }
    }
    // despite completing traversing the equation, few operators might be in stack as they have higher precedence
    // so, we will be placing them at the end of the equation
    while (!operationStack.isEmpty()) {
        postfixEquation[postFixIndex++] = operationStack.pop();
    }
    postfixEquation[postFixIndex] = '\0';
    cout << "After conversion, the resulting postfix equation is: " << postfixEquation << "." << endl;
    delete[] postfixEquation;
}