#include <iostream>

using namespace std;

class Solution {
 public:
  int strStr(string haystack, string needle) {
    int needleSize = needle.size();
    if (needleSize <= 0) {
      return 0;
    }
    int next[needleSize];
    next[0] = -1;
    if (needleSize > 1) {
      next[1] = 0;
    }
    int k = 1;
    for (int i = 2; i < needleSize; ++i) {
      k = next[k];
      if (k == -1 || needle[k] == needle[i - 1]) {
        next[i] = k + 1;
        k = i;
      } else {
        --i;
      }
    }
    int i = 0, j = 0;
    while (i < haystack.size() && j < needleSize) {
      if (j == -1 || haystack[i] == needle[j]) {
        ++i;
        ++j;
      } else {
        j = next[j];
      }
    }
    if (j >= needleSize) {
      return i - needleSize;
    }
    return -1;
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
