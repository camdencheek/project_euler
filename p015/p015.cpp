#include <iostream>
#include <boost/multiprecision/gmp.hpp>

using namespace std;

typedef boost::multiprecision::mpz_int bigint;

bigint factorial(int n) {
  bigint prod = 1;
  while(n > 1) {
    prod *= n;
    n--;
  }
  return prod;
}

bigint nCr(int n,int r) {
  return factorial(n)/(factorial(r)*factorial(n-r));
}

bigint num_paths(int i,int j){
  return nCr(i+j,i);
}

int main() {
  cout << num_paths(20,20) << endl;
}