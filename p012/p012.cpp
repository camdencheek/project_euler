#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int nth_triangular(int n) {
  return n*(n+1)/2;
}

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
};

int num_factors_from_prime_factors(unordered_map<int,int> prime_factors) {
  int total = 1;
  for (auto i: prime_factors) {
    total *= (i.second + 1);
  }
  return total + 1;
}

int main() {
  Primes myprimes;
  int num_factors = 1;
  int i = 2;
  int num;
  while (num_factors <= 500) {
    num = nth_triangular(i);
    auto factors = myprimes.prime_factors(num);
    num_factors = num_factors_from_prime_factors(factors);
    i++;
  }

  cout << num << endl;

  return 0;
}
