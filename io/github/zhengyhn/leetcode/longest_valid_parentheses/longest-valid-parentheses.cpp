#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestValidParentheses(string s) {
    int ret = 0;
    int left = 0;
    int right = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        ++left;
      } else {
        ++right;
      }
      if (right > left) {
        left = 0;
        right = 0;
      } else if (left == right) {
        ret = max(ret, left * 2);
      }
    }
    left = 0;
    right = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
      if (s[i] == '(') {
        ++left;
      } else {
        ++right;
      }
      if (left > right) {
        left = 0;
        right = 0;
      } else if (left == right) {
        ret = max(ret, left * 2);
      }
    }
    return ret;
  }
};

int main() {
  Solution sln;
  cout << sln.longestValidParentheses(")()())") << endl;
  cout << sln.longestValidParentheses("(()") << endl;
}