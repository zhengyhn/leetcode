#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int i = 0;
      int j = 0;
      while (i < m && j < n) {
        if (nums2[j] < nums1[i]) {
          int k = m;
          for (; k > i; --k) {
            nums1[k] = nums1[k - 1];
          }
          nums1[k] = nums2[j];
          ++m;
          ++j;
        }
        ++i;
      }
      while (j < n) {
        nums1[i++] = nums2[j++];
      }
    }
};

int main() {
  Solution sln;
  vector<int> nums1 = {1, 2, 4, 0, 0, 0, 0};
  vector<int> nums2 = {1, 3, 4};
  sln.merge(nums1, 3, nums2, 3);
  for (int i: nums1) {
    std::cout << i << std::endl;
  }

  return 0;
}
