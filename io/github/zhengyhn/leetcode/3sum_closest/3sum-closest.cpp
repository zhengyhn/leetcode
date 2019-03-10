#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int threeSumClosest(vector<int>& nums, int target) {
      if (nums.size() < 3) {
        return 0;
      }
      sort(nums.begin(), nums.end());
      int ret = -0xffff;
      for (int i = 0; i < nums.size() - 2; ++i) {
        for (int j = i + 1; j < nums.size() - 1; ++j) {
          for (int k = j + 1; k < nums.size(); ++k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (abs(sum - target) <= abs(ret - target)) {
              ret = sum;
              if (sum > target && nums[i] >= target) {
                return ret;
              }
            } else if (sum > target) {
              break;
            }
          }
        }
      }
      return ret;
    }
    int threeSumClosest2(vector<int>& nums, int target) {
      if (nums.size() < 3) {
        return 0;
      }
      sort(nums.begin(), nums.end());
      int ret = -0xffff;
      for (int i = 0; i < nums.size() - 2; ++i) {
        for (int j = i + 1; j < nums.size() - 1; ++j) {
          int low = j + 1;
          int high = nums.size() - 1;
          int val = target - nums[i] - nums[j];
          int found = nums[low];
          while (low <= high) {
            int mid = (low + high) / 2;
            if (abs(val - nums[mid]) < abs(val - found)) {
              found = nums[mid];
            }
            if (nums[mid] < val) {
              low = mid + 1;
            } else if (nums[mid] > val) {
              high = mid - 1;
            } else {
              return target;
            }
          }
          int sum = nums[i] + nums[j] + found;
          // cout << nums[i] << " " << nums[j]  << " " << found << endl;
          if (abs(sum - target) < abs(ret - target)) {
            ret = sum;
          }
        }
      }
      return ret;
    }
    int threeSumClosest3(vector<int>& nums, int target) {
      if (nums.size() < 3) {
        return 0;
      }
      sort(nums.begin(), nums.end());
      int ret = nums[0] + nums[1] + nums[2];
      for (int i = 0; i < nums.size() - 2; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) {
          continue;
        }
        if (3 * nums[i] > target) {
          int sum = nums[i] + nums[i + 1] + nums[i + 2];
          if (abs(sum - target) < abs(ret - target)) {
            return sum;
          }
        }
        int second = i + 1;
        int third = nums.size() - 1;
        while (second < third) {
          int sum = nums[i] + nums[second] + nums[third];
          if (abs(sum - target) < abs(ret - target)) {
            ret = sum;
          }
          if (sum < target) {
            ++second;
          } else if (sum > target) {
            --third;
          } else {
            return target;
          }
        }
      }
      return ret;
    }
};
int main() {
  Solution sln;
  vector<int> nums;
  nums = {-1, 0, 1, 1, 55};
  cout << sln.threeSumClosest(nums, 3) << endl;
  cout << sln.threeSumClosest2(nums, 3) << endl;
  cout << sln.threeSumClosest3(nums, 3) << endl;

  return 0;
}
