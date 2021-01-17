#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int findDuplicate(vector<int>& nums) {
      int turtle = 0;
      int rabbit = 0;
      int entry = 0;
      for (int i = 0; i < nums.size(); ++i) {
        turtle = nums[turtle];
        rabbit = nums[nums[rabbit]];
        if (turtle == rabbit) {
          for (int j = 0; j < nums.size(); ++j) {
            entry = nums[entry];
            turtle = nums[turtle];
            if (entry == turtle) {
              return entry;
            }
          }
        }
      }
      return 0;
    }
};

int main() {
  Solution sln;
  // vector<int> nums = {1, 4, 3, 4, 2};
  vector<int> nums = {1, 1};
  // vector<int> nums = {2, 2, 1, 3, 4};
  std::cout << sln.findDuplicate(nums) << std::endl;

  return 0;
}
