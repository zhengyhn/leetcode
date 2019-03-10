#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
      for (int i = 0; i < nums.size() - 1; ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
          if (nums[i] + nums[j] == target) {
            int arr[2] = {i, j};
            vector<int> vec(arr, arr + 2);
            return vec;
          }
        }
      }
    }
};

int main() {
  Solution sln;
  const int size = 3;
  int arr[size] = {3, 2, 3};
  std::vector<int> vec(arr, arr + size);
  vector<int> result = sln.twoSum(vec, 6);
  for (int i = 0; i < result.size(); ++i) {
    std::cout << result[i] << std::endl;
  }

  return 0;
}
