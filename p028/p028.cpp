#include <iostream>
#include <boost/timer.hpp>

using namespace std;

int diagonals_sum(int n)  {
  int sum = 1;
  for (int i = 0; i < (n-1)/2; i++) {
    sum +=  16*i*i + 36*i + 24;
  }

  return sum;
}

int main() {
  boost::timer t;

  cout << diagonals_sum(1001) << endl << t.elapsed()*1000 << "ms" << endl;

}
