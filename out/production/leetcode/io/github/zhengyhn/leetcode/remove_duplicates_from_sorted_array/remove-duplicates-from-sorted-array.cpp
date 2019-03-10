#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int removeDuplicatesOld(vector<int>& nums) {
      if (nums.size() <= 1) {
        return nums.size();
      }
      int now = nums[0];
      for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != now) {
          now = nums[i];
        } else {
          nums.erase(nums.begin() + i);
          --i;
        }
      }
      return nums.size();
    }

    int removeDuplicates(vector<int>& nums) {
      if (nums.size() <= 1) {
        return nums.size();
      }
      int begin = 0;
      for (int end = 1; end < nums.size(); ++end) {
        if (nums[begin] != nums[end]) {
          ++begin;
          nums[begin] = nums[end];
        }
      }
      return begin + 1;
    }
};

int main() {
  Solution sln;
  vector<int> nums;
  nums = {1, 1, 2};
  std::cout << sln.removeDuplicates(nums) << std::endl;
  for (int item: nums) {
    std::cout << item << std::endl;
  }
  nums = {1, 1, 2, 3, 4, 4};
  std::cout << sln.removeDuplicates(nums) << std::endl;
  for (int item: nums) {
    std::cout << item << std::endl;
  }
  nums = {};
  std::cout << sln.removeDuplicates(nums) << std::endl;
  nums = {2};
  std::cout << sln.removeDuplicates(nums) << std::endl;

  return 0;
}
