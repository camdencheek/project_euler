#include <iostream>

using namespace std;

long smallestFactor(long n) {
    int i = 2;
    while (true) {
        if (n % i == 0) {
            return i;
        }

        i++;
    }
}

int main() {

    long n = 600851475143;

    while (true) {
        long sm = smallestFactor(n);
        if (sm == n) {
            cout << "Largest prime factor: " << sm;
            return 0;
        } else {
            n /= smallestFactor(n);
        }
    }
}