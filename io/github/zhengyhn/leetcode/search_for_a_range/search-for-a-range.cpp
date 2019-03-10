#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> searchRange(vector<int>& nums, int target) {
      int startIdx = -1;
      int low = 0;
      int high = nums.size() - 1;
      while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] < target) {
          low = mid + 1;
        } else if (nums[mid] > target) {
          high = mid - 1;
        } else {
          startIdx = mid;
          high = mid - 1;
        }
      }
      vector<int> ret = {-1, -1};
      if (startIdx == -1) {
        return ret;
      } else {
        ret[0] = startIdx;
      }
      int endIdx = startIdx;
      low = startIdx;
      high = nums.size() - 1;
      while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] < target) {
          low = mid + 1;
        } else if (nums[mid] > target) {
          high = mid- 1;
        } else {
          endIdx = mid;
          low = mid + 1;
        }
      }
      ret[1] = endIdx;

      return ret;
    }
};

int main() {
  Solution sln;
  vector<int> nums;
  vector<int> ret;
  // nums = {5, 7, 7, 8, 8, 10};
  nums = {1, 2, 2, 2, 2, 3, 3, 3, 3};
  ret = sln.searchRange(nums, 2);
  // ret = sln.searchRange(nums, 6);
  for (int item: ret) {
    std::cout << item << " ";
  }
  std::cout << std::endl;

  return 0;
}
