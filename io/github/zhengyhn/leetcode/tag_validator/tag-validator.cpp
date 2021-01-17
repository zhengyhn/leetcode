#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
 public:
  bool isValid(string code) {
    if (code.size() == 0) {
      return false;
    }
    stack<char> s;
    for (int i = 0; i < code.size(); ++i) {
      if (code[i] == '<') {
        ++i;
        if (i >= code.size()) {
          return false;
        }
        if (code[i] == '/') {
          stack<char> tempStack;
          while (i < code.size()) {
            ++i;
            if (code[i] == '>') {
              break;
            }
            tempStack.push(code[i]);
          }
          if (s.size() > tempStack.size()) {
            while (!tempStack.empty()) {
              char a = tempStack.top();
              tempStack.pop();
              char b = s.top();
              s.pop();
              if (a != b) {
                return false;
              }
            }
          }
        } else if (code[i] == '!') {
          if (i + 7 < code.size() && code.substr(i + 1, 7) == "[CDATA[") {
            i += 8;
            while (i < code.size()) {
              if (i + 2 < code.size() && code[i] == ']' && code[i + 1] == ']' &&
                  code[i + 2] == '>') {
                i += 2;
                break;
              }
              ++i;
            }
            if (i == code.size()) {
              return false;
            }
          } else {
            return false;
          }
        } else {
          s.push(code[i - 1]);
          int k = i;
          while (k < code.size()) {
            if (code[k] == '>') {
              break;
            }
            if (!this->isUpper(code[k])) {
              return false;
            }
            s.push(code[k]);
            ++k;
          }
          if (k - i > 9) {
            return false;
          }
          i = k;
        }
      }
    }
    return !s.empty() && s.top() == '<';
  }

 private:
  bool isUpper(char c) { return c >= 'A' && c <= 'Z'; }
};

int main() {
  Solution sln;
  cout << sln.isValid("<DIV>This is the first line <![CDATA[<div>]]></DIV>")
       << endl;
  cout << sln.isValid("<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>")
       << endl;
  cout << sln.isValid("<A>  <B> </A>   </B>")
       << endl;
  cout << sln.isValid("<DIV>  div tag is not closed  <DIV>")
       << endl;
  cout << sln.isValid("<DIV>  unmatched <  </DIV>")
       << endl;
  cout << sln.isValid("<DIV> closed tags with invalid tag name  <b>123</b> </DIV>")
       << endl;
  cout << sln.isValid("<DIV> unmatched tags with invalid tag name  </1234567890> and <CDATA[[]]>  </DIV>")
       << endl;
  cout << sln.isValid("<DIV>  unmatched start tag <B>  and unmatched end tag </C>  </DIV>")
       << endl;
  cout << sln.isValid("<![CDATA[wahaha]]]><![CDATA[]> wahaha]]>")
       << endl;

  return 0;
}