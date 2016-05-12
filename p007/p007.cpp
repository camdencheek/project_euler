#include <iostream>
#include <vector>

using namespace std;

struct Primes {
  vector<int> prime_list;

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

  void append_next() {
    int biggest = *(prime_list.end() - 1) + 2;
    while (!is_prime(biggest)) {
      biggest += 2;
    }
    prime_list.push_back(biggest);
  }
};

int main() {

  Primes my_primes;

  cout << my_primes.get_nth(10001) << endl;

  
}
