#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int mySqrt(int x) {
      long long times = 0;
      int y = x;
      while (y > 0) {
        y >>= 1;
        ++times;
        if (y <= times) {
          break;
        }
      }
      long long z = x;
      while (true) {
        long long product = times * times;
        if (product == z) {
          return times;
        } else if (product > z) {
          return times - 1;
        }
        ++times;
      }
    }

    int mySqrt2(int x) {
      long long ret = x;
      while (ret * ret > x) {
        ret = (ret + x / ret) / 2;
      }
      return ret;
    }
};

int main() {
  Solution sln;
  std::cout << sln.mySqrt2(4) << std::endl;
  std::cout << sln.mySqrt2(8) << std::endl;
  std::cout << sln.mySqrt2(9) << std::endl;
  std::cout << sln.mySqrt2(2147483647) << std::endl;

  return 0;
}
