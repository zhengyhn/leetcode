#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int maxArea(vector<int>& height) {
      int max = 0;
      for (int i = 0; i < height.size() - 1; ++i) {
        for (int j = i + 1; j < height.size(); ++j) {
          int min = this->min(height[i], height[j]);
          // std::cout << "min:" << min << " " << min * (j - i) << " " << max << std::endl;
          if (min * (j - i) > max) {
            max = min * (j - i);
          }
        }
      }
      return max;
    }

    int maxArea2(vector<int>& height) {
      int max = 0;
      int i = 0;
      int j = height.size() - 1;
      while (i < j) {
        int min = this->min(height[i], height[j]);
        // std::cout << "min:" << min << " " << min * (j - i) << " " << max << std::endl;
        if (min * (j - i) > max) {
          max = min * (j - i);
        }
        if (min == height[i]) {
          ++i;
        } else if (min == height[j]) {
          --j;
        }
      }
      return max;
    }

    int min(int left, int right) {
      return left < right ? left : right;
    }
};

int main() {
  Solution sln;
  vector<int> height;
  height = {1, 1};
  std::cout << sln.maxArea(height) << std::endl;
  std::cout << sln.maxArea2(height) << std::endl;
  height = {1, 2, 3};
  std::cout << sln.maxArea(height) << std::endl;
  std::cout << sln.maxArea2(height) << std::endl;
  height = {1, 2, 3, 2, 10, 6};
  std::cout << sln.maxArea(height) << std::endl;
  std::cout << sln.maxArea2(height) << std::endl;
  height = {1, 2, 1};
  std::cout << sln.maxArea(height) << std::endl;
  std::cout << sln.maxArea2(height) << std::endl;
  height = {3, 2, 1, 3};
  std::cout << sln.maxArea(height) << std::endl;
  std::cout << sln.maxArea2(height) << std::endl;

  return 0;
}
