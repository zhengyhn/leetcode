#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  int trap(vector<int>& height) {
    int size = height.size();
    if (size < 3) {
      return 0;
    }
    int ret = 0;
    stack<int> s;
    s.push(0);
    int i = 1;
    while (!s.empty() && i < size) {
      while (!s.empty() && height[i] > height[s.top()]) {
        int top = s.top();
        s.pop();
        if (s.empty()) {
          break;
        }
        int width = i - s.top() - 1;
        int h = min(height[i], height[s.top()]) - height[top];
        ret += width * h;
      }
      s.push(i++);
    }
    return ret;
  }
};

int main() {
  Solution sln;
  vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << sln.trap(arr) << endl;

  return 0;
}