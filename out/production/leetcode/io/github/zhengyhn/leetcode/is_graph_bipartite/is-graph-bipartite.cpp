#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool isBipartite(vector<vector<int>>& graph) {
      vector<int> roots(graph.size(), -1);
      roots[0] = 0;

      for (int i = 0; i < graph.size(); ++i) {
        if (roots[i] == -1) {
            roots[i] = 0;
        }
        int leftRoot = roots[i];
        for (int j = 0; j < graph[i].size(); ++j) {
          int rightRoot = roots[graph[i][j]];
          if (rightRoot == leftRoot) {
            return false;
          } else if (rightRoot == -1) {
            roots[graph[i][j]] = leftRoot == 0 ? 1 : 0;
          }
        }
      }
      return true;
    }
};

int main() {
  Solution sln;
  vector<vector<int>> graph;
  graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
  std::cout << sln.isBipartite(graph) << std::endl;

  graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
  std::cout << sln.isBipartite(graph) << std::endl;

  return 0;
}
