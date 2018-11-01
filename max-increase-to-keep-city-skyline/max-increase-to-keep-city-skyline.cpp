#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
  {
    vector<int> left(grid.size(), 0);
    vector<int> top(grid.size(), 0);
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[i].size(); ++j) {
        left[i] = max(left[i], grid[i][j]);
        top[j] = max(top[j], grid[i][j]);
      }
    }
    int ans = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[i].size(); ++j) {
        ans += min(left[i], top[j]) - grid[i][j];
      }
    }
    return ans;
  }
};

int main()
{
  Solution sln;
  vector<vector<int>> grid;
  grid = {
    {3, 0, 8, 4},
    {2, 4, 5, 7},
    {9, 2, 6, 3},
    {0, 3, 1, 0}
  };
  cout << sln.maxIncreaseKeepingSkyline(grid) << endl;

  return 0;
}