#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void nextPermutation(vector<int>& nums) {
      int i = nums.size() - 1;
      for (; i > 0; --i) {
        if (nums[i - 1] < nums[i]) {
          break;
        }
      }
      if (i > 0) {
        int j = nums.size() - 1;
        for (; j >= i; --j) {
          if (nums[j] > nums[i - 1]) {
            break;
          }
        }
        swap(nums[j], nums[i - 1]);
      }
      int end = nums.size() - 1;
      while (i < end) {
        swap(nums[i++], nums[end--]);
      }
    }

    void swap(int& a, int& b) {
      int temp = a;
      a = b;
      b = temp;
    }
};

int main() {
  Solution sln;
  vector<int> nums;
  nums = {1, 2, 3};
  sln.nextPermutation(nums);
  for (int num: nums) {
    cout << num << " ";
  }
  cout << endl;

  nums = {3, 2, 1};
  sln.nextPermutation(nums);
  for (int num: nums) {
    cout << num << " ";
  }
  cout << endl;

  nums = {1, 1, 5};
  sln.nextPermutation(nums);
  for (int num: nums) {
    cout << num << " ";
  }
  cout << endl;

  nums = {1, 3, 5, 2, 4};
  sln.nextPermutation(nums);
  for (int num: nums) {
    cout << num << " ";
  }
  cout << endl;

  nums = {1, 2};
  sln.nextPermutation(nums);
  for (int num: nums) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
