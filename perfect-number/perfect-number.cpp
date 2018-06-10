#include <iostream>
#include <cmath>

using namespace std;

class Solution {
  public:
    bool checkPerfectNumber(int num) {
      if (num < 4) {
        return false;
      }
      int sum = 1;
      for (int i = 2; i < sqrt(num); ++i) {
        if (num % i == 0) {
          sum += i + num / i;
        }
      }
      return sum == num;
    }

    bool checkPerfectNumber2(int num) {
      std::cout << pn(2) << std::endl;
    }

    int pn(int p) {
      return (1 << (p - 1)) * ((1 << p) - 1);
    }
};

int main() {
  Solution sln;
  for (int i = 1; i < 29; ++i) {
    std::cout << sln.checkPerfectNumber2(i) << std::endl;
  }

  return 0;
}
