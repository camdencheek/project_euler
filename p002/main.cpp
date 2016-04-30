#include <iostream>
#include <boost/timer.hpp>
#include <iomanip>

using namespace std;


long fibonacciSum(long n) {
    long a = 1;
    long b = 2;
    long c;
    long sum = 2;

    while (true) {
        c = a + b;
        a = b;
        b = c;
        if (b > n) break;
        if (!(c%2))
            sum += c;
    }

    return sum;
}

long fibonacciSumOptimized(long n) {
    long a = 1;
    long b = 2;
    long c;
    long sum = 2;

    while (true) {
        c = a + 2*b;
        b = 2*a + 3*b;
        a = c;
        if (b > n) break;
        sum += b;

    }

    return sum;

}

int main() {

    long n = 4000000;

    boost::timer t;
    long sum = fibonacciSum(n);
    double time = t.elapsed();

    boost::timer t_optimized;
    long sum_optimized = fibonacciSumOptimized(n);
    double time_optimzed = t_optimized.elapsed();

    cout << "Non-optimized:" << endl;
    cout << "  Sum:  " << sum << endl;
    cout << "  Time: " << fixed << setprecision(3) << time*1000 << "ms" << endl << endl;
    cout << "Optimized:" << endl;
    cout << "  Sum:  " << sum_optimized << endl;
    cout << "  Time: " << time_optimzed*1000 << "ms" << endl;

}