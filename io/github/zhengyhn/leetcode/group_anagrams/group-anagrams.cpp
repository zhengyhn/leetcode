#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>> ret;
      map<string, vector<string>> anagrams;
      for (string str: strs) {
        string temp(str);
        sort(temp.begin(), temp.end());
        if (anagrams.find(temp) != anagrams.end()) {
          anagrams[temp].push_back(str);
        } else {
          vector<string> arr = {str};
          anagrams[temp] = arr;
        }
      }
      for (map<string, vector<string>>::iterator it = anagrams.begin(); it != anagrams.end(); ++it) {
        ret.push_back(it->second);
      }
      return ret;
    }

    vector<vector<string>> groupAnagrams2(vector<string>& strs) {
      vector<vector<string>> ret;
      map<string, vector<string>> anagrams;
      for (string str: strs) {
        string key = getKey(str);
        if (anagrams.find(key) != anagrams.end()) {
          anagrams[key].push_back(str);
        } else {
          vector<string> arr = {str};
          anagrams[key] = arr;
        }
      }
      for (map<string, vector<string>>::iterator it = anagrams.begin(); it != anagrams.end(); ++it) {
        ret.push_back(it->second);
      }
      return ret;

    }

    string getKey(string& str) {
      string ret;
      int arr[26] = {0};
      for (char c: str) {
        ++arr[c - 'a'];
      }
      for (int i = 0; i < 26; ++i) {
        stringstream ss;
        ss << '#';
        if (arr[i] > 0) {
          ss << arr[i];
        }
        ret.append(ss.str());
      }
      return ret;
    }
};

int main() {
  Solution sln;
  vector<string> strs;
  vector<vector<string>> ret;
  strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  ret = sln.groupAnagrams(strs);
  for (vector<string> arr: ret) {
    for (string str: arr) {
      cout << str << " ";
    }
    cout << endl;
  }

  return 0;
}
