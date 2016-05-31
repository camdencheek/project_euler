#include <iostream>
#include <boost/timer.hpp>
#include <primes.h>

using namespace std;

int main() {
  boost::timer t;

  Primes p;

  int max_len = 0;
  int max_a;
  int max_b;
  for (int a = -999; a < 1000; a++) {
    for (int b = -999; b < 1000; b++) {
      int n = 0;
      while (p.is_prime(n*n+a*n+b)) {
        n++;
      }
      if (max_len < n) {
        max_len = n;
        max_a = a;
        max_b = b;
      }
    }
  }

  cout << max_a * max_b << endl;
  cout << t.elapsed() << endl;

  return 0;
}
