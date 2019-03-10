#include <iostream>
#include <set>
#include <vector>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
      std::set<int> s;
      std::pair<std::set<int>::iterator, bool> ret;

      for (int i = 0; i < nums.size(); ++i) {
        ret = s.insert(nums[i]);

        if (!ret.second) {
          return true;
        }
      }
      return false;
    }
};

int main() {
  Solution sln;
  const int size = 4;
  int arr[size] = {3, 2, 1, 0};
  std::vector<int> vec(arr, arr + size);

  if (sln.containsDuplicate(vec)) {
    std::cout << "y" << std::endl;;
  } else {
    std::cout << "n" << std::endl;
  }

  for (int i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
