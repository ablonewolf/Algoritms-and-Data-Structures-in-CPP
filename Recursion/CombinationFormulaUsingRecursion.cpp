#include <iostream>

using namespace std;

int findNumberOfCombinations(int n, int r) {
    if (r == 0 || n == r) {
        return 1;
    }
    if (r == 1) {
        return n;
    }
    return findNumberOfCombinations(n - 1, r - 1) + findNumberOfCombinations(n - 1, r);
}

int main() {
    cout << "Enter the value of n and r to find the number of combinations." << endl;
    int n, r;
    cout << "n :";
    cin >> n;
    cout << "r :";
    cin >> r;
    cout << "The number of combinations for " << n << " and " << r << " is: " << findNumberOfCombinations(n, r) << endl;
}