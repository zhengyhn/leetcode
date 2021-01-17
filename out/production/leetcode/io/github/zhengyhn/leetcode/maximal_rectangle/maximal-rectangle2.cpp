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
    int ret = 0;
    for (int i = 0; i < rowSize; ++i) {
      for (int j = 0; j < colSize; ++j) {
        if (matrix[i][j] == '0') {
          continue;
        }
        int minCol = colSize;
        int m = i;
        int minCols[rowSize];
        for (; m < rowSize; ++m) {
          int n = j;
          for (; n < minCol; ++n) {
            if (matrix[m][n] == '0') {
              break;
            }
          }
          minCol = min(minCol, n);
          minCols[m] = minCol;
        }
        for (m = i; m < rowSize; ++m) {
          int n = j;
          for (; n < minCol; ++n) {
            if (matrix[m][n] == '0') {
              break;
            }
          }
          ret = max(ret, (m - i + 1) * (minCols[m] - j));
          if (n < minCol) {
            break;
          }
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