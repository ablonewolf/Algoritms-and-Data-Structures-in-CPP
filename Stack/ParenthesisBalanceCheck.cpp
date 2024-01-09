#include <iostream>
#include "CharacterStack.h"
using namespace std;

int main()
{
  string equation;
  cout << "Enter the equation to check whether its parenthesis are balanced: ";
  // we are using the get line function so that we can take an entire line as input
  getline(cin, equation);

  Stack *parenthesisStack = new Stack();
  for (int i = 0; i < equation.length(); i++)
  {
    if (equation[i] == '(' ||
        equation[i] == '{' ||
        equation[i] == '[')
    {
      // we will only store the opening brackets
      parenthesisStack->push(equation[i]);
    }
    // if we encounter a closing bracket
    else if (equation[i] == ')' || equation[i] == '}' || equation[i] == ']')
    {
      // storing the current top of the stack here
      char top = parenthesisStack->top();
      // if the closing bracket is the matched for the top, then we will pop that top.
      if ((equation[i] == ')' && top == '(') ||
          (equation[i] == '}' && top == '{') ||
          (equation[i] == ']' && top == '['))
        parenthesisStack->pop();
    }
    // ignore the other characters
    else
    {
      continue;
    }
  }
  // the stack should be emtpy if the brackets in the equation are balanced
  if (parenthesisStack->isEmpty())
  {
    cout << "The equation is balanced." << endl;
  }
  else
  {
    cout << "The equation is not balanced." << endl;
  }
}