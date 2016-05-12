#include <iostream>
#include <vector>
#include <set>

using namespace std;

int nth_triangular(int n) {
  return n*(n+1)/2;
}

long smallestFactor(long n) {
  long i = 2;
  while (true) {
    if (n % i == 0) {
      return i;
    }
    i++;
  }
}

set<long> factors(long n) {
  set<long> factors;
  while (true) {
    long sm = smallestFactor(n);
    factors.insert(sm);
    if (sm == n) {
      return factors;
    } else {
      n /= sm;
    }
  }
}

int main() {
  int num_factors = 0;
  int i = 2;
  long curr;
  while ( num_factors <= 500 ) {
    curr = nth_triangular(i);
    set<long> factor_set = factors(curr);
    num_factors = factor_set.size();
    cout << curr << ": " << num_factors << endl;
    i++;
  }
  cout << "Solution: " << curr << endl;
  return 0;
}
