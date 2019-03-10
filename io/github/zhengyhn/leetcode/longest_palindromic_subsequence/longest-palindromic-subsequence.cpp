#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int longestPalindromeSubseqRecursive(string& s, int start, int end) {
    if (start > end) {
      return 0;
    }
    if (start == end) {
      return 1;
    }
    int maxLen = 0;
    for (int i = start; i < end; ++i) {
      int len = 0;
      for (int j = end; j >= i; --j) {
        if (s[i] == s[j]) {
          if (i == j) {
            ++len;
            break;
          } else {
            len += 2;
            len += this->longestPalindromeSubseqRecursive(s, i + 1, j - 1);
            break;
          }
        }
      }
      maxLen = max(len, maxLen);
    } 
    return maxLen;
  }
  int longestPalindromeSubseq(string s)
  {
    return this->longestPalindromeSubseqRecursive(s, 0, s.size() - 1);
  }

  int longestPalindromeSubseqDp(string s) {
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
    for (int i = s.size() - 1; i >= 0; --i) {
      dp[i][i] = 1;
      for (int j = i + 1; j < s.size(); ++j) {
        if (s[i] == s[j]) {
          dp[i][j] = dp[i + 1][j - 1] + 2;
        } else {
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[0][s.size() - 1];
  }
};

int main()
{
  Solution sln;
  string s;
  s = "bbbab";
  cout << sln.longestPalindromeSubseq(s) << endl;
  cout << sln.longestPalindromeSubseqDp(s) << endl;
  s = "cbbd";
  cout << sln.longestPalindromeSubseq(s) << endl;
  cout << sln.longestPalindromeSubseqDp(s) << endl;

  return 0;
}