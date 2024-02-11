#include <bits/stdc++.h>
using namespace std;


int countTotalWays(int n, int k) {
  vector<int> stepArray(n + 1, 0);
  // initialize values for base case
  stepArray[0] = 1;
  stepArray[1] = 1;

  // for step number 2 upto k, it will be the double of the ways to reach the previous
  for (int i = 2; i <= k; i++) {
    stepArray[i] = 2 * stepArray[i - 1];
  }

  // here, we are using the recurrence relationship to count ways for steps higher than max step k
  for (int i = k + 1; i <= n; i++) {
    stepArray[i] = 2 * stepArray[i - 1] - stepArray[i - k - 1];
  }

  return stepArray[n];
}



int main() {
  cout << "Enter the total number of steps: ";
  int steps;
  cin >> steps;
  cout << "Enter the length of at most max step: ";
  int max;
  cin >> max;
  int answer = countTotalWays(steps, max);
  cout << "The total number of ways to reach that step is " << answer << "." << endl;
}

