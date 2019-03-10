#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int uniquePaths(int m, int n) {
      long long dp[m + 1][n + 1];
      dp[m][n] = 1;
      for (int i = 1; i < n; ++i) {
        dp[m][i] = 1;
      }
      for (int i = 1; i < m; ++i) {
        dp[i][n] = 1;
      }
      for (int i = m - 1; i >= 1; --i) {
        for (int j = n - 1; j >= 1; --j) {
          dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
          cout << i << " " << j << " " << dp[i][j] << endl;
        }
      }
      return dp[1][1];
    }
};

int main() {
  Solution sln;
  cout << sln.uniquePaths(3, 2) << endl;
  cout << sln.uniquePaths(7, 3) << endl;
  // cout << sln.uniquePaths(100, 100) << endl;

  return 0;
}
