#include <iostream>
#include <vector>

using namespace std;

struct Point {
  int x;
  int y;
  Point(int x, int y)
    :x(x), y(y)
  {}
};

class Solution {
  public:
    void setZeroes(vector<vector<int>>& matrix) {
      vector<Point> stack;
      for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
          if (matrix[i][j] == 0) {
            stack.push_back(Point(i, j));
          }
        }
      }
      while (!stack.empty()) {
        Point top = stack.back();
        stack.pop_back();
        for (int i = 0; i < matrix.size(); ++i) {
          matrix[i][top.y] = 0;
        }
        for (int i = 0; i < matrix[top.x].size(); ++i) {
          matrix[top.x][i] = 0;
        }
      }
    }

    void setZeroes2(vector<vector<int>>& matrix) {
      for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
          if (matrix[i][j] == 0) {
            int rowHasZero = 0;
            for (int k = 0; k < matrix[i].size(); ++k) {
              if (matrix[i][k] != 0) {
                matrix[i][k] = 0xffff;
              } else {
                rowHasZero = 1;
              }
            }
            for (int k = 0; k < matrix.size(); ++k) {
              if (matrix[k][j] != 0) {
                matrix[k][j] = 0xffff;
              }
            }
            if (!rowHasZero) {
              break;
            }
          }
        }
      }
      for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
          if (matrix[i][j] == 0xffff) {
            matrix[i][j] = 0;
          }
        }
      }
    }
};

int main() {
  Solution sln;
  vector<vector<int>> matrix;
  matrix = {
    {1,1,1},
    {1,0,1},
    {1,1,1}
  };
  sln.setZeroes2(matrix);
  for (auto row: matrix) {
    for (auto col: row) {
      cout << col << " ";
    }
    cout << endl;
  }

  matrix = {
    {0,1,2,0},
    {3,4,5,2},
    {1,3,1,5}
  };
  sln.setZeroes2(matrix);
  for (auto row: matrix) {
    for (auto col: row) {
      cout << col << " ";
    }
    cout << endl;
  }

  return 0;
}
