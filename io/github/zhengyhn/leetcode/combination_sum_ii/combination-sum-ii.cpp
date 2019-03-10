#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
  public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      vector<int> stack;
      vector<vector<int>> ret;
      if (candidates.size() == 0) {
        return ret;
      }
      std::sort(candidates.begin(), candidates.end());
      stack.push_back(-1);
      int sum = 0;
      int back = stack.back();

      while (!stack.empty()) {
        for (int i = back + 1; i < candidates.size(); ++i) {
          sum += candidates[i];
          stack.push_back(i);
          // std::cout << "value:" << candidates[i] << " " << sum << std::endl;
          if (sum == target) {
            vector<int> temp(stack.size() - 1);
            for (int j = 1; j < stack.size(); ++j) {
              temp[j - 1] = candidates[stack[j]];
            }
            int k = 0;
            for (; k < ret.size(); ++k) {
              if (temp == ret[k]) {
                break;
              }
            }
            if (k == ret.size()) {
              ret.push_back(temp);
            }
            break;
          } else if (sum > target) {
            sum -= candidates[i];
            stack.pop_back();
            break;
          }
        }
        if (stack.size() > 0) {
          back = stack.back();
          if (back >= 0) {
            sum -= candidates[back];
            // std::cout << back << " " << candidates[back] << std::endl;
          }
          stack.pop_back();
        }
      }
      return ret;
    }
};

int main() {
  Solution sln;
  vector<vector<int>> ret;
  vector<int> candidates;
  
  candidates = {2,5,1,1,2,3,3,3,1,2,2};
  ret = sln.combinationSum2(candidates, 5);
  // candidates = {2,5,2,1,2};
  // ret = sln.combinationSum2(candidates, 5);
  // candidates = {10,1,2,7,6,1,5};
  // ret = sln.combinationSum2(candidates, 8);
  for (vector<int> row: ret) {
    for (int col: row) {
      std::cout << col << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
