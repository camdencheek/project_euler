#include <iostream>
#include <gmp.h>
#include <boost/timer.hpp>

using namespace std;


int main() {
  boost::timer t;
  mpz_t a;
  mpz_init(a);
  int  i = 1;
  do {
    mpz_fib_ui(a,i);
    i++;
  } while (mpz_sizeinbase(a,10) < 1000);
  cout << i << endl << t.elapsed() << endl;
}



