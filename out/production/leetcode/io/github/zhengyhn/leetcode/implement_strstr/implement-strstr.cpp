#include <iostream>

using namespace std;

class Solution {
  public:
    int strStr(string haystack, string needle) {
      if (needle.size() <= 0) {
        return 0;
      }
      int ret = -1;
      for (int i = 0; i < (int)haystack.size() - (int)needle.size() + 1; ++i) {
        int j = 0;
        for (; j < needle.size(); ++j) {
          if (haystack[i + j] != needle[j]) {
            break;
          }
        }
        if (j == needle.size()) {
          return i;
        }
      }
      return ret;
    }
};

int main(void) {
  Solution sln;
  std::cout << sln.strStr("", "") << std::endl;
  std::cout << sln.strStr("", "a") << std::endl;
  std::cout << sln.strStr("a", "") << std::endl;
  std::cout << sln.strStr("hello", "ll") << std::endl;
  std::cout << sln.strStr("aaaaa", "ba") << std::endl;

  return 0;
}
