#include <iostream>
#include <map>
#include "../headers/primes.h"
#include <boost/timer.hpp>

using namespace std;

int main() {
	
	boost::timer t;	
	Primes p;
    int max = 20;

    map<int,int> factors;

    for (int i = 1; i <= max; i++) {
        auto curr_factors = p.prime_factors(i);

        for (map<long,int>::iterator it = curr_factors.begin(); it != curr_factors.end();
             ++it) {
            if (factors[it->first] < it->second){
                factors[it->first] = it->second;
            }
        }
    }

    long product = 1;
    for (map<int,int>::iterator it = factors.begin(); it != factors.end(); ++it) {
        for (int i = 0; i < it->second; i++) {
            product *= it->first;
        }
    }

    cout << product << endl;
	cout << t.elapsed()*1000 << "ms" << endl;

    return 0;
}
