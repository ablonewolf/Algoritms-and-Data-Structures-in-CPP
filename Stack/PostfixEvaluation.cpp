#include <iostream>
#include <cmath>
#include "Stack.h"

using namespace std;

// function to check whether the encountered character is an operand or an operator
bool isOperand(char character) {
    if (character == '+' || character == '-' || character == '*' || character == '/') {
        return false;
    }
    return true;
}

int main() {
    string postFixEquation;
    cout << "Enter the postfix equation: ";
    cin >> postFixEquation;
    // a stack to hold all the operands
    Stack operandStack;

    int index = 0;
    while (postFixEquation[index] != '\0') {
        char currentCharacter = postFixEquation[index];
        // push the encountered character into the stack if it's an operand
        if (isOperand(currentCharacter)) {
            int integerValue = currentCharacter - '0';
            operandStack.push(integerValue);
        } else {
            // if it's an operator, pop the last two items from the stack and perform the operator on those two
            // then push the result
            int secondOperand = operandStack.pop();
            int firstOperand = operandStack.pop();
            int result;
            if (currentCharacter == '+') {
                result = firstOperand + secondOperand;
            }
            if (currentCharacter == '-') {
                result = firstOperand - secondOperand;
            }
            if (currentCharacter == '*') {
                result = firstOperand * secondOperand;
            }
            if (currentCharacter == '/') {
                result = firstOperand / secondOperand;
            }
            if (currentCharacter == '^') {
                result = pow(firstOperand, secondOperand);
            }
            operandStack.push(result);
        }
        ++index;
    }

    int result = operandStack.pop();
    cout << "The evaluated result of this postfix equation is: " << result << "." << endl;
}