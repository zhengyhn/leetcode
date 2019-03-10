#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<string> restoreIpAddresses(string s) {
      if (s.size() < 4) {
        return {};
      }
      return restore(s, 0, 4);
    }

    vector<string> restore(string s, int start, int n) {
      if (n == 1 && s.size() - start > 3) {
        return {};
      }
      vector<string> ret;
      for (int i = start; i < start + 3; ++i) {
        if (!isValid(s, start, i)) {
          continue;
        }
        string temp(s.begin() + start, s.begin() + i + 1);
        if (n == 1) {
          if (i == s.size() - 1) {
            ret.push_back(temp);
          }
          continue;
        }
        vector<string> subRet = restore(s, i + 1, n - 1);
        for (int j = 0; j < subRet.size(); ++j) {
          string copy(temp);
          copy.push_back('.');
          copy.append(subRet[j]);
          ret.push_back(copy);
        }
      }
      return ret;
    }

    bool isValid(string s, int start, int end) {
      if (end - start >= 1 && s[start] == '0') {
        return false;
      }
      if (end - start == 2) {
        int sum = (s[start] - '0') * 100 + (s[start + 1] - '0') * 10 + s[start + 2] - '0';
        if (sum > 255) {
          return false;
        }
      }
      return true;
    }
};

int main() {
  Solution sln;
  vector<string> ret;
  ret = sln.restoreIpAddresses("25525511135");
  for (string item: ret) {
    cout << item << endl;
  }

  return 0;
}
