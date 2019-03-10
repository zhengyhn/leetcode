#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> combine(int n, int k) {
      int stack[n];
      int top = -1;
      vector<vector<int>> ret;
      if (k == 1) {
        for (int i = 1; i <= n; ++i) {
          ret.push_back({i});
        }
        return ret;
      }

      stack[++top] = 1;
      while ((n - stack[0] + 1) >= k) {
        for (int i = stack[top] + 1; i <= n; ++i) {
          stack[++top] = i;
          if (top == k - 1) {
            vector<int> temp;
            for (int j = 0; j < k; ++j) {
              temp.push_back(stack[j]);
            }
            ret.push_back(temp);
            --top;
          }
        }
        ++stack[top];
        if (top > 0 && stack[top] >= n) {
          --top;
          ++stack[top];
        }
      }
      return ret;
    }
};

int main() {
  Solution sln;
  vector<vector<int>> ret = sln.combine(4, 2);
  for (vector<int> row: ret) {
    for (int col: row) {
      std::cout << col << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
