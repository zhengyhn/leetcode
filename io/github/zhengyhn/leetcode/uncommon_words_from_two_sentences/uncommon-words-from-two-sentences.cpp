#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
  public:
    vector<string> uncommonFromSentences(string A, string B) {
      vector<string> strsA = split(A);
      vector<string> strsB = split(B);
      map<string, int> m;
      for (string str: strsA) {
        if (m.find(str) != m.end()) {
          m[str] += 1;
        } else {
          m[str] = 1;
        }
      }
      for (string str: strsB) {
        if (m.find(str) != m.end()) {
          m[str] += 1;
        } else {
          m[str] = 1;
        }
      }
      vector<string> ret;
      for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it) {
        // cout << it->first << ": " << it->second << endl;
        if (it->second == 1) {
          ret.push_back(it->first);
        }
      }
      return ret;
    }
    
    vector<string> split(string a) {
      vector<string> ret;
      if (a.size() == 0) {
        return ret;
      }
      int begin = 0;
      while (a[begin] == ' ') {
        ++begin;
      }
      int end = begin + 1;
      for (; end < a.size(); ++end) {
        if (a[end] == ' ') {
          string temp(a.begin() + begin, a.begin() + end);
          ret.push_back(temp);
          begin = end + 1;
          while (a[begin] == ' ') {
            ++begin;
          }
          end = begin;
        }
      }
      if (begin < a.size() && end > begin) {
        string temp(a.begin() + begin, a.begin() + end);
        ret.push_back(temp);
      }
      return ret;
    }
};
int main() {
  Solution sln;
  string A;
  string B;
  vector<string> ret;
  A = "this apple is sweet";
  B = "this apple is sour";
  ret = sln.uncommonFromSentences(A, B);
  for (string str: ret) {
    cout << str << endl;
  }
  A = "apple apple";
  B = "banana";
  ret = sln.uncommonFromSentences(A, B);
  for (string str: ret) {
    cout << str << endl;
  }
  A = "bb   ";
  B = "   aaa";
  ret = sln.uncommonFromSentences(A, B);
  for (string str: ret) {
    cout << str << endl;
  }

  return 0;
}
