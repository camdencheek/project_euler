#include <iostream>
#include <fstream>
#include <vector>
#include <boost/algorithm/string.hpp>

using namespace std;

int main() {
  ifstream names_file("/Users/ccheek/project_euler/p022/p022_names.txt");
  string line;
  vector<string> names_vector;
  if (names_file.is_open()) {
    while (getline(names_file,line,',')) {
      boost::erase_all(line,"\"");
      names_vector.push_back(line);
    }
  }
  names_file.close();



}
