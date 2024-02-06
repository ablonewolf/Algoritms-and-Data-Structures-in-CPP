#include <iostream>
using namespace std;


int findCombination(int n, int r) {
  if (n == 1 || n == r) {
    return 1;
  }
  if (r == 1) {
    return n;
  }
  return findCombination(n - 1, r - 1) + findCombination(n - 1, r);
}

int findTotalNumberofPossibleTrees(int nodeNumber) {
  if (nodeNumber == 0 || nodeNumber == 1) {
    return 1;
  }
  int denominator = findCombination(2 * nodeNumber, nodeNumber);
  return denominator / (nodeNumber + 1);
}

int main() {
  cout << "Enter the number of nodes: ";
  int nodeNumbers;
  cin >> nodeNumbers;
  cout << "Total number of possible binary trees with this number of nodes is: " << findTotalNumberofPossibleTrees(nodeNumbers) << "." << endl;
}