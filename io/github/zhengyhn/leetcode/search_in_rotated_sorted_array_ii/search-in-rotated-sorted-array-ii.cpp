#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
  public:
    bool search(vector<int>& nums, int target) {
      int iStart = nums.size() - 1;
      while (iStart > 0 && nums[iStart] >= nums[iStart - 1]) {
        --iStart;
      }
      int iEnd = iStart + nums.size() - 1;
      while (iStart <= iEnd) {
        int mid = (iStart + iEnd) / 2;
        if (nums[mid % nums.size()] < target) {
          iStart = mid + 1;
        } else if (nums[mid % nums.size()] > target) {
          iEnd = mid - 1;
        } else {
          return true;
        }
      }
      return false;
    }
};

int main() {
  Solution sln;
  vector<int> nums;
  nums = {2,5,6,0,0,1,2};
  cout << sln.search(nums, 0) << endl;
  cout << sln.search(nums, 3) << endl;

  return 0;
}
