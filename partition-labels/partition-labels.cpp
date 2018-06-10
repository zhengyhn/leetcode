#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    vector<int> partitionLabels(string S) {
      vector<int> ret;
      if (S.size() == 0) {
        return ret;
      }
      // unordered_map<int, unordered_map<char, int>>> map = {0: {S[0]: 1}};
      vector<int> roots(S.size());
      for (int i = 0; i < S.size(); ++i) {
        int j = 0;
        for (; j < i; ++j) {
          if (S[j] == S[i]) {
            // std::cout << "i " << S[j] << " " << S[i] << " " << j << " " << i << std::endl;
            for (int k = j + 1; k <= i; ++k) {
              roots[k] = roots[j];
            }
            break;
          }
        }
        if (j == i) {
          roots[j] = j;
        }
      }
      // for (int it: roots) {
      //   std::cout << "r " << it << std::endl;
      // }
      int beginValue = roots[0];
      int begin = 0;
      int i = 1;
      for (; i < roots.size(); ++i) {
        if (roots[i] != beginValue) {
          ret.push_back(i - begin);
          begin = i;
          beginValue = roots[i];
        }
      }
      ret.push_back(i - begin);
      return ret;
    }
};

int main() {
  Solution sln;
  vector<int> ret = sln.partitionLabels("abab");
  for (int it: ret) {
    std::cout << it << std::endl;
  }

  return 0;
}
