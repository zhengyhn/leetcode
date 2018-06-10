#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
      if (nums.size() == 2) {
        return nums[0] < nums[1] ? nums[0] : nums[1];
      }
      std::sort(nums.begin(), nums.end());
      int sum = 0;
      for (int i = 0; i < nums.size(); i += 2) {
        sum += nums[i];
      }
      return sum;
    }

    int arrayPairSumBucketSort(vector<int>& nums) {
      vector<int> bucket(10000 * 2 + 1, 0);
      int lower = 10000 * 2;
      for (int i = 0; i < nums.size(); ++i) {
        bucket[nums[i] + 10000] += 1;
        if (nums[i] + 10000 < lower) {
          lower = nums[i] + 10000;
        }
      }

      int count = 0;
      int sum = 0;
      bool skip = false;
      while (count < nums.size() / 2) {
        if (bucket[lower] > 0 && !skip) {
          sum += lower - 10000;
          skip = true;
          ++count;
          bucket[lower]--;
        } else if (bucket[lower] > 0 && skip) {
          skip = false;
          bucket[lower]--;
        } else {
          ++lower;
        }
      }
      return sum;
    }
};

int main() {
  Solution sln;

  const int length = 4;
  int arr[length] = {1, 1, 1, 1};
  std::vector<int> vec(arr, arr + length);
  std::cout << sln.arrayPairSum(vec) << std::endl;
  std::cout << sln.arrayPairSumBucketSort(vec) << std::endl;

  return 0;
}
