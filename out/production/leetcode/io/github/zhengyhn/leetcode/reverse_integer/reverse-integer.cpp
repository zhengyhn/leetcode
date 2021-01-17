#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath> 

using namespace std;

class Solution {
public:
    int reverse(int x) {
      int maxPow = -1;
      int temp = x;
      while (temp != 0) {
        maxPow += 1;
        temp /= 10;
      }
      long long result = 0;
      temp = x;
      while (temp != 0) {
        int mod = temp % 10;
        result += mod * pow(10, maxPow);
        --maxPow;
        temp /= 10;
        // std::cout << mod << " " << maxPow << " " << temp << " " << result << std::endl;
        // break;
      }
      if (result > (pow(2, 31) - 1) || result < -pow(2, 31)) {
        return 0;
      }
      return result;
    }
};

int main() {
  Solution sln;
  std::cout << sln.reverse(120) << std::endl;
  std::cout << sln.reverse(-120) << std::endl;
  std::cout << sln.reverse(-123) << std::endl;
  std::cout << sln.reverse(123) << std::endl;
  std::cout << sln.reverse(2147483647) << std::endl;
  std::cout << sln.reverse(-2147483647) << std::endl;
  std::cout << sln.reverse(1534236469) << std::endl;

  return 0;
}
