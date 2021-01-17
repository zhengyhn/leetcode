#include <iostream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
      if (s.size() <= 0) {
        return s;
      }
      char stack[s.size()];
      int top = -1;
      string result;
      for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
          while (top >= 0) {
            result.push_back(stack[top--]);
          }
          result.push_back(s[i]);
        } else {
          stack[++top] = s[i];
        }
      }
      while (top >= 0) {
        result.push_back(stack[top--]);
      }
      return result; 
    }
};

int main() {
  Solution sln;
  std::cout << sln.reverseWords("Let's take LeetCode contest") << std::endl;

  return 0;
}
