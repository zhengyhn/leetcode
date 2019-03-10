#include <iostream>

class Solution {
  public:
    int addDigits(int num) {
      int result = num;

      while (result / 10 != 0) {
        result = result % 10 + result / 10;
      }

      return result;
    }

    int addDigits2(int num) {
      return (num - 1) % 9 + 1;
    }

};

int main() {
  Solution sln;
  std::cout << sln.addDigits(38) << std::endl;
  std::cout << sln.addDigits2(38) << std::endl;

  return 0;
}
