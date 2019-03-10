#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      int m1, m2;
      int m1_count = 0, m2_count = 0;

      for (std::vector<int>::iterator it = nums.begin();
           it != nums.end(); ++it) {
        if (*it == m1) {
          ++m1_count;
        } else if (*it == m2) {
          ++m2_count;
        } else if (m1_count == 0) {
          m1 = *it;
          m1_count = 1;
        } else if (m2_count == 0) {
          m2 = *it;
          m2_count = 1;
        } else {
          --m1_count;
          --m2_count;
        }
      }

      vector<int> res;
      m1_count = m2_count = 0;
      for (std::vector<int>::iterator it = nums.begin();
           it != nums.end(); ++it) {
        if (*it == m1) {
          ++m1_count; 
        } else if (*it == m2) {
          ++m2_count;
        }
      }
      if (m1_count > (nums.size() / 3)) {
        res.push_back(m1);
      }
      if (m2_count > (nums.size() / 3)) {
        res.push_back(m2);
      }

      return res;
    }
};

int main(void) {
  Solution sln;
  int arr[20] = {1, 2, 3, 4, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 8};
  std::vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

  std::vector<int> res = sln.majorityElement(nums);

  for (std::vector<int>::iterator it = res.begin();
       it != res.end(); ++it) {
    std::cout << *it << std::endl;
  }

  return 0;
}
