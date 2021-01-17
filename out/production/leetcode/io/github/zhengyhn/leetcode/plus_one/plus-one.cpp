#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> plusOne(vector<int>& digits) {
      int len = digits.size() + 1;
      vector<int> result(len);
      int plus = 1;
      for (int i = digits.size() - 1; i >= 0; --i) {
        int sum = digits[i] + plus;
        if (sum > 9) {
          result[--len] = (sum % 10);
          plus = sum / 10;
        } else {
          result[--len] = sum;
          plus = 0;
        }
      }
      if (plus == 1) {
        result[--len] = plus;
      }
      if (len > 0) {
        result.erase(result.begin());
      }
      return result;
    }
};

int main(void) {
  Solution sln;
  vector<int> digits, result;
  digits = {0};
  result = sln.plusOne(digits);
  for (int item: result) {
    std::cout << item;
  }
  std::cout << std::endl;

  return 0;
}
