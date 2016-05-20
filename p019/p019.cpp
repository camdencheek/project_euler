#include <iostream>
#include <boost/algorithm/string.hpp>
#include <vector>

using namespace std;
using namespace boost;


const unsigned days_in_month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
const string days_of_week[] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};

struct Date {
  int day;
  int month;
  int year;


  bool is_leap_year(int y) {
    if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) {
      return true;
    }
    return false;
  }

  Date(string date_string) {
    vector<string> split_string;
    split(split_string,date_string,is_any_of("/-"));
    day = stoi(split_string[0]);
    month = stoi(split_string[1]);
    year = stoi(split_string[2]);
  }


  string day_of_week() {
    int days_from = 0;
    for (int i = 1900; i < year; i++) {
      if (is_leap_year(i)) {
        days_from += 366;
      } else {
        days_from += 365;
      }
    };
    for (int i = 1; i < month; i++) {
      days_from += days_in_month[i];
      if(is_leap_year(year) && i == 2 )
        days_from++;
    }
    days_from += day - 1;

    return days_of_week[days_from % 7];
  };
};

int main() {
  Date date1("1/1/1900");

  int count = 0;
  for (int year = 1901; year <= 2000; year++) {
    date1.year = year;
    for (int month = 1; month <= 12; month++ ) {
      date1.month = month;
      if (date1.day_of_week() == "Sunday") {
        count++;
      }
    }
  }
  cout << count;
}