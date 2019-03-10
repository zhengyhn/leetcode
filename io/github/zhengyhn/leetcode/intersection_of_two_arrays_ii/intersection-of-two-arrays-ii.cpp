#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ret;
    if (nums1.size() <= 0 || nums2.size() <= 0) {
      return ret;
    }
    vector<int>& left = nums1.size() < nums2.size() ? nums1 : nums2;
    vector<int>& right = nums1.size() < nums2.size() ? nums2 : nums1;
    unordered_map<int, int> map;
    for (int item: left) {
      if (map.find(item) != map.end()) {
        map[item]++;
      } else {
        map[item] = 1;
      }
    }
    for (int item: right) {
      if (map.find(item) != map.end() && map[item] > 0) {
        map[item]--;
        ret.push_back(item);
      }
    }
    return ret;
  }
};

int main() {
  Solution sln;
  // vector<int> nums1 = {1, 2, 2, 1};
  // vector<int> nums2 = {2, 2};
  vector<int> nums1 = {1};
  vector<int> nums2 = {1, 1};
  vector<int> ret = sln.intersect(nums1, nums2);
  for (int item: ret) {
    std::cout << item << std::endl;
  }

  return 0;
}
