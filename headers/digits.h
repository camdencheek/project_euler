#ifndef DIGITS_HEADER
#define DIGITS_HEADER

#include <iostream>
#include <deque>

namespace cam {

	template <typename uint_type>
		int num_digits(uint_type x) {
			if (x < 0) return num_digits(-x) + 1;

			int num_digits = 0;
			while (x > 999999999) {
				num_digits++;	
				x /= 10;
			}

			if (x >= 10000) {
				if (x >= 10000000) {
					if (x >= 100000000) {
						if (x >= 1000000000)
							return 10;
						return num_digits + 9;
					}
					return num_digits + 8;
				}
				if (x >= 100000) {
					if (x >= 1000000)
						return num_digits + 7;
					return num_digits + 6;
				}
				return num_digits + 5;
			}
			if (x >= 100) {
				if (x >= 1000)
					return num_digits + 4;
				return num_digits + 3;
			}
			if (x >= 10)
				return num_digits + 2;
			return num_digits + 1;
		}

	template <typename uint_type>
		std::deque<uint_type> digits(uint_type n) {
			std::deque<uint_type> digits_deque;
			while (n >= 1) {
				digits_deque.push_front(n % 10);
				n /= 10;
			}
			return digits_deque;
		}

}

#endif
