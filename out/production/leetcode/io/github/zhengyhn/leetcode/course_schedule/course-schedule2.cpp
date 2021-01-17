#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    if (prerequisites.size() == 0) {
      return true;
    }
    unordered_map<int, vector<int>> graph;
    int degrees[numCourses];
    for (int i = 0; i < numCourses; ++i) {
      degrees[i] = 0;
    }
    for (vector<int> item : prerequisites) {
      if (graph.find(item[0]) == graph.end()) {
        graph[item[0]] = {item[1]};
      } else {
        graph[item[0]].push_back(item[1]);
      }
      degrees[item[1]]++;
    }
    stack<int> st;
    for (int i = 0; i < numCourses; ++i) {
      if (degrees[i] == 0) {
        st.push(i);
      }
    }
    int finished = 0;
    while (!st.empty()) {
      int top = st.top();
      st.pop();
      ++finished;
      if (graph.find(top) == graph.end()) {
        continue;
      }
      for (int i = 0; i < graph[top].size(); ++i) {
        degrees[graph[top][i]]--;
        if (degrees[graph[top][i]] == 0) {
          st.push(graph[top][i]);
        }
      }
    }
    return finished == numCourses;
  }
};
int main() {
  Solution sln;
  // vector<pair<int, int>> prerequisites = {{1, 0}};
  // vector<pair<int, int>> prerequisites = {{1, 0}, {0, 1}};
  vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {2, 0}};
  std::cout << sln.canFinish(3, prerequisites) << std::endl;

  return 0;
}
