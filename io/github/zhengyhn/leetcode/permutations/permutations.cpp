#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> ret;
      if (nums.size() == 1) {
        ret.push_back(nums);
        return ret;
      }
      for (int i = 0; i < nums.size(); ++i) {
        vector<int> copy(nums);
        copy[i] = copy[copy.size() - 1];
        copy.pop_back();
        vector<vector<int>> result = permute(copy);
        for (int j = 0; j < result.size(); ++j) {
          result[j].insert(result[j].begin(), nums[i]);
          ret.push_back(result[j]);
        }
      }
      return ret;
    }
};

int main() {
  Solution sln;
  vector<int> nums;
  nums = {1, 2, 3};
  vector<vector<int>> ret = sln.permute(nums);
  for (vector<int> row: ret) {
    for (int col: row) {
      cout << col << " ";
    }
    cout << endl;
  }

  return 0;
}
