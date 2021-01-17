#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int singleNumber(vector<int>& nums) {
      int result = 0;
      for (int num: nums) {
        result ^= num;
      }
      return result;
    }
};

int main() {
  Solution sln;
  vector<int> nums;
  nums = {2, 2, 1};
  std::cout << sln.singleNumber(nums) << std::endl;

  nums = {4, 1, 2, 1, 2};
  std::cout << sln.singleNumber(nums) << std::endl;

  return 0;
}
