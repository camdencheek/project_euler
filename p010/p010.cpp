#include <iostream>
#include "../headers/primes.h"
#include <boost/timer.hpp>

using namespace std;

int main() {

	boost::timer t;
	int i = 1;

	Primes my_primes;
	int max = 2000000;
	long sum = 0;
	while (my_primes.get_nth(i) < max) {
		sum += my_primes.get_nth(i);
		i++;
	}

	cout << "Sum: " << sum << endl;
	cout << t.elapsed()*1000 << "ms" << endl;

	return 0;

}
