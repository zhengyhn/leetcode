#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    string simplifyPath(string path) {
      if (path.size() <= 0) {
        return path;
      }
      if (path[path.size() - 1] != '/') {
        path.push_back('/');
      }
      vector<char> stack;
      stack.push_back(path[0]);
      for (int i = 1; i < path.size(); ++i) {
        if (path[i] == '/') {
          while (stack.size() > 0 && stack.back() == '/') {
            stack.pop_back();
          }
          if (stack.size() > 1 && stack[stack.size() - 1] == '.' && stack[stack.size() - 2] == '/') {
            stack.pop_back();
            stack.pop_back();
          }
          if (stack.size() > 2 && stack[stack.size() - 1] == '.' && stack[stack.size() - 2] == '.' && stack[stack.size() - 3] == '/') {
            stack.pop_back();
            stack.pop_back();
            stack.pop_back();
            while (stack.size() > 0) {
              if (stack.back() != '/') {
                stack.pop_back();
              } else {
                stack.pop_back();
                break;
              }
            }
          }
        }
        stack.push_back(path[i]);
      }
      if (stack.size() > 1 && stack.back() == '/') {
        stack.pop_back();
      }
      string ret(stack.begin(), stack.end());
      return ret;
    }
};

int main() {
  Solution sln;
  cout << sln.simplifyPath("/home/") << endl;
  cout << sln.simplifyPath("/a/./b/../../c/") << endl;
  cout << sln.simplifyPath("/../") << endl;
  cout << sln.simplifyPath("/home//foo/") << endl;
  cout << sln.simplifyPath("/.....hidden") << endl;
  cout << sln.simplifyPath("/.../") << endl;
  cout << sln.simplifyPath("/...") << endl;
  cout << sln.simplifyPath("/") << endl;
  cout << sln.simplifyPath("/.") << endl;
  cout << sln.simplifyPath("/./") << endl;

  return 0;
}
