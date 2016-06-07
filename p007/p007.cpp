#include <iostream>
#include <vector>
#include "../headers/primes.h"
#include <boost/timer.hpp>

using namespace std;

int main() {

	boost::timer t;
	Primes my_primes;

	cout << my_primes.get_nth(10001) << endl;
	cout << t.elapsed()*1000 << "ms" << endl;

  
}
