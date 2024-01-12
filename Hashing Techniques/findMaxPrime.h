#include <math.h>

using namespace std;

bool isPrime(int number) {
    bool isPrime = true;
    if (number == 0 || number == 1) {
        return false;
    } else {
        for (int index = 2; index <= sqrt(number); index++) {
            if (number % index == 0) {
                isPrime = false;
                break;
            }
        }
        return isPrime;
    }
}

int findMaxPrime(int size) {
    int maxPrime = 2;
    for (int item = 2; item <= size; item++) {
        if (isPrime(item)) {
            if (item >= maxPrime) {
                maxPrime = item;
            } else {
                continue;
            }
        }
    }
    return maxPrime;
}