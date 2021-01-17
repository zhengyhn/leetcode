#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int calculate(string s) {
    unordered_map<char, int> insidePriority = {
        {'#', 0}, {'+', 3}, {'-', 3}, {'*', 5}, {'/', 5}};
    unordered_map<char, int> outsidePriority = {
        {'#', 0}, {'+', 2}, {'-', 2}, {'*', 4}, {'/', 4}};
    stack<char> operators;
    operators.push('#');
    stack<int> suffix;
    s.push_back('#');
    for (int i = 0; i < s.size(); ++i) {
      char c = s[i];
      if (c == ' ') {
        continue;
      }
      if (isNumber(c)) {
        int n = c - '0';
        while (i < s.size() - 1 && isNumber(s[++i])) {
          n = n * 10 + (s[i] - '0');
        }
        suffix.push(n);
        --i;
        continue;
      }
      while (!operators.empty()) {
        if (outsidePriority[c] > insidePriority[operators.top()]) {
          operators.push(c);
          break;
        } else if (outsidePriority[c] == insidePriority[operators.top()]) {
          operators.pop();
          break;
        } else {
          int right = suffix.top();
          suffix.pop();
          int left = suffix.top();
          suffix.pop();
          switch (operators.top()) {
            case '+':
              suffix.push(left + right);
              break;
            case '-':
              suffix.push(left - right);
              break;
            case '*':
              suffix.push(left * right);
              break;
            case '/':
              suffix.push(left / right);
              break;
          }
          operators.pop();
        }
      }
    }
    return suffix.top();
  }
  bool isNumber(char c) { return c >= '0' && c <= '9'; }
};

int main() {
  Solution sln;
  cout << sln.calculate("3+2*2") << endl;
  cout << sln.calculate(" 3/2 ") << endl;
  cout << sln.calculate(" 3+5 / 2 ") << endl;
  cout << sln.calculate("2147483647") << endl;

  return 0;
}