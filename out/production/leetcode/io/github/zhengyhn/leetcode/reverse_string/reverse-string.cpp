#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
      string ret;
      for (int i = s.size() - 1; i >= 0; --i) {
        ret.push_back(s[i]);
      }
      return ret;
    }
};

int main() {
  Solution sln;
  std::cout << sln.reverseString("hello") << std::endl;
  std::cout << sln.reverseString("h") << std::endl;
  std::cout << sln.reverseString("") << std::endl;

  return 0;
}
