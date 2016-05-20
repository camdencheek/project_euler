#include <iostream>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <boost/timer.hpp>
#include <thread>

using namespace std;

struct Primes {
protected:
  vector<int> prime_list;

  void append_next() {
    int biggest = *(prime_list.end() - 1) + 2;
    while (!is_prime(biggest)) {
      biggest += 2;
    }
    prime_list.push_back(biggest);
  }

  void factors_recursive(int &sum, unordered_map<int,int> &prime_factors,
                         unordered_map<int,int>::iterator it, int curr) {
    if (it == prime_factors.end()) {
      sum += curr;
      return;
    } else {
      for(int i = 0; i <= it->second; i++) {
        auto it2 = it;
        factors_recursive(sum,prime_factors,++it2,curr*pow(it->first,i));
      }
    }
  }

public:

  Primes() {
    prime_list.push_back(2);
    prime_list.push_back(3);
  }

  bool is_prime(int n) {
    int i = 0;
    while (prime_list[i]*prime_list[i] <= n) {
      if (n % prime_list[i] == 0)
        return false;
      i++;
    }
    return true;
  }

  int get_nth(int n) {
    while (prime_list.size() < n) {
      append_next();
    }
    return prime_list[n - 1];
  }

  int smallest_prime_factor(int n) {
    int i = 1;
    while (true) {
      int curr = get_nth(i);
      if (n % get_nth(i) == 0)
        return curr;
      i++;
    }
  }

  unordered_map<int,int> prime_factors(int n) {
    unordered_map<int,int> factor_list;
    while (n != 1) {
      int factor = smallest_prime_factor(n);
      factor_list.emplace(factor,0);
      factor_list[factor]++;

      n /= factor;
    }
    return factor_list;
  }

  int sum_proper_divisors(int n) {
    auto p_factors = prime_factors(n);
    int sum = 0;
    auto it = p_factors.begin();
    int curr = 1;
    factors_recursive(sum,p_factors,it,curr);
    sum -= n;
    return sum;
  }
};

int is_amicable(int n, Primes &p) {
  int fac_sum1 = p.sum_proper_divisors(n);
  if ( fac_sum1 <= n ) {
    return 0;
  }


  int fac_sum2 = p.sum_proper_divisors(fac_sum1);
  if (fac_sum2 == n) {
    return n + fac_sum1;
  }
  return 0;
}

int main() {

  boost::timer t;
  Primes p;

  long sum = 0;
  for (int i = 2; i < 100000;i++ ) {
    sum += is_amicable(i,p);
  }
  cout << sum << endl;
  cout << t.elapsed() << endl;

}
