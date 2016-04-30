#include <iostream>
#include <vector>

using namespace std;

bool isPalindromic(int n) {
    vector<int> digits;
    while (n) {
        digits.push_back(n % 10);
        n /= 10;
    }
    for (int i = 0; i < digits.size()/2; i++) {
       if (digits[i] != digits[digits.size() - 1 - i])
           return false;
    }
    return true;
}

struct ProductGeneratorHighToLow {
    int a,b;
    vector< vector<int> > poss;

    ProductGeneratorHighToLow() {
        a = 999;
        b = 999;
        vector<int> arr {a,b};
        poss.push_back(arr);
    }
    int getNext() {
        if (poss.back()[1] == poss.back()[0] - 2) {
            vector<int> arr {poss.back()[0]-1,poss.back()[0]-1};
            poss.push_back(arr);
        }
        int max = -1;
        int max_index = -1;
        for (int i = 0; i < poss.size(); i++) {
            int prod = poss[i][0]*poss[i][1];
            if (prod > max) {
                max = prod;
                max_index = i;
            }
        }

        poss[max_index] = vector<int> {poss[max_index][0],poss[max_index][1]-1};

        return max;
    }
};

int main() {

    auto gen = ProductGeneratorHighToLow();

    while (true) {
        int next_highest = gen.getNext();
        if (isPalindromic(next_highest)){
            cout << "Highest Palindromic: " << next_highest;
            break;
        }
    }

    return 0;
}