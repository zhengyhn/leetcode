#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
      vector<int> scores;
      int sum = 0;

      for (string op: ops) {
        if (op == "C") {
          int val = scores.back();
          scores.pop_back();
          sum -= val;
        } else if (op == "D") {
          int val = scores.back() * 2;
          scores.push_back(val);
          sum += val;
        } else if (op == "+") {
          int val = scores[scores.size() - 1] + scores[scores.size() - 2];
          scores.push_back(val);
          sum += val;
        } else {
          int val = this->toInteger(op);
          scores.push_back(val);
          sum += val;
        }
      }
      return sum;
    }

    int toInteger(string str) {
      int ret = 0;
      for (int i = str.size() - 1; i >= 0; --i) {
        if (str[i] == '-') {
          ret = -ret;
        } else {
          ret += (str[i] - '0') * pow(10, str.size() - i - 1);
        }
      }
      return ret;
    }
};

int main() {
  Solution sln;
  // vector<string> ops = {"5","2","C","D","+"};
  vector<string> ops = {"5","-2","4","C","D","9","+","+"};
  std::cout << sln.calPoints(ops) << std::endl;

  return 0;
}
