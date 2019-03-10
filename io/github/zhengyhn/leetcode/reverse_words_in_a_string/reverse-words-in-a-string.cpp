#include <iostream>
#include <stack>

using namespace std;

class Solution {
  public:
    void reverseWords(string &s) {
      stack<char> stack;
      int start = 0;
      while (s[start] == ' ') {
        ++start;
      }
      int i = start;
      while (i < s.size()) {
        if (s[i] == ' ') {
          if (i > 0 && s[i - 1] == ' ') {
            ++i;
            continue;
          }
          for (int j = i - 1; j >= start; --j) {
            stack.push(s[j]);
          }
          stack.push(' ');
          start = -1;
        } else if (start == -1) {
          start = i;
        }
        ++i;
      }
      if (i == s.size() && s[i - 1] != ' ') {
        for (int j = i - 1; j >= start; --j) {
          stack.push(s[j]);
        }
      }
      string ret;
      while (!stack.empty() && stack.top() == ' ') {
        stack.pop();
      }
      while (!stack.empty()) {
        ret.push_back(stack.top());
        stack.pop();
      }
      s = ret;
    }
};

int main() {
  Solution sln;
  // string str = " the sky  is blue ";
  // string str = "a";
  string str = "hello world!";
  sln.reverseWords(str);
  std::cout << str << std::endl;

  return 0;
}
