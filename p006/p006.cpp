#include <iostream>
#include <boost/timer.hpp>
#include <vector>
#include <boost/multiprecision/gmp.hpp>

using namespace std;

typedef boost::multiprecision::mpz_int bigint;

bigint bruteForceSolution(bigint n) {
    bigint sum_squares = 0, square_sum = 0, sum = 0;

    for (bigint i = 1; i <= n; i++) {
        sum_squares += i*i;
        sum += i;
    }

    square_sum = sum*sum;

    return square_sum - sum_squares;
};

bigint seriesSolution(bigint n) {
    bigint sum_squares, square_sum;
    
    sum_squares = n*(n+1)*(2*n+1)/6;
    square_sum = n*n*(n+1)*(n+1)/4;

    return square_sum - sum_squares;
}

int main() {

  vector<int> testnums = {100,500,1000,10000,100000,1000000,10000000,100000000};

    for (auto i: testnums) {
        boost::timer t_brute;
        bigint brute_force_answer = bruteForceSolution(i);
        double brute_force_time = t_brute.elapsed();

        boost::timer t_series;
        bigint series_answer = seriesSolution(i);
        double series_time = t_series.elapsed();

        cout << "For test number " << i << ":" << endl;
        cout << "  Brute Answer:  " << brute_force_answer << endl;
        cout << "  Brute Time:    " << brute_force_time << endl << endl;
        cout << "  Series Answer: " << series_answer << endl;
        cout << "  Series Time:   " << series_time << endl << endl;

    }

}
