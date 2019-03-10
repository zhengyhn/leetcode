#include <iostream>
#include <cmath>

class Solution {
  public:
    bool isPalindrome(int x) {
      if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
      }
      int bits = log10(x) + 1;
      for (int i = 1; i <= bits / 2; ++i) {
        int j = bits - i;
        if (j < i) {
          break;
        }
        // std::cout << "i:" << i << " j:" << j << std::endl;
        int start = (x / (int)pow(10, i - 1)) % 10;
        int end = (x % (int)pow(10, j + 1)) / (int)pow(10, j);
        // std::cout << start << " " << end << std::endl;
        if (start != end) {
          return false;
        }
      }

      return true;
    }
};

int main() {
  Solution sln;
  // std::cout << sln.isPalindrome(-9) << std::endl;
  // std::cout << sln.isPalindrome(121) << std::endl;
  // std::cout << sln.isPalindrome(-1221) << std::endl;
  // std::cout << sln.isPalindrome(123454321) << std::endl;
  // std::cout << sln.isPalindrome(124454321) << std::endl;
  std::cout << sln.isPalindrome(-2147483648) << std::endl;
  std::cout << sln.isPalindrome(-2147483647) << std::endl;
  std::cout << sln.isPalindrome(2147483647) << std::endl;

  return 0;
}
