#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    double myPow(double x, int n) {
      int m = n;
      if (n == -2147483648) {
        m = n + 1;
      }
      double ret = 1;
      double y = x > 0 ? x : -x;
      for (int i = 0; i < abs(m); ++i) {
        if (ret * y == ret) {
          break;
        }
        ret *= y;
        if ((m > 0 && ret == 0) || (m < 0 && (1 / ret) == 0)) {
          break;
        }
      }
      if (m != n) {
        ret *= y;
      }
      if (x < 0 && (n & 1)) {
        ret = -ret;
      }
      return n > 0 ? ret : 1 / ret;
    }
    double myPow2(double x, int n) {
      if (n == 0) {
        return 1;
      }
      long long m = n;
      if (m < 0) {
        x = 1 / x;
        m = -m;
      }
      if (m == 1) {
        return x;
      }
      double temp = this->myPow2(x, m >> 1);
      double ret = temp * temp;
      if (m & 1) {
        ret *= x;
      }
      return ret;
    }
    double myPow3(double x, int n) {
      if (n == 0) {
        return 1;
      }
      long long m = n;
      if (m < 0) {
        x = 1 / x;
        m = -m;
      }
      if (m == 1) {
        return x;
      }
      double current = x;
      double ret = 1;
      for (long long i = m; i > 0; i >>= 1) {
        if (i & 1) {
          ret = ret * current;
        }
        current = current * current;
      }
      return ret;
    }
};

int main() {
  Solution sln;
  std::cout << sln.myPow3(-1, -2147483648) << std::endl;
  std::cout << sln.myPow3(2, 3) << std::endl;
  std::cout << sln.myPow3(2, 10) << std::endl;
  std::cout << sln.myPow3(2, 0) << std::endl;
  std::cout << sln.myPow3(2, 1) << std::endl;
  std::cout << sln.myPow3(2.1, 3) << std::endl;

  return 0;
}
