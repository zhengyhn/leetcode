#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
  public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
      vector<vector<int>> ret;
      int numVisit = 0;
      int r = r0;
      int c = c0;
      vector<int> dirR = {0, 1, 0, -1};
      vector<int> dirC = {1, 0, -1, 0};
      int iDirR = 0;
      int iDirC = 0;
      int curRowSize = 0;
      int curColSize = 1;
      while (numVisit < R * C) {
        // cout << "aa:" << r << " " << c << " " << iDirR << " " << iDirC << endl;
        if (r >= 0 && r < R && c >= 0 && c < C) {
          vector<int> pos = {r, c};
          ret.push_back(pos);
          ++numVisit;
        }
        if (dirC[iDirC] != 0 && abs(c + dirC[iDirC] - c0) > curColSize) {
          if (dirC[iDirC] > 0) {
            ++curRowSize;
          }
          iDirC = (iDirC + 1) % 4;
          iDirR = (iDirR + 1) % 4;
        } else if (dirR[iDirR] != 0 && abs(r + dirR[iDirR] - r0) > curRowSize) {
          if (dirR[iDirR] < 0) {
            ++curColSize;
          }
          iDirC = (iDirC + 1) % 4;
          iDirR = (iDirR + 1) % 4;
        }
        c += dirC[iDirC];
        r += dirR[iDirR];
      }
      return ret;
    }
};
int main() {
  Solution sln;
  vector<vector<int>> ret;
  ret = sln.spiralMatrixIII(1, 4, 0, 0);
  for (vector<int> row: ret) {
    for (int col: row) {
      cout << col << " ";
    }
    cout << endl;
  }
  ret = sln.spiralMatrixIII(5, 6, 1, 4);
  for (vector<int> row: ret) {
    for (int col: row) {
      cout << col << " ";
    }
    cout << endl;
  }
   return 0;
}
