#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int removeElement(vector<int>& nums, int val) {
      if (nums.size() <= 0) {
        return 0;
      }
      int begin = 0;
      int end = nums.size() - 1;
      while (begin <= end) {
        if (nums[begin] == val) {
          nums[begin] = nums[end];
          --end;
        } else {
          ++begin;
        }
      }
      return end + 1;
    }
};

int main() {
  Solution sln;
  vector<int> nums;
  nums = {1, 1, 2};
  std::cout << sln.removeElement(nums, 1) << std::endl;
  for (int item: nums) {
    std::cout << item << std::endl;
  }
  nums = {1, 1, 2, 3, 4, 4};
  std::cout << sln.removeElement(nums, 4) << std::endl;
  for (int item: nums) {
    std::cout << item << std::endl;
  }
  nums = {};
  std::cout << sln.removeElement(nums, 0) << std::endl;
  nums = {2};
  std::cout << sln.removeElement(nums, 2) << std::endl;

  return 0;
}
