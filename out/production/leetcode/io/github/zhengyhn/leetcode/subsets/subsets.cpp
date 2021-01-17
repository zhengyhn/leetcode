#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> ret;
      ret.push_back({});
      if (nums.size() <= 0) {
        return ret;
      }
      vector<int> stack;
      sort(nums.begin(), nums.end());
      stack.push_back(0);
      while (!stack.empty()) {
        int top = stack.back();
        vector<int> temp(stack.size());
        for (int i = 0; i < stack.size(); ++i) {
          temp[i] = nums[stack[i]];
        }
        ret.push_back(temp);
        if (top < nums.size() - 1) {
          stack.push_back(++top);
        } else {
          while (!stack.empty() && top >= nums.size() - 1) {
            stack.pop_back();
            top = stack.back();
          }
          if (!stack.empty()) {
            ++stack[stack.size() - 1];
          }
        }
      }
      return ret;
    }
};

int main() {
  Solution sln;
  vector<int> nums;
  nums = {1, 2, 3, 5, 4};
  vector<vector<int>> ret;
  ret = sln.subsets(nums);
  for (auto row: ret) {
    for (auto col: row) {
      cout << col << "_";
    }
    cout << endl;
  }

  return 0;
}
