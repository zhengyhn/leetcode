#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    string longestCommonPrefix(vector<string>& strs) {
      if (strs.size() <= 0) {
        return "";
      }
      int shortest;
      int minSize = 0;
      for (int i = 0; i < strs.size(); ++i) {
        if (strs[i].size() < minSize) {
          minSize = strs[i].size();
          shortest = i;
        }
      }
      int i, j;
      for (i = strs[shortest].size() - 1; i >= 0; --i) {
        for (j = 0; j < strs.size(); ++j) {
          if (strs[j].substr(0, i + 1) != strs[shortest].substr(0, i + 1)) {
            break;
          }
        }
        if (j == strs.size()) {
          return strs[shortest].substr(0, i + 1);
        }
      }
      return "";
    }
};

int main() {
  Solution sln;
  vector<string> strs = {"abdfdf", "abc", "absdjflsfdj"};
  std::cout << sln.longestCommonPrefix(strs) << std::endl;

  return 0;
}
