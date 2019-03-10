#include<iostream>
#include<climits>

using namespace std;

class Solution {
  public:
    int myAtoi(string str) {
      long long ret = 0;
      int i = 0;
      while (i < str.size() && str[i] == ' ') {
        ++i;
      }
      if (i >= str.size()) {
        return 0;
      }
      int sign = 1;
      if (str[i] == '+') {
        sign = 1;
        ++i;
      } else if (str[i] == '-') {
        sign = -1;
        ++i;
      } else if (!isDigit(str[i])) {
        return 0;
      }
      while (i < str.size() && str[i] == '0') {
        ++i;
      }
      int j = i;
      while (j < str.size() && isDigit(str[j])) {
        ++j;
      }
      long long base = 1;
      for (int start = j - 1; start >= i; --start) {
        ret += base * (str[start] - '0');
        // std::cout << ret << " " << base << " " << str[start] << " " << start << std::endl;
        if (ret * sign > INT_MAX || base * sign > INT_MAX) {
          return INT_MAX;
        }
        if (ret * sign < INT_MIN || base * sign < INT_MIN) {
          return INT_MIN;
        }
        base *= 10;
      }
      return ret * sign;
    }

    bool isDigit(char c) {
      return c >= '0' && c <= '9';
    }
};

int main() {
  Solution sln;
  std::cout << sln.myAtoi("") << std::endl;
  std::cout << sln.myAtoi("  ") << std::endl;
  std::cout << sln.myAtoi("42") << std::endl;
  std::cout << sln.myAtoi("  +42") << std::endl;
  std::cout << sln.myAtoi("  -42") << std::endl;
  std::cout << sln.myAtoi("4193 with words") << std::endl;
  std::cout << sln.myAtoi("123 with words 123") << std::endl;
  std::cout << sln.myAtoi("words and 987") << std::endl;
  std::cout << sln.myAtoi("-91283472332") << std::endl;
  std::cout << sln.myAtoi("91283472332") << std::endl;
  std::cout << sln.myAtoi("10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000522545459") << std::endl;
  std::cout << sln.myAtoi("00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000522545459") << std::endl;
  std::cout << sln.myAtoi("-000000000000001") << std::endl;

  return 0;
}
