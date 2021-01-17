#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
  public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
      vector<int> ret(findNums.size(), -1);
      for (int i = 0; i < findNums.size(); ++i) {
        int j = 0;
        for (; j < nums.size(); ++j) {
          if (nums[j] == findNums[i]) {
            break;
          }
        }
        ++j;
        for (; j < nums.size(); ++j) {
          if (nums[j] > findNums[i]) {
            ret[i] = nums[j];
            break;
          }
        }
      }
      return ret;
    }
    vector<int> nextGreaterElement2(vector<int>& findNums, vector<int>& nums) {
      if (findNums.size() <= 0) {
        return {};
      }
      if (nums.size() <= 0) {
        return vector<int>(findNums.size(), -1);
      }
      vector<int> ret(findNums.size(), -1);
      unordered_map<int, int> retMap;
      unordered_map<int, int> map;
      for (int i = 0; i < nums.size(); ++i) {
        map[nums[i]] = i;
        retMap[nums[i]] = -2;
      }
      for (int i = 0; i < findNums.size(); ++i) {
        int j = map[findNums[i]] + 1;
        for (; j < nums.size(); ++j) {
          // cout << j << " " << nums[j] << " " << findNums[i] << " " << retMap[nums[j]] << endl;
          if (nums[j] > findNums[i]) {
            retMap[findNums[i]] = j;
            ret[i] = nums[j];
            break;
          } else if (nums[j] < findNums[i]) {
            if (retMap[nums[j]] == -1) {
              retMap[findNums[i]] = -1;
              ret[i] = -1;
              break;
            } else if (retMap[nums[j]] != -2) {
              j = retMap[nums[j]] - 1;
            }
          }
        }
        if (j == nums.size()) {
          retMap[findNums[i]] = -1;
          ret[i] = -1;
        }
      }
      return ret;
    }

    vector<int> nextGreaterElement3(vector<int>& findNums, vector<int>& nums) {
      if (findNums.size() <= 0) {
        return {};
      }
      if (nums.size() <= 0) {
        return vector<int>(findNums.size(), -1);
      }
      vector<int> ret(findNums.size(), -1);
      unordered_map<int, int> map;
      stack<int> st;
      for (int i = 0; i < nums.size(); ++i) {
        while (!st.empty() && nums[i] > st.top()) {
          map[st.top()] = nums[i];
          st.pop();
        }
        st.push(nums[i]);
      }
      for (int i = 0; i < findNums.size(); ++i) {
        if (map.count(findNums[i]) > 0) {
          ret[i] = map[findNums[i]];
        }
      }
      return ret;
    }
};

int main() {
  Solution sln;
  vector<int> findNums;
  vector<int> nums;
  vector<int> ret;
  findNums = {3, 1, 5, 7, 9, 2, 6};
  nums = {1, 2, 3, 5, 6, 7, 9, 11};
  ret = sln.nextGreaterElement3(findNums, nums);
  for (int item: ret) {
    cout << item << " ";
  }
  cout << endl;

  findNums = {4, 1, 2};
  nums = {1, 3, 4, 2};
  ret = sln.nextGreaterElement3(findNums, nums);
  for (int item: ret) {
    cout << item << " ";
  }
  cout << endl;

  return 0;
}
