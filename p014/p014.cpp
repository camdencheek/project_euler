#include <iostream>
#include <boost/timer.hpp>

using namespace std;

int collatz_length(long n) {
  int len = 1;
  while (n!=1) {
    if (n&1) {
      n = (n*3+1)/2;
      len += 2;
    } else {
      n = n/2;
      len++;
    }
  }
  return len;
}

int main() {

  boost::timer t;
  int max = 0, res;
  for(int i = 2; i < 1000000; i++ ) {
    int curr = collatz_length(i);
    if (max < curr) {
      max = curr;
      res = i;
    }
  }
  cout << res << " " << max << endl;
  cout << t.elapsed() << "s" << endl;

}