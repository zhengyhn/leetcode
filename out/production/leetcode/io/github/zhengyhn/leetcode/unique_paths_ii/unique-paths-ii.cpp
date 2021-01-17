#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      if (obstacleGrid.size() <= 0) {
        return 0;
      }
      int m = obstacleGrid.size();
      int n = obstacleGrid[0].size();
      int dp[m][n];
      for (int i = m - 1; i >= 0; --i) {
        if (obstacleGrid[i][n - 1] == 1) {
          for (int j = i; j >= 0; --j) {
            dp[j][n - 1] = 0;
          }
          break;
        } else {
          dp[i][n - 1] = 1;
        }
      }
      for (int i = n - 1; i >= 0; --i) {
        if (obstacleGrid[m - 1][i] == 1) {
          for (int j = i; j >= 0; --j) {
            dp[m - 1][j] = 0;
          }
          break;
        } else {
          dp[m - 1][i] = 1;
        }
      }
      for (int i = m - 2; i >= 0; --i) {
        for (int j = n - 2; j >= 0; --j) {
          if (obstacleGrid[i][j] == 1) {
            dp[i][j] = 0;
          } else {
            dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
          }
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
  cout << sln.uniquePathsWithObstacles(matrix) << endl;

  return 0;
}
