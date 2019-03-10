#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int minCostClimbingStairsOld(vector<int>& cost) {
      int first = min(cost, 0);
      int second = min(cost, 1);
      return first < second ? first : second;
    }

    int min(vector<int>& cost, int idx) {
      if (idx >= cost.size()) {
        return 0;
      }
      int first = cost[idx] + min(cost, idx + 1);
      int second = cost[idx] + min(cost, idx + 2);
      return first < second ? first : second;
    }

    int minCostClimbingStairs(vector<int>& cost) {
      if (cost.size() <= 0) {
        return 0;
      }
      if (cost.size() == 1) {
        return cost[0];
      }
      if (cost.size() == 2) {
        return cost[0] < cost[1] ? cost[0] : cost[1];
      }
      int cache[cost.size()];
      cache[cost.size() - 1] = cost[cost.size() - 1];
      cache[cost.size() - 2] = cost[cost.size() - 2];
      for (int i = cost.size() - 3; i >= 0; --i) {
        int first = cost[i] + cache[i + 1];
        int second = cost[i] + cache[i + 2];
        cache[i] = first < second ? first : second; 
      }
      return cache[0] < cache[1] ? cache[0] : cache[1];
    }
};

int main() {
  Solution sln;
  vector<int> cost;
  cost = {10, 15, 20};
  std::cout << sln.minCostClimbingStairs(cost) << std::endl;

  cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  std::cout << sln.minCostClimbingStairs(cost) << std::endl;

  return 0;
}
