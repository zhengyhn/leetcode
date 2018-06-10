#include <iostream>

using namespace std;

class Solution {
public:
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
  std::cout << sln.longestPalindrome("babad") << std::endl;
  std::cout << sln.longestPalindrome("cbbd") << std::endl;

  return 0;
}
