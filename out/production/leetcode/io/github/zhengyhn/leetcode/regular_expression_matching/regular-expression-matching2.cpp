#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isMatch(string s, string p) {
    bool dp[s.size() + 1][p.size() + 1];
    dp[0][0] = true;
    for (int i = 1; i <= s.size(); ++i) {
      dp[i][0] = false;
    }
    for (int i = 1; i <= p.size(); ++i) {
      if (i % 2 == 1) {
        dp[0][i] = false;
      } else if (p[i - 1] == '*') {
        dp[0][i] = dp[0][i - 2];
      } else {
        dp[0][i] = false;
      }
    }
    for (int i = 0; i < s.size(); ++i) {
      for (int j = 0; j < p.size(); ++j) {
        if (s[i] == p[j] || p[j] == '.') {
          dp[i + 1][j + 1] = dp[i][j];
        } else if (p[j] != '*' && p[j] != s[i]) {
          dp[i + 1][j + 1] = false;
        } else if (j >= 1) {
          if (dp[i + 1][j - 1]) {
            dp[i + 1][j + 1] = true;
          } else {
            dp[i + 1][j + 1] = false;
            for (int k = i; k >= 0; --k) {
              if ((s[k] == p[j - 1] || p[j - 1] == '.')) {
                if (dp[k][j - 1]) {
                  dp[i + 1][j + 1] = dp[k][j - 1];
                }
              } else {
                break;
              }
            }
          }
        } else {
          dp[i + 1][j + 1] = false;
        }
        // cout << "dp[" << i + 1 << "][" << j + 1 << "] = " << dp[i + 1][j + 1]
        //      << endl;
      }
    }
    return dp[s.size()][p.size()];
  }
};

int main() {
  Solution sln;

  std::cout << sln.isMatch("aaa", "ab*ac*a") << std::endl;
  //   std::cout << sln.isMatch("a", ".*..a*") << std::endl;
  //   std::cout << sln.isMatch("aa", "a") << std::endl;
  //   std::cout << sln.isMatch("aa", "a*") << std::endl;
  //   std::cout << sln.isMatch("ab", ".*") << std::endl;
  std::cout << sln.isMatch("aab", "c*a*b") << std::endl;
  std::cout << sln.isMatch("mississippi", "mis*is*p*.") << std::endl;

  return 0;
}
