#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    int rowSize = matrix.size();
    if (rowSize <= 0) {
      return 0;
    }
    int colSize = matrix[0].size();
    vector<vector<int>> widths =
        vector<vector<int>>(rowSize, vector<int>(colSize));
    int ret = 0;
    for (int i = 0; i < rowSize; ++i) {
      for (int j = 0; j < colSize; ++j) {
        if (matrix[i][j] == '0') {
          widths[i][j] = 0;
          continue;
        }
        if ((j - 1) >= 0) {
          widths[i][j] = widths[i][j - 1] + 1;
        } else {
          widths[i][j] = 1;
        }
        ret = max(ret, widths[i][j]);
        int minWidth = widths[i][j];
        for (int k = i - 1; k >= 0; --k) {
          minWidth = min(minWidth, widths[k][j]);
          ret = max(ret, minWidth * (i - k + 1));
        }
      }
    }
    return ret;
  }
};

int main() {
  Solution sln;
  vector<vector<char>> matrix;
  matrix = {{'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}};
  cout << sln.maximalRectangle(matrix) << endl;

  matrix = {{'1'}};
  cout << sln.maximalRectangle(matrix) << endl;
  matrix = {{'0'}};
  cout << sln.maximalRectangle(matrix) << endl;
  matrix = {{'1', '1'}, {'1', '1'}};
  cout << sln.maximalRectangle(matrix) << endl;
  matrix = {{'1', '0'}, {'1', '1'}};
  cout << sln.maximalRectangle(matrix) << endl;
  matrix = {{'1', '1'}, {'0', '1'}};
  cout << sln.maximalRectangle(matrix) << endl;
  matrix = {{'1', '1'}, {'1', '0'}};
  cout << sln.maximalRectangle(matrix) << endl;
  matrix = {{'1', '0'}, {'0', '0'}};
  cout << sln.maximalRectangle(matrix) << endl;

  return 0;
}