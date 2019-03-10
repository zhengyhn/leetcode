#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int maxCoinsOld(vector<int>& nums) {
      if (nums.size() == 0) {
        return 0;
      }
      if (nums.size() == 1) {
        return nums[0];
      }
      vector<int> left(nums.size(), -1);
      vector<int> right(nums.size(), -1);
      for (int i = 0; i < nums.size(); ++i) {
        left[i] = i - 1;
        right[i] = i + 1 < nums.size() ? i + 1 : -1;
      }
      int maxCoins = 0;
      for (int i = 0; i < nums.size(); ++i) {
        int max = 0;
        int maxIndex = i;
        for (int j = 0; j < nums.size(); ++j) {
          if (nums[j] == -1) {
            continue;
          }
          int leftValue = left[j] >= 0 ? nums[left[j]] : 1;
          int rightValue = right[j] >= 0 ? nums[right[j]] : 1;
          if (leftValue * rightValue > max) {
            max = leftValue * rightValue;
            maxIndex = j;
          }
        }
        std::cout << maxIndex << " " << max << std::endl;
        maxCoins += max * nums[maxIndex];
        if (right[maxIndex] >= 0) {
          left[right[maxIndex]] = left[maxIndex];
        }
        if (left[maxIndex] >= 0) {
          right[left[maxIndex]] = right[maxIndex];
        }
        nums[maxIndex] = -1;
      }
      return maxCoins;
    }

    int maxCoins(vector<int>& nums) {
      string str(nums.size(), '0');
      for (int i = 0; i < nums.size(); ++i) {
        str[i] = nums[i];
      }
      return this->robot(str);
    }

    int robot(string& str) {
      if (str.size() == 0) {
        return 0;
      }
      if (str.size() == 1) {
        return str[0] - '0';
      }
      int max = 0;
      for (int i = 0; i < str.size(); ++i) {
        string temp(str);
        temp.erase(temp.begin() + i);
        int coins = this->robot(temp);
        int left = i - 1 >= 0 ? str[i - 1] - '0' : 1;
        int right = i + 1 < str.size() ? str[i + 1] - '0' : 1;
        coins += left * (str[i] - '0') * right;
        if (coins > max) {
          max = coins;
        }
      }
      return max;
    }
};

int main() {
  Solution sln;
  // vector<int> nums = {3, 1, 5, 8};
  // vector<int> nums = {9,76,64,21,97,60};
  vector<int> nums = {35,16,83,87,84,59,48,41,20};
  // vector<int> nums = {1, 99, 1};
  std::cout << sln.maxCoins(nums) << std::endl;

  return 0;
}
