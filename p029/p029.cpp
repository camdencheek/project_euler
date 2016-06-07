#include <iostream>
#include <set>
#include <cmath>
#include <boost/timer.hpp>

using namespace std;

unsigned long num_terms(int a_min, int a_max, int b_min, int b_max) {
  std::set<double> unique;

  for (int a = a_min; a <= a_max; a++) {
    for (int b = b_min; b <= b_max; b++) {
      unique.insert(pow(a,b));
    }
  };

  return unique.size();
};


int main() {
  boost::timer t;
  cout << num_terms(2,100,2,100) << endl << t.elapsed()*1000 << "ms" << endl;
}
