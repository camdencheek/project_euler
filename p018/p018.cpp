#include <iostream>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>

using namespace std;

struct Triangle {
  vector< vector <int> > triangle;

  Triangle(string triangle_string) {
    vector<string> lines;
    boost::split(lines,triangle_string,boost::is_any_of("\n"));
    for (auto line: lines) {
      vector<string> split_line;
      boost::split(split_line,line,boost::is_any_of(" "));

      vector<int> ints_line;
      for (auto val: split_line) {
        ints_line.push_back(stoi(val));
      }
      triangle.push_back(ints_line);
    }

    vector< vector<int> > original(triangle);
  }

  void collapse_last_row() {
    int last_row = triangle.size() - 1;
    for (int i = 0; i < triangle[last_row].size()-1; i++) {
      triangle[last_row - 1][i] += max(triangle[last_row][i],triangle[last_row][i+1]);
    }
    triangle.pop_back();
  }

  int find_biggest_sum() {
    while (triangle.size() > 1) {
      collapse_last_row();
    }
    return triangle[0][0];
  };
};

int main() {
  string triangle_string = "75\n"
          "95 64\n"
          "17 47 82\n"
          "18 35 87 10\n"
          "20 04 82 47 65\n"
          "19 01 23 75 03 34\n"
          "88 02 77 73 07 63 67\n"
          "99 65 04 28 06 16 70 92\n"
          "41 41 26 56 83 40 80 70 33\n"
          "41 48 72 33 47 32 37 16 94 29\n"
          "53 71 44 65 25 43 91 52 97 51 14\n"
          "70 11 33 28 77 73 17 78 39 68 17 57\n"
          "91 71 52 38 17 14 91 43 58 50 27 29 48\n"
          "63 66 04 68 89 53 67 30 73 16 69 87 40 31\n"
          "04 62 98 27 23 09 70 98 73 93 38 53 60 04 23";

  Triangle t(triangle_string);
  cout << t.find_biggest_sum() << endl;


};
