#include <iostream>
#include <unordered_map>
#include <set>
#include <unordered_set>


using namespace std;

struct Primes {
protected:
  set<int> prime_list;

  unordered_map<int,unordered_map<int,int> > all_prime_factors;
  unordered_map<int,set<int> > all_proper_divisors;

  unordered_set<int> all_abundant;
  unordered_set<int> all_deficient;
  unordered_set<int> all_perfect;

  void append_next() {
    int biggest = *(prime_list.rbegin()) + 2;
    while (!is_prime(biggest)) {
      biggest += 2;
    }
    prime_list.insert(biggest);
  }

  void proper_divisors_recursive(set<int> &divisors, unordered_map<int,int> &prime_factors,
                                 unordered_map<int,int>::iterator it,int curr) {
    if (it == prime_factors.end()) {
      divisors.insert(curr);
      return;
    } else {
      for (int i = 0; i <= it->second; i++) {
        auto it2 = it;
        proper_divisors_recursive(divisors,prime_factors,++it2,int(curr*pow(it->first,i)));
      }
    }

  }

public:

  Primes() {
    prime_list.insert(2);
    prime_list.insert(3);
  }

  bool is_prime(int n) {
    if (n <= *(prime_list.rbegin())){
      if (prime_list.count(n)) {
        return true;
      }
      return false;
    } else {
      auto it = prime_list.begin();
      while ((*it)*(*it) <= n) {
        if (n%(*it) == 0) {
          return false;
        }
        it++;
      }
      return true;
    }
  }

  int get_nth(int n) {
    while (prime_list.size() < n) {
      append_next();
    }
    set<int>::iterator it = prime_list.begin();
    advance(it,n-1);
    return *it;
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
    if (all_prime_factors.count(n)) {
      return all_prime_factors.at(n);
    }

    unordered_map<int,int> factor_list;
    while (n != 1) {
      int factor = smallest_prime_factor(n);
      factor_list.emplace(factor,0);
      factor_list[factor]++;
      n /= factor;
    }

    return factor_list;
  }

  set<int> proper_divisors(int n) {
    if (all_proper_divisors.count(n)) {
      return all_proper_divisors.at(n);
    }
    auto p_factors = prime_factors(n);
    set<int> divisors;

    auto it = p_factors.begin();
    int curr = 1;

    proper_divisors_recursive(divisors,p_factors,it,curr);
    divisors.erase(n);

    return divisors;
  }

  int abundance(int n) {
    if (all_abundant.count(n)) {
      return 1;
    } else if (all_deficient.count(n)) {
      return -1;
    } else if (all_perfect.count(n)) {
      return 0;
    }

    int sum = 0;
    for (auto i: proper_divisors(n)) {
      sum += i;
    }
    if (sum == n) {
      all_perfect.insert(n);
      return 0;
    } else if (sum > n){
      all_abundant.insert(n);
      return 1;
    } else {
      all_deficient.insert(n);
      return -1;
    }
  }

  bool is_sum_of_abundant(int n) {
    for (int i = 1; i <= n/2; i++) {
      if (abundance(i) == 1 && abundance(n-i) == 1) {
        return true;
      }
    }
    return false;
  }

};

int main() {

  Primes p;

  for (int i = 1; i < 28123; i++ ) {
    cout << i << " " <<  p.abundance(i) << endl;
  }

  int sum = 0;
  for (int i = 1; i <= 28123; i++ ) {
    cout << i << endl;
    if (!p.is_sum_of_abundant(i)) {
      sum += i;
    }
  }

  cout << sum << endl;
}