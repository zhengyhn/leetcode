#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
  public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      set<vector<int>> retSet;
      if (nums.size() == 1) {
        vector<vector<int>> ret = {nums};
        return ret;
      }
      for (int i = 0; i < nums.size(); ++i) {
        vector<int> copy(nums);
        copy[i] = copy[copy.size() - 1];
        copy.pop_back();
        vector<vector<int>> result = permuteUnique(copy);
        for (int j = 0; j < result.size(); ++j) {
          result[j].insert(result[j].begin(), nums[i]);
          retSet.insert(result[j]);
        }
      }
      vector<vector<int>> ret(retSet.size());
      int i = 0;
      for (set<vector<int>>::iterator it = retSet.begin(); it != retSet.end(); ++it) {
        ret[i++] = *it;
      }
      return ret;
    }

    vector<vector<int>> permuteUnique2(vector<int>& nums) {
      vector<vector<int>> ret;
      sort(nums.begin(), nums.end());
      ret.push_back(nums);

      while (true) {
        int i = nums.size() - 1;
        for (; i > 0; --i) {
          if (nums[i] > nums[i - 1]) {
            break;
          }
        }
        if (i == 0) {
          break;
        }
        int j = nums.size() - 1;
        for (; j >= i; --j) {
          if (nums[j] > nums[i - 1]) {
            break;
          }
        }
        swap(nums[j], nums[i - 1]);
        recursive(nums, i, nums.size() - 1);
        ret.push_back(nums);
      }
      return ret;
    }

    void recursive(vector<int>& nums, int begin, int end) {
      while (begin < end) {
        swap(nums[begin++], nums[end--]);
      }
    }
};

int main() {
  Solution sln;
  vector<int> nums;
  // nums = {1, 1, 1, 1, 2};
  nums = {1, 2, 3};
  vector<vector<int>> ret = sln.permuteUnique2(nums);
  for (vector<int> row: ret) {
    for (int col: row) {
      cout << col << " ";
    }
    cout << endl;
  }

  return 0;
}
