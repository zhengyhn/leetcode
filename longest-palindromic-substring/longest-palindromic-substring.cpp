#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindromeDp(string s) {
      vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
      int maxI = 0, maxJ = 0;
      for (int i = s.size() - 1; i >= 0; --i) {
        dp[i][i] = true;
        for (int j = i + 1; j < s.size(); ++j) {
          if (s[i] == s[j]) {
            dp[i][j] = i + 1 >= j - 1 ? true : dp[i + 1][j - 1];
          }
          if (dp[i][j] && (j - i) > (maxJ - maxI))
          {
            maxI = i;
            maxJ = j;
          }
        }
        // cout << maxI << " " << maxJ << endl;
      }
      return s.substr(maxI, maxJ - maxI + 1);
    }

    string longestPalindrome(string s) {
      string maxStr;
      for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j <= i - (int)maxStr.size(); ++j) {
          string str = s.substr(j, i - j + 1);
          if (isPalindrome(str) && str.size() > maxStr.size()) {
            maxStr = str;
          }
          // std::cout << i << " " << j << " " << maxStr.size() << " " << (j <= (i - maxStr.size())) << std::endl;
        }
      }
      return maxStr;
    }

    bool isPalindrome(std::string s) {
      int i = 0, j = s.size() - 1;
      while (i <= j) {
        if (s[i] != s[j]) {
          return false;
        }
        ++i;
        --j;
      }
      return true;
    }
};

int main(void) {
  Solution sln;

  // std::cout << sln.longestPalindrome("") << std::endl;
  std::cout << sln.longestPalindrome("a") << std::endl;
  std::cout << sln.longestPalindromeDp("a") << std::endl;
  std::cout << sln.longestPalindrome("babad") << std::endl;
  std::cout << sln.longestPalindromeDp("babad") << std::endl;
  std::cout << sln.longestPalindrome("cbbd") << std::endl;
  std::cout << sln.longestPalindromeDp("cbbd") << std::endl;

  return 0;
}
