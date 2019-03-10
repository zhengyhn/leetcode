#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void sortColors(vector<int>& nums) {
      int zeroStart = -1, oneStart = -1, twoStart = -1;
      int zeroCount = 0, oneCount = 0, twoCount = 0;
      for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 0) {
          ++zeroCount;
          if (zeroStart == -1) {
            ++zeroStart;
          }
          nums[zeroStart + zeroCount - 1] = 0;
          if (oneStart != -1) {
            ++oneStart;
            nums[oneStart + oneCount - 1] = 1;
          }
          if (twoStart != -1) {
            ++twoStart;
            nums[twoStart + twoCount - 1] = 2;
          }
        } else if (nums[i] == 1) {
          ++oneCount;
          if (oneStart == -1) {
            oneStart = zeroStart == -1 ? 0 : zeroStart + zeroCount;
          }
          nums[oneStart + oneCount - 1] = 1;
          if (twoStart != -1) {
            ++twoStart;
            nums[twoStart + twoCount - 1] = 2;
          }
        } else if (nums[i] == 2) {
          ++twoCount;
          if (twoStart == -1) {
            twoStart = oneStart == -1 ? (zeroStart == -1 ? 0 : zeroStart + zeroCount) : oneStart + oneCount;
          }
          nums[twoStart + twoCount - 1] = 2;
        }
      }
    }
};

int main() {
  Solution sln;
  vector<int> nums;
  nums = {2,0,2,1,1,0};
  sln.sortColors(nums);
  for (int num: nums) {
    cout << num << " ";
  }
  cout << endl;
  nums = {};
  for (int i = 0; i < 100; ++i) {
    nums.push_back(rand() % 3);
  }
  sln.sortColors(nums);
  for (int num: nums) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
