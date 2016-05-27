#include <iostream>
#include <vector>
#include <boost/timer.hpp>

using namespace std;

int vector_contains(vector<int> &vec, int n) {
  for (int i = 0; i < vec.size(); i++ ) {
    if (vec[i] == n) {
      return i;
    }
  }
  return -1;
}

int determine_cycle_length(int n) {

  int i = 0;
  int rem;
  int curr = 10;
  vector<int> remainders;
  while (true) {

    rem = curr % n;

    if (rem == 0) {
      return -1;
    } else {
      rem = curr % n;
      int loc = vector_contains(remainders,rem);
      if (loc == -1) {
        remainders.push_back(rem);
        curr = rem;
      } else {
        return (i - loc);
      }
    }

    curr *= 10;
    i++;

  }
}


int main () {
  boost::timer t;
  int max_repeats = 0;
  int max_d = -1;
  for (int i = 2; i < 1000; i++ ) {
    int a = determine_cycle_length(i);
    if (max_repeats < a) {
      max_repeats = a;
      max_d = i;
    }
  }
  cout << max_d << " " << t.elapsed() << endl;
}