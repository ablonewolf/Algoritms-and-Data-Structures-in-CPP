#include <iostream>
#include "CharacterStack.h"
using namespace std;

bool isValidEquation(string equation)
{
  int index = equation.find('(');
  if (index >= 0)
  {
    return true;
  }
  return false;
}

int main()
{
  string equation;
  cout << "Enter the equation to check whether its parenthesis are balanced: ";
  getline(cin, equation);

  if (isValidEquation(equation))
  {
    Stack *parenthesisStack = new Stack();
    for (int i = 0; i < equation.length(); i++)
    {
      if (equation[i] == '(')
      {
        parenthesisStack->push(equation[i]);
      }
      else if (equation[i] == ')')
      {
        parenthesisStack->pop();
      }
      else
      {
        continue;
      }
    }
    if (parenthesisStack->isEmpty())
    {
      cout << "The equation is balanced." << endl;
    }
    else
    {
      cout << "The equation is not balanced." << endl;
    }
  }
  else
  {
    cout << "It's an invalid eqaution." << endl;
  }
}