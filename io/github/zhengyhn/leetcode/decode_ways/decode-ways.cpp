#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    int numDecodings3(string s) {
      vector<int> dp(s.size() + 1, 0);
      dp[s.size()] = 1;
      for (int i = s.size() - 1; i >= 0; --i) {
        if (i < s.size() - 1) {
          if (isValid(s[i], s[i + 1])) {
            dp[i] += dp[i + 2];
          }
        }
        if (isValid(s[i])) {
          dp[i] += dp[i + 1];
        }
      }
      return dp[0];
    }

    bool isValid(char a) {
      return a >= '1' && a <= '9';
    }

    bool isValid(char a, char b) {
      return a == '1' || (a == '2' && b <= '6');
    }

    int numDecodings2(string s) {
      unordered_set<string> set;
      for (int i = 1; i <= 26; ++i) {
        set.insert(intToStr(i));
      }
      vector<int> dp(s.size() + 1, 0);
      dp[s.size()] = 1;
      for (int i = s.size() - 1; i >= 0; --i) {
        if (i < s.size() - 1 && set.find(s.substr(i, 2)) != set.end()) {
          dp[i] += dp[i + 2];
        }
        if (set.find(s.substr(i, 1)) != set.end()) {
          dp[i] += dp[i + 1];
        }
      }
      return dp[0];
    }

    int numDecodings(string s) {
      unordered_set<string> set;
      for (int i = 1; i <= 26; ++i) {
        set.insert(intToStr(i));
      }
      return _numDecodings(s, set);
    }

    int _numDecodings(string s, unordered_set<string>& set) {
      if (s.size() <= 0) {
        return 1;
      }
      int count = 0;
      if (s.size() >= 2 && set.find(s.substr(0, 2)) != set.end()) {
        count += _numDecodings(s.substr(2), set);
      }
      if (set.find(s.substr(0, 1)) != set.end()) {
        count += _numDecodings(s.substr(1), set);
      }
      return count;
    }

    string intToStr(int num) {
      string str;
      if (num >= 10) {
        str.push_back('0' + (num / 10));
      }
      str.push_back('0' + (num % 10));

      return str;
    }
};

int main() {
  Solution sln;
  cout << sln.numDecodings("0") << " " << sln.numDecodings3("0") << endl;
  cout << sln.numDecodings("01") << " " << sln.numDecodings3("01") << endl;
  cout << sln.numDecodings("10") << " " << sln.numDecodings3("10") << endl;
  cout << sln.numDecodings("12") << " " << sln.numDecodings3("12") << endl;
  cout << sln.numDecodings("226") << " " << sln.numDecodings3("226") << endl;
  cout << sln.numDecodings("1122") << " " << sln.numDecodings3("1122") << endl;

  return 0;
}
