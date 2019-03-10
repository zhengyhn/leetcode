#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> generateMatrix(int n) {
      if (n <= 0) {
        return {};
      }
      vector<vector<int>> ret(n);
      for (int i = 0; i < n; ++i) {
        vector<int> temp(n, 0);
        ret[i] = temp;
      }
      int curX = 0;
      int curY = 0;
      int dir = 1;
      int val = 1;
      int numTry = 0;
      while (val <= n * n) {
        int tempX = curX;
        int tempY = curY;
        if (dir == 1) {
          ++tempY;
        } else if (dir == 2) {
          ++tempX;
        } else if (dir == 3) {
          --tempY;
        } else {
          --tempX;
        }
        if (tempX >= n || tempY >= n || tempX < 0 || tempY < 0 || ret[tempX][tempY] > 0) {
          dir = (dir + 1) % 4;
          ++numTry;
        } else {
          ret[curX][curY] = val;
          curX = tempX;
          curY = tempY;
          ++val;
          numTry = 0;
        }
        if (numTry == 2) {
          ret[curX][curY] = val;
          break;
        }
      }
      return ret;
    }

    vector<vector<int>> generateMatrix2(int n) {
      vector<vector<int>> ret(n);
      for (int i = 0; i < n; ++i) {
        vector<int> temp(n, 0);
        ret[i] = temp;
      }
      int rowBegin = 0;
      int rowEnd = n - 1;
      int colBegin = 0;
      int colEnd = n - 1;
      int val = 1;
      while (rowBegin <= rowEnd && colBegin <= colEnd) {
        for (int col = colBegin; col <= colEnd; ++col) {
          ret[rowBegin][col] = val++;
        }
        for (int row = rowBegin + 1; row <= rowEnd; ++row) {
          ret[row][colEnd] = val++;
        }
        if (rowBegin < rowEnd && colBegin < colEnd) {
          for (int col = colEnd - 1; col >= colBegin; --col) {
            ret[rowEnd][col] = val++;
          }
          for (int row = rowEnd - 1; row > rowBegin; --row) {
            ret[row][colBegin] = val++;
          }
        }
        ++rowBegin;
        --rowEnd;
        ++colBegin;
        --colEnd;
      }
      return ret;
    }
};

int main() {
  Solution sln;
  vector<vector<int>> matrix;
  matrix = sln.generateMatrix2(10);
  for (vector<int> row: matrix) {
    for (int col: row) {
      cout << col << " ";
    }
    cout << endl;
  }

  return 0;
}
