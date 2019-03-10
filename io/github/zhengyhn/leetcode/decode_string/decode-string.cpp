#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
  inline bool isDigit(char c) {
    return c >= '0' && c <= '9';
  }

  string decodeString(string s) {
    int countStack[s.size() + 1];
    string strStack[s.size() + 1];
    int countTop = -1;
    int strTop = -1;
    string subStr;

    for (int i = 0; i < s.size(); ++i) {
      if (this->isDigit(s[i])) {
        string countStr;
        while (this->isDigit(s[i])) {
          countStr.push_back(s[i++]);
        }
        --i;
        int count = 0;
        for (int j = 0; j < countStr.size(); ++j) {
          count += (countStr[j] - '0') * pow(10, countStr.size() - j - 1);
        }
        countStack[++countTop] = count;
      } else if (s[i] == '[') {
        strStack[++strTop] = subStr;
        subStr = "";
      } else if (s[i] == ']') {
        string temp = strStack[strTop--];
        int count = countStack[countTop--];
        for (int i = 0; i < count; ++i) {
          temp.append(subStr);
        }
        subStr = temp;
      } else {
        subStr.push_back(s[i]);
      }
    }
    return subStr;
  }
};

int main(int argc, char **argv) {
  Solution sln;
  string str(argv[1]);

  std::cout << sln.decodeString(str) << std::endl;

  return 0;
}
