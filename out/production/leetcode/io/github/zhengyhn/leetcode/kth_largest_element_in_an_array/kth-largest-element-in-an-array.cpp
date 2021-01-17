#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
  }
};

int main() {
  Solution sln;
  vector<int> arr;
  arr = {3, 2, 1, 5, 6, 4};
  cout << sln.findKthLargest(arr, 2) << endl;

  return 0;
}