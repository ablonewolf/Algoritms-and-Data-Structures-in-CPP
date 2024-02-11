#include <bits/stdc++.h>
using namespace std;


int countTotalWays(int n, int k) {
  vector<int> stepArray(n + 1, 0);
  // initialize values for base case
  stepArray[0] = 1;
  stepArray[1] = 1;

  for (int i = 2; i <= n; i++) {
    // if the current step is greater than K, we will consider the previous K steps and sum them up
    if (i >= k) {
      stepArray[i] = 2 * stepArray[i - 1] - stepArray[i - k - 1];
    }
    // if not, then we will just increment by 1 from the previous step
    else {
      stepArray[i] = stepArray[i - 1] + 1;
    }
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

