#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    if (s.size() <= 0 || words.size() <= 0) {
      return {};
    }
    set<int> ret;
    int len = words[0].size();
    for (int i = 0; i < s.size(); ++i) {
      if ((s.size() - i) < (len * words.size())) {
        break;
      }
      for (int j = 0; j < words.size(); ++j) {
        if (s.substr(i, len) == words[j]) {
          // vector<string> subSet(words.begin(), words.end());
          words.erase(words.begin() + j);
          if (isMatch(s, i + len, len, words)) {
            ret.insert(i);
          }
          words.insert(words.begin() + j, s.substr(i, len));
        }
      }
    }
    return vector<int>(ret.begin(), ret.end());
  }

  bool isMatch(string& s, int start, int len, vector<string>& words) {
    if (words.size() <= 0) {
      return true;
    }
    if ((s.size() - start) < (len * words.size())) {
      return false;
    }
    for (int j = 0; j < words.size(); ++j) {
      if (s.substr(start, len) == words[j]) {
        // vector<string> subSet(words.begin(), words.end());
        words.erase(words.begin() + j);
        bool ret = isMatch(s, start + len, len, words);
        words.insert(words.begin() + j, s.substr(start, len));
        return ret;
      }
    }
    return false;
  }
};

int main() {
  Solution sln;

  string s;
  vector<string> words;
  vector<int> ret;
  // s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
  // words = {"fooo", "barr", "wing", "ding", "wing"};
  // ret = sln.findSubstring(s, words);
  // for (auto i : ret) {
  //   cout << i << " ";
  // }
  // cout << endl;
  s = "barfoothefoobarman";
  words = {"foo", "bar"};
  ret = sln.findSubstring(s, words);
  for (auto i : ret) {
    cout << i << " ";
  }
  cout << endl;
  s = "barfoofoobarthefoobarman";
  words = {"bar", "foo", "the"};
  ret = sln.findSubstring(s, words);
  for (auto i : ret) {
    cout << i << " ";
  }
  cout << endl;
  s = "wordgoodgoodgoodbestword";
  words = {"good", "best", "word"};
  ret = sln.findSubstring(s, words);
  for (auto i : ret) {
    cout << i << " ";
  }
  cout << endl;
}