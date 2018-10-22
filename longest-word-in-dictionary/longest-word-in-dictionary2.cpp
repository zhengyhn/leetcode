#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> s;
        for (int i = 0; i < words.size(); ++i) {
            s.insert(words[i]);
        }
        string ret;
        unordered_set<string> s2;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i].size() < ret.size()) {
                continue;
            }
            string temp(words[i], 0, words[i].size() - 1);
            while (temp.size() > 0) {
                if (s2.find(temp) != s2.end()) {
                    temp = "";
                    break;
                }
                if (s.find(temp) != s.end()) {
                    temp = temp.substr(0, temp.size() - 1);
                } else {
                    break;
                }
            }
            if (temp.size() <= 0 && (words[i].size() > ret.size() || (words[i].size() == ret.size() && words[i] < ret))) {
                ret = words[i];
                s2.insert(ret);
            }
        }
        return ret;
    }
};

int main() {
    Solution sln;
    vector<string> words;
    words = {"w","wo","wor","worl", "world"};
    cout << sln.longestWord(words) << endl;
    words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    cout << sln.longestWord(words) << endl;
    words = {"yo","ew","fc","zrc","yodn","fcm","qm","qmo","fcmz","z","ewq","yod","ewqz","y"};
    cout << sln.longestWord(words) << endl;

    return 0;
}