#include <iostream>
#include <vector>

using namespace std;

class Solution {
  private:
    int calculate(string& sum, int result) {
      if (result >= 2) {
        sum.insert(0, 1, (char)(result % 2 + '0'));
        return result / 2;
      } else {
        sum.insert(0, 1, (char)(result + '0'));
        return 0;
      }
    }
  public:
    string addBinary(string a, string b) {
      string sum;
      int i = a.size() - 1;
      int j = b.size() - 1;
      int plus = 0;
      while (i >= 0 && j >= 0) {
        plus = calculate(sum, a[i] - '0' + b[j] - '0' + plus);
        --i;
        --j;
      }
      while (i >= 0) {
        plus = calculate(sum, a[i] - '0' + plus);
        --i;
      }
      while (j >= 0) {
        plus = calculate(sum, b[j] - '0' + plus);
        --j;
      }
      if (plus == 1) {
        sum.insert(0, 1, '1');
      }
      return sum;
    }
};

int main(void) {
  Solution sln;
  std::cout << sln.addBinary("11", "1") << std::endl;
  std::cout << sln.addBinary("", "") << std::endl;
  std::cout << sln.addBinary("1", "") << std::endl;
  std::cout << sln.addBinary("0", "0") << std::endl;
  std::cout << sln.addBinary("0", "1") << std::endl;
  std::cout << sln.addBinary("1", "1") << std::endl;
  std::cout << sln.addBinary("10", "1") << std::endl;
  std::cout << sln.addBinary("10", "01") << std::endl;
  std::cout << sln.addBinary("1111", "1111") << std::endl;

  return 0;
}
