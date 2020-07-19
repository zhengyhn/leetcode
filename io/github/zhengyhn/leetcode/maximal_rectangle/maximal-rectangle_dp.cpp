#include <iostream>
#include <stack>
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
    vector<int> heights = vector<int>(colSize, 0);
    vector<int> lefts = vector<int>(colSize, 0);
    vector<int> rights = vector<int>(colSize, colSize);
    int ret = 0;
    for (int i = 0; i < rowSize; ++i) {
      int maxLeft = 0;
      int minRight = colSize;
      for (int j = 0; j < colSize; ++j) {
        if (matrix[i][j] == '1') {
          heights[j] += 1;
          lefts[j] = max(lefts[j], maxLeft);
        } else {
          heights[j] = 0;
          lefts[j] = 0;
          maxLeft = j + 1;
        }
        if (matrix[i][colSize - j - 1] == '1') {
          rights[colSize - j - 1] = min(rights[colSize - j - 1], minRight);
        } else {
          rights[colSize - j - 1] = colSize;
          minRight = colSize - j - 1;
        }
      }
      for (int j = 0; j < colSize; ++j) {
        ret = max(ret, (rights[j] - lefts[j]) * heights[j]);
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