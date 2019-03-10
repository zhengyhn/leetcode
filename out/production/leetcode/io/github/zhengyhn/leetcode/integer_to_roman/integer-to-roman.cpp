#include <iostream>
#include <map>

using namespace std;

class Solution {
  public:
    string intToRoman(int num) {
      map<int, string> symbolMap = {
        {1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"},
        {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}
      };
      string ret;
      while (num > 0) {
        for (map<int, string>::reverse_iterator it = symbolMap.rbegin(); it != symbolMap.rend();) {
          if (num >= it->first) {
            ret.append(it->second);
            num -= it->first;
          } else {
            ++it;
          }
        }
        // std::cout << num << " " << ret << std::endl;
      }
      return ret;
    }
};

int main() {
  Solution sln;
  std::cout << sln.intToRoman(1994) << std::endl;
  std::cout << sln.intToRoman(58) << std::endl;
  std::cout << sln.intToRoman(9) << std::endl;
  std::cout << sln.intToRoman(4) << std::endl;
  std::cout << sln.intToRoman(3) << std::endl;

  for (int i = 1; i < 100; ++i) {
    std::cout << sln.intToRoman(i) << std::endl;
  }

  return 0;
}
