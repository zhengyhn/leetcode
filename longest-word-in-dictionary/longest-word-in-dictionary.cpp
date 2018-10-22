#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool cmp(string lhs, string rhs) {
    if (lhs.size() != rhs.size()) {
        return lhs.size() < rhs.size();
    }
    return lhs < rhs;
}
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        unordered_set<string> s;
        string ret;
        for (int i = 0; i < words.size(); ++i) {
            string temp(words[i], 0, words[i].size() - 1);
            // cout << words[i] << endl;
            if (words[i].size() == 1 || s.find(temp) != s.end()) {
                s.insert(words[i]);
                if (words[i].size() > ret.size() || (words[i].size() == ret.size() && words[i] < ret)) {
                    ret = words[i];
                }
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