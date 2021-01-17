#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<int> stack;
      vector<vector<int>> ret;
      if (candidates.size() == 0) {
        return ret;
      }
      stack.push_back(-1);
      int sum = 0;

      while (!stack.empty()) {
        int back = stack.back();
        if (back >= 0) {
          sum -= candidates[back];
        }
        stack.pop_back();
        for (int i = back + 1; i < candidates.size();) {
          sum += candidates[i];
          if (sum == target) {
            vector<int> temp;
            for (std::vector<int>::iterator it = stack.begin(); it != stack.end(); ++it) {
              temp.push_back(candidates[*it]);
            }
            temp.push_back(candidates[i]);
            ret.push_back(temp);
          } else if (sum < target) {
            stack.push_back(i);
            continue;
          }
          sum -= candidates[i];
          ++i;
        }

        while (stack.size() > 0 && (stack.back() + 1) >= candidates.size()) {
          int temp = stack.back();
          sum -= candidates[temp];
          stack.pop_back();
        }
      }
      return ret;
    }
};

int main() {
  Solution sln;
  vector<int> candidates = {2};
  vector<vector<int>> ret = sln.combinationSum(candidates, 1);
  for (vector<int> row: ret) {
    for (int col: row) {
      std::cout << col << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
