#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int searchInsert(vector<int>& nums, int target) {
      if (nums.size() <= 0) {
        return 0;
      }
      int low = 0;
      int high = nums.size() - 1;
      while (low <= high) {
        int mid = (low + high) / 2;
        if (target == nums[mid]) {
          return mid;
        } else if (target < nums[mid]) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      }
      return low;
    }
};

int main(void) {
  Solution sln;
  vector<int> nums;
  std::cout << sln.searchInsert(nums, 1) << std::endl;
  nums = {1, 3, 5, 6};
  std::cout << sln.searchInsert(nums, 5) << std::endl;
  std::cout << sln.searchInsert(nums, 2) << std::endl;
  std::cout << sln.searchInsert(nums, 7) << std::endl;
  std::cout << sln.searchInsert(nums, 0) << std::endl;

  return 0;
}
