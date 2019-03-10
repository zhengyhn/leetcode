#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void rotate(vector<vector<int>>& matrix) {
      int i = 0;
      while (i < matrix.size() / 2) {
        vector<int> temp(matrix.size() - 2 * i);
        int k = 0;
        for (int j = i; j < matrix.size() - i; ++j) {
          temp[k++] = matrix[i][j];
        }
        k = i;
        for (; k < matrix.size() - i; ++k) {
          matrix[i][matrix.size() - k - 1] = matrix[k][i];
        }
        k = i;
        for (; k < matrix.size() - i; ++k) {
          matrix[k][i] = matrix[matrix.size() - i - 1][k];
        }
        k = i;
        for (; k < matrix.size() - i; ++k) {
          matrix[matrix.size() - i - 1][k] = matrix[matrix.size() - k - 1][matrix.size() - i - 1];
        }
        k = i;
        int x = 0;
        for (; k < matrix.size() - i; ++k) {
          matrix[k][matrix.size() - i -1] = temp[x++];
        }
        ++i;
      }
    }
};

int main() {
  Solution sln;
  vector<vector<int>> matrix;
  matrix = {
    {}
  };
  sln.rotate(matrix);
  for (vector<int> row: matrix) {
    for (int col: row) {
      cout << col << " ";
    }
    cout << endl;
  }
  return 0;
}
