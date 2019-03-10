#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      if (matrix.size() <= 0) {
        return false;
      }
      int m = matrix.size();
      int n = matrix[0].size();
      int low = 0;
      int high = m * n - 1;;
      while (low <= high) {
        int mid = (low + high) / 2;
        int iMid = mid / n;
        int jMid = mid % n;
        if (matrix[iMid][jMid] < target) {
          low = mid + 1;
        } else if (matrix[iMid][jMid] > target) {
          high = mid - 1;
        } else {
          return true;
        }
      }
      return false;
    }
};

int main() {
  Solution sln;
  vector<vector<int>> matrix;
  matrix = {
    {1,   3,  5,  7},
    {10, 11, 16, 20},
    {23, 30, 34, 50}
  };
  cout << sln.searchMatrix(matrix, 3) << endl;
  cout << sln.searchMatrix(matrix, 13) << endl;
  cout << sln.searchMatrix(matrix, 50) << endl;
  cout << sln.searchMatrix(matrix, 16) << endl;

  return 0;
}
