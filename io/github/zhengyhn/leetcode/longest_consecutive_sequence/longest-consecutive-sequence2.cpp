#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> map;
    unordered_map<int, int> pos;
    int ret = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (pos.find(nums[i]) != pos.end()) {
        continue;
      }
      pos[nums[i]] = i;
      map[nums[i]] = -1;
      int j = nums[i] + 1;
      if (map.find(j) != map.end()) {
        map[nums[i]] += map[j];
        map[j] = pos[nums[i]];
        ++j;
      }
      ret = max(ret, -map[nums[i]]);
      j = nums[i] - 1;
      while (map.find(j) != map.end()) {
        if (map[j] >= 0) {
          j = nums[map[j]];
          continue;
        }
        map[j] += map[nums[i]];
        map[nums[i]] = pos[j];
        int k = nums[i] - 1;
        while (map[k] >= 0) {
          int t = k;
          k = nums[map[k]];
          map[t] = pos[j];
        }
        ret = max(ret, -map[j]);
        break;
      }
    }
    return ret;
  }
};

int main() {
  Solution sln;
  // const int size = 6;
  // int arr[size] = {100, 4, 200, 1, 3, 2};
  const int size = 7;
  int arr[size] = {100, 0, 99, 101, 1, 3, 2};
  vector<int> vec(arr, arr + size);
  std::cout << sln.longestConsecutive(vec) << std::endl;

  return 0;
}
