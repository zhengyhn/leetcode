#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    string multiply(string num1, string num2) {
      vector<int> top;
      vector<int> bottom;
      if (num1.size() > num2.size()) {
        top = stringToVector(num1);
        bottom = stringToVector(num2);
      } else {
        top = stringToVector(num2);
        bottom = stringToVector(num1);
      }
      vector<int> add(top.size() + bottom.size(), 0);
      vector<int> result(add);
      for (int i = 0; i < bottom.size(); ++i) {
        if (bottom[i] == 0) {
          continue;
        }
        for (int j = 0; j < top.size(); ++j) {
          int val = bottom[i] * top[j];
          add[i + j + 1] += val / 10;
          result[i + j] += val % 10;
        }
      }
      for (int i = 0; i < result.size(); ++i) {
        int val = result[i] + add[i];
        result[i] = val % 10;
        add[i + 1] += val / 10;
      }
      return vectorToString(result);
    }

    vector<int> stringToVector(string& num) {
      vector<int> vec(num.size());
      for (int i = 0; i < num.size(); ++i) {
        vec[num.size() - i - 1] = num[i] - '0';
      }
      return vec;
    }

    string vectorToString(vector<int>& vec) {
      int i = vec.size() - 1;
      while (vec[i] == 0) {
        --i;
      }
      if (i < 0) {
        return "0";
      }
      string str(i + 1, '0');
      for (; i >= 0; --i) {
        str[str.size() - i - 1] = vec[i] + '0';
      }
      return str;
    }
};

int main() {
  Solution sln;
  string num1, num2;
  num1 = "2";
  num2 = "3";
  cout << sln.multiply(num1, num2) << endl;
  num1 = "123";
  num2 = "456";
  cout << sln.multiply(num1, num2) << endl;
  num1 = "0";
  num2 = "0";
  cout << sln.multiply(num1, num2) << endl;
  num1 = "123";
  num2 = "0";
  cout << sln.multiply(num1, num2) << endl;
  num1 = "99999";
  num2 = "99999";
  cout << sln.multiply(num1, num2) << endl;

  return 0;
}
