#include <iostream>
#include "../headers/digits.h"
#include <set>
#include <algorithm>

using namespace std;

void print_set(set<int> a) {
	for (std::set<int>::iterator it=a.begin(); it!=a.end(); ++it)
		std::cout << ' ' << *it;

	cout << endl;
}

bool is_pandigital_with_multiplicands(int n) {
	vector<int> n_digits = cam::digits(n);
	set<int> remaining_digits;

	for (int i = 1; i <= 9; i++) {
		remaining_digits.insert(i);
	}

	for (int digit: n_digits) {
		if ( digit == 0 ) {
			return false;
		} else if ( !remaining_digits.count(digit) ) {
			return false;
		}

		remaining_digits.erase(digit);
	}


	int a = 1;
	while ( a * a < n ) {
		
		bool next = false;
		set<int> local_remaining_digits = remaining_digits;


		int b = n / a;
		if ( n % a == 0 ) {

			vector<int> a_digits = cam::digits(a);
			for (int digit: a_digits) {
				if (digit == 0 ||  !local_remaining_digits.count(digit) ) {
					next = true;
					break;
				}

				local_remaining_digits.erase(digit);
			}
			
			vector<int> b_digits = cam::digits(b);
			for (int digit: cam::digits(b)) {
				if (digit == 0 || !local_remaining_digits.count(digit) ) {
					next = true;
					break;
				}

				local_remaining_digits.erase(digit);
			}

			if (next) {
				a++;
				continue;
			}

			if (!local_remaining_digits.size()) {

				cout << n << " " << a << " " << b << endl;
				return true;
			}

		}

		a++;
	}

	return false;
}


int main() {
	int sum = 0;
	for (int i = 1; i < 10000; i++) {
		if (is_pandigital_with_multiplicands(i)) {
			sum += i;
		}
	}

	cout << sum << endl;
}

