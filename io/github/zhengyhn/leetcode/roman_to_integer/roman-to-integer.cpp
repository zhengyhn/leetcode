#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
      std::unordered_map<char, int> convert = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
      };
      int result = 0;
      for (int i = s.size() - 1; i >= 0; --i) {
        if (i != (s.size() - 1) && convert[s[i]] < convert[s[i + 1]]) {
          result -= convert[s[i]];
        } else {
          result += convert[s[i]];
        }
      }
      return result;
    }
};

int main() {
  Solution sln;
  std::cout << sln.romanToInt("I") << std::endl;
  std::cout << sln.romanToInt("II") << std::endl;
  std::cout << sln.romanToInt("III") << std::endl;
  std::cout << sln.romanToInt("IV") << std::endl;
  std::cout << sln.romanToInt("V") << std::endl;
  std::cout << sln.romanToInt("VI") << std::endl;
  std::cout << sln.romanToInt("IX") << std::endl;
  std::cout << sln.romanToInt("XIV") << std::endl;
  std::cout << sln.romanToInt("XVI") << std::endl;
  std::cout << sln.romanToInt("MMMCCCXXXIII") << std::endl;

  return 0;
}
