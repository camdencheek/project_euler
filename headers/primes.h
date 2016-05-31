#include <vector>
#include <assert.h>
#include <cmath>
#include <limits>
#include <map>

#ifndef PRIMES_HEADER
#define PRIMES_HEADER

struct Primes {

  std::vector<bool *> ptrs;
  unsigned long max;

  Primes() {
    bool* block = new bool[1000000];
    ptrs.push_back(block);
    std::fill(block,block+1000000,true);

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
    std::fill(block,block+1000000,true);

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

  unsigned long get_nth(unsigned long n) {
    assert(n > 0);
    long long i = -1;
    while (n > 0) {
      i++;
      if (i > max) {
	append_next_block();
      }
      if (is_prime(i)) {
        n--;
      }

    }
    return  i;
  }

  std::map<long,int> prime_factors(unsigned long n) {
    assert(n > 0);
    std::map<long,int> res;
    int i = 1;
    while (n != 1) {
      unsigned long tmp = get_nth(i);
      if (n % tmp == 0) {
        if (!res.count(tmp)) {
          res[tmp] = 1;
        } else {
          res[tmp]++;
        }
        n /= tmp;
      }
      i++;
    }
    return res;
  };
};

#endif
