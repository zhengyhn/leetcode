#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  int trap(vector<int>& height) {
    int size = height.size();
    if (size < 3) {
      return 0;
    }
    int ret = 0;
    int left = 0, right = size - 1, left_most = 0, right_most = 0;
    while (left < right) {
      if (height[left] < height[right]) {
        if (height[left] >= left_most) {
          left_most = height[left];
        } else {
          ret += left_most - height[left];
        }
        ++left;
      } else {
        if (height[right] >= right_most) {
          right_most = height[right];
        } else {
          ret += right_most - height[right];
        }
        --right;
      }
    }
    return ret;
  }
};

int main() {
  Solution sln;
  vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << sln.trap(arr) << endl;

  return 0;
}