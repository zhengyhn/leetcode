#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    int graph[N + 1][N + 1];
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        if (i == j) {
          graph[i][j] = 0;
        } else {
          graph[i][j] = INT_MAX;
        }
      }
    }
    for (int i = 0; i < times.size(); ++i) {
      graph[times[i][0]][times[i][1]] = times[i][2];
    }
    int len[N + 1];
    int visited[N + 1];
    for (int i = 1; i <= N; ++i) {
      len[i] = graph[K][i];
      visited[i] = false;
    }
    for (int i = 1; i <= N; ++i) {
      int s = 0;
      int minValue = INT_MAX;
      for (int j = 1; j <= N; ++j) {
        if (!visited[j] && len[j] < minValue) {
          s = j;
          minValue = len[j];
        }
      }
      visited[s] = true;
      for (int j = 1; j <= N; ++j) {
        if (!visited[j] && minValue < INT_MAX && graph[s][j] < INT_MAX) {
          len[j] = min(len[j], minValue + graph[s][j]);
        }
      }
    }
    int ret = -1;
    for (int i = 1; i <= N; ++i) {
      if (len[i] == INT_MAX) {
        return -1;
      }
      ret = max(ret, len[i]);
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