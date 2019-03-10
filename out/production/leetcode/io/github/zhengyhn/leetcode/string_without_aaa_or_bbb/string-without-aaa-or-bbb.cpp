#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  string strWithout3a3b(int A, int B) {
    int max, min;
    char maxC, minC;
    if (A > B) {
      max = A;
      maxC = 'a';
      min = B;
      minC = 'b';
    } else {
      max = B;
      maxC = 'b';
      min = A;
      minC = 'a';
    }
    string ret;
    int len = 0;
    while (max > 0 || min > 0) {
      if ((len + 1 >= 3 && min > 0) || max <= 0) {
        int maxCount = max / 2;
        int minCount = min - maxCount >= 2 ? 2 : 1;
        int i = 0;
        while (min > 0 && i < minCount) {
          ret.push_back(minC);
          --min;
          ++i;
        }
        len = 0;
      } else if (max > 0) {
        ret.push_back(maxC);
        --max;
        ++len;
      }
    }
    return ret;
  }
};

int main() {
  Solution sln;
  cout << sln.strWithout3a3b(3, 4) << endl;

  return 0;
}