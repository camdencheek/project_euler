/* 
* Determines the sum of all the multiples of 3 and 5 less than a number
* 
* Three solutions are presented in this file, and the time taken by the three is compared 
* by the main method. 
*/
#include <iostream>
#include <boost/timer.hpp>
#include <iomanip>

using namespace std;

/*
The solutionBruteForce function solves the solution by going through every number less than num and summing them. 
This is the least efficient, but simplest method presented.
*/
unsigned long solutionBruteForce(unsigned long num) {

    unsigned long sum = 0;
    for (long i = 1; i < num; i++) {
        if (i % 5 == 0 || i % 3 == 0)
            sum += i;
    }

    return sum;
}

/*
The solutionMultiples function solves the problem by finding the maximum multiple of each of 3, 5, and 15. For each 
multiple of 3 and 5 below num, it adds that number to the growing sum. For each multiple of 15, it subtracts that number
from the sum because otherwise each multiple of 15 will be counted twice (once by 3 and once by 5). 
*/
unsigned long solutionMultiples(unsigned long num) {
    unsigned long max_mult_5 = (num - 1) / 5;
    unsigned long max_mult_3 = (num - 1) / 3;
    unsigned long max_mult_15 = (num - 1) / 15;
    unsigned long sum = 0;

    for (long i = 1; i <= max_mult_3; i++) {
        sum += i*3;
        if (i <= max_mult_5)
            sum += i*5;
        if (i <= max_mult_15)
            sum -= i*15;
    }

    return sum;
}

/*
The solutionArithmetic function solves the problem with a closed form solution, greatly increasing the efficiency of the function.
It does this by utilizing the fact that sum from 1 to n of arithmetic sum a_n is equal to (n/2)*(a_1 + a_n).
*/ 
unsigned long solutionArithmetic(unsigned long num) {
    unsigned long max_mult_5 = (num - 1) / 5;
    unsigned long max_mult_3 = (num - 1) / 3;
    unsigned long max_mult_15 = (num - 1) / 15;

    unsigned long sum = ((max_mult_3*3)*(max_mult_3 + 1) + (max_mult_5*5)*(max_mult_5+1) -
                                          (max_mult_15*15)*(max_mult_15+1))/2;

    return sum;
}


int main() {

    unsigned long test_nums[] = {10,1000,100000,1000000};

    for (int i = 0; i < sizeof(test_nums)/sizeof(long); i++) {
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
