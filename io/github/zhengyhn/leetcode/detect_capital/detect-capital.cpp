#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool detectCapitalUse(string word) {
      if (word.size() <= 1) {
        return true;
      }
      if (this->isUpper(word[0])) {
        if (this->isUpper(word[1])) {
          for (int i = 2; i < word.size(); ++i) {
            if (!this->isUpper(word[i])) {
              return false;
            }
          }
          return true;
        } else {
          for (int i = 2; i < word.size(); ++i) {
            if (this->isUpper(word[i])) {
              return false;
            }
          }
          return true;
        }
      } else {
        for (int i = 1; i < word.size(); ++i) {
          if (this->isUpper(word[i])) {
            return false;
          }
        }
        return true;
      }
    }

    bool isUpper(char c) {
      return c >= 'A' && c <= 'Z';
    }
};

int main() {
  Solution sln;
  std::cout << sln.detectCapitalUse("USA") << std::endl;
  std::cout << sln.detectCapitalUse("FlaG") << std::endl;
  std::cout << sln.detectCapitalUse("leetcode") << std::endl;
  std::cout << sln.detectCapitalUse("Google") << std::endl;

  return 0;
}
