#include <iostream>

using namespace std;

int main() {

  int sum = 1000;
  
  for (int b = 1; b < sum/2 - 1; b++ ) {
    for (int a = 1; a < b; a++ ) {
      int c = sum - b - a;
      if (a*a + b*b == c*c) {
	cout << a * b * c << endl;
	return 0;
      }
    }
  }      
}
