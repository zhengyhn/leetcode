#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
  public:
    int maxSubArray(vector<int>& nums) {
      if (nums.size() == 1) {
        return nums[0];
      }
      int result = -pow(2, 31);
      for (int i = 0; i < nums.size(); ++i) {
        int sum = 0;
        for (int j = i + 1; j < nums.size(); ++j) {
          sum += nums[j];
          if (sum > result) {
            result = sum;
          }
        }
      }
      return result; 
    }

    int maxSubArray2(vector<int>& nums) {
      int result = -pow(2, 31);
      int sum = 0;
      int minSum = 0;
      for (int i = 0; i < nums.size(); ++i) {
        if (sum < minSum) {
          minSum = sum;
        }
        sum += nums[i];
        if ((sum - minSum) > result) {
          result = sum - minSum;
        }
      }
      return result; 
    }

    int maxSubArray3(vector<int>& nums) {
      int result = nums[0];
      int *max = new int[nums.size()];
      max[0] = nums[0];
      for (int i = 1; i < nums.size(); ++i) {
        if (max[i - 1] > 0) {
          max[i] = max[i - 1] + nums[i];
        } else {
          max[i] = nums[i];
        }
        if (max[i] > result) {
          result = max[i];
        }
      }
      return result; 
    }
};

int main() {
  Solution sln;
  const int length = 9;
  int arr[length] = {-2,1,-3,4,-1,2,1,-5,4};
  std::vector<int> vec(arr, arr + length);
  std::cout << sln.maxSubArray(vec) << std::endl;
  std::cout << sln.maxSubArray2(vec) << std::endl;
  std::cout << sln.maxSubArray3(vec) << std::endl;

  return 0;
}
