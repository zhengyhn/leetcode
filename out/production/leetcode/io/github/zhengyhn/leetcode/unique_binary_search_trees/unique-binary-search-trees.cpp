#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees2(int n) {
      if (n < 1) {
        return 0;
      }
      vector<vector<int>> dp(n + 2, vector<int>(n + 2, 1));
      for (int i = n; i > 0; --i) {
        for (int j = i; j <= n; ++j) {
          dp[i][j] = 0;
          for (int k = i; k <= j; ++k) {
            dp[i][j] += dp[i][k - 1] * dp[k + 1][j];
          }
        }
      }
      return dp[1][n];
    }
    int numTrees(int n) {
      if (n < 1) {
        return 0;
      }
      return this->robot(0, n - 1);
    }

    int robot(int i, int j) {
      if (i >= j) {
        return 1;
      }
      int count = 0;
      for (int k = i; k <= j; ++k) {
        count += this->robot(i, k - 1) * this->robot(k + 1, j);
      }
      return count;
    }
};

int main() {
    Solution sln;
    for (int i = -1; i < 100; ++i) {
      cout << sln.numTrees(i) << endl;
      cout << sln.numTrees2(i) << endl;
    }
    return 0;
}