#include <iostream>
#include <boost/timer.hpp>
#include <iomanip>

using namespace std;


unsigned long int solutionBruteForce(unsigned int num) {

    unsigned long int sum = 0;
    for (int i = 1; i < num; i++) {
        if (i % 5 == 0 || i % 3 == 0)
            sum += i;
    }

    return sum;
}

unsigned long int solutionMultiples(unsigned int num) {
    unsigned int max_mult_5 = (num - 1) / 5;
    unsigned int max_mult_3 = (num - 1) / 3;
    unsigned int max_mult_15 = (num - 1) / 15;
    unsigned long sum = 0;

    for (int i = 1; i <= max_mult_3; i++) {
        if (i <= max_mult_5)
            sum += i*5;
        if (i <= max_mult_3)
            sum += i*3;
        if (i <= max_mult_15)
            sum -= i*15;
    }

    return sum;
}

unsigned long int solutionArithmetic(unsigned int num) {
    unsigned int max_mult_5 = (num - 1) / 5;
    unsigned int max_mult_3 = (num - 1) / 3;
    unsigned int max_mult_15 = (num - 1) / 15;

    unsigned long sum = ((max_mult_3*3)*(max_mult_3 + 1) + (max_mult_5*5)*(max_mult_5+1) -
                                          (max_mult_15*15)*(max_mult_15+1))/2;

    return sum;
}


int main() {

    unsigned int test_nums[] = {10,1000,100000,10000};

    for (int i = 0; i < sizeof(test_nums)/sizeof(int); i++) {
        boost::timer t_brute_force;
        unsigned long brute_force_solution = solutionBruteForce(test_nums[i]);
        double brute_force_time = t_brute_force.elapsed();

        boost::timer t_multiples;
        unsigned long multiples_solution = solutionMultiples(test_nums[i]);
        double multiples_time = t_multiples.elapsed();

        boost::timer t_arithmetic;
        unsigned long arithmetic_solution = solutionArithmetic(test_nums[i]);
        double arithmetic_time = t_arithmetic.elapsed();


        cout << "Sum of all multiples below " << test_nums[i] << ":" << endl;

        cout << "Brute Force Method:" << endl;
        cout << "  Solution: " << brute_force_solution << endl;
        cout << "  Time: " << fixed << setprecision(4) <<
                brute_force_time*1000 << "ms" << endl << endl;

        cout << "Multiples Method:" << endl;
        cout << "  Solution: " << multiples_solution << endl;
        cout << "  Time: " << fixed << setprecision(4) <<
                multiples_time*1000 << "ms" << endl << endl;

        cout << "Arithmetic Method:" << endl;
        cout << "  Solution: " << arithmetic_solution << endl;
        cout << "  Time: " << fixed << setprecision(4) <<
                arithmetic_time*1000 << "ms" << endl << endl;

    }
}
