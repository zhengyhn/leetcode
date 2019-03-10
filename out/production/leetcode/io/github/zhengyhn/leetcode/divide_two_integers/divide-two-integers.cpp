#include <iostream>
#include <climits>

using namespace std;

class Solution {
  public:
    int divide(int dividend, int divisor) {
      long long above = (long long)dividend;
      long long bottom = (long long)divisor;
      int sign = 1;
      if (dividend < 0) {
        sign = -sign;
        above = -above;
      }
      if (divisor < 0) {
        sign = -sign;
        bottom = -bottom;
      }
      long long quotient = 0;
      if (bottom == 1) {
        quotient = above;
      } else {
        while (above >= bottom) {
          ++quotient;
          above -= bottom;
        }
      }
      quotient = sign > 0 ? quotient : -quotient;
      if (quotient >= INT_MAX) {
        quotient = INT_MAX;
      }
      if (quotient <= INT_MIN) {
        quotient = INT_MIN;
      }
      return quotient;
    }
    int divideFast(int dividend, int divisor) {
      long long above = (long long)dividend;
      long long bottom = (long long)divisor;
      int sign = 1;
      if (dividend < 0) {
        sign = -sign;
        above = -above;
      }
      if (divisor < 0) {
        sign = -sign;
        bottom = -bottom;
      }
      long long quotient = 0;
      if (bottom == 1) {
        quotient = above;
      } else {
        while (above >= bottom) {
          long long tempDivisor = bottom;
          long long tempQuotient = 1;
          // 左移一位相当于除以2，可以快速计算2^n乘以divisor接近dividend
          while (above > (tempDivisor << 1)) {
            tempDivisor <<= 1;
            tempQuotient <<= 1;
          }
          above -= tempDivisor;
          quotient += tempQuotient;
        }
      }
      quotient = sign > 0 ? quotient : -quotient;
      if (quotient >= INT_MAX) {
        quotient = INT_MAX;
      }
      if (quotient <= INT_MIN) {
        quotient = INT_MIN;
      }
      return quotient;
    }
};

int main() {
  Solution sln;
  std::cout << sln.divide(10, 3) << std::endl;
  std::cout << sln.divideFast(10, 3) << std::endl;
  std::cout << sln.divide(7, -3) << std::endl;
  std::cout << sln.divideFast(7, -3) << std::endl;
  std::cout << sln.divide(INT_MIN, 1) << std::endl;
  std::cout << sln.divideFast(INT_MIN, 1) << std::endl;
  std::cout << sln.divide(INT_MIN, -1) << std::endl;
  std::cout << sln.divideFast(INT_MIN, -1) << std::endl;
  std::cout << sln.divide(INT_MIN, -2) << std::endl;
  std::cout << sln.divideFast(INT_MIN, -2) << std::endl;
  std::cout << sln.divide(INT_MAX, 2) << std::endl;
  std::cout << sln.divideFast(INT_MAX, 2) << std::endl;

  return 0;
}
