#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int islandPerimeter(vector<vector<int>>& grid) {
      int oneCount = 0;
      int ajacentCount = 0;
      for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
          if (grid[i][j] != 1) {
            continue;
          }
          ++oneCount;
          if ((i - 1) >= 0 && grid[i - 1][j] == 1) {
            ++ajacentCount;
          }
          if ((i + 1) < grid.size() && grid[i + 1][j] == 1) {
            ++ajacentCount;
          }
          if ((j - 1) >= 0 && grid[i][j - 1] == 1) {
            ++ajacentCount;
          }
          if ((j + 1) < grid[i].size() && grid[i][j + 1] == 1) {
            ++ajacentCount;
          }
        }
      }
      return 4 * oneCount - ajacentCount;
    }
};

int main() {
  Solution sln;
  vector<vector<int>> grid = {
    {0, 1, 0, 0},
    {1, 1, 1, 0},
    {0, 1, 0, 0},
    {1, 1, 0, 0}
  };
  std::cout << sln.islandPerimeter(grid) << std::endl;

  return 0;
}
