#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int value;
  Node *next;
  Node(int val, Node *n) : value(val), next(n) {}
};
class Solution {
 public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    int maxNode = edges.size() + 1;
    Node *set[maxNode + 1];
    for (int i = 0; i < maxNode + 1; ++i) {
      set[i] = NULL;
    }
    int ret = 0;
    for (int i = 0; i < edges.size(); ++i) {
      vector<int> pair = edges[i];
      if (set[pair[0]] != NULL && set[pair[0]] == set[pair[1]]) {
        ret = i;
        continue;
      }
      if (set[pair[0]] == NULL && set[pair[1]] == NULL) {
        set[pair[0]] = new Node(pair[0], new Node(pair[1], NULL));
        set[pair[1]] = set[pair[0]];
      } else if (set[pair[1]] == NULL) {
        Node *node = new Node(pair[1], set[pair[0]]->next);
        set[pair[0]]->next = node;
        set[pair[1]] = set[pair[0]];
      } else if (set[pair[0]] == NULL) {
        Node *node = new Node(pair[0], set[pair[1]]->next);
        set[pair[1]]->next = node;
        set[pair[0]] = set[pair[1]];
      } else {
        Node *p = set[pair[1]];
        while (p != NULL) {
          Node *temp = p->next;
          p->next = set[pair[0]]->next;
          set[pair[0]]->next = p;
          set[p->value] = set[pair[0]];
          p = temp;
        }
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