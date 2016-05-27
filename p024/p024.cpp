#include <iostream>
#include <vector>
#include <set>

using namespace std;


int factorial(int n) {
  int prod = 1;
  for (; n > 1; n--) {
    prod *= n;
  }
  return prod;
}

vector<int> nth_permutation(int n, vector<int> nums) {
  n--;
  vector<int> res;
  for (int i = nums.size() - 1; i > 0; i-- ) {
    int curr = n/factorial(i);
    n = n % factorial(i);
    res.push_back(nums[curr]);
    nums.erase(nums.begin()+curr);
  }
  res.push_back(nums[0]);
  return res;
}

int main() {

  vector<int> vec({0,1,2,3,4,5,6,7,8,9});


  auto t = nth_permutation(1000000, vec);
  for (auto j: t) {
    cout << j << " ";
  }
  cout << endl;



}