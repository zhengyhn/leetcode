#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    int rowSize = matrix.size();
    if (rowSize <= 0) {
      return 0;
    }
    int colSize = matrix[0].size();
    vector<int> heights = vector<int>(colSize);
    int ret = 0;
    for (int i = 0; i < rowSize; ++i) {
      for (int j = 0; j < colSize; ++j) {
        if (matrix[i][j] == '0') {
          heights[j] = 0;
          continue;
        }
        if ((i - 1) >= 0) {
          heights[j] += 1;
        } else {
          heights[j] = 1;
        }
      }
      ret = max(ret, helper(heights));
    }
    return ret;
  }

 private:
  int helper(vector<int> heights) {
    stack<int> st;
    st.push(0);
    int ret = 0;
    heights.push_back(0);
    for (int i = 1; i < heights.size(); ++i) {
      while (!st.empty() && heights[st.top()] > heights[i]) {
        int top = st.top();
        st.pop();
        int width = 0;
        if (!st.empty()) {
          width = i - st.top() - 1;
        } else {
          width = i;
        }
        ret = max(ret, heights[top] * width);
      }
      st.push(i);
    }
    return ret;
  }
};

int main() {
  Solution sln;
  vector<vector<char>> matrix;
  matrix = {{'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}};
  cout << sln.maximalRectangle(matrix) << endl;

  matrix = {{'1'}};
  cout << sln.maximalRectangle(matrix) << endl;
  matrix = {{'0'}};
  cout << sln.maximalRectangle(matrix) << endl;
  matrix = {{'1', '1'}, {'1', '1'}};
  cout << sln.maximalRectangle(matrix) << endl;
  matrix = {{'1', '0'}, {'1', '1'}};
  cout << sln.maximalRectangle(matrix) << endl;
  matrix = {{'1', '1'}, {'0', '1'}};
  cout << sln.maximalRectangle(matrix) << endl;
  matrix = {{'1', '1'}, {'1', '0'}};
  cout << sln.maximalRectangle(matrix) << endl;
  matrix = {{'1', '0'}, {'0', '0'}};
  cout << sln.maximalRectangle(matrix) << endl;

  return 0;
}