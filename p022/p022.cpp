#include <iostream>
#include <fstream>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <unordered_map>

using namespace std;


int name_score(string name) {
  static unordered_map<char,int> alphabet_score;
  if (!alphabet_score.size()) {
    for (int i = 0; i < 26; i++) {
      alphabet_score.insert({'A' + i, i + 1});
    }
  }

  int score = 0;
  for(char i: name) {
      score += alphabet_score[i];
  }

  return score;
}

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

  sort(names_vector.begin(),names_vector.end());

  int total = 0;
  for (int i = 0; i < names_vector.size(); i++) {
    total += (i+1) * name_score(names_vector[i]);

  }

  cout << total << endl;


}
