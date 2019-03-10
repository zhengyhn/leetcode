#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> hash;
      for (int i = 0; i < nums.size(); ++i) {
        hash.insert(std::pair<int, int>(nums[i], i));
      }
      for (int i = 0; i < nums.size(); ++i) {
        if ((hash.find(target - nums[i]) != hash.end()) && (hash[target - nums[i]] != i)) {
          int arr[2] = {i, hash[target - nums[i]]};
          vector<int> vec(arr, arr + 2);
          return vec;
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
