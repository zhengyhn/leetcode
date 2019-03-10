#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
      int rows = nums.size();
      if (rows <= 0) {
        return nums;
      }
      int cols = nums[0].size();
      if (cols <= 0) {
        return nums;
      }
      if (rows * cols != r * c) {
        return nums;
      }
      vector<int> store(r * c);
      int k = 0;
      for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < nums[i].size(); ++j) {
          store[k++] = nums[i][j];
        }
      }
      k = 0;
      vector<vector<int>> ret(r);
      for (int i = 0; i < r; ++i) {
        vector<int> temp(c);
        for (int j = 0; j < c; ++j) {
          temp[j] = store[k++];
        }
        ret[i] = temp;
      }
      return ret;
    }
};

int main() {
  Solution sln;
  vector<vector<int>> input = {{1, 2}, {3, 4}};
  vector<vector<int>> ret = sln.matrixReshape(input, 4, 1);
  for (int i = 0; i < ret.size(); ++i) {
    for (int j = 0; j < ret[i].size(); ++j) {
      std::cout << ret[i][j] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
