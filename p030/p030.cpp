#include <iostream>
#include <boost/timer.hpp>

using namespace std;



int sum_of_digit_powers(int n, int exp) {

static bool powers_generated = false;
	static int powers[10];
    if (!powers_generated) {
        for (int i = 0; i < 10; i++ ) {
            int tot = 1;
            for (int j = 0; j < exp; j++ ) {
                tot *= i;
            }
            powers[i] = tot;
        }

        powers_generated = true;
    }

    int sum = 0;
    while (n) {
        sum += powers[n%10];
        n/=10;
    }

    return sum;
}

int main () {
    boost::timer t;
    int total_sum = 0;
    for (int i = 2; i < 500000; i++) {
        int sdp = sum_of_digit_powers(i,5);
        if (sdp == i) {
            total_sum += i;
        }
    }

    cout << total_sum << endl;
    cout << t.elapsed()*1000 << "ms" << endl;

    return 0;
}
