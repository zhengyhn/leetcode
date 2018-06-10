#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
  vector<string> letterCasePermutation(string S) {
    vector<string> ret;

    if (S.size() == 0) {
      ret.push_back("");
      return ret;
    }
    int start = 0;
    while (start < S.size() && !this->isLetter(S[start])) {
      ++start;
    }
    if (start >= S.size()) {
      ret.push_back(S);
      return ret;
    }
    string s(S, 0, start + 1);
    string next(S, start + 1, S.size() - start - 1);
    vector<string> children = this->letterCasePermutation(next);
    for (int j = 0; j < children.size(); ++j) {
      string temp(s);
      temp.append(children[j]);
      ret.push_back(temp);
      string toggleTemp(temp);
      toggleTemp[start] = this->toggleLetter(toggleTemp[start]);
      ret.push_back(toggleTemp);
    }
    if (children.size() == 0) {
      ret.push_back(s);
    }
    return ret;
  }

  bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
  }

  char toggleLetter(char c) {
    if (c >= 'a' && c <= 'z') {
      return 'Z' - ('z' - c);
    } else {
      return 'z' - ('Z' - c);
    }
  }
};

int main() {
  Solution sln;
  // vector<string> ret = sln.letterCasePermutation("a1b2");
  vector<string> ret = sln.letterCasePermutation("");
  for (string str: ret) {
    std::cout << str << std::endl;
  }

  return 0;
}
