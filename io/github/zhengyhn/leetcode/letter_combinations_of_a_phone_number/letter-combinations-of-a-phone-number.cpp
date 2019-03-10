#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<string> letterCombinations(string digits) {
      vector<string> ret;
      if (digits.size() <= 0) {
        return ret;
      }
      vector<vector<char>> map = {{}, {}};
      char c = 'a';
      for (int i = 2; i < 10; ++i) {
        vector<char> temp = {c, (char)(c + 1), (char)(c + 2)};
        if (i == 7 || i == 9) {
          temp.push_back((char)(c + 3));
          c += 1;
        }
        map.push_back(temp);
        c += 3;
      }
      ret.push_back("");
      for (int i = 0; i < digits.size(); ++i) {
        int index = digits[i] - '0';
        if (index == 0 || index == 1) {
          continue;
        }
        vector<string> temp(ret.size() * map[index].size());
        int j = 0;
        for (int k = 0; k < ret.size(); ++k) {
          for (int x = 0; x < map[index].size(); ++x) {
            string str(ret[k]);
            str.push_back(map[index][x]);
            temp[j++] = str;
          }
        }
        ret = temp;
      }
      return ret;
    }
};

int main() {
  Solution sln;
  vector<string> ret = sln.letterCombinations("7");
  std::cout << ret.size() << std::endl;
  for (auto item: ret) {
    std::cout << item << std::endl;
  }

  return 0;
}
