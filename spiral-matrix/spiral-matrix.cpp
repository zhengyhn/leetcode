#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector<vector<int>> map(matrix.size());
      for (int i = 0; i < matrix.size(); ++i) {
        vector<int> temp(matrix[i].size(), 0);
        map[i] = temp;
      }
      vector<int> ret;
      if (matrix.size() <= 0) {
        return ret;
      }
      int curX = 0;
      int curY = 0;
      int dir = 1;
      int numTry = 0;
      while (true) {
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
        if (tempX >= matrix.size() || tempY >= matrix[curX].size() || tempX < 0 || tempY < 0 || map[tempX][tempY] == 1) {
          dir = (dir + 1) % 4;
          ++numTry;
        } else {
          map[curX][curY] = 1;
          ret.push_back(matrix[curX][curY]);
          curX = tempX;
          curY = tempY;
          numTry = 0;
        }
        if (numTry == 2) {
          map[curX][curY] = 1;
          ret.push_back(matrix[curX][curY]);
          break;
        }
      }
      return ret;
    }
};

int main() {
  Solution sln;
  vector<vector<int>> matrix;
  vector<int> ret;
  matrix = {
    { 1, 2, 3 },
    { 4, 5, 6 },
    { 7, 8, 9 }
  };
  ret = sln.spiralOrder(matrix);
  for (int item: ret) {
    cout << item << " ";
  }
  cout << endl;

  matrix = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9,10,11,12}
  };
  ret = sln.spiralOrder(matrix);
  for (int item: ret) {
    cout << item << " ";
  }
  cout << endl;

  return 0;
}
