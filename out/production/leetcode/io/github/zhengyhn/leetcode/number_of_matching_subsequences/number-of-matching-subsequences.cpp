#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int numMatchingSubseq(string S, vector<string>& words) {
      if (S.size() <= 0 || words.size() <= 0) {
        return 0;
      }
      unordered_map<string> map;
      for (int i = 0; i < words.size(); ++i) {
        for (int j = words[i].size(); j > 0; --j) {
          string str = words[i].substr(0, j);
          if (set[str]
        }
      }

    }
};

int main(void) {
  Solution sln;

  return 0;
}
