#include <iostream>
#include <vector>

using namespace std;

class Solution {
  private:
    bool isChar(char c) {
      return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
  public:
    int lengthOfLastWord(string s) {
      if (s.size() <= 0) {
        return 0;
      }
      int begin = s.size();
      int end = s.size();
      for (int i = s.size() - 1; i >= 0; --i) {
        if (isChar(s[i])) {
          begin = i;
        } else if (begin == end) {
          end = i;
          begin = i;
        } else {
          break;
        }
      }
      return end - begin;
    }
};

int main(void) {
  Solution sln;
  std::cout << sln.lengthOfLastWord("") << std::endl;
  std::cout << sln.lengthOfLastWord("a") << std::endl;
  std::cout << sln.lengthOfLastWord(" ") << std::endl;
  std::cout << sln.lengthOfLastWord("  ") << std::endl;
  std::cout << sln.lengthOfLastWord("Hello World") << std::endl;
  std::cout << sln.lengthOfLastWord("a ") << std::endl;

  return 0;
}
