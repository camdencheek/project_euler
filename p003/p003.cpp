#include <iostream>

using namespace std;

/*
Returns the smallest factor of number n
*/
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
    //if the smallest factor of a number is itself, it is a prime number
    //Since all the smaller factors have already been divided out, this is the
    //largest prime factor of n
    if (sm == n) {
      cout << "Largest prime factor: " << sm << endl; 
      return 0;
    } else {
      n /= sm;
    }
  }
}
