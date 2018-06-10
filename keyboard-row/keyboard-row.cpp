#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  string tolower(string str) {
    for (char& item: str) {
      if (item >= 'A' && item <= 'Z') {
        item = item - ('A' - 'a');
      }
    }
    return str;
  }

  vector<string> findWords(vector<string>& words) {
    std::vector<std::string> rows = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
    std::map<char, int> map;
    std::vector<string> ret;

    for (int i = 0; i < rows.size(); ++i) {
      for (char c: rows[i]) {
        map[c] = i;
      }
    }

    for (string word: words) {
      string lowerWord = this->tolower(word);
      if (lowerWord.size() <= 0) {
        continue;
      }
      int category = map[lowerWord[0]];
      int i = 1;
      for (; i < lowerWord.size(); ++i) {
        if (map[lowerWord[i]] != category) {
          break;
        }
      }
      if (i == lowerWord.size()) {
        ret.push_back(word);
      }
    }

    return ret;
  }
};

int main() {
  Solution sln;
  std::vector<std::string> v = {"Hello", "Alaska", "Dad", "Peace"};
  std::vector<std::string> ret = sln.findWords(v);

  for (std::string item: ret) {
    std::cout << item << std::endl;
  }

  return 0;
}
