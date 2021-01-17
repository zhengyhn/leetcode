#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 private:
  int find(int *set, int x) {
    while (set[x] != x) {
      x = set[x] = set[set[x]];
    }
    return x;
  }
  void union_set(int *set, int x, int y) {
    int xRoot = find(set, x);
    int yRoot = find(set, y);
    if (xRoot != yRoot) {
      set[yRoot] = xRoot;
    }
  }

 public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    int maxNode = edges.size() + 1;
    int set[maxNode + 1];
    for (int i = 0; i < maxNode; ++i) {
      set[i + 1] = i + 1;
    }
    int ret = 0;
    for (int i = 0; i < edges.size(); ++i) {
      vector<int> pair = edges[i];
      if (find(set, pair[0]) == find(set, pair[1])) {
        ret = i;
      } else {
        union_set(set, pair[0], pair[1]);
      }
    }
    return edges[ret];
  }
};
int main() {
  Solution sln;

  vector<vector<int>> graph = {{9, 10}, {5, 8},  {2, 6},  {1, 5}, {3, 8},
                               {4, 9},  {8, 10}, {4, 10}, {6, 8}, {7, 9}};
  vector<int> ret = sln.findRedundantConnection(graph);
  cout << ret[0] << " " << ret[1] << endl;

  return 0;
}