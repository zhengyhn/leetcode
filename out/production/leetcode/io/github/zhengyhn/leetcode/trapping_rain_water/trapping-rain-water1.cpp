#include <iostream>
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
    vector<int> left_max = vector<int>(size);
    vector<int> right_max = vector<int>(size);
    left_max[0] = height[0];
    right_max[size - 1] = height[size - 1];

    for (int i = 1; i < size - 1; ++i) {
      left_max[i] = max(left_max[i - 1], height[i]);
    }
    for (int i = size - 2; i > 0; --i) {
      right_max[i] = max(right_max[i + 1], height[i]);
    }
    for (int i = 1; i < size - 1; ++i) {
      int min_h = min(left_max[i - 1], right_max[i + 1]);
      if (min_h > height[i]) {
        ret += min_h - height[i];
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