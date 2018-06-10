#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> ret;
      if (nums.size() < 3) {
        return ret;
      }
      int stack[nums.size()];
      int top = -1;
      stack[++top] = 0;
      int sum = nums[0];

      while (nums.size() - stack[top] > 2) {
        for (int i = stack[top] + 1; i < nums.size(); ++i) {
          stack[++top] = i;
          sum += nums[i];
          if (top == 2) {
            --top;
            sum -= nums[i];
            if (sum == 0) {
              vector<int> temp;
              for (int j = 0; j < 3; ++j) {
                temp.push_back(nums[stack[j]]);
              }
              ret.push_back(temp);
              break;
            }
          }
        }
        sum -= nums[stack[top]];
        ++stack[top];
        sum += nums[stack[top]];
        while (top > 0 && stack[top] >= nums.size()) {
          sum -= nums[stack[top]];
          --top;
          ++stack[top];
          sum -= nums[stack[top]];
        }
      }
      return ret;
    }
};

int main() {
  Solution sln;
  // vector<int> nums = {-1, 0, 1, 2, -1, -4};
  // vector<int> nums = {-1, 1, 0};
  vector<int> nums = {-2, 1, 1, -2, 1, 1};
  vector<vector<int>> ret = sln.threeSum(nums);
  for (vector<int> row: ret) {
    for (int col: row) {
      std::cout << col << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
