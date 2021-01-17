#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct ArcNode {
  int vertex;
  ArcNode *next;
};
struct Node {
  int value;
  ArcNode *firstArc;
};

class Solution {
 public:
  bool findWhetherExistsPath(int n, vector<vector<int>> &graph, int start,
                             int target) {
    Node nodes[n];
    for (int i = 0; i < n; ++i) {
      nodes[i].value = i;
      nodes[i].firstArc = NULL;
    }
    for (auto pair : graph) {
      ArcNode *arc = new ArcNode();
      arc->vertex = pair[1];
      arc->next = nodes[pair[0]].firstArc;
      nodes[pair[0]].firstArc = arc;
    }
    queue<Node> q;
    q.push(nodes[start]);
    while (!q.empty()) {
      Node node = q.front();
      q.pop();
      if (node.value == target) {
        return true;
      }
      if (!node.firstArc) {
        continue;
      }
      ArcNode *arc = node.firstArc;
      if (arc->vertex == node.value) {
        break;
      }
      ArcNode *p = arc;
      while (p != NULL) {
        q.push(nodes[p->vertex]);
        p = p->next;
      }
    }
    return false;
  }
};

int main() {
  Solution sln;

  vector<vector<int>> graph = {{0, 1}, {0, 2}, {1, 2}, {1, 2}};
  cout << sln.findWhetherExistsPath(3, graph, 0, 2) << endl;

  return 0;
}
