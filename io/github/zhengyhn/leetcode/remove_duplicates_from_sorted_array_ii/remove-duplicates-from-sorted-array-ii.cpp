#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
      if (nums.size() <= 2) {
        return nums.size();
      }
      int cur = nums[0];
      int curCount = 1;
      int iStart = 1;
      int iEnd = iStart;
      for (; iStart < nums.size(); ++iStart) {
        if (nums[iStart] == cur) {
          if (curCount == 1) {
            ++curCount;
          } else {
            while (iEnd < nums.size() && nums[iEnd] == nums[iStart]) {
              ++iEnd;
            }
            if (iEnd >= nums.size()) {
              return iStart;
            }
            swap(nums[iStart], nums[iEnd]);
            cur = nums[iStart];
            curCount = 1;
          }
        } else if (nums[iStart] < cur) {
          if (curCount == 2) {
            while (iEnd < nums.size() && nums[iEnd] <= cur) {
              ++iEnd;
            }
          } else {
            iEnd += 1;
          }
          if (iEnd >= nums.size()) {
            return iStart;
          }
          swap(nums[iStart], nums[iEnd]);
          if (nums[iStart] == cur) {
            ++curCount;
          } else {
            cur = nums[iStart];
            curCount = 1;
          }
        } else {
          cur = nums[iStart];
          curCount = 1;
        }
        if (iEnd <= iStart) {
          ++iEnd;
        }
      }
      return iStart;
    }

    int removeDuplicates2(vector<int>& nums) {
      if (nums.size() <= 2) {
        return nums.size();
      }
      int iStart = 1;
      int iEnd = iStart;
      int cur = nums[0];
      int curCount = 1;
      while (iEnd < nums.size()) {
        if (nums[iStart] == cur) {
          if (curCount == 1) {
            ++curCount;
            // nums[iStart + 1] = nums[iEnd];
          } else {
            while (iEnd < nums.size() && nums[iEnd] == cur) {
              ++iEnd;
            }
            if (iEnd >= nums.size()) {
              return iStart;
            }
            nums[iStart] = nums[iEnd];
            cur = nums[iEnd];
            curCount = 1;
          }
        } else {
          // nums[iStart] = nums[iEnd];
          cur = nums[iEnd];
          curCount = 1;
        }
        ++iStart;
        ++iEnd;
        if (iEnd < nums.size()) {
          nums[iStart] = nums[iEnd];
        }
      }
      return iStart;
    }

    int removeDuplicates3(vector<int>& nums) {
      if (nums.size() <= 2) {
        return nums.size();
      }
      int iStart = 0;
      int iEnd = iStart + 1;
      int cur = nums[0];
      int curCount = 1;
      while (iEnd < nums.size()) {
        if (nums[iEnd] == cur) {
          if (curCount == 1) {
            nums[++iStart] = nums[iEnd];
            ++curCount;
          }
        } else {
          nums[++iStart] = nums[iEnd];
          cur = nums[iEnd];
          curCount = 1;
        }
        ++iEnd;
      }
      return iStart + 1;
    }

    int removeDuplicates4(vector<int>& nums) {
      int iStart = 0;
      int iEnd = 0;
      while (iEnd < nums.size()) {
        if (iStart < 2 || nums[iEnd] > nums[iStart - 2]) {
          nums[iStart++] = nums[iEnd];
        }
        ++iEnd;
      }
      return iStart;
    }
};

int main() {
  Solution sln;
  vector<int> nums;
  nums = {1, 1, 1, 2, 2, 3};
  cout << sln.removeDuplicates4(nums) << endl;
  for (int num: nums) {
    cout << num << endl;
  }
  cout << endl;
  nums = {0, 0, 1, 1, 1, 2, 2, 2, 3, 3};
  cout << sln.removeDuplicates4(nums) << endl;
  for (int num: nums) {
    cout << num << endl;
  }
  return 0;
}
