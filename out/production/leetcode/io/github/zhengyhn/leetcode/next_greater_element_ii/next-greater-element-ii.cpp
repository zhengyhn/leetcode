#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
  public:
    vector<int> nextGreaterElements(vector<int>& nums) {
      vector<int> ret(nums.size(), -1);
      vector<int> st;
      for (int i = 0; i < nums.size(); ++i) {
        while (!st.empty() && nums[i] > nums[st.back()]) {
          ret[st.back()] = nums[i];
          st.pop_back();
        }
        st.push_back(i);
      }
      int last = 0;
      while (st.size() > 1) {
        while (last <= st.front()) {
          if (nums[last] > nums[st.back()]) {
            ret[st.back()] = nums[last];
            break;
          }
          ++last;
        }
        st.pop_back();
      }
      return ret;
    }

    vector<int> nextGreaterElements2(vector<int>& nums) {
      if (nums.size() <= 0) {
        return {};
      }
      vector<int> ret(nums.size(), -1);
      vector<int> st;
      for (int i = 0; i <= nums.size(); ++i) {
        while (!st.empty() && nums[i] > nums[st.back()]) {
          ret[st.back()] = nums[i];
          st.pop_back();
        }
        st.push_back(i);
      }
      for (int i = 0; i < st.front(); ++i) {
        if (nums[i] > nums[st.back()]) {
          while (nums[i] > nums[st.back()]) {
            ret[st.back()] = nums[i];
            st.pop_back();
          }
        }
      }
      return ret;
    }
};

int main() {
  Solution sln;
  vector<int> nums;
  vector<int> ret;
  nums = {1, 2, 3, 5, 6, 7, 9, 11};
  ret = sln.nextGreaterElements2(nums);
  for (int item: ret) {
    cout << item << " ";
  }
  cout << endl;

  nums = {1, 3, 4, 2};
  ret = sln.nextGreaterElements2(nums);
  for (int item: ret) {
    cout << item << " ";
  }
  cout << endl;

  return 0;
}
