#include <iostream>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size() + 1;
        int n = word2.size() + 1;
        int **dp = new int*[m];
        dp[0] = new int[n];
        for (int j = 0; j < n; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i < m; ++i) {
            dp[i] = new int[n];
            dp[i][0] = i;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                int a = dp[i - 1][j] + 1;
                int b = dp[i][j - 1] + 1;
                int c = word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] : dp[i - 1][j - 1] + 1;
                dp[i][j] = min(min(a, b), c);
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
  Solution sln;
  cout << sln.minDistance("horse", "ros") << endl;

  return 0;
}