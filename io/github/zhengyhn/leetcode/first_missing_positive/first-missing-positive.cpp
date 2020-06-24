#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    int ret = 1;
    unordered_set<int> container;

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] <= 0) {
        continue;
      }
      if (nums[i] == ret) {
        for (int j = ret + 1;; ++j) {
          if (container.find(j) == container.end()) {
            ret = j;
            break;
          }
        }
      } else {
        container.insert(nums[i]);
      }
    }
    return ret;
  }
};

int main() {
  Solution sln;
  // vector<int> nums = {3, 4, -1, 1};
  // vector<int> nums = {1, 2, 0};
  vector<int> nums = {7, 8, 9, 11, 12};
  std::cout << sln.firstMissingPositive(nums) << std::endl;

  return 0;
}
