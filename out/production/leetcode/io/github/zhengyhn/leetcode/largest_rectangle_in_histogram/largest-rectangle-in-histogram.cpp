#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    if (heights.size() <= 0) {
      return 0;
    }
    int ret = 0;
    stack<int> stack;
    stack.push(0);
    int i = 1;
    while (!stack.empty()) {
      while (i == heights.size() || heights[i] < heights[stack.top()]) {
        int top = stack.top();
        stack.pop();
        int width = i;
        if (!stack.empty()) {
          width = i - stack.top() - 1;
        }
        ret = max(width * heights[top], ret);
        if (stack.empty()) {
          break;
        }
      }
      if (i == heights.size()) {
        break;
      }
      stack.push(i++);
    }
    return ret;
  }
};

int main() {
  Solution sln;
  vector<int> arr = {2, 1, 5, 6, 2, 3};
  cout << sln.largestRectangleArea(arr) << endl;

  return 0;
}