#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct Node {
    unordered_map<char, Node*> child;
    int end;
    char val;
    public:
      Node(char c) : val(c), end(-1)
      {
      }
};

class Trie {
    private:
        Node *root;
      public:
        Trie() : root(new Node('0'))
        {
        }

        void insert(string word, int idx) {
            Node *p = this->root;
            for (char c: word) {
                if (!p->child[c]) {
                    p->child[c] = new Node(c);
                }
                p = p->child[c];
            }
            p->end = idx;
        }

        string longestWord(const vector<string>& words) {
            string ret;
            queue<Node *> q;
            q.push(this->root);
            while (!q.empty()) {
                Node *p = q.front();
                q.pop();
                if (p->end >= 0 || p == this->root) {
                    if (p != this->root) {
                        string word = words[p->end];
                        if (word.size() > ret.size() || (word.size() == ret.size() && word < ret)) {
                            ret = word;
                        }
                    }
                    for (auto it = p->child.begin(); it != p->child.end(); ++it) {
                        q.push(it->second);
                    }
                }
            }
            return ret;
        }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie *trie = new Trie();
        for (int i = 0; i < words.size(); ++i) {
            trie->insert(words[i], i);
        }
        return trie->longestWord(words);
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