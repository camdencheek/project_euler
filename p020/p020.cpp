#include <iostream>
#include <boost/multiprecision/gmp.hpp>

using namespace std;

typedef boost::multiprecision::mpz_int bigint;

bigint sum_digits(bigint n) {
  bigint sum = 0;
  while (n) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

bigint factorial(int n) {
  bigint prod = 1;
  for (; n > 1; n-- ) {
    prod *= n;
  }
  return prod;
}

int main() {
  cout << sum_digits(factorial(10));
  return 0;
}