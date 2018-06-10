#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> degrees(numCourses, 0);
    queue<int> queue;

    for (pair<int, int> item: prerequisites) {
      degrees[item.first] += 1;
    }
    for (int i = 0; i < degrees.size(); ++i) {
      if (degrees[i] == 0) {
        queue.push(i);
      }
    }
    if (queue.empty()) {
      return false;
    }
    int count = 0;
    while (count < numCourses && !queue.empty()) {
      int elem = queue.front();
      for (pair<int, int> item: prerequisites) {
        if (item.second == elem) {
          degrees[item.first] -= 1;
          if (degrees[item.first] == 0) {
            queue.push(item.first);
          }
        }
      }
      queue.pop();
      ++count;
    }
    if (count < numCourses) {
      return false;
    }
    return true;
  }
};

int main() {
  Solution sln;
  // vector<pair<int, int>> prerequisites = {{1, 0}};
  // vector<pair<int, int>> prerequisites = {{1, 0}, {0, 1}};
  vector<pair<int, int>> prerequisites = {{1, 0}, {2, 1}, {2, 0}};
  std::cout << sln.canFinish(3, prerequisites) << std::endl;

  return 0;
}
