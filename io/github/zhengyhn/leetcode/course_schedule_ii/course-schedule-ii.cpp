#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> degrees(numCourses, 0);
    queue<int> queue;
    unordered_map<int, vector<int>> graph;

    for (pair<int, int> item: prerequisites) {
      if (graph.find(item.second) == graph.end()) {
        graph[item.second] = {};
      }
      graph[item.second].push_back(item.first);
      degrees[item.first] += 1;
    }
    for (int i = 0; i < degrees.size(); ++i) {
      if (degrees[i] == 0) {
        queue.push(i);
      }
    }
    vector<int> result;
    if (queue.empty()) {
      return {};
    }
    int count = 0;
    while (!queue.empty()) {
      int elem = queue.front();
      result.push_back(elem);
      for (int item: graph[elem]) {
        degrees[item] -= 1;
        if (degrees[item] == 0) {
          queue.push(item);
        }
      }
      queue.pop();
      ++count;
    }
    if (count < numCourses) {
      return {};
    }
    return result;
  }
};

int main() {
  Solution sln;
  vector<pair<int, int>> prerequisites;
  prerequisites = {{1, 0}};
  vector<int> ret;
  ret = sln.findOrder(2, prerequisites);
  for (int item: ret) {
    std::cout << item << " ";
  }
  cout << endl;

  prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
  ret = sln.findOrder(4, prerequisites);
  for (int item: ret) {
    std::cout << item << " ";
  }
  cout << endl;

  return 0;
}
