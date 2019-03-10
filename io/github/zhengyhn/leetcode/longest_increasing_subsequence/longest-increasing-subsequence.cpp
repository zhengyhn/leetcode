#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int lengthOfLIS(vector<int> &nums)
  {
    if (nums.size() <= 0) {
      return 0;
    }
    int max_len = 1;
    vector<int> dp(nums.size(), 1);
    for (int i = nums.size() - 2; i >= 0; --i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        if (nums[j] > nums[i]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      max_len = max(max_len, dp[i]);
    }
    return max_len;
  }

  int binSearch(vector<int> &minEnds, int low, int high, int key) {
    while (low <= high) {
      int mid = (low + high) / 2;
      if (key <= minEnds[mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return low;
  }
  int lengthOfLIS2(vector<int> &nums)
  {
    if (nums.size() <= 0) {
      return 0;
    }
    vector<int> minEnds(nums.size(), 0);
    minEnds[0] = nums[0];
    int len = 1;
    for (int i = 1; i < nums.size(); ++i) {
      int pos = this->binSearch(minEnds, 0, len - 1, nums[i]);
      minEnds[pos] = nums[i];
      if (pos == len) {
        ++len;
      }
    }
    return len;
  }
};

int main()
{
  Solution sln;
  vector<int> nums;
  nums = {10, 9, 2, 5, 3, 7, 101, 18};
  cout << sln.lengthOfLIS(nums) << endl;
  cout << sln.lengthOfLIS2(nums) << endl;

  return 0;
}