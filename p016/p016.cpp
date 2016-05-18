#include <iostream>
#include <boost/multiprecision/gmp.hpp>

using namespace std;

typedef boost::multiprecision::mpz_int bigint;

bigint sum_digits(bigint n) {
  bigint sum = 0;
  while (n) {
    sum = sum +  n % 10;
    n /= 10;
  }
  return sum;
}

bigint pow(int n, int p) {
  bigint exp = 1;
  for (int i = 0; i < p; i++ ) {
    exp *= n;
  }
  return exp;
}

int main() {

  cout << sum_digits(pow(2,1000)) << endl;
  return 0;
}
