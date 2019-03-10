#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    bool isValid(string s) {
      stack<char> stack;
      unordered_map<char, char> map = {{')', '('}, {'}', '{'}, {']', '['}};
      
      for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
          stack.push(s[i]);
        } else if (map.find(s[i]) != map.end()) {
          if (stack.empty() || stack.top() != map[s[i]]) {
            return false;
          } else {
            stack.pop();
          }
        }
      }
      return stack.empty();
    }
};

int main() {
  Solution sln;
  std::cout << sln.isValid("") << std::endl;
  std::cout << sln.isValid("(") << std::endl;
  std::cout << sln.isValid("()") << std::endl;
  std::cout << sln.isValid("aaa{(1+1) + 3} + [1]abc") << std::endl;

  return 0;
}
