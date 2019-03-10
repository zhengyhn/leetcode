#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    string convert(string s, int numRows) {
      if (s.size() <= 0) {
        return s;
      }
      if (numRows <= 1) {
        return s;
      }
      string ret;
      for (int i = 0; i < s.size(); i += 2 * numRows - 2) {
        ret.push_back(s[i]);
      }
      for (int i = 1; i < numRows - 1; ++i) {
        int count = 1;
        for (int j = i; j < s.size(); ) {
          ret.push_back(s[j]);
          ++count;
          if (count % 2) {
            j += 2 * i;
          } else {
            j += 2 * (numRows - 1 - i);
          }
        }
      }
      for (int i = numRows - 1; i < s.size(); i += 2 * numRows - 2) {
        ret.push_back(s[i]);
      }
      return ret;
    }
};

int main() {
  Solution sln;
  std::cout << sln.convert("ABCDEFGHIJK", 4) << std::endl;
  std::cout << sln.convert("ABC", 3) << std::endl;
  std::cout << sln.convert("PAYPALISHIRING", 3) << std::endl;
  std::cout << sln.convert("PAYPALISHIRING", 5) << std::endl;

  return 0;
}
