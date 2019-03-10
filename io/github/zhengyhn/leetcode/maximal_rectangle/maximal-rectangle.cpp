#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int maximalRectangle(vector<vector<char>>& matrix) {
      int max = 0;
      for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
          if (matrix[i][j] != '1') {
            continue;
          }
          if (max <= 0) {
            max = 1;
          }
          int width = 1;
          int k = j + 1;
          while (k < matrix[i].size() && matrix[i][k] == '1') {
            ++width;
            ++k;
          }
          int height = 1;
          if (width * height > max) {
            max = width * height;
          }
          k = i + 1;
          while (k < matrix.size() && matrix[k][j] == '1') {
            int tempWidth = 1;
            int t = j + 1;
            while (t < matrix[k].size() && matrix[k][t] == '1') {
              ++tempWidth;
              ++t;
            }
            if (tempWidth < width) {
              width = tempWidth;
            }
            ++height;
            // std::cout << i << " " << j << " " << k << " " << width << " " << height << std::endl;
            if (width * height > max) {
              max = width * height;
            }
            ++k;
          }
        }
      }
      return max;
    }
};

int main() {
  Solution sln;
  // vector<vector<char>> board = {
  //   {'1', '1'}
  // };
  vector<vector<char>> board = {
    {'0','0','0','1','0','1','0'},
    {'0','1','0','0','0','0','0'}, 
    {'0','1','0','1','0','0','1'}, 
    {'0','0','1','1','0','0','1'}, 
    {'1','1','1','1','1','1','0'}, 
    {'1','0','0','1','0','1','1'}, 
    {'0','1','0','0','1','0','1'}, 
    {'1','1','0','1','1','1','0'}, 
    {'1','0','1','0','1','0','1'}, 
    {'1','1','1','0','0','0','0'}
  };
  // vector<vector<char>> board = {
  //   {'1',
  //   '0',
  //   '1', '0', '0'},
  //   {'1', '0', '1', '1', '1'}
  // };
  // vector<vector<char>> board = {
  //   {'1', '0', '1', '0', '0'},
  //   {'1', '0', '1', '1', '1'},
  //   {'1', '1', '1', '1', '1'},
  //   {'1', '0', '0', '1', '0'}
  // };
  // vector<vector<char>> board = {
  //   {'1','1','1','1','1','1','1','1'},
  //   {'1','1','1','1','1','1','1','0'},
  //   {'1','1','1','1','1','1','1','0'},
  //   {'1','1','1','1','1','0','0','0'},
  //   {'0','1','1','1','1','0','0','0'}
  // };
  std::cout << sln.maximalRectangle(board) << std::endl;

  return 0;
}
