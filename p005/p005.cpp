#include <iostream>
#include <map>

using namespace std;

map<int,int> primeFactors(int n) {
    int curr = 2;
    map<int,int> factors;

    while (curr <= n) {
        if (n % curr == 0) {
            factors[curr] += 1;
            n /= curr;
        } else {
            curr += 1;
        }
    }

    return factors;
};

int main() {

    int max = 1000;

    map<int,int> factors;

    for (int i = 1; i <= max; i++) {
        auto curr_factors = primeFactors(i);

        for (map<int,int>::iterator it = curr_factors.begin(); it != curr_factors.end();
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

    cout << product;

    return 0;
}