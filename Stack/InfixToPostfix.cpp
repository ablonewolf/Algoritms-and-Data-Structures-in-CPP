#include <bits/stdc++.h>
#include "CharacterStack.h"

using namespace std;

int getPrecedence(char operation) {
    if (operation == '+' || operation == '-') {
        return 1;
    } else if (operation == '*' || operation == '/') {
        return 2;
    }
    return 0;
}

int main() {
    string equation;
    cout << "Enter an infix equation to convert it to a postfix equation: ";
    // we are using the get line function so that we can take an entire line as input
    cin >> equation;
    // a character array to store the newly formed postfix equation
    char *postfixEquation = new char[equation.length()];
    // in this stack, we will be pushing the operators
    Stack operationStack;
    int index = 0;
    int postFixIndex = 0;
    while (equation[index] != '\0') {
        char tempChar = equation[index];
        // store the current character instantly in the equation if it's an operand
        if (getPrecedence(tempChar) == 0) {
            postfixEquation[postFixIndex++] = tempChar;
        // if it's an operand, we will do the following
        // given that the stack is empty, we will push the stack immediately
        // else, if the top of the stack has lower precedence comparing to the current operator, we will pop it
        // then, we will push the encountered operand
        } else {
            if (operationStack.isEmpty()) {
                operationStack.push(tempChar);
            } else {
                char currentTop = operationStack.top();
                if (getPrecedence(tempChar) >= getPrecedence(currentTop)) {
                    operationStack.pop();
                    postfixEquation[postFixIndex++] = currentTop;
                    operationStack.push(tempChar);
                } else {
                    operationStack.push(tempChar);
                }
            }
        }
        index = index + 1;
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