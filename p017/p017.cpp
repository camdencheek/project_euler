#include <iostream>
#include <boost/algorithm/string.hpp>
#include <cmath>

using namespace std;
using namespace boost;


string int_to_words(long long n, bool use_and = true) {
  string one_to_nine[] = {"","one","two","three","four","five","six","seven","eight","nine"};
  string tens[] = {"","ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
  string teens[] = {"","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
  string thousands[] = {"","thousand","million","billion","trillion","quadrillion","quintillion","sextillion","septillion","octillion","nonillion"};

  int t = 1;

  while (pow(10,3*t) <= n ) {
    t += 1;
  }

  string return_string = "";

  for (; t > 0; t-- ) {
    string string_t("");
    int group_t = n % (long long)(pow(10,3*t)) / (long long)(pow(10,3*(t-1)));
    if (group_t == 0) continue;

    int hundreds = group_t/100;
    string hundreds_string("");
    if (hundreds != 0){
      hundreds_string = (one_to_nine[hundreds] + " hundred");
    }

    int tens_and_ones = group_t % 100;
    string tens_and_ones_string("");
    if(tens_and_ones <= 9 && tens_and_ones > 0) {
      tens_and_ones_string += one_to_nine[tens_and_ones];
    } else if (tens_and_ones <= 19 && tens_and_ones > 10) {
      tens_and_ones_string += teens[tens_and_ones % 10];
    } else if (tens_and_ones % 10 == 0) {
      tens_and_ones_string += tens[tens_and_ones/10];
    } else {
      tens_and_ones_string += tens[tens_and_ones/10] + "-" + one_to_nine[tens_and_ones % 10];
    }

    if (hundreds_string != "" && tens_and_ones_string != "") {
      string_t = hundreds_string + (use_and ? " and " : " " ) + tens_and_ones_string + (t == 1 ? "" : " " ) + thousands[t-1] + ", ";
    } else if (hundreds_string == "" && tens_and_ones_string == "" ) {
      string_t = "";
    } else {
      string_t = hundreds_string + tens_and_ones_string + (t != 1 ? " " : "" ) + thousands[t-1] + ", ";
    }

    return_string += string_t;
  }

  return_string.erase(return_string.end() - 2, return_string.end());
  return return_string;


}

int main() {
  string whole = "";
  for (int i = 1; i <= 1000; i ++ ){
    whole += int_to_words(i);
  }

  erase_all(whole," ");
  erase_all(whole,",");
  erase_all(whole,"-");
  cout << whole.size();
}