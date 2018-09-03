#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int projectionArea(vector<vector<int>>& grid) {
      int ret = 0;
      if (grid.size() <= 0) {
        return ret;
      }
      int xy = 0, yz = 0, zx = 0;
      vector<int> yzMax(grid[0].size(), 0);
      for (int i = 0; i < grid.size(); ++i) {
        int zxMax = 0;
        for (int j = 0; j < grid[i].size(); ++j) {
          if (grid[i][j] > 0) {
            xy += 1;
          }
          if (grid[i][j] > zxMax) {
            zxMax = grid[i][j];
          }
          if (grid[i][j] > yzMax[j]) {
            yzMax[j] = grid[i][j];
          }
        }
        zx += zxMax;
      }
      ret = xy + zx;
      for (int i = 0; i < grid[0].size(); ++i) {
        ret += yzMax[i];
      }
      return ret;
    }
};
int main() {
  Solution sln;
  vector<vector<int>> grid;
  grid = {{2}};
  cout << sln.projectionArea(grid) << endl;
  grid = {{1, 2}, {3, 4}};
  cout << sln.projectionArea(grid) << endl;
  grid = {{1, 0}, {0, 2}};
  cout << sln.projectionArea(grid) << endl;
  grid = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  cout << sln.projectionArea(grid) << endl;
  grid = {{2, 2, 2}, {2, 1, 2}, {2, 2, 2}};
  cout << sln.projectionArea(grid) << endl;

  return 0;
}
