#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      vector<vector<int>> ret;
      if (nums.size() < 4) {
        return ret;
      }
      sort(nums.begin(), nums.end());
      int i = 0;
      while (i < nums.size() - 3) {
        int j = i + 1;
        while (j < nums.size() - 2) {
          int front = j + 1;
          int back = nums.size() - 1;
          int val = target - nums[i] - nums[j];
          while (front < back) {
            int sum = nums[front] + nums[back];
            if (sum < val) {
              ++front;
            } else if (sum > val) {
              --back;
            } else {
              vector<int> temp = {nums[i], nums[j], nums[front], nums[back]};
              ret.push_back(temp);
              ++front;
              while (front < back && nums[front] == nums[front - 1]) {
                ++front;
              }
              --back;
              while (front < back && nums[back] == nums[back + 1]) {
                --back;
              }
            }
          }
          ++j;
          while (j < nums.size() - 2 && nums[j] == nums[j - 1]) {
            ++j;
          }
        }
        ++i;
        while (i < nums.size() - 3 && nums[i] == nums[i - 1]) {
          ++i;
        }
      }
      return ret;
    }
};

int main() {
  Solution sln;
  // vector<int> nums = {1,-2,-5,-4,-3,3,3,5};
  vector<int> nums = {1, 0, -1, 0, -2, 2};
  // vector<int> nums = {-2, 1, 1, -2, 1, 1};
  vector<vector<int>> ret = sln.fourSum(nums, 0);
  for (vector<int> row: ret) {
    for (int col: row) {
      std::cout << col << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
