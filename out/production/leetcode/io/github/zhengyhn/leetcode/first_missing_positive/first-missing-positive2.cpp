#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    if (nums.size() < 1) {
      return 1;
    }
    for (int i = 0; i < nums.size(); ++i) {
      while (nums[i] > 0 && nums[i] <= nums.size() &&
             nums[i] != nums[nums[i] - 1]) {
        int temp = nums[i];
        int rightIndex = nums[i] - 1;
        nums[i] = nums[rightIndex];
        nums[rightIndex] = temp;
      }
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != (i + 1)) {
        return i + 1;
      }
    }
    return nums.size() + 1;
  }
};

int main() {
  Solution sln;
  vector<vector<int>> nums = {{3, 4, -1, 1}, {1, 2, 0}, {7, 8, 9, 11, 12}};
  for (int i = 0; i < nums.size(); ++i) {
    std::cout << sln.firstMissingPositive(nums[i]) << std::endl;
  }
  return 0;
}
