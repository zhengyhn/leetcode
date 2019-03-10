#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int search(vector<int>& nums, int target) {
      int size = nums.size();
      int low = 0;
      int high = size - 1;
      while (low <= high) {
        if (low + 1 == high) {
          low = nums[low] < nums[high] ? low : high;
          break;
        }
        int mid = (low + high) / 2;
        if (nums[low] > nums[mid]) {
          high = mid;
        } else if (nums[high] < nums[mid]) {
          low = mid;
        } else {
          break;
        }
      }
      int rotatedLow = low;
      low = 0 + rotatedLow;
      high = size - 1 + rotatedLow;
      while (low <= high) {
        int mid = (low + high) / 2;
        if (target < nums[mid % size]) {
          high = mid - 1;
        } else if (target > nums[mid % size]) {
          low = mid + 1;
        } else {
          return mid % size;
        }
      }
      return -1;
    }
    int search2(vector<int>& nums, int target) {
      int size = nums.size();
      int low = 0;
      int high = size - 1;
      while (low < high) {
        int mid = (low + high) / 2;
        if (nums[high] < nums[mid]) {
          low = mid + 1;
        } else {
          high = mid;
        }
      }
      int rotatedLow = low;
      low = 0 + rotatedLow;
      high = size - 1 + rotatedLow;
      while (low <= high) {
        int mid = (low + high) / 2;
        if (target < nums[mid % size]) {
          high = mid - 1;
        } else if (target > nums[mid % size]) {
          low = mid + 1;
        } else {
          return mid % size;
        }
      }
      return -1;
    }
};

int main() {
  Solution sln;
  vector<int> nums;
  nums = {4, 5, 6, 7, 0, 1, 2};
  std::cout << sln.search2(nums, 0) << std::endl;
  std::cout << sln.search2(nums, 3) << std::endl;
  nums = {8, 0, 1, 2, 3, 4, 5, 6, 7};
  std::cout << sln.search2(nums, 0) << std::endl;
  nums = {3, 5, 1};
  std::cout << sln.search2(nums, 3) << std::endl;
  nums = {5, 1, 3};
  std::cout << sln.search2(nums, 5) << std::endl;
  nums = {};
  std::cout << sln.search2(nums, 3) << std::endl;

  return 0;
}
