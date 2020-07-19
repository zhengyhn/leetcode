#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int trap(vector<int>& height) {
    if (height.size() < 3) {
      return 0;
    }
    int ret = 0;
    for (int i = 1; i < height.size() - 1; ++i) {
      if (height[i] > height[i - 1]) {
        continue;
      }
      int j = i + 1;
      int max = height[i];
      for (; j < height.size(); ++j) {
        if (height[j] >= height[i - 1]) {
          for (int k = i; k < j; ++k) {
            ret += height[i - 1] - height[k];
          }
          i = j;
          break;
        } else if (height[j] > max) {
          max = height[j];
        }
      }
      if (j == height.size() && max > height[i]) {
        int k = i;
        for (; k < j; ++k) {
          if (height[k] == max) {
            break;
          } else {
            ret += max - height[k];
          }
        }
        i = k;
      }
    }
    return ret;
  }
};

int main() {
  Solution sln;
  vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << sln.trap(arr) << endl;

  return 0;
}