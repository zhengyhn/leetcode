#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int longestConsecutive1(vector<int>& nums) {
    unordered_set<int> set;
    for (int i = 0; i < nums.size(); ++i) {
      set.insert(nums[i]);
    }
    int maxCount = 0;
    int currentCount = 0;
    for (std::unordered_set<int>::iterator it = set.begin(); it != set.end(); ++it) {
      if (set.find(*it - 1) == set.end()) {
        currentCount = 1;
        while (set.find(*it + currentCount) != set.end()) {
          ++currentCount;
        }
        if (currentCount > maxCount) {
          maxCount = currentCount;
        }
      }
    }
    return maxCount;
  }

  int longestConsecutive(vector<int>& nums) {
    if (nums.size() <= 0) {
      return 0;
    }
    for (int i = (nums.size() - 1) / 2; i >= 0; --i) {
      int left = 2 * i + 1;
      int right = 2 * i + 2;
      int temp = nums[i];
      int k = i;
      
      for (int j = 2 * i + 1; j < nums.size(); j = j * 2 + 1) {
        if (j < nums.size() - 1 && nums[j + 1] < nums[j]) {
          j += 1;
        }
        if (temp < nums[j]) {
          break;
        }
        nums[k] = nums[j];
        k = j;
      }
      nums[k] = temp;
    }
    for (int i = 0; i < nums.size(); ++i) {
      std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    int maxCount = 0;
    for (int i = 0; i < (nums.size() - 1) / 2; ++i) {
      int currentCount = 1;
      currentCount += this->getConsecutiveCount(nums, i);
      if (currentCount > maxCount) {
        maxCount = currentCount;
      }
    }

    return maxCount;
  }

  int getConsecutiveCount(vector<int>& nums, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int count = 0;
    if (i <= (nums.size() - 1) / 2 && nums[left] > nums[right]) {
      swap(nums, left, right);
    }
    if (nums[left] - nums[i] == 1) {
      ++count;
      count += this->getConsecutiveCount(nums, left);
      if (nums[right] - nums[left] == 1) {
        ++count;
        count += this->getConsecutiveCount(nums, right);
      }
    }
    return count;
  }

  void swap(vector<int>& nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }
};

int main() {
  Solution sln;
  // const int size = 6;
  // int arr[size] = {100, 4, 200, 1, 3, 2};
  const int size = 7;
  int arr[size] = {100, 0, 99, 101, 1, 3, 2};
  vector<int> vec(arr, arr + size);
  std::cout << sln.longestConsecutive1(vec) << std::endl;

  return 0;
}
