#include <iostream>
#include <boost/timer.hpp>
#include <vector>
#include <cmath>

using namespace std;

struct Primes {

  vector<bool *> ptrs;
  unsigned long max;

  Primes() {
    bool* block = new bool[1000000];
    ptrs.push_back(block);
    fill(block,block+1000000,true);

    for (int i = 2; i <= 1000; i++) {
      if (!block[i]) {
        continue;
      }
      int j = 2;
      while (i*j < 1000000) {
        block[i*j] = false;
        j++;
      }
    }
    block[0] = false;
    block[1] = false;

    max = 999999;
  }

  bool is_prime(long long n) {
    if (n < 2) {
      return false;
    }
    while (n > max) {
      append_next_block();
    }
    auto blk_ptr = ptrs[n/1000000];
    return blk_ptr[n%1000000];
  }

  void append_next_block() {

    unsigned long sqrt_max = (unsigned long) std::sqrt(max + 1000000) + 1;
    bool* block = new bool[1000000];
    ptrs.push_back(block);
    fill(block,block+1000000,true);

    for (unsigned long i = 2; i <= sqrt_max; i++) {
      if (!is_prime(i)) {
        continue;
      }
      unsigned long j = 1+((max-1)/i);
      unsigned long jmax = (max+1000000)/i;
      for (; j <= jmax; j++) {
        block[i*j%1000000] = false;
      }
    }

    max += 1000000;

  }
};



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

  cout << max_a*max_b << endl;

  return 0;
}