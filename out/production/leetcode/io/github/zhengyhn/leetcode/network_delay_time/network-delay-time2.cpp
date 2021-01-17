#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    int dist[N + 1][N + 1];
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        if (i == j) {
          dist[i][j] = 0;
        } else {
          dist[i][j] = INT_MAX;
        }
      }
    }
    for (int i = 0; i < times.size(); ++i) {
      dist[times[i][0]][times[i][1]] = times[i][2];
    }
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        for (int k = 1; k <= N; ++k) {
          if (dist[j][i] < INT_MAX && dist[i][k] < INT_MAX) {
            dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
          }
        }
      }
    }
    int ret = -1;
    for (int i = 1; i <= N; ++i) {
      if (dist[K][i] == INT_MAX) {
        return -1;
      }
      ret = max(ret, dist[K][i]);
    }
    return ret;
  }
};

int main() {
  Solution sln;

  vector<vector<int>> graph = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
  cout << sln.networkDelayTime(graph, 4, 2) << endl;

  return 0;
}