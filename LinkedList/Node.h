#include <bits/stdc++.h>
#define default_value -9999999
using namespace std;
class Node
{
public:
  int value;
  Node *next = nullptr;
  Node(int value)
  {
    this->value = value;
    this->next = nullptr;
  }
  Node()
  {
    this->value = default_value;
    this->next = nullptr;
  }
};