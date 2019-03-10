#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
  public:
    vector<int> findDuplicates(vector<int>& nums) {
      vector<int> ret;
      for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > 0 && nums[i] != (i + 1)) {
          if (nums[nums[i] - 1] == nums[i]) {
            ret.push_back(nums[i]);
            nums[i] = 0;
          } else {
            int temp = nums[i];
            nums[i] = nums[nums[i] - 1];
            nums[temp - 1] = temp;
            --i;
          }
        }
      }
      return ret;
    }

    vector<int> findDuplicates2(vector<int>& nums) {
      vector<int> ret;
      for (int i = 0; i < nums.size(); ++i) {
        nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        if (nums[abs(nums[i]) - 1] > 0) {
          ret.push_back(abs(nums[i]));
        }
      }
      return ret;
    }
};

int main() {
  Solution sln;
  // vector<int> nums = {4,3,2,7,8,2,3,1};
  vector<int> nums = {4,3,2,4,3,2,5,1};
  vector<int> ret = sln.findDuplicates2(nums);
  for (int item: ret) {
    std::cout << item << std::endl;
  }

  return 0;
}
