#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
  public:
    int rob(vector<int>& nums) {
      if (nums.size() == 0) {
        return 0;
      }
      int cache[nums.size()];
      for (int i = 0; i < nums.size(); ++i) {
        cache[i] = 0;
      }
      for (int i = nums.size() - 1; i >= 0; --i) {
        cache[i] = nums[i];
        if (i + 2 < nums.size()) {
          cache[i] = nums[i] + cache[i + 2];
        }
        if (i + 1 < nums.size() && cache[i + 1] > cache[i]) {
          cache[i] = cache[i + 1];
        }
      }
      return cache[0];
    }
};

int main() {
  Solution sln;
  // vector<int> nums = {1, 2, 0, 3, 0};
  // vector<int> nums = {1, 3, 1};
  vector<int> nums = {114,117,207,117,235,82,90,67,143,146,53,108,200,91,80,223,58,170,110,236,81,90,222,160,165,195,187,199,114,235,197,187,69,129,64,214,228,78,188,67,205,94,205,169,241,202,144,240};
  // vector<int> nums = {114,117,207,117,235,82,90,67,143,146,53,108,200,91,80,223,58,170,110,236,81,90,222,160,165,195,187,199,114,235,197,187,69,129,64,214,228,78,188};
    std::cout << sln.rob(nums) << std::endl;

  return 0;
}
