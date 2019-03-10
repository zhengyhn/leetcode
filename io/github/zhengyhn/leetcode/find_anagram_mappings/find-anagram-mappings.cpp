#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> map;
        vector<int> ret;
        for (int i = 0; i < B.size(); ++i) {
            map[B[i]] = i;
        }
        for (int i = 0; i < A.size(); ++i) {
            ret.push_back(map[A[i]]);
        }
        return ret;
    }
};

int main() {
  Solution sln;
  return 0;
}
