#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    for (int j = n / 2; j >= 0; j--) {
      adjustDown(nums, j, n);
    }
    for (int i = 0; i < k; ++i) {
      swap(nums, 0, n - i - 1);
      adjustDown(nums, 0, n - i - 1);
    }
    return nums[n - k];
  }

  void swap(vector<int>& nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }

  void adjustDown(vector<int>& nums, int start, int end) {
    if (end <= 1) {
      return;
    }
    int root = start;
    int maxIdx = root;
    while (root >= 0 && root < end) {
      int left = 2 * root + 1;
      int right = 2 * root + 2;
      if (left < end && nums[left] > nums[maxIdx]) {
        maxIdx = left;
      }
      if (right < end && nums[right] > nums[maxIdx]) {
        maxIdx = right;
      }
      if (maxIdx != root) {
        swap(nums, maxIdx, root);
        root = maxIdx;
      } else {
        break;
      }
    }
  }
};

int main() {
  Solution sln;
  vector<int> arr;
  int k;
  arr = {3, 2, 1, 5, 6, 4};
  k = 2;
  cout << sln.findKthLargest(arr, k) << endl;
  arr = {3, 2, 3, 1, 2, 4, 5, 5, 6};
  k = 4;
  cout << sln.findKthLargest(arr, k) << endl;

  return 0;
}