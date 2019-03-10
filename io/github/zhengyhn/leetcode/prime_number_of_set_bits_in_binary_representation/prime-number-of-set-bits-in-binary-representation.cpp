#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int countPrimeSetBits(int L, int R) {
      int count = 0;
      for (int i = L; i <= R; ++i) {
        int num = this->getBitCount(i);
        if (this->isPrime(num)) {
          ++count;
        }
      }
      return count;
    }

    int getBitCount(int n) {
      int count = 0;
      while (n > 0) {
        if (n & 1) {
          ++count;
        }
        n >>= 1;
      }
      return count;
    }

    bool isPrime(int n) {
      if (n < 2) {
        return false;
      }
      if (n == 2) {
        return true;
      }
      for (int i = 2; i < n; ++i) {
        if (n % i == 0) {
          return false;
        }
      }
      return true;
    }
};

int main() {
  Solution sln;
  std::cout << sln.countPrimeSetBits(842, 888) << std::endl;

  return 0;
}
