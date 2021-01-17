#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    if (s.size() <= 0 || words.size() <= 0) {
      return {};
    }
    unordered_map<string, int> map;
    for (int i = 0; i < words.size(); ++i) {
      if (map.find(words[i]) == map.end()) {
        map[words[i]] = 0;
      } else {
        map[words[i]] += 1;
      }
    }
    vector<int> ret;
    int wordLen = words[0].size();
    int len = wordLen * words.size();
    for (int i = 0; i < s.size() - len + 1; ++i) {
      string str = s.substr(i, len);
      unordered_map<string, int> temp;
      int j = 0;
      for (; j < str.size(); j += wordLen) {
        string word = str.substr(j, wordLen);
        if (map.find(word) == map.end()) {
          break;
        }
        if (temp.find(word) == temp.end()) {
          temp[word] = 0;
        } else {
          temp[word] += 1;
        }
        if (temp[word] > map[word]) {
          break;
        }
      }
      if (j == str.size() && temp == map) {
        ret.push_back(i);
      }
    }
    return ret;
  }
};

int main() {
  Solution sln;

  string s;
  vector<string> words;
  vector<int> ret;
  s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
  words = {"fooo", "barr", "wing", "ding", "wing"};
  ret = sln.findSubstring(s, words);
  for (auto i : ret) {
    cout << i << " ";
  }
  cout << endl;
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