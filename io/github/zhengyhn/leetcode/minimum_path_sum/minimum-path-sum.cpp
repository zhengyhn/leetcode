#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int minPathSum(vector<vector<int>>& grid) {
      if (grid.size() <= 0) {
        return 0;
      }
      int m = grid.size();
      int n = grid[0].size();
      int dp[m][n];
      dp[m - 1][n - 1] = grid[m - 1][n - 1];
      for (int i = n - 2; i >= 0; --i) {
        dp[m - 1][i] = dp[m - 1][i + 1] + grid[m - 1][i];
      }
      for (int i = m - 2; i >= 0; --i) {
        dp[i][n - 1] = dp[i + 1][n - 1] + grid[i][n - 1];
      }
      for (int i = m - 2; i >= 0; --i) {
        for (int j = n - 2; j >= 0; --j) {
          dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j];
        }
      }
      return dp[0][0];
    }
};

int main() {
  Solution sln;
  vector<vector<int>> matrix;
  matrix = {
    {0, 0, 0},
    {0, 1, 0},
    {0, 0, 0}
  };
  cout << sln.minPathSum(matrix) << endl;

  matrix = {
    {1,3,1},
    {1,5,1},
    {4,2,1}
  };
  cout << sln.minPathSum(matrix) << endl;

  return 0;
}
